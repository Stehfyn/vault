# Window Sizing

`WM_GETMINMAXINFO` is the main hook for top-level tracking constraints. Set `ptMinTrackSize` and `ptMaxTrackSize` to control resize limits, and use `MonitorFromWindow` plus `GetMonitorInfo` when overriding maximized size or position so the work area respects taskbars and the monitor containing the window. Hard-coding primary-screen metrics is the classic multi-monitor bug.

Sizing is also a DPI problem. Minimum widths, splitter thicknesses, toolbar heights, and custom frame borders should be derived from the window's current DPI or font metrics, then recalculated on `WM_DPICHANGED`. A borderless window in particular must pair `WM_GETMINMAXINFO` with non-client hit testing or it will maximize and resize unlike a normal overlapped window.

## Forum Claim to Test

The Stack Overflow origin is a useful warning: sending `WM_GETMINMAXINFO` yourself to ask "what are this window's natural min/max values?" is the wrong model. The message is normally sent by the system while a size or position change is being negotiated, and Windows initializes the `MINMAXINFO` payload before your procedure sees it. If you allocate a local `MINMAXINFO` and call `SendMessage(hwnd, WM_GETMINMAXINFO, 0, &mmi)` without initializing the structure yourself, a default handler has no reason to synthesize meaningful app-specific constraints.

The falsifiable probe is tiny:

```cpp
case WM_GETMINMAXINFO: {
    auto* mmi = (MINMAXINFO*)lParam;
    OutputDebugStringW(L"WM_GETMINMAXINFO\n");
    mmi->ptMinTrackSize.x = dpi_scale(640);
    mmi->ptMinTrackSize.y = dpi_scale(360);
    return 0;
}
```

Run it under Spy++ or a debugger and resize the window. You should see the message during interactive tracking. Then call `SendMessage` manually with an uninitialized `MINMAXINFO` and observe that you are testing your own initialization, not querying a persistent system database of constraints.

For maximize behavior, test on a secondary monitor with a taskbar:

```cpp
auto mon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
MONITORINFO mi = { sizeof(mi) };
GetMonitorInfoW(mon, &mi);
mmi->ptMaxPosition = { mi.rcWork.left - mi.rcMonitor.left,
                       mi.rcWork.top  - mi.rcMonitor.top };
mmi->ptMaxSize = { mi.rcWork.right - mi.rcWork.left,
                   mi.rcWork.bottom - mi.rcWork.top };
```

If maximizing covers the taskbar or jumps to primary-monitor dimensions, your `WM_GETMINMAXINFO` handler is using the wrong rectangle source.

## Verification Route

Claim: the Stack Overflow question fails because `WM_GETMINMAXINFO` is not a query API. The system fills `MINMAXINFO` while negotiating a move/size operation; a manual `SendMessage` with uninitialized storage only proves what your caller initialized.

Why it matters for new code: sizing code should own its constraints. Record minimum client size after dialog initialization, recompute DPI-derived track sizes on `WM_DPICHANGED`, and respond when USER asks. Do not build layout systems that "ask Windows" for an app-specific minimum the app never supplied.

How to verify:

- Put a breakpoint or `OutputDebugStringW` in the handler and resize interactively; Spy++ should show `WM_GETMINMAXINFO` in the sizing stream.
- Fill a local `MINMAXINFO` with sentinel bytes, send `WM_GETMINMAXINFO` manually, and compare before/after. If your handler is absent, the sentinel data is not converted into meaningful dialog constraints.
- Move the window to a secondary monitor with a different work area and maximize. Wrong code uses primary-screen metrics; correct code uses the nearest monitor's `rcWork`.

Minimal code/pseudocode:

```cpp
MINMAXINFO mmi;
memset(&mmi, 0xCC, sizeof(mmi));
SendMessageW(hwnd, WM_GETMINMAXINFO, 0, (LPARAM)&mmi);
Dump(mmi.ptMinTrackSize, mmi.ptMaxTrackSize); // this is not a durable query
```

```cpp
case WM_GETMINMAXINFO:
    auto* m = (MINMAXINFO*)lParam;
    m->ptMinTrackSize = ScaleDpi({ 640, 360 }, GetDpiForWindow(hwnd));
    return 0;
```

Interpretation: the useful code path is the handler, not the manual message. If a manual send appears to work, it is because your handler wrote values into the caller's struct; it is still your policy, not hidden system state.

## References
- <https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-getminmaxinfo> - tracking-size message contract.
- <https://stackoverflow.com/questions/4134946/wm-getminmaxinfo-does-not-seem-to-work-how-to-get-a-windows-minimum-and-maximu> - monitor work-area correction for maximize bounds.

## Connections
- `Borderless Window.md` depends on this for correct custom chrome.
- `DPI Awareness/Per-Monitor V2 DPI Reference.md` covers DPI-triggered recomputation.
