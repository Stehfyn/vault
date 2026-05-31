/*
 * 04_nt_create_process_ex.c — exhaust NtCreateProcessEx (legacy bring-up).
 *
 *   NTSTATUS NTAPI NtCreateProcessEx(
 *       PHANDLE ProcessHandle,
 *       ACCESS_MASK DesiredAccess,
 *       PCOBJECT_ATTRIBUTES ObjectAttributes,
 *       HANDLE ParentProcess,
 *       ULONG Flags,                    // PROCESS_CREATE_FLAGS_*
 *       HANDLE SectionHandle,           // SEC_IMAGE section of the image
 *       HANDLE DebugPort,
 *       HANDLE TokenHandle,
 *       ULONG  Reserved);               // JobMemberLevel — must be 0
 *
 * NtCreateProcessEx is the older API path that *only* creates the process
 * object. There is no thread, the PEB is empty, and ProcessParameters is
 * NULL. The caller is responsible for:
 *
 *   1. Opening the image file.
 *   2. Creating a SEC_IMAGE section over it.
 *   3. NtCreateProcessEx with that section.
 *   4. Building an RTL_USER_PROCESS_PARAMETERS block.
 *   5. Denormalizing the block (pointers -> offsets).
 *   6. NtAllocateVirtualMemory in the target, writing the block.
 *   7. NtWriteVirtualMemory to set PEB->ProcessParameters.
 *   8. NtQuerySection(SectionImageInformation) to learn the entry point.
 *   9. NtCreateThreadEx with that entry as StartRoutine.
 *   10. NtResumeThread.
 *
 * Everything that NtCreateUserProcess does for you in the kernel, you do
 * yourself here. That's the point of the exercise.
 *
 * Exhaustiveness checklist
 *   ProcessHandle      -> out
 *   DesiredAccess      -> PROCESS_ALL_ACCESS
 *   ObjectAttributes   -> NULL (could carry SD; demonstrating shape only)
 *   ParentProcess      -> NtCurrentProcess()
 *   Flags              -> PROCESS_CREATE_FLAGS_INHERIT_HANDLES
 *   SectionHandle      -> built via NtCreateSection(SEC_IMAGE)
 *   DebugPort          -> NULL
 *   TokenHandle        -> NULL
 *   Reserved           -> 0
 */

#include "common.h"

