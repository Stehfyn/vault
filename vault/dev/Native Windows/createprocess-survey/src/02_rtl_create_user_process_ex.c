/*
 * 02_rtl_create_user_process_ex.c — exhaust RtlCreateUserProcessEx.
 *
 * Signature (Windows 10 RS2+, ntdll):
 *
 *   NTSTATUS NTAPI RtlCreateUserProcessEx(
 *       PCUNICODE_STRING NtImagePathName,
 *       PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
 *       BOOLEAN InheritHandles,
 *       PRTL_USER_PROCESS_EXTENDED_PARAMETERS Extended OPTIONAL,
 *       PRTL_USER_PROCESS_INFORMATION ProcessInformation);
 *
 *   struct RTL_USER_PROCESS_EXTENDED_PARAMETERS {
 *       USHORT Version;                                 // = 1
 *       USHORT NodeNumber;                              // preferred NUMA
 *       PSECURITY_DESCRIPTOR ProcessSecurityDescriptor;
 *       PSECURITY_DESCRIPTOR ThreadSecurityDescriptor;
 *       HANDLE ParentProcess;
 *       HANDLE DebugPort;
 *       HANDLE TokenHandle;
 *       HANDLE JobHandle;                               // added vs the old API
 *   };
 *
 * Versus RtlCreateUserProcess this:
 *   - flattens the four trailing arguments into a struct, and
 *   - adds a JobHandle slot (caller-controlled job association at create time).
 *
 * Exhaustiveness checklist
 *   Version       -> RTL_USER_PROCESS_EXTENDED_PARAMETERS_VERSION (1)
 *   NodeNumber    -> 0
 *   ProcessSD     -> NULL-DACL SD
 *   ThreadSD      -> NULL-DACL SD
 *   ParentProcess -> NtCurrentProcess()
 *   DebugPort     -> NULL (default WER port)
 *   TokenHandle   -> NULL (inherit)
 *   JobHandle     -> a freshly-created CreateJobObjectW handle so we can
 *                    verify the child enters our job.
 */

#include "common.h"

