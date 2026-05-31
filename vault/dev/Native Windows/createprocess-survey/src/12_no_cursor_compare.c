/*
 * 12_no_cursor_compare.c — launch gui_target.exe three ways and
 * dump the differences observable by the launched process and by us.
 *
 * The feedback cursor (IDC_APPSTARTING, the arrow with a spinning ring)
 * is armed by kernelbase!CreateProcessInternalW on the *launcher's*
 * side whenever:
 *   - the launched image has Subsystem = WINDOWS_GUI, and
 *   - STARTUPINFO.dwFlags lacks STARTF_FORCEOFFFEEDBACK.
 *
 * The cursor lives until WaitForInputIdle returns on the new process
 * or 5s elapses. It is *not* set by the launched process — it lives in
 * the launching process's UI thread. So the only ways to suppress it
 * are:
 *   (A) Caller passes STARTF_FORCEOFFFEEDBACK.
 *   (B) Caller bypasses CreateProcess entirely (Nt* APIs).
 *   (C) Caller is a process that doesn't show cursors (services, daemons).
 *   (D) The EXE is activated through a non-CreateProcess path (UWP /
 *       MSIX activation via IApplicationActivationManager). Requires
 *       registering an AppUserModelID. CreateProcess is not involved.
 *
 * From within the EXE there is no PE-format bit or manifest entry
 * that turns the cursor off. The "in all cases" form requires either
 * (D) — register the EXE as a packaged app / app execution alias —
 * or a shim EXE that Explorer launches (which itself exits instantly,
 * cursor expires) and re-launches the real GUI via NtCreateUserProcess.
 *
 * Run three launches: each one writes gui_target.marker so we can read
 * back what STARTUPINFO the child saw. Watch the mouse pointer during
 * each launch — only the first should show a feedback cursor for ~3s.
 */

#include "common.h"

static void show_marker(const WCHAR *banner)
{
    fwprintf(stderr, L"  --- %ls: gui_target.marker ---\n", banner);
    HANDLE f = CreateFileW(L"gui_target.marker", GENERIC_READ, FILE_SHARE_READ,
                          NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f == INVALID_HANDLE_VALUE) {
        fwprintf(stderr, L"    (marker missing)\n"); return;
    }
    char buf[512] = {0};
    DWORD r = 0;
    ReadFile(f, buf, sizeof(buf)-1, &r, NULL);
    CloseHandle(f);
    fwprintf(stderr, L"%hs", buf);
}

