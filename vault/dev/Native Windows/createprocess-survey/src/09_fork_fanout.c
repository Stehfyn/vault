/*
 * 09_fork_fanout.c — fan-out 4 workers from a fork. Each worker sees
 * the parent's pre-fork heap unchanged and processes a different slice.
 *
 * Why this is crazy / impossible with CreateProcess
 * --------------------------------------------------
 * With CreateProcess the only way to give 4 worker processes a 100 MB
 * dataset is to either (a) re-load it from disk in each worker, (b)
 * marshal it through pipes / shared memory, or (c) jam it in a memory-
 * mapped file.
 *
 * With RtlCloneUserProcess, the kernel copies the parent's entire
 * address space to each child via copy-on-write — N children cost
 * approximately 1x the parent's memory (only the modified pages
 * diverge). The children read live heap pointers that were valid in
 * the parent at the instant of fork.
 *
 * In this sample the dataset is small but the mechanism is the same.
 * Each child:
 *   - reads worker_id from a pre-fork variable to know which slot it owns
 *   - dereferences a pointer to the parent-heap-allocated table
 *   - computes its slot's result and writes it to a marker file
 *
 * The parent reads each marker and prints a summary.
 */

#define STATUS_PROCESS_CLONED ((NTSTATUS)0x00000129L)

#include "common.h"

#define WORKER_COUNT 4

typedef struct _WORK_ITEM {
    int    input;
    char   name[32];
} WORK_ITEM;

static int compute(int x) { return x * x + 17; }

static void child_run(int worker_id,
                      const WORK_ITEM *table,
                      const WCHAR *cwd)
{
    /* CWD handle is broken post-clone — write to an absolute path. */
    WCHAR marker[MAX_PATH];
    swprintf_s(marker, MAX_PATH, L"%s\\09_fork.worker%d.marker",
               cwd, worker_id);

    HANDLE f = CreateFileW(marker, GENERIC_WRITE, FILE_SHARE_READ, NULL,
                           CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f == INVALID_HANDLE_VALUE) {
        NtTerminateProcess(NtCurrentProcess(), 0xE1);
        return;
    }

    int result = compute(table[worker_id].input);
    char buf[256];
    int n = _snprintf_s(buf, sizeof(buf), _TRUNCATE,
        "worker_id=%d\n"
        "child_pid=%lu\n"
        "table_ptr=%p (same pointer that parent owned!)\n"
        "name=%s\n"
        "input=%d\n"
        "result=%d\n",
        worker_id,
        GetCurrentProcessId(),
        (PVOID)table,
        table[worker_id].name,
        table[worker_id].input,
        result);
    DWORD wrote;
    WriteFile(f, buf, (DWORD)n, &wrote, NULL);
    CloseHandle(f);

    NtTerminateProcess(NtCurrentProcess(), (NTSTATUS)result);
}

int wmain(void)
{
    /* Capture absolute cwd up front — children can't compute it post-fork. */
    WCHAR cwd[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, cwd);

    /* Allocate work items in the parent heap. The children will see
     * these at the same virtual address. */
    WORK_ITEM *table = HeapAlloc(GetProcessHeap(), 0,
                                 sizeof(WORK_ITEM) * WORKER_COUNT);
    if (!table) return 1;
    for (int i = 0; i < WORKER_COUNT; ++i) {
        table[i].input = (i + 1) * 10;  /* 10, 20, 30, 40 */
        sprintf_s(table[i].name, sizeof(table[i].name), "task-%d", i);
    }
    fwprintf(stderr, L"[09] parent loaded %d items at %p, forking %d workers\n",
             WORKER_COUNT, (PVOID)table, WORKER_COUNT);

    HANDLE child_handles[WORKER_COUNT] = {0};

    for (int i = 0; i < WORKER_COUNT; ++i) {
        int worker_id = i;  /* captured by value — survives across the clone */
        RTL_USER_PROCESS_INFORMATION pi = {0};

        NTSTATUS status = RtlCloneUserProcess(
            RTL_CLONE_PROCESS_FLAGS_INHERIT_HANDLES,
            NULL, NULL, NULL, &pi);

        if (status == STATUS_PROCESS_CLONED) {
            /* CHILD — diverge based on the captured worker_id. */
            child_run(worker_id, table, cwd);
            /* unreachable */
            NtTerminateProcess(NtCurrentProcess(), 0xE0);
        }
        if (!NT_SUCCESS(status)) {
            fwprintf(stderr, L"  fork %d failed: 0x%08lX\n",
                     i, (unsigned long)status);
            continue;
        }
        child_handles[i] = pi.ProcessHandle;
        NtClose(pi.ThreadHandle);
        fwprintf(stderr, L"  parent: forked worker %d pid=%llu\n",
                 i,
                 (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueProcess);
    }

    /* Wait for all children. */
    fwprintf(stderr, L"  parent: waiting for %d workers...\n", WORKER_COUNT);
    for (int i = 0; i < WORKER_COUNT; ++i) {
        if (child_handles[i]) {
            NtWaitForSingleObject(child_handles[i], FALSE, NULL);
        }
    }

    /* Read each marker. */
    int total = 0;
    for (int i = 0; i < WORKER_COUNT; ++i) {
        WCHAR marker[MAX_PATH];
        swprintf_s(marker, MAX_PATH, L"%s\\09_fork.worker%d.marker", cwd, i);
        HANDLE f = CreateFileW(marker, GENERIC_READ, FILE_SHARE_READ, NULL,
                               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (f == INVALID_HANDLE_VALUE) {
            fwprintf(stderr, L"  parent: worker %d marker MISSING\n", i);
            continue;
        }
        char buf[512] = {0};
        DWORD read = 0;
        ReadFile(f, buf, sizeof(buf) - 1, &read, NULL);
        CloseHandle(f);
        fwprintf(stderr, L"  --- worker %d ---\n%hs", i, buf);

        PROCESS_BASIC_INFORMATION pbi = {0};
        NtQueryInformationProcess(child_handles[i], ProcessBasicInformation,
                                  &pbi, sizeof(pbi), NULL);
        total += (int)pbi.ExitStatus;
        NtClose(child_handles[i]);
    }

    int expected = compute(10) + compute(20) + compute(30) + compute(40);
    fwprintf(stderr, L"  parent: sum of worker exit codes = %d (expected %d)\n",
             total, expected);

    HeapFree(GetProcessHeap(), 0, table);
    return total == expected ? 0 : 2;
}
