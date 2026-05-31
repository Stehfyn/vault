/*
 * 08_skip_loader_init.c — run a process whose initial thread bypasses
 * ntdll!LdrInitializeThunk entirely.
 *
 * Why CreateProcess cannot do this
 * ---------------------------------
 * Every CreateProcess path resolves to NtCreateUserProcess in the kernel,
 * which always wires the first thread to enter ntdll!LdrInitializeThunk
 * before user code. The loader runs module init, TLS callbacks, hooks,
 * the works.
 *
 * THREAD_CREATE_FLAGS_SKIP_LOADER_INIT (0x20) on NtCreateThreadEx is
 * the only escape. The kernel jumps the thread directly to the user
 * StartRoutine. ntdll is still mapped, but its loader is dormant —
 * PEB->Ldr is NULL, no module list, no TLS, no DLLs. The process
 * exists in the simplest possible runtime state.
 *
 * To exercise this we use a tiny PE built with /NODEFAULTLIB and no
 * imports (tiny_target.exe). Its entry just spins in a NOP loop.
 *
 * The parent:
 *   1. NtCreateProcessEx with tiny_target.exe.
 *   2. NtCreateThreadEx + SKIP_LOADER_INIT + CREATE_SUSPENDED at the
 *      image's entry point.
 *   3. Resume, sleep briefly, suspend.
 *   4. Read the child's PEB. Confirm PEB->Ldr is NULL (would be non-NULL
 *      if LdrInitializeThunk had run).
 *   5. Terminate.
 */

#include "common.h"

int wmain(void)
{
    NTSTATUS status;
    HANDLE hFile = NULL, hSection = NULL, hProcess = NULL, hThread = NULL;

    /* tiny_target.exe must be in the same dir. */
    WCHAR dos_image[MAX_PATH];
    GetModuleFileNameW(NULL, dos_image, MAX_PATH);
    PWSTR slash = wcsrchr(dos_image, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_image), L"tiny_target.exe");
    fwprintf(stderr, L"[08] running %ls with SKIP_LOADER_INIT\n", dos_image);

    UNICODE_STRING nt_image;
    status = Cps_DosToNtPath(dos_image, &nt_image);
    if (!NT_SUCCESS(status)) return 1;

    OBJECT_ATTRIBUTES oa;
    InitializeObjectAttributes(&oa, &nt_image, OBJ_CASE_INSENSITIVE, NULL, NULL);
    IO_STATUS_BLOCK iosb = {0};
    status = NtCreateFile(&hFile,
        FILE_READ_DATA | FILE_EXECUTE | FILE_READ_ATTRIBUTES | SYNCHRONIZE,
        &oa, &iosb, NULL, FILE_ATTRIBUTE_NORMAL,
        FILE_SHARE_READ | FILE_SHARE_DELETE,
        FILE_OPEN, FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,
        NULL, 0);
    Cps_PrintStatus("NtCreateFile(tiny_target)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    status = NtCreateSection(&hSection, SECTION_ALL_ACCESS, NULL, NULL,
                             PAGE_READONLY, SEC_IMAGE, hFile);
    Cps_PrintStatus("NtCreateSection(SEC_IMAGE)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    status = NtCreateProcessEx(&hProcess, PROCESS_ALL_ACCESS, NULL,
        NtCurrentProcess(),
        0,                  /* no inherit-handles — keep it tiny */
        hSection, NULL, NULL, 0);
    Cps_PrintStatus("NtCreateProcessEx", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    SECTION_IMAGE_INFORMATION sii = {0};
    NtQuerySection(hSection, SectionImageInformation, &sii, sizeof(sii), NULL);
    fwprintf(stderr, L"  entry=%p subsys=%d machine=0x%04X\n",
        sii.TransferAddress, sii.SubSystemType, sii.Machine);

    /* Find target PEB. */
    PROCESS_BASIC_INFORMATION pbi = {0};
    NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                              &pbi, sizeof(pbi), NULL);
    fwprintf(stderr, L"  child pid=%llu PEB=%p\n",
        (unsigned long long)(ULONG_PTR)pbi.UniqueProcessId,
        pbi.PebBaseAddress);

    /* The headline: SKIP_LOADER_INIT in CreateFlags. */
    status = NtCreateThreadEx(
        &hThread,
        THREAD_ALL_ACCESS,
        NULL,
        hProcess,
        (PUSER_THREAD_START_ROUTINE)sii.TransferAddress,
        NULL,
        THREAD_CREATE_FLAGS_CREATE_SUSPENDED |
        THREAD_CREATE_FLAGS_SKIP_LOADER_INIT,
        0, 0, 0,
        NULL);
    Cps_PrintStatus("NtCreateThreadEx(SKIP_LOADER_INIT)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    NtResumeThread(hThread, NULL);

    /* Give the child a moment to enter its NOP loop. */
    LARGE_INTEGER delay;
    delay.QuadPart = -100LL * 10 * 1000;  /* 100 ms */
    NtDelayExecution(FALSE, &delay);

    NtSuspendThread(hThread, NULL);

    /* Read PEB->Ldr from the child. Offset 0x18 on x64. */
    PVOID child_ldr = NULL;
    SIZE_T read = 0;
    PVOID ldr_field = (PVOID)((ULONG_PTR)pbi.PebBaseAddress + 0x18);
    NTSTATUS rs = NtReadVirtualMemory(hProcess, ldr_field, &child_ldr,
                                      sizeof(child_ldr), &read);
    Cps_PrintStatus("NtReadVirtualMemory(child PEB->Ldr)", rs);

    /* Read PEB->ProcessHeap (offset 0x30) and PEB->ImageBaseAddress (0x10)
     * for comparison. ImageBase IS set by the kernel during section map.
     * ProcessHeap is set during loader init, so should be NULL here. */
    PVOID child_imagebase = NULL, child_heap = NULL;
    NtReadVirtualMemory(hProcess, (PVOID)((ULONG_PTR)pbi.PebBaseAddress + 0x10),
                        &child_imagebase, sizeof(child_imagebase), NULL);
    NtReadVirtualMemory(hProcess, (PVOID)((ULONG_PTR)pbi.PebBaseAddress + 0x30),
                        &child_heap, sizeof(child_heap), NULL);

    fwprintf(stderr, L"  child PEB->Ldr            = %p  (NULL = loader init was skipped)\n",
             child_ldr);
    fwprintf(stderr, L"  child PEB->ImageBaseAddress = %p  (set by kernel from section)\n",
             child_imagebase);
    fwprintf(stderr, L"  child PEB->ProcessHeap    = %p  (NULL = no heap created, loader didn't run)\n",
             child_heap);

    /* Confirm the thread is actually executing in the NOP loop by
     * reading its context's Rip. */
    CONTEXT ctx = {0};
    ctx.ContextFlags = CONTEXT_CONTROL;
    if (NT_SUCCESS(NtGetContextThread(hThread, &ctx))) {
        fwprintf(stderr,
            L"  child RIP=%p  (should be at or near %p, the entry)\n",
            (PVOID)ctx.Rip, sii.TransferAddress);
    }

    NtTerminateProcess(hProcess, 0x99);
    NtWaitForSingleObject(hProcess, FALSE, NULL);

cleanup:
    if (hThread)  NtClose(hThread);
    if (hProcess) NtClose(hProcess);
    if (hSection) NtClose(hSection);
    if (hFile)    NtClose(hFile);
    RtlFreeUnicodeString(&nt_image);
    return 0;
}
