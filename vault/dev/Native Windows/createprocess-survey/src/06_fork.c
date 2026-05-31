/*
 * 06_fork.c — fork() on Windows via RtlCloneUserProcess.
 *
 * Why CreateProcess cannot do this
 * ---------------------------------
 * fork() copies the entire address space (heap, stack, mapped files,
 * loaded DLLs, every variable). The child resumes at the same source
 * line as the parent, with identical state, then immediately diverges.
 *
 * Win32 has no fork. CreateProcess always launches a *separate* binary
 * — argv, env, address space layout, all start from scratch. The
 * closest you can do is CreateProcess(self) + serialize state through
 * a pipe / shared memory / re-exec marshalling. Not the same.
 *
 * The ntdll routine RtlCloneUserProcess wraps NtCreateUserProcess with
 * a kernel-side "copy parent address space" flag. The single call
 * returns *twice*:
 *
 *   - in the parent  -> STATUS_SUCCESS (0x00000000), ProcessInformation filled
 *   - in the child   -> STATUS_PROCESS_CLONED (0x00000129), ProcessInformation
 *                       has the *parent's* identity
 *
 * Both then continue executing the same code; we branch on the return.
 *
 * Caveats
 *   - RtlCloneUserProcess freezes all other threads while it copies,
 *     then resumes them. We are single-threaded here, so no issue.
 *   - The child does not inherit the CRT lock state from the parent
 *     in a guaranteed-clean way; classic fork gotchas apply. Avoid
 *     calling printf/malloc from the child between fork and exit if
 *     the parent was holding any of those locks. Our child only does
 *     CreateFile/WriteFile/NtTerminateProcess.
 */

#define STATUS_PROCESS_CLONED ((NTSTATUS)0x00000129L)

#include "common.h"

int wmain(void)
{
    /* A pre-fork sentinel in the parent's address space — the child
     * will see the same value (proving address space was copied). */
    volatile ULONG_PTR pre_fork_marker = 0xDEADBEEF11223344ULL;

    /* Compute the absolute marker path BEFORE forking. We can't rely on
     * the child's CWD handle in PEB->ProcessParameters being functional
     * post-clone — RtlCloneUserProcess does not run the CreateProcess
     * prep that makes the cwd handle inheritable. Doing this here means
     * the child receives a fully-qualified path with no relative
     * resolution needed. */
    WCHAR marker_path[MAX_PATH];
    {
        WCHAR cwd[MAX_PATH];
        GetCurrentDirectoryW(MAX_PATH, cwd);
        swprintf_s(marker_path, MAX_PATH, L"%s\\06_fork.child.marker", cwd);
    }

    RTL_USER_PROCESS_INFORMATION pi = {0};

    fwprintf(stderr, L"[06] about to fork. pre_fork_marker=0x%llX (parent pid=%lu)\n",
        (unsigned long long)pre_fork_marker, GetCurrentProcessId());
    fwprintf(stderr, L"  marker path: %ls\n", marker_path);
    fflush(stderr);

    NTSTATUS status = RtlCloneUserProcess(
        RTL_CLONE_PROCESS_FLAGS_INHERIT_HANDLES,
        NULL,           /* ProcessSecurityDescriptor */
        NULL,           /* ThreadSecurityDescriptor */
        NULL,           /* DebugPort */
        &pi);

    if (status == STATUS_PROCESS_CLONED) {
        /* ---------------- CHILD branch ---------------- */
        /* We are now executing in the freshly-forked process.
         * Be careful: do not touch the CRT lock state inherited from
         * the parent. Write directly via Win32 file APIs. */
        DWORD child_pid = GetCurrentProcessId();
        HANDLE f = CreateFileW(marker_path, GENERIC_WRITE, FILE_SHARE_READ, NULL,
                               CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (f != INVALID_HANDLE_VALUE) {
            char buf[256];
            int n = _snprintf_s(buf, sizeof(buf), _TRUNCATE,
                "FORK CHILD\n"
                "child_pid=%lu\n"
                "saw_pre_fork_marker=0x%llX (expected 0xDEADBEEF11223344)\n"
                "RtlCloneUserProcess returned 0x%08lX (STATUS_PROCESS_CLONED)\n"
                "parent_handle_in_pi=%p\n"
                "thread_handle_in_pi=%p\n",
                child_pid,
                (unsigned long long)pre_fork_marker,
                (unsigned long)status,
                pi.ProcessHandle, pi.ThreadHandle);
            DWORD wrote;
            WriteFile(f, buf, (DWORD)n, &wrote, NULL);
            CloseHandle(f);
        }
        /* Exit via the Nt path — RtlExitUserProcess runs DLL detach
         * handlers, but on a cloned address space those handlers can
         * touch state the parent still owns. NtTerminateProcess
         * bypasses cleanup. */
        NtTerminateProcess(NtCurrentProcess(), 0x5A /* sentinel */);
        /* unreachable */
        return 0;
    }

    if (!NT_SUCCESS(status)) {
        fwprintf(stderr, L"  RtlCloneUserProcess FAILED: 0x%08lX\n",
                 (unsigned long)status);
        return 1;
    }

    /* ---------------- PARENT branch ---------------- */
    fwprintf(stderr,
        L"  parent: clone OK, child pid=%llu tid=%llu\n",
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueProcess,
        (unsigned long long)(ULONG_PTR)pi.ClientId.UniqueThread);

    /* Wait for the child to finish */
    NtWaitForSingleObject(pi.ProcessHandle, FALSE, NULL);

    PROCESS_BASIC_INFORMATION pbi = {0};
    NtQueryInformationProcess(pi.ProcessHandle, ProcessBasicInformation,
                              &pbi, sizeof(pbi), NULL);
    fwprintf(stderr,
        L"  parent: child exit status = 0x%08lX (expected 0x5A)\n",
        (unsigned long)pbi.ExitStatus);

    NtClose(pi.ThreadHandle);
    NtClose(pi.ProcessHandle);

    /* Sanity check: open the marker we expect the child to have left. */
    HANDLE f = CreateFileW(marker_path, GENERIC_READ, FILE_SHARE_READ,
                          NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f != INVALID_HANDLE_VALUE) {
        char buf[512] = {0};
        DWORD read = 0;
        ReadFile(f, buf, sizeof(buf) - 1, &read, NULL);
        CloseHandle(f);
        fwprintf(stderr, L"  parent: child wrote:\n");
        fwprintf(stderr, L"%hs\n", buf);
    } else {
        fwprintf(stderr, L"  parent: no marker file found (child may have crashed)\n");
        return 2;
    }
    return pbi.ExitStatus == 0x5A ? 0 : 2;
}
