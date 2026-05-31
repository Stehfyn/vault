/*
 * 01_rtl_create_user_process.c — exhaust the RtlCreateUserProcess interface.
 *
 * Signature (ntdll, exported, undocumented):
 *
 *   NTSTATUS NTAPI RtlCreateUserProcess(
 *       PCUNICODE_STRING NtImagePathName,           // \??\C:\... form, mandatory
 *       ULONG            ExtendedParameters,        // HIWORD=NumaNode, LOWORD=reserved(0)
 *       PRTL_USER_PROCESS_PARAMETERS ProcessParameters, // built by RtlCreateProcessParametersEx
 *       PSECURITY_DESCRIPTOR ProcessSecurityDescriptor, // optional
 *       PSECURITY_DESCRIPTOR ThreadSecurityDescriptor,  // optional
 *       HANDLE           ParentProcess,             // optional; NULL = current
 *       BOOLEAN          InheritHandles,            // copy inheritable handles
 *       HANDLE           DebugPort,                 // optional ALPC port
 *       HANDLE           TokenHandle,               // optional primary token
 *       PRTL_USER_PROCESS_INFORMATION ProcessInformation);
 *
 * Notes
 *   - The returned thread is *suspended*; you must NtResumeThread it.
 *   - DllPath in the parameters is ignored on modern Windows (loader uses
 *     PEB->ApiSetMap / registry).
 *   - Strings inside RTL_USER_PROCESS_PARAMETERS may be normalized
 *     (absolute pointers) or denormalized (offsets); we pass
 *     RTL_USER_PROC_PARAMS_NORMALIZED so RtlCreateUserProcess will
 *     denormalize on its own.
 *
 * Exhaustiveness checklist of the 10 parameters:
 *   1. NtImagePathName            -> resolved via RtlDosPathNameToNtPathName_U_WithStatus
 *   2. ExtendedParameters         -> packs preferred NUMA node 0 in HIWORD
 *   3. ProcessParameters          -> built with command line, environment, cwd
 *   4. ProcessSecurityDescriptor  -> empty SD (NULL DACL = full access)
 *   5. ThreadSecurityDescriptor   -> empty SD
 *   6. ParentProcess              -> explicit handle to ourselves via NtCurrentProcess
 *   7. InheritHandles             -> FALSE (we don't share fds)
 *   8. DebugPort                  -> NULL (default WER ALPC port)
 *   9. TokenHandle                -> NULL (inherit caller's token)
 *  10. ProcessInformation         -> out, validated
 */

#include "common.h"