int wmain(void)
{
    NTSTATUS status;
    int rc = 1;

    HANDLE hFile = NULL, hSection = NULL;
    HANDLE hProcess = NULL, hThread = NULL;
    PRTL_USER_PROCESS_PARAMETERS params = NULL;
    PVOID env = NULL;
    PVOID remote_params = NULL;
    PVOID remote_env = NULL;

    /* ---------------- image path ---------------------------------------- */
    WCHAR dos_image[MAX_PATH];
    GetModuleFileNameW(NULL, dos_image, MAX_PATH);
    PWSTR slash = wcsrchr(dos_image, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_image), L"test_target.exe");
    fwprintf(stderr, L"[04] image = %ls\n", dos_image);

    UNICODE_STRING nt_image;
    status = Cps_DosToNtPath(dos_image, &nt_image);
    Cps_PrintStatus("RtlDosPathNameToNtPathName_U_WithStatus", status);
    if (!NT_SUCCESS(status)) return 1;

    /* ---------------- open image file ----------------------------------- */
    OBJECT_ATTRIBUTES file_oa;
    InitializeObjectAttributes(&file_oa, &nt_image, OBJ_CASE_INSENSITIVE, NULL, NULL);
    IO_STATUS_BLOCK iosb = {0};
    status = NtCreateFile(
        &hFile,
        FILE_READ_DATA | FILE_EXECUTE | FILE_READ_ATTRIBUTES | SYNCHRONIZE,
        &file_oa,
        &iosb,
        NULL,                                 /* AllocationSize */
        FILE_ATTRIBUTE_NORMAL,
        FILE_SHARE_READ | FILE_SHARE_DELETE,
        FILE_OPEN,                            /* CreateDisposition */
        FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,
        NULL, 0);
    Cps_PrintStatus("NtCreateFile(image)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    /* ---------------- create SEC_IMAGE section -------------------------- */
    status = NtCreateSection(
        &hSection,
        SECTION_ALL_ACCESS,
        NULL,                  /* ObjectAttributes */
        NULL,                  /* MaximumSize — NULL = use file size */
        PAGE_READONLY,         /* SectionPageProtection (for SEC_IMAGE: ignored) */
        SEC_IMAGE,
        hFile);
    Cps_PrintStatus("NtCreateSection(SEC_IMAGE)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    /* ---------------- create the process (no thread) --------------------- */
    status = NtCreateProcessEx(
        &hProcess,
        PROCESS_ALL_ACCESS,
        NULL,                          /* ObjectAttributes */
        NtCurrentProcess(),            /* ParentProcess */
        PROCESS_CREATE_FLAGS_INHERIT_HANDLES,
        hSection,
        NULL,                          /* DebugPort */
        NULL,                          /* TokenHandle */
        0);                            /* JobMemberLevel — must be 0 */
    Cps_PrintStatus("NtCreateProcessEx", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    /* ---------------- pull section image info (entry point) ------------- */
    SECTION_IMAGE_INFORMATION sii = {0};
    status = NtQuerySection(hSection, SectionImageInformation, &sii, sizeof(sii), NULL);
    Cps_PrintStatus("NtQuerySection(SectionImageInformation)", status);
    if (!NT_SUCCESS(status)) goto cleanup;
    fwprintf(stderr, L"  entry=%p stack=%llu-%llu subsys=%d machine=0x%04X\n",
        sii.TransferAddress,
        (unsigned long long)sii.CommittedStackSize,
        (unsigned long long)sii.MaximumStackSize,
        sii.SubSystemType,
        sii.Machine);

    /* ---------------- find target's PEB ---------------------------------- */
    PROCESS_BASIC_INFORMATION pbi = {0};
    status = NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                                       &pbi, sizeof(pbi), NULL);
    Cps_PrintStatus("NtQueryInformationProcess(ProcessBasicInformation)", status);
    if (!NT_SUCCESS(status)) goto cleanup;
    fwprintf(stderr, L"  target PEB = %p\n", pbi.PebBaseAddress);

    /* ---------------- build process parameters --------------------------- */
    WCHAR cmdbuf[MAX_PATH + 64];
    swprintf_s(cmdbuf, _countof(cmdbuf), L"\"%s\" nt_cp_ex", dos_image);
    UNICODE_STRING cmdline;
    Cps_InitUnicodeString(&cmdline, cmdbuf);

    PCWSTR env_entries[] = {
        L"CPS_TARGET_TAG=04_nt_create_process_ex",
        L"PATH=C:\\Windows\\System32;C:\\Windows",
        L"SystemRoot=C:\\Windows",
        L"TEMP=C:\\Windows\\Temp",
        L"TMP=C:\\Windows\\Temp",
    };
    env = Cps_BuildEnvBlock(env_entries, _countof(env_entries));

    CPS_EXTRAS extras;
    Cps_FillExtras(&extras, L"04_nt_create_process_ex");
    status = Cps_MakeParamsFull(&nt_image, &cmdline, env, &extras, &params);
    Cps_PrintStatus("RtlCreateProcessParametersEx", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    fwprintf(stderr,
        L"  params (pre-denorm): MaximumLength=%lu Length=%lu Flags=0x%08X "
        L"EnvSize=%llu Env=%p ImagePath.Buf=%p\n",
        params->MaximumLength, params->Length, params->Flags,
        (unsigned long long)params->EnvironmentSize,
        params->Environment, params->ImagePathName.Buffer);

    /* The block is currently normalized — string pointers are absolute,
     * relative to our address space. Denormalize to turn them into
     * offsets from the params base. The first thread will renormalize
     * inside the target. */
    PRTL_USER_PROCESS_PARAMETERS denorm = RtlDeNormalizeProcessParams(params);
    fwprintf(stderr,
        L"  params (post-denorm): same=%d MaximumLength=%lu Length=%lu "
        L"Flags=0x%08X Env=%p ImagePath.Buf=%p\n",
        denorm == params, params->MaximumLength, params->Length,
        params->Flags, params->Environment, params->ImagePathName.Buffer);

    /* The environment block lives in a *separate* allocation that
     * Environment points to. RtlDeNormalizeProcessParams does not
     * convert that pointer (and RtlNormalizeProcessParams in the target
     * will leave it alone too) — so we have to map the env into the
     * target, then patch our local copy's Environment field to that
     * remote address before writing the params block. */
    SIZE_T env_size = params->EnvironmentSize;
    if (env_size > 0 && params->Environment != NULL) {
        status = NtAllocateVirtualMemory(hProcess, &remote_env, 0,
                                         &env_size,
                                         MEM_COMMIT | MEM_RESERVE,
                                         PAGE_READWRITE);
        Cps_PrintStatus("NtAllocateVirtualMemory(target env)", status);
        if (!NT_SUCCESS(status)) goto cleanup;
        SIZE_T env_wrote = 0;
        status = NtWriteVirtualMemory(hProcess, remote_env,
                                      params->Environment,
                                      params->EnvironmentSize, &env_wrote);
        Cps_PrintStatus("NtWriteVirtualMemory(env block)", status);
        if (!NT_SUCCESS(status)) goto cleanup;
        fwprintf(stderr, L"  wrote %llu env bytes at %p\n",
                 (unsigned long long)env_wrote, remote_env);
        /* Patch our local copy — the kernel/loader in the target will see
         * the new pointer, which is valid in *its* address space. */
        params->Environment = remote_env;
    }

    SIZE_T params_size = params->MaximumLength;
    fwprintf(stderr, L"  params block: %llu bytes\n",
             (unsigned long long)params_size);

    /* ---------------- write parameters into target ---------------------- */
    status = NtAllocateVirtualMemory(hProcess, &remote_params, 0,
                                     &params_size,
                                     MEM_COMMIT | MEM_RESERVE,
                                     PAGE_READWRITE);
    Cps_PrintStatus("NtAllocateVirtualMemory(target params)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    SIZE_T wrote = 0;
    status = NtWriteVirtualMemory(hProcess, remote_params, params,
                                  params->MaximumLength, &wrote);
    Cps_PrintStatus("NtWriteVirtualMemory(params block)", status);
    if (!NT_SUCCESS(status)) goto cleanup;
    fwprintf(stderr, L"  wrote %llu bytes at %p\n",
             (unsigned long long)wrote, remote_params);

    /* ---------------- patch PEB->ProcessParameters ---------------------- */
    /* In x64, PEB->ProcessParameters lives at offset 0x20. We confirm via
     * FIELD_OFFSET to stay portable to phnt's PEB layout. */
    PVOID peb_params_field =
        (PVOID)((ULONG_PTR)pbi.PebBaseAddress + FIELD_OFFSET(PEB, ProcessParameters));
    status = NtWriteVirtualMemory(hProcess, peb_params_field,
                                  &remote_params, sizeof(remote_params), &wrote);
    Cps_PrintStatus("NtWriteVirtualMemory(PEB->ProcessParameters)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    /* ---------------- create the initial thread ------------------------- */
    /* StartRoutine = image entry. The kernel automatically routes the
     * first thread of a process through ntdll!LdrInitializeThunk; our
     * entry runs after loader init. */
    status = NtCreateThreadEx(
        &hThread,
        THREAD_ALL_ACCESS,
        NULL,                      /* ObjectAttributes */
        hProcess,
        (PUSER_THREAD_START_ROUTINE)sii.TransferAddress,
        NULL,                      /* Argument */
        THREAD_CREATE_FLAGS_CREATE_SUSPENDED,
        0, 0, 0,                   /* ZeroBits, StackSize, MaxStack (defaults) */
        NULL);                     /* AttributeList */
    Cps_PrintStatus("NtCreateThreadEx", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    THREAD_BASIC_INFORMATION tbi = {0};
    if (NT_SUCCESS(NtQueryInformationThread(hThread, ThreadBasicInformation,
                                            &tbi, sizeof(tbi), NULL))) {
        fwprintf(stderr, L"  child pid=%llu tid=%llu\n",
            (unsigned long long)(ULONG_PTR)tbi.ClientId.UniqueProcess,
            (unsigned long long)(ULONG_PTR)tbi.ClientId.UniqueThread);
    }

    /* ---------------- resume + wait ------------------------------------ */
    ULONG prev = 0;
    status = NtResumeThread(hThread, &prev);
    Cps_PrintStatus("NtResumeThread", status);

    status = NtWaitForSingleObject(hProcess, FALSE, NULL);
    Cps_PrintStatus("NtWaitForSingleObject", status);

    PROCESS_BASIC_INFORMATION pbi2 = {0};
    NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                              &pbi2, sizeof(pbi2), NULL);
    NTSTATUS exit_status = (NTSTATUS)pbi2.ExitStatus;
    fwprintf(stderr, L"  child exit = 0x%08lX\n", (unsigned long)exit_status);

    rc = (exit_status == EXPECTED_CHILD_EXIT) ? 0 : 2;

cleanup:
    if (hThread)   NtClose(hThread);
    if (hProcess)  NtClose(hProcess);
    if (hSection)  NtClose(hSection);
    if (hFile)     NtClose(hFile);
    if (params)    RtlDestroyProcessParameters(params);
    if (env)       HeapFree(GetProcessHeap(), 0, env);
    RtlFreeUnicodeString(&nt_image);
    return rc;
}