int wmain(void)
{
    NTSTATUS status;
    int rc = 1;
    HANDLE job = NULL;
    PRTL_USER_PROCESS_PARAMETERS params = NULL;
    PVOID env = NULL;

    /* image path */
    WCHAR dos_image[MAX_PATH];
    GetModuleFileNameW(NULL, dos_image, MAX_PATH);
    PWSTR slash = wcsrchr(dos_image, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_image), L"test_target.exe");
    fwprintf(stderr, L"[02] image = %ls\n", dos_image);

    UNICODE_STRING nt_image;
    status = Cps_DosToNtPath(dos_image, &nt_image);
    Cps_PrintStatus("RtlDosPathNameToNtPathName_U_WithStatus", status);
    if (!NT_SUCCESS(status)) return 1;

    /* command line */
    WCHAR cmdbuf[MAX_PATH + 64];
    swprintf_s(cmdbuf, _countof(cmdbuf), L"\"%s\" rtl_ex_test", dos_image);
    UNICODE_STRING cmdline;
    Cps_InitUnicodeString(&cmdline, cmdbuf);

    /* environment */
    PCWSTR env_entries[] = {
        L"CPS_TARGET_TAG=02_rtl_create_user_process_ex",
        L"PATH=C:\\Windows\\System32;C:\\Windows",
        L"SystemRoot=C:\\Windows",
        L"TEMP=C:\\Windows\\Temp",
        L"TMP=C:\\Windows\\Temp",
    };
    env = Cps_BuildEnvBlock(env_entries, _countof(env_entries));

    CPS_EXTRAS extras;
    Cps_FillExtras(&extras, L"02_rtl_create_user_process_ex");
    status = Cps_MakeParamsFull(&nt_image, &cmdline, env, &extras, &params);
    Cps_PrintStatus("RtlCreateProcessParametersEx", status);
    if (!NT_SUCCESS(status)) goto fail0;

    /* security descriptors */
    SECURITY_DESCRIPTOR proc_sd, thr_sd;
    InitializeSecurityDescriptor(&proc_sd, SECURITY_DESCRIPTOR_REVISION);
    SetSecurityDescriptorDacl(&proc_sd, TRUE, NULL, FALSE);
    InitializeSecurityDescriptor(&thr_sd, SECURITY_DESCRIPTOR_REVISION);
    SetSecurityDescriptorDacl(&thr_sd, TRUE, NULL, FALSE);

    /* job — empty, just to demonstrate the JobHandle slot is functional */
    job = CreateJobObjectW(NULL, NULL);
    if (!job) {
        fprintf(stderr, "CreateJobObjectW failed: %lu\n", GetLastError());
        goto fail1;
    }

    /* Make sure breakaway is NOT set so the child stays in our job. */
    JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = {0};
    /* JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE lets us prove we owned the child by
     * tearing it down when the job closes (we don't actually invoke that
     * path here — we wait normally — but it's wired). */
    jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
    SetInformationJobObject(job, JobObjectExtendedLimitInformation,
                            &jeli, sizeof(jeli));

    RTL_USER_PROCESS_EXTENDED_PARAMETERS extp = {0};
    extp.Version                     = RTL_USER_PROCESS_EXTENDED_PARAMETERS_VERSION;
    extp.NodeNumber                  = 0;
    extp.ProcessSecurityDescriptor   = &proc_sd;
    extp.ThreadSecurityDescriptor    = &thr_sd;
    extp.ParentProcess               = NtCurrentProcess();
    extp.DebugPort                   = NULL;
    extp.TokenHandle                 = NULL;
    extp.JobHandle                   = job;

    RTL_USER_PROCESS_INFORMATION pi = {0};
    status = RtlCreateUserProcessEx(
        &nt_image,
        params,
        FALSE,       /* InheritHandles */
        &extp,
        &pi);
    Cps_PrintStatus("RtlCreateUserProcessEx", status);
    if (!NT_SUCCESS(status)) goto fail2;

    fwprintf(stderr, L"  child pid=%llu tid=%llu\n",
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueProcess,
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueThread);

    /* Confirm child landed in our job. */
    JOBOBJECT_BASIC_PROCESS_ID_LIST idlist = {0};
    DWORD ret = 0;
    BOOL ok = QueryInformationJobObject(job, JobObjectBasicProcessIdList,
                                        &idlist, sizeof(idlist), &ret);
    fwprintf(stderr,
        L"  QueryInformationJobObject ok=%d NumberOfAssignedProcesses=%lu first=%llu\n",
        ok, idlist.NumberOfAssignedProcesses,
        idlist.NumberOfAssignedProcesses
            ? (unsigned long long)idlist.ProcessIdList[0] : 0ULL);

    /* resume + wait */
    ULONG prev = 0;
    NtResumeThread(pi.ThreadHandle, &prev);
    NtWaitForSingleObject(pi.ProcessHandle, FALSE, NULL);

    PROCESS_BASIC_INFORMATION pbi = {0};
    NtQueryInformationProcess(pi.ProcessHandle, ProcessBasicInformation,
                              &pbi, sizeof(pbi), NULL);
    NTSTATUS exit_status = (NTSTATUS)pbi.ExitStatus;
    fwprintf(stderr, L"  child exit = 0x%08lX\n", (unsigned long)exit_status);

    rc = (exit_status == EXPECTED_CHILD_EXIT) ? 0 : 2;

    NtClose(pi.ThreadHandle);
    NtClose(pi.ProcessHandle);
fail2:
    if (job) NtClose(job);
fail1:
    if (params) RtlDestroyProcessParameters(params);
fail0:
    if (env) HeapFree(GetProcessHeap(), 0, env);
    RtlFreeUnicodeString(&nt_image);
    return rc;
}