int wmain(void)
{
    NTSTATUS status;

    /* ---------------- locate test_target.exe ----------------------------- */
    WCHAR dos_image[MAX_PATH];
    DWORD n = GetModuleFileNameW(NULL, dos_image, MAX_PATH);
    if (n == 0 || n >= MAX_PATH) {
        fprintf(stderr, "GetModuleFileNameW failed\n"); return 1;
    }
    /* Replace our own name with test_target.exe sitting next to us. */
    PWSTR slash = wcsrchr(dos_image, L'\\');
    if (!slash) { fprintf(stderr, "no slash in path\n"); return 1; }
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_image), L"test_target.exe");

    fwprintf(stderr, L"[01] image = %ls\n", dos_image);

    UNICODE_STRING nt_image;
    status = Cps_DosToNtPath(dos_image, &nt_image);
    Cps_PrintStatus("RtlDosPathNameToNtPathName_U_WithStatus", status);
    if (!NT_SUCCESS(status)) return 1;

    /* ---------------- build process parameters --------------------------- */
    /* Command line: argv[0] must be the image path. Some loaders trim it. */
    WCHAR cmdbuf[MAX_PATH + 64];
    swprintf_s(cmdbuf, _countof(cmdbuf),
               L"\"%s\" alpha bravo charlie", dos_image);
    UNICODE_STRING cmdline;
    Cps_InitUnicodeString(&cmdline, cmdbuf);

    /* Environment: inherit ours, plus stamp CPS_TARGET_TAG. */
    PCWSTR env_entries[] = {
        L"CPS_TARGET_TAG=01_rtl_create_user_process",
        L"PATH=C:\\Windows\\System32;C:\\Windows",
        L"SystemRoot=C:\\Windows",
        L"TEMP=C:\\Windows\\Temp",
        L"TMP=C:\\Windows\\Temp",
    };
    PVOID env = Cps_BuildEnvBlock(env_entries, _countof(env_entries));

    PRTL_USER_PROCESS_PARAMETERS params = NULL;
    CPS_EXTRAS extras;
    Cps_FillExtras(&extras, L"01_rtl_create_user_process");
    status = Cps_MakeParamsFull(&nt_image, &cmdline, env, &extras, &params);
    Cps_PrintStatus("RtlCreateProcessParametersEx", status);
    if (!NT_SUCCESS(status)) { RtlFreeUnicodeString(&nt_image); return 1; }

    /* The 3 handles must be inheritable AND we must pass InheritHandles=TRUE. */
    SetHandleInformation(params->StandardInput,  HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
    SetHandleInformation(params->StandardOutput, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
    SetHandleInformation(params->StandardError,  HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);

    /* ---------------- security descriptors ------------------------------- */
    /* Self-relative SDs with NULL DACL = grant-everything; only meaningful
     * here to demonstrate they're plumbed through. */
    SECURITY_DESCRIPTOR proc_sd, thr_sd;
    InitializeSecurityDescriptor(&proc_sd, SECURITY_DESCRIPTOR_REVISION);
    SetSecurityDescriptorDacl(&proc_sd, TRUE, NULL, FALSE);
    InitializeSecurityDescriptor(&thr_sd, SECURITY_DESCRIPTOR_REVISION);
    SetSecurityDescriptorDacl(&thr_sd, TRUE, NULL, FALSE);

    /* ---------------- the call ------------------------------------------- */
    RTL_USER_PROCESS_INFORMATION pi = {0};

    ULONG extended = (0u << 16); /* HIWORD = preferred NUMA node 0 */

    status = RtlCreateUserProcess(
        &nt_image,
        extended,
        params,
        &proc_sd,
        &thr_sd,
        NtCurrentProcess(),   /* explicit parent = us */
        FALSE,                /* InheritHandles */
        NULL,                 /* DebugPort */
        NULL,                 /* TokenHandle */
        &pi);
    Cps_PrintStatus("RtlCreateUserProcess", status);
    if (!NT_SUCCESS(status)) {
        RtlDestroyProcessParameters(params);
        RtlFreeUnicodeString(&nt_image);
        return 1;
    }

    fwprintf(stderr,
        L"  child pid=%llu tid=%llu image_base=%p entry=%p\n",
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueProcess,
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueThread,
        pi.ImageInformation.TransferAddress,
        pi.ImageInformation.TransferAddress);

    /* ---------------- resume + wait + exit-code check -------------------- */
    ULONG prev = 0;
    status = NtResumeThread(pi.ThreadHandle, &prev);
    Cps_PrintStatus("NtResumeThread", status);

    status = NtWaitForSingleObject(pi.ProcessHandle, FALSE, NULL);
    Cps_PrintStatus("NtWaitForSingleObject(process)", status);

    PROCESS_BASIC_INFORMATION pbi = {0};
    status = NtQueryInformationProcess(pi.ProcessHandle, ProcessBasicInformation,
                                       &pbi, sizeof(pbi), NULL);
    Cps_PrintStatus("NtQueryInformationProcess(ProcessBasicInformation)", status);

    NTSTATUS exit_status = (NTSTATUS)pbi.ExitStatus;
    fwprintf(stderr, L"  child exited with NTSTATUS 0x%08lX (%lu)\n",
             (unsigned long)exit_status, (unsigned long)exit_status);

    int rc = (exit_status == EXPECTED_CHILD_EXIT) ? 0 : 2;

    /* ---------------- cleanup ------------------------------------------- */
    NtClose(pi.ThreadHandle);
    NtClose(pi.ProcessHandle);
    RtlDestroyProcessParameters(params);
    HeapFree(GetProcessHeap(), 0, env);
    RtlFreeUnicodeString(&nt_image);
    return rc;
}
