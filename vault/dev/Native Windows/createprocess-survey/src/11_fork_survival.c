/*
 * 11_fork_survival.c — survey what survives RtlCloneUserProcess.
 *
 * Stuff state into every plausible place, fork, and have the child
 * report what it actually sees. Each category exposes a different
 * classical fork hazard.
 *
 *   1. CRT static (mutable global)        — should survive
 *   2. Heap allocation                    — should survive
 *   3. TlsAlloc/TlsSetValue slot          — should survive on the
 *                                            calling thread (only thread
 *                                            in child)
 *   4. CRITICAL_SECTION held by parent    — child inherits a "locked"
 *                                            CS that no live thread owns
 *                                            (CLASSIC FORK BUG)
 *   5. EVENT signaled before fork         — kernel handle, should survive
 *                                            via INHERIT_HANDLES
 *   6. PEB->NumberOfHeaps                 — kernel-managed; should be
 *                                            identical
 *
 * Hazards we exercise rather than work around:
 *   - We deliberately do NOT call RtlUpdateClonedCriticalSection. We
 *     want the child to discover the CS is "locked" by a phantom owner.
 *   - We TryEnterCriticalSection with timeout 0 so the child doesn't
 *     deadlock.
 */

#define STATUS_PROCESS_CLONED ((NTSTATUS)0x00000129L)

#include "common.h"

/* CRT static. */
static volatile int g_counter = 0;
static const char  *g_phrase  = "set-before-fork";

