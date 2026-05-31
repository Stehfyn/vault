/*
 * gui_target.c — a tiny GUI subsystem app (Subsystem = WINDOWS_GUI = 2).
 *
 * It exists to be launched by other examples so they can prove that
 * (a) CreateProcessW arms the feedback cursor for this process,
 * (b) NtCreateUserProcess does NOT, and
 * (c) STARTF_FORCEOFFFEEDBACK turns it off.
 *
 * Behavior:
 *   - Creates a small visible window with title "cps-gui-target".
 *   - Writes a marker file gui_target.marker indicating launch path
 *     diagnostics: STARTUPINFO.dwFlags as seen via GetStartupInfoW,
 *     whether STARTF_FORCEOFFFEEDBACK is set, and a few PEB fields.
 *   - Waits 3 seconds (long enough that, if a feedback cursor were
 *     armed, a human user would see it) then exits.
 *
 * If you launch this from Explorer or via CreateProcessW with no
 * special flags, you'll see the spinning-wait cursor for ~3s next to
 * the mouse pointer. If you launch via one of the Nt* APIs, you will
 * not.
 *
 * Linked /SUBSYSTEM:WINDOWS so wWinMain is the entry.
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    if (msg == WM_DESTROY) { PostQuitMessage(0); return 0; }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prev,
                    PWSTR cmd, int show)
{
    (void)prev; (void)cmd; (void)show;

    /* Capture the startup info and write a diagnostic marker first. */
    STARTUPINFOW si = {0};
    GetStartupInfoW(&si);

    WCHAR path[MAX_PATH];
    GetModuleFileNameW(NULL, path, MAX_PATH);
    PWSTR slash = wcsrchr(path, L'\\');
    if (slash) {
        wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - path), L"gui_target.marker");
    }
    FILE *f = NULL;
    _wfopen_s(&f, path, L"w");
    if (f) {
        fprintf(f, "gui_target launched\n");
        fprintf(f, "pid=%lu\n", GetCurrentProcessId());
        fprintf(f, "STARTUPINFO.dwFlags=0x%08lX\n", si.dwFlags);
        fprintf(f, "STARTF_FORCEOFFFEEDBACK (0x80)=%s\n",
                (si.dwFlags & STARTF_FORCEOFFFEEDBACK) ? "SET (cursor suppressed)" : "clear");
        fprintf(f, "STARTF_FORCEONFEEDBACK  (0x40)=%s\n",
                (si.dwFlags & STARTF_FORCEONFEEDBACK)  ? "SET" : "clear");
        fprintf(f, "wShowWindow=%u\n", si.wShowWindow);
        fclose(f);
    }

    /* Create a small visible window. */
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"cps-gui-target";
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(0, L"cps-gui-target", L"cps-gui-target",
                                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                CW_USEDEFAULT, CW_USEDEFAULT, 320, 200,
                                NULL, NULL, hInstance, NULL);
    if (!hwnd) return 1;
    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    /* IAT-patch demo target: we call MessageBoxW exactly once. If our
     * IAT was patched between image map and thread resume, the call
     * lands in our shellcode stub instead, returns IDOK silently, and
     * no dialog appears. */
    int mb = MessageBoxW(hwnd, L"This dialog only appears if MessageBoxW was NOT patched.",
                         L"gui_target", MB_OK);
    /* Stash the return into the marker for later comparison. */
    FILE *fm = NULL;
    if (slash) {
        wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - path), L"gui_target.marker");
        _wfopen_s(&fm, path, L"a");
        if (fm) {
            fprintf(fm, "MessageBoxW returned=%d  (IDOK=1)\n", mb);
            fclose(fm);
        }
    }

    /* Pump messages for 3 seconds then exit. The lifetime gives a human
     * watcher time to observe whether the wait cursor appears next to
     * the mouse on launch. */
    DWORD deadline = GetTickCount() + 3000;
    MSG msg;
    while (GetTickCount() < deadline) {
        while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) goto done;
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
        Sleep(10);
    }
done:
    DestroyWindow(hwnd);
    return 0;
}
