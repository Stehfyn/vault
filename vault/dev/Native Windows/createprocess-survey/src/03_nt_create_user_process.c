/*
 * 03_nt_create_user_process.c — exhaust NtCreateUserProcess.
 *
 *   NTSTATUS NTAPI NtCreateUserProcess(
 *       PHANDLE ProcessHandle,
 *       PHANDLE ThreadHandle,
 *       ACCESS_MASK ProcessDesiredAccess,
 *       ACCESS_MASK ThreadDesiredAccess,
 *       PCOBJECT_ATTRIBUTES ProcessObjectAttributes,
 *       PCOBJECT_ATTRIBUTES ThreadObjectAttributes,
 *       ULONG ProcessFlags,               // PROCESS_CREATE_FLAGS_*
 *       ULONG ThreadFlags,                // THREAD_CREATE_FLAGS_*
 *       PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
 *       PPS_CREATE_INFO CreateInfo,
 *       PPS_ATTRIBUTE_LIST AttributeList);
 *
 * Notes
 *   - This is the modern syscall — every CreateProcess* path ends here.
 *   - The kernel maps the image *from PsAttributeImageName*; we do not
 *     pre-open the file. Pass an NT path.
 *   - We build a PS_ATTRIBUTE_LIST covering the attributes that are
 *     plausibly testable from user mode without elevation:
 *
 *      [0] PsAttributeImageName       (in)    — image NT path
 *      [1] PsAttributeParentProcess   (in)    — explicit parent
 *      [2] PsAttributeClientId        (out)   — receives child CLIENT_ID
 *      [3] PsAttributeImageInfo       (out)   — receives SECTION_IMAGE_INFORMATION
 *      [4] PsAttributeTebAddress      (out)   — receives initial-thread TEB pointer
 *      [5] PsAttributeMitigationOptions (in)  — DEP_ENABLE
 *      [6] PsAttributeChildProcessPolicy (in) — value 0 (no restriction)
 *      [7] PsAttributePriorityClass   (in)    — NORMAL (2)
 *      [8] PsAttributeErrorMode       (in)    — SEM_NOGPFAULTERRORBOX
 *
 *   Out attributes pass their storage via ValuePtr; for HANDLE-typed in
 *   attributes the handle goes in Value (the union member).
 *
 *   PsAttributeImageName Value = byte buffer; Size = #bytes of the wide
 *   path *without* the trailing NUL.
 */

#include "common.h"

#define ATTR_COUNT 9