int wmain(void)
{
    /* Capture absolute cwd up front — child's cwd handle is broken. */
    WCHAR cwd[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, cwd);

    /* (1) CRT static: bump it. */
    g_counter = 0xABCDEF;

    /* (2) Heap: stash a sentinel block. */
    char *heap_blob = HeapAlloc(GetProcessHeap(), 0, 64);
    if (!heap_blob) return 1;
    strcpy_s(heap_blob, 64, "I-was-allocated-by-the-parent");

    /* (3) TLS: allocate a slot, set a value. */
    DWORD tls_slot = TlsAlloc();
    LPVOID tls_val = (LPVOID)(ULONG_PTR)0xDEADC0DE;
    TlsSetValue(tls_slot, tls_val);

    /* (4) Critical section: HOLD IT across the fork. */
    CRITICAL_SECTION cs;
    InitializeCriticalSection(&cs);
    EnterCriticalSection(&cs);   /* lock held by the calling thread */

    /* (5) Event: create signaled. */
    HANDLE ev = CreateEventW(NULL, TRUE /*manual reset*/, TRUE /*signaled*/, NULL);
    SetHandleInformation(ev, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);

    /* (6) PEB->NumberOfHeaps — read from our own PEB. */
#ifdef _WIN64
    PVOID our_peb = (PVOID)__readgsqword(0x60);
#else
    PVOID our_peb = (PVOID)__readfsdword(0x30);
#endif
    ULONG parent_heap_count = *(ULONG *)((char *)our_peb + 0xE8);
    ULONG parent_proc_heap_off = 0x30;
    PVOID parent_proc_heap = *(PVOID *)((char *)our_peb + parent_proc_heap_off);

    fwprintf(stderr,
        L"[11] parent state pre-fork:\n"
        L"     g_counter=0x%X heap_blob=%p tls_slot=%lu ev=%p\n"
        L"     PEB->NumberOfHeaps=%lu PEB->ProcessHeap=%p CS owner=this thread\n",
        g_counter, (PVOID)heap_blob, tls_slot, ev,
        parent_heap_count, parent_proc_heap);

    RTL_USER_PROCESS_INFORMATION pi = {0};
    NTSTATUS status = RtlCloneUserProcess(
        RTL_CLONE_PROCESS_FLAGS_INHERIT_HANDLES,
        NULL, NULL, NULL, &pi);

    if (status == STATUS_PROCESS_CLONED) {
        /* ----- CHILD branch ----- */
        WCHAR marker_path[MAX_PATH];
        swprintf_s(marker_path, MAX_PATH, L"%s\\11_fork_survival.child.marker", cwd);
        HANDLE f = CreateFileW(marker_path, GENERIC_WRITE, FILE_SHARE_READ, NULL,
                               CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (f == INVALID_HANDLE_VALUE) {
            NtTerminateProcess(NtCurrentProcess(), 0xE1);
        }
        char buf[1024];
        char heap_seen[64] = "(unreadable)";
        __try { strcpy_s(heap_seen, sizeof(heap_seen), heap_blob); }
        __except(EXCEPTION_EXECUTE_HANDLER) {}

        /* TLS read — should see the parent's value because the thread
         * is the same (in the kernel/clone sense) and TEB.TlsSlots is
         * part of the cloned address space. */
        LPVOID tls_seen = TlsGetValue(tls_slot);

        /* CS check — try to enter without blocking. With the lock
         * held by a phantom owner, TryEnterCriticalSection should
         * return FALSE — a fingerprint of the classic fork-with-locks
         * bug. */
        BOOL cs_acquired = TryEnterCriticalSection(&cs);
        /* Don't actually leave it if we got it; we're about to die. */

        /* Event handle — should be signaled (inherited via INHERIT_HANDLES). */
        DWORD ev_wait = WaitForSingleObject(ev, 0);

        /* PEB->NumberOfHeaps & ProcessHeap in the child. */
#ifdef _WIN64
        PVOID child_peb = (PVOID)__readgsqword(0x60);
#else
        PVOID child_peb = (PVOID)__readfsdword(0x30);
#endif
        ULONG child_heap_count = *(ULONG *)((char *)child_peb + 0xE8);
        PVOID child_proc_heap  = *(PVOID *)((char *)child_peb + 0x30);

        int n = _snprintf_s(buf, sizeof(buf), _TRUNCATE,
            "FORK SURVIVAL REPORT\n"
            "child_pid=%lu  parent_pid=%lu\n"
            "(1) g_counter        = 0x%X    (parent set 0xABCDEF)  %s\n"
            "(2) heap_blob (%p) = \"%s\"\n"
            "(3) TlsGetValue(%lu) = %p    (parent set 0xDEADC0DE)  %s\n"
            "(4) TryEnterCriticalSection = %s  (BUG: child sees lock held by phantom owner -> FALSE)\n"
            "(5) WaitForSingleObject(event,0) = 0x%lX  (0 = WAIT_OBJECT_0 = signaled)\n"
            "(6) PEB->NumberOfHeaps = %lu  (parent had %lu)\n"
            "(6) PEB->ProcessHeap   = %p  (parent had %p)\n"
            "(6) PEB pointer itself = %p  (parent had %p)\n",
            GetCurrentProcessId(),
            (DWORD)(ULONG_PTR)NtCurrentTeb()->ClientId.UniqueThread,  /* tid */
            g_counter, g_counter == 0xABCDEF ? "OK" : "DRIFTED",
            (PVOID)heap_blob, heap_seen,
            tls_slot, tls_seen,
            tls_seen == tls_val ? "OK" : "DRIFTED",
            cs_acquired ? "TRUE (unexpected!)" : "FALSE (expected)",
            ev_wait,
            child_heap_count, parent_heap_count,
            child_proc_heap, parent_proc_heap,
            child_peb, our_peb);
        DWORD wrote;
        WriteFile(f, buf, (DWORD)n, &wrote, NULL);
        CloseHandle(f);
        NtTerminateProcess(NtCurrentProcess(), 0x77);
    }

    if (!NT_SUCCESS(status)) {
        fwprintf(stderr, L"  RtlCloneUserProcess: 0x%08lX\n", (unsigned long)status);
        return 1;
    }

    /* ----- PARENT branch ----- */
    NtWaitForSingleObject(pi.ProcessHandle, FALSE, NULL);
    NtClose(pi.ThreadHandle);
    NtClose(pi.ProcessHandle);

    WCHAR marker_path[MAX_PATH];
    swprintf_s(marker_path, MAX_PATH, L"%s\\11_fork_survival.child.marker", cwd);
    HANDLE f = CreateFileW(marker_path, GENERIC_READ, FILE_SHARE_READ, NULL,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f != INVALID_HANDLE_VALUE) {
        char buf[1500] = {0};
        DWORD read = 0;
        ReadFile(f, buf, sizeof(buf) - 1, &read, NULL);
        CloseHandle(f);
        fwprintf(stderr, L"%hs\n", buf);
    }

    LeaveCriticalSection(&cs);
    DeleteCriticalSection(&cs);
    CloseHandle(ev);
    TlsFree(tls_slot);
    HeapFree(GetProcessHeap(), 0, heap_blob);
    return 0;
}