int wmain(void)
{
    WCHAR path[MAX_PATH];
    GetModuleFileNameW(NULL, path, MAX_PATH);
    PWSTR slash = wcsrchr(path, L'\\');
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - path), L"gui_target.exe");

    /* ============== A. CreateProcessW with no special flags ============== */
    fwprintf(stderr, L"[12 A] CreateProcessW default. Watch the cursor — you should\n"
                     L"        see a busy ring next to the pointer for ~3 seconds.\n");
    DeleteFileW(L"gui_target.marker");
    {
        STARTUPINFOW si = { sizeof(si) };
        PROCESS_INFORMATION pi = {0};
        WCHAR cmd[MAX_PATH + 32];
        swprintf_s(cmd, _countof(cmd), L"\"%s\"", path);
        BOOL ok = CreateProcessW(path, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
        if (ok) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
        } else fwprintf(stderr, L"  CreateProcessW failed: %lu\n", GetLastError());
    }
    show_marker(L"A: CreateProcessW default");

    /* ============== B. CreateProcessW + STARTF_FORCEOFFFEEDBACK ========== */
    fwprintf(stderr, L"\n[12 B] CreateProcessW + STARTF_FORCEOFFFEEDBACK. No cursor.\n");
    DeleteFileW(L"gui_target.marker");
    {
        STARTUPINFOW si = { sizeof(si) };
        si.dwFlags = STARTF_FORCEOFFFEEDBACK;
        PROCESS_INFORMATION pi = {0};
        WCHAR cmd[MAX_PATH + 32];
        swprintf_s(cmd, _countof(cmd), L"\"%s\"", path);
        BOOL ok = CreateProcessW(path, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
        if (ok) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
        } else fwprintf(stderr, L"  CreateProcessW failed: %lu\n", GetLastError());
    }
    show_marker(L"B: CreateProcessW + STARTF_FORCEOFFFEEDBACK");

    /* ============== C. NtCreateUserProcess — never arms the cursor ====== */
    fwprintf(stderr, L"\n[12 C] NtCreateUserProcess. CSRSS gets notified of the new\n"
                     L"        process but kernelbase never runs, so the busy cursor\n"
                     L"        is never armed. No cursor.\n");
    DeleteFileW(L"gui_target.marker");
    {
        UNICODE_STRING nt_image;
        NTSTATUS s = Cps_DosToNtPath(path, &nt_image);
        if (!NT_SUCCESS(s)) { fwprintf(stderr, L"  path conv failed\n"); return 1; }

        WCHAR cmd[MAX_PATH + 32];
        swprintf_s(cmd, _countof(cmd), L"\"%s\"", path);
        UNICODE_STRING cmdline;
        Cps_InitUnicodeString(&cmdline, cmd);

        PCWSTR env_entries[] = {
            L"PATH=C:\\Windows\\System32;C:\\Windows",
            L"SystemRoot=C:\\Windows",
            L"TEMP=C:\\Windows\\Temp",
            L"TMP=C:\\Windows\\Temp",
        };
        PVOID env = Cps_BuildEnvBlock(env_entries, _countof(env_entries));

        PRTL_USER_PROCESS_PARAMETERS params = NULL;
        s = Cps_MakeParams(&nt_image, &cmdline, env, &params);
        if (!NT_SUCCESS(s)) { fwprintf(stderr, L"  make params failed 0x%08lX\n",
                                        (unsigned long)s); return 1; }
        params->StandardInput  = GetStdHandle(STD_INPUT_HANDLE);
        params->StandardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        params->StandardError  = GetStdHandle(STD_ERROR_HANDLE);

        SIZE_T list_bytes = sizeof(SIZE_T) + 2 * sizeof(PS_ATTRIBUTE);
        PPS_ATTRIBUTE_LIST attrs = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, list_bytes);
        attrs->TotalLength = list_bytes;
        attrs->Attributes[0].Attribute = PS_ATTRIBUTE_IMAGE_NAME;
        attrs->Attributes[0].Size      = nt_image.Length;
        attrs->Attributes[0].ValuePtr  = nt_image.Buffer;
        attrs->Attributes[1].Attribute = PS_ATTRIBUTE_PARENT_PROCESS;
        attrs->Attributes[1].Size      = sizeof(HANDLE);
        attrs->Attributes[1].Value     = (ULONG_PTR)NtCurrentProcess();

        PS_CREATE_INFO ci = { sizeof(ci) };
        ci.State = PsCreateInitialState;
        HANDLE hP=NULL, hT=NULL;
        s = NtCreateUserProcess(&hP, &hT,
            PROCESS_ALL_ACCESS, THREAD_ALL_ACCESS,
            NULL, NULL,
            PROCESS_CREATE_FLAGS_INHERIT_HANDLES, 0,
            params, &ci, attrs);
        if (NT_SUCCESS(s)) {
            NtWaitForSingleObject(hP, FALSE, NULL);
            NtClose(hT); NtClose(hP);
        } else fwprintf(stderr, L"  NtCreateUserProcess: 0x%08lX\n", (unsigned long)s);
        HeapFree(GetProcessHeap(), 0, attrs);
        RtlDestroyProcessParameters(params);
        HeapFree(GetProcessHeap(), 0, env);
        RtlFreeUnicodeString(&nt_image);
    }
    show_marker(L"C: NtCreateUserProcess");

    fwprintf(stderr,
        L"\nSummary:\n"
        L"  A. Cursor on.  STARTUPINFO.dwFlags == 0x00000000.\n"
        L"  B. Cursor off. STARTUPINFO.dwFlags has STARTF_FORCEOFFFEEDBACK (0x80).\n"
        L"  C. Cursor off. kernelbase's cursor-arm code never ran because we\n"
        L"     bypassed CreateProcessInternalW entirely.\n"
        L"  For 'in all cases' (incl. Explorer double-click) the EXE must be\n"
        L"  registered through an activation path (AppX/MSIX/AppExecAlias).\n"
        L"  No PE bit or manifest setting can do this on its own.\n");
    return 0;
}