int wmain(void)
{
    NTSTATUS status;
    int rc = 1;
    PRTL_USER_PROCESS_PARAMETERS params = NULL;
    PVOID env = NULL;
    HANDLE hProcess = NULL, hThread = NULL;
    PPS_ATTRIBUTE_LIST attrs = NULL;

    /* image */
    WCHAR dos_image[MAX_PATH];
    GetModuleFileNameW(NULL, dos_image, MAX_PATH);
    PWSTR slash = wcsrchr(dos_image, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_image), L"test_target.exe");
    fwprintf(stderr, L"[03] image = %ls\n", dos_image);

    UNICODE_STRING nt_image;
    status = Cps_DosToNtPath(dos_image, &nt_image);
    Cps_PrintStatus("RtlDosPathNameToNtPathName_U_WithStatus", status);
    if (!NT_SUCCESS(status)) return 1;

    /* command line */
    WCHAR cmdbuf[MAX_PATH + 64];
    swprintf_s(cmdbuf, _countof(cmdbuf), L"\"%s\" nt_cup", dos_image);
    UNICODE_STRING cmdline;
    Cps_InitUnicodeString(&cmdline, cmdbuf);

    /* env */
    PCWSTR env_entries[] = {
        L"CPS_TARGET_TAG=03_nt_create_user_process",
        L"PATH=C:\\Windows\\System32;C:\\Windows",
        L"SystemRoot=C:\\Windows",
        L"TEMP=C:\\Windows\\Temp",
        L"TMP=C:\\Windows\\Temp",
    };
    env = Cps_BuildEnvBlock(env_entries, _countof(env_entries));

    CPS_EXTRAS extras;
    Cps_FillExtras(&extras, L"03_nt_create_user_process");
    status = Cps_MakeParamsFull(&nt_image, &cmdline, env, &extras, &params);
    Cps_PrintStatus("RtlCreateProcessParametersEx", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    /* ---------------- attribute list ------------------------------------- */
    /* Out-receiver storage */
    CLIENT_ID                  out_cid  = {0};
    SECTION_IMAGE_INFORMATION  out_imginfo = {0};
    PTEB                       out_teb  = NULL;

    /* In-payload storage */
    ULONG64 mitigation = 0;
    /* DEP_ENABLE = 0x01 << (2 * PS_MITIGATION_OPTION_NX) = 0x01 (slot 0). */
    mitigation |= (ULONG64)0x01;
    ULONG child_policy = 0;
    UCHAR prio_class   = 2;  /* NORMAL_PRIORITY_CLASS in NT form */
    ULONG err_mode     = SEM_NOGPFAULTERRORBOX;

    SIZE_T list_bytes = sizeof(SIZE_T) + ATTR_COUNT * sizeof(PS_ATTRIBUTE);
    attrs = (PPS_ATTRIBUTE_LIST)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, list_bytes);
    if (!attrs) { fprintf(stderr, "OOM\n"); goto cleanup; }
    attrs->TotalLength = list_bytes;

    /* [0] ImageName — the NT path buffer. Size excludes NUL. */
    attrs->Attributes[0].Attribute    = PS_ATTRIBUTE_IMAGE_NAME;
    attrs->Attributes[0].Size         = nt_image.Length;
    attrs->Attributes[0].ValuePtr     = nt_image.Buffer;
    /* [1] ParentProcess — HANDLE goes inline in Value. */
    attrs->Attributes[1].Attribute    = PS_ATTRIBUTE_PARENT_PROCESS;
    attrs->Attributes[1].Size         = sizeof(HANDLE);
    attrs->Attributes[1].Value        = (ULONG_PTR)NtCurrentProcess();
    /* [2] ClientId — out struct. */
    attrs->Attributes[2].Attribute    = PS_ATTRIBUTE_CLIENT_ID;
    attrs->Attributes[2].Size         = sizeof(out_cid);
    attrs->Attributes[2].ValuePtr     = &out_cid;
    /* [3] ImageInfo — out struct. */
    attrs->Attributes[3].Attribute    = PS_ATTRIBUTE_IMAGE_INFO;
    attrs->Attributes[3].Size         = sizeof(out_imginfo);
    attrs->Attributes[3].ValuePtr     = &out_imginfo;
    /* [4] TebAddress — out PTEB. */
    attrs->Attributes[4].Attribute    = PS_ATTRIBUTE_TEB_ADDRESS;
    attrs->Attributes[4].Size         = sizeof(out_teb);
    attrs->Attributes[4].ValuePtr     = &out_teb;
    /* [5] MitigationOptions — ULONG64 bitfield (one slot is enough). */
    attrs->Attributes[5].Attribute    = PS_ATTRIBUTE_MITIGATION_OPTIONS;
    attrs->Attributes[5].Size         = sizeof(mitigation);
    attrs->Attributes[5].ValuePtr     = &mitigation;
    /* [6] ChildProcessPolicy — ULONG. */
    attrs->Attributes[6].Attribute    = PS_ATTRIBUTE_CHILD_PROCESS_POLICY;
    attrs->Attributes[6].Size         = sizeof(child_policy);
    attrs->Attributes[6].ValuePtr     = &child_policy;
    /* [7] PriorityClass — UCHAR. */
    attrs->Attributes[7].Attribute    = PS_ATTRIBUTE_PRIORITY_CLASS;
    attrs->Attributes[7].Size         = sizeof(prio_class);
    attrs->Attributes[7].ValuePtr     = &prio_class;
    /* [8] ErrorMode — ULONG. */
    attrs->Attributes[8].Attribute    = PS_ATTRIBUTE_ERROR_MODE;
    attrs->Attributes[8].Size         = sizeof(err_mode);
    attrs->Attributes[8].ValuePtr     = &err_mode;

    /* ---------------- PS_CREATE_INFO ------------------------------------- */
    PS_CREATE_INFO ci = {0};
    ci.Size  = sizeof(ci);
    ci.State = PsCreateInitialState;
    ci.InitState.InitFlags = 0;                /* default */
    ci.InitState.AdditionalFileAccess = 0;

    /* ---------------- the call ------------------------------------------- */
    status = NtCreateUserProcess(
        &hProcess,
        &hThread,
        PROCESS_ALL_ACCESS,
        THREAD_ALL_ACCESS,
        NULL,    /* ProcessObjectAttributes */
        NULL,    /* ThreadObjectAttributes */
        PROCESS_CREATE_FLAGS_INHERIT_HANDLES,
        THREAD_CREATE_FLAGS_CREATE_SUSPENDED,
        params,
        &ci,
        attrs);
    Cps_PrintStatus("NtCreateUserProcess", status);

    /* Map common failure states to readable text. */
    fwprintf(stderr, L"  PS_CREATE_INFO.State = %d (Success=%d)\n",
             ci.State, PsCreateSuccess);
    if (!NT_SUCCESS(status)) {
        /* Anything that fails leaves the failure reason in ci.* */
        switch (ci.State) {
            case PsCreateFailOnFileOpen:
                fwprintf(stderr, L"  -> file could not be opened\n"); break;
            case PsCreateFailOnSectionCreate:
                fwprintf(stderr, L"  -> section creation failed\n"); break;
            case PsCreateFailExeFormat:
                fwprintf(stderr, L"  -> EXE format invalid; dll chars=0x%04X\n",
                         ci.ExeFormat.DllCharacteristics);
                break;
            case PsCreateFailExeName:
                fwprintf(stderr, L"  -> name rejected (debugger via IFEO)\n"); break;
            default: break;
        }
        goto cleanup;
    }

    fwprintf(stderr,
        L"  out: pid=%llu tid=%llu teb=%p machine=0x%04X "
        L"entry=%p protected=%lu manifest=%p\n",
        (unsigned long long)(ULONG_PTR)out_cid.UniqueProcess,
        (unsigned long long)(ULONG_PTR)out_cid.UniqueThread,
        out_teb,
        out_imginfo.Machine,
        out_imginfo.TransferAddress,
        (unsigned long)ci.SuccessState.ProtectedProcess,
        (PVOID)ci.SuccessState.ManifestAddress);

    /* resume + wait */
    ULONG prev = 0;
    NtResumeThread(hThread, &prev);
    NtWaitForSingleObject(hProcess, FALSE, NULL);

    PROCESS_BASIC_INFORMATION pbi = {0};
    NtQueryInformationProcess(hProcess, ProcessBasicInformation, &pbi, sizeof(pbi), NULL);
    NTSTATUS exit_status = (NTSTATUS)pbi.ExitStatus;
    fwprintf(stderr, L"  child exit = 0x%08lX\n", (unsigned long)exit_status);

    rc = (exit_status == EXPECTED_CHILD_EXIT) ? 0 : 2;

cleanup:
    if (hThread)  NtClose(hThread);
    if (hProcess) NtClose(hProcess);
    if (attrs)    HeapFree(GetProcessHeap(), 0, attrs);
    if (params)   RtlDestroyProcessParameters(params);
    if (env)      HeapFree(GetProcessHeap(), 0, env);
    RtlFreeUnicodeString(&nt_image);
    return rc;
}
