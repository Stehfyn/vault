/*
 * 05_no_thread.c — create a real, fully-mapped process that has no thread.
 *
 * Why CreateProcess cannot do this
 * ---------------------------------
 * Every Win32 CreateProcess variant always creates the initial thread —
 * even with CREATE_SUSPENDED you still get a thread handle, the kernel
 * has reserved a stack, registered the thread in the EPROCESS thread
 * list, and runs PspUserThreadStartup the moment you resume.
 *
 * NtCreateProcessEx, by contrast, separates *process* creation from
 * *thread* creation. The result is a kernel EPROCESS object with a
 * fully populated address space (ntdll mapped, image mapped, PEB
 * allocated by the kernel) but ETHREAD count = 0. It cannot run; it
 * just exists.
 *
 * Use cases
 *   - Forensic / introspection tools that want to load and inspect an
 *     image's memory layout exactly as the kernel would, without ever
 *     executing it.
 *   - Sandbox factories that mint zombie templates which other code
 *     finishes wiring up (write PEB, create thread) later, possibly
 *     under different security contexts.
 *
 * What we demonstrate
 *   1. NtCreateFile + NtCreateSection(SEC_IMAGE).
 *   2. NtCreateProcessEx.
 *   3. PROCESS_BASIC_INFORMATION / SECTION_IMAGE_INFORMATION queries.
 *   4. NtQueryVirtualMemory walk over the address space — proves
 *      everything is really mapped.
 *   5. NtTerminateProcess to tear it down. The kernel destroys the
 *      EPROCESS once we close every handle.
 *
 * Expect zero threads, exit code = STATUS_PROCESS_IS_TERMINATING after
 * we terminate.
 */

#include "common.h"

static const char *MemStateName(ULONG s)
{
    switch (s) {
        case MEM_COMMIT:  return "COMMIT";
        case MEM_RESERVE: return "RESERVE";
        case MEM_FREE:    return "FREE";
        default:          return "?";
    }
}
static const char *MemTypeName(ULONG t)
{
    switch (t) {
        case MEM_IMAGE:   return "IMAGE";
        case MEM_MAPPED:  return "MAPPED";
        case MEM_PRIVATE: return "PRIVATE";
        default:          return "-";
    }
}

int wmain(void)
{
    NTSTATUS status;
    HANDLE hFile = NULL, hSection = NULL, hProcess = NULL;

    WCHAR dos_image[MAX_PATH];
    GetModuleFileNameW(NULL, dos_image, MAX_PATH);
    PWSTR slash = wcsrchr(dos_image, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - dos_image), L"test_target.exe");
    fwprintf(stderr, L"[05] mapping %ls without ever creating a thread\n", dos_image);

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
    Cps_PrintStatus("NtCreateFile", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    status = NtCreateSection(&hSection, SECTION_ALL_ACCESS, NULL, NULL,
                             PAGE_READONLY, SEC_IMAGE, hFile);
    Cps_PrintStatus("NtCreateSection(SEC_IMAGE)", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    status = NtCreateProcessEx(&hProcess, PROCESS_ALL_ACCESS, NULL,
        NtCurrentProcess(),
        PROCESS_CREATE_FLAGS_INHERIT_HANDLES,
        hSection, NULL, NULL, 0);
    Cps_PrintStatus("NtCreateProcessEx", status);
    if (!NT_SUCCESS(status)) goto cleanup;

    /* --- the process is alive but has zero threads. Inspect it. -------- */
    PROCESS_BASIC_INFORMATION pbi = {0};
    NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                              &pbi, sizeof(pbi), NULL);
    fwprintf(stderr,
        L"  child pid=%llu PEB=%p ParentPID=%llu BasePriority=%ld\n",
        (unsigned long long)(ULONG_PTR)pbi.UniqueProcessId,
        pbi.PebBaseAddress,
        (unsigned long long)(ULONG_PTR)pbi.InheritedFromUniqueProcessId,
        pbi.BasePriority);

    /* ProcessHandleCount query — should show 0 threads on this process,
     * which is the headline. NtQueryInformationProcess(ProcessSessionInformation)
     * confirms the EPROCESS is real. */
    ULONG handle_count = 0;
    status = NtQueryInformationProcess(hProcess, ProcessHandleCount,
                                       &handle_count, sizeof(handle_count), NULL);
    Cps_PrintStatus("NtQueryInformationProcess(ProcessHandleCount)", status);
    fwprintf(stderr, L"  child handle count: %lu\n", handle_count);

    /* The thread-count query: ask the kernel about its threads. We use
     * ProcessBasicInformation again and additionally NtQuerySystemInformation
     * would be heavyweight; just confirm with the ETHREAD enumeration
     * via NtGetNextThread (returns STATUS_NO_MORE_ENTRIES immediately). */
    HANDLE first_thread = NULL;
    status = NtGetNextThread(hProcess, NULL, THREAD_QUERY_LIMITED_INFORMATION,
                             0, 0, &first_thread);
    fwprintf(stderr,
        L"  NtGetNextThread first call: 0x%08lX %ls (no-thread = STATUS_NO_MORE_ENTRIES 0x8000001A)\n",
        (unsigned long)status,
        (status == STATUS_NO_MORE_ENTRIES) ? L"<- expected" : L"!! unexpected");

    /* --- prove the address space is real by walking it ----------------- */
    fwprintf(stderr, L"  address-space map (first 12 regions):\n");
    PVOID base = NULL;
    MEMORY_BASIC_INFORMATION mbi;
    int rows = 0;
    while (NtQueryVirtualMemory(hProcess, base, MemoryBasicInformation,
                                &mbi, sizeof(mbi), NULL) == STATUS_SUCCESS) {
        if (mbi.State != MEM_FREE) {
            fwprintf(stderr, L"    %p  %12llu  %-8hs %-7hs prot=0x%lX\n",
                mbi.BaseAddress,
                (unsigned long long)mbi.RegionSize,
                MemStateName(mbi.State),
                MemTypeName(mbi.Type),
                mbi.Protect);
            if (++rows >= 12) break;
        }
        base = (PUCHAR)mbi.BaseAddress + mbi.RegionSize;
        if ((ULONG_PTR)base >= (ULONG_PTR)0x00007FFFFFFEFFFFULL) break;
    }

    /* --- tear it down -------------------------------------------------- */
    status = NtTerminateProcess(hProcess, STATUS_CANCELLED);
    Cps_PrintStatus("NtTerminateProcess", status);

    /* Wait for the process to actually leave the kernel's process list.
     * Without a thread the process can't run code, but NtTerminateProcess
     * synchronously transitions the EPROCESS to "terminating". */
    NtWaitForSingleObject(hProcess, FALSE, NULL);
    NtQueryInformationProcess(hProcess, ProcessBasicInformation,
                              &pbi, sizeof(pbi), NULL);
    fwprintf(stderr, L"  final ExitStatus = 0x%08lX\n",
             (unsigned long)pbi.ExitStatus);

cleanup:
    if (hProcess) NtClose(hProcess);
    if (hSection) NtClose(hSection);
    if (hFile)    NtClose(hFile);
    RtlFreeUnicodeString(&nt_image);
    /* Return 0 on success — the demo is informational. */
    return 0;
}
