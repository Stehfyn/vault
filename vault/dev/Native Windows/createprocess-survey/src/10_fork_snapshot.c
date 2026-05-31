/*
 * 10_fork_snapshot.c — use a suspended clone as a frozen memory snapshot
 * that an external observer can inspect at leisure.
 *
 * Why this is crazy / impossible with CreateProcess
 * --------------------------------------------------
 * The whole point of a "snapshot" is that you freeze a process's
 * exact heap+stack+TEB state at an instant, so a forensic tool can
 * read it without races. There is no Win32 API that produces a live,
 * suspended, but otherwise identical copy of the calling process.
 * CreateToolhelp32Snapshot / minidumps are *read-only descriptors*,
 * not live PROCESS_VM_READ-able kernel objects.
 *
 * RtlCloneUserProcess + RTL_CLONE_PROCESS_FLAGS_CREATE_SUSPENDED gives
 * us exactly that: a real kernel EPROCESS object with a frozen address
 * space identical to ours, that will never execute unless we let it.
 *
 * Demonstration:
 *   1. Stuff a recognizable sentinel into the heap.
 *   2. Clone suspended.
 *   3. From the parent, read the child's memory at the same virtual
 *      address and confirm the sentinel matches.
 *   4. Walk the child's address-space regions to prove the layout
 *      mirrors ours.
 *   5. Terminate without resuming.
 */

#define STATUS_PROCESS_CLONED ((NTSTATUS)0x00000129L)

#include "common.h"

#define SENTINEL_BYTES 4096
static const ULONG SENTINEL_PATTERN = 0xCAFED00DUL;

int wmain(void)
{
    /* --- Stuff sentinels into the heap. --- */
    ULONG *blob = HeapAlloc(GetProcessHeap(), 0, SENTINEL_BYTES);
    if (!blob) return 1;
    for (SIZE_T i = 0; i < SENTINEL_BYTES / sizeof(ULONG); ++i)
        blob[i] = SENTINEL_PATTERN ^ (ULONG)i;

    fwprintf(stderr,
        L"[10] parent: sentinel at %p, %d bytes, first=0x%08X last=0x%08X\n",
        (PVOID)blob, SENTINEL_BYTES,
        blob[0], blob[SENTINEL_BYTES / sizeof(ULONG) - 1]);

    /* --- Clone suspended. --- */
    RTL_USER_PROCESS_INFORMATION pi = {0};
    NTSTATUS status = RtlCloneUserProcess(
        RTL_CLONE_PROCESS_FLAGS_CREATE_SUSPENDED |
        RTL_CLONE_PROCESS_FLAGS_INHERIT_HANDLES,
        NULL, NULL, NULL, &pi);

    if (status == STATUS_PROCESS_CLONED) {
        /* This branch should be reached only if the parent ever resumes
         * the child. We don't, so this is dead code. If it ever runs
         * it means the SUSPENDED flag was not honored; bail loudly. */
        NtTerminateProcess(NtCurrentProcess(), 0xDEADC0DE);
        return 0xDEADC0DE;
    }
    if (!NT_SUCCESS(status)) {
        fwprintf(stderr, L"  RtlCloneUserProcess: 0x%08lX\n", (unsigned long)status);
        return 1;
    }

    fwprintf(stderr,
        L"  parent: cloned suspended. child pid=%llu tid=%llu (will NOT resume)\n",
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueProcess,
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueThread);

    /* --- Read child's memory at the sentinel's address. --- */
    ULONG *child_read = HeapAlloc(GetProcessHeap(), 0, SENTINEL_BYTES);
    SIZE_T read = 0;
    status = NtReadVirtualMemory(pi.ProcessHandle, blob,
                                 child_read, SENTINEL_BYTES, &read);
    Cps_PrintStatus("NtReadVirtualMemory(child sentinel)", status);
    fwprintf(stderr, L"  read %llu bytes\n", (unsigned long long)read);

    int identical = (memcmp(blob, child_read, SENTINEL_BYTES) == 0);
    fwprintf(stderr,
        L"  child has IDENTICAL bytes at %p: %ls\n",
        (PVOID)blob, identical ? L"YES" : L"NO");
    fwprintf(stderr, L"  child first=0x%08X last=0x%08X\n",
        child_read[0],
        child_read[SENTINEL_BYTES / sizeof(ULONG) - 1]);

    /* --- Inspect the child's thread context. --- */
    CONTEXT ctx = {0};
    ctx.ContextFlags = CONTEXT_FULL;
    if (NT_SUCCESS(NtGetContextThread(pi.ThreadHandle, &ctx))) {
        fwprintf(stderr,
            L"  child thread context (suspended): Rip=%p Rsp=%p Rbp=%p Rax=%p\n",
            (PVOID)ctx.Rip, (PVOID)ctx.Rsp, (PVOID)ctx.Rbp, (PVOID)ctx.Rax);
    }

    /* --- Walk the child's region map (first 10 non-free). --- */
    fwprintf(stderr, L"  child address-space snapshot (first 10 non-free regions):\n");
    PVOID base = NULL;
    MEMORY_BASIC_INFORMATION mbi;
    int rows = 0;
    while (NtQueryVirtualMemory(pi.ProcessHandle, base, MemoryBasicInformation,
                                &mbi, sizeof(mbi), NULL) == STATUS_SUCCESS) {
        if (mbi.State != MEM_FREE) {
            fwprintf(stderr,
                L"    %p  %12llu  state=0x%lX type=0x%lX prot=0x%lX\n",
                mbi.BaseAddress,
                (unsigned long long)mbi.RegionSize,
                mbi.State, mbi.Type, mbi.Protect);
            if (++rows >= 10) break;
        }
        base = (PUCHAR)mbi.BaseAddress + mbi.RegionSize;
        if ((ULONG_PTR)base >= 0x00007FFFFFFEFFFFULL) break;
    }

    /* --- Tear down without ever resuming the child. --- */
    NtTerminateProcess(pi.ProcessHandle, 0);
    NtClose(pi.ThreadHandle);
    NtClose(pi.ProcessHandle);
    HeapFree(GetProcessHeap(), 0, blob);
    HeapFree(GetProcessHeap(), 0, child_read);
    return identical ? 0 : 2;
}
