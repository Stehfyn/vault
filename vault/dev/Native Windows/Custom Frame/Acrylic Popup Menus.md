# Acrylic Popup Menus

Process-wide shim that retrofits acrylic onto every classic `HMENU` popup the host app creates — the menus `TrackPopupMenu` spawns are owner-drawn `#32768` windows that normally ignore DWM accent policy. The hack subclasses each popup as it appears (via a `WH_CBT` hook watching for `HCBT_CREATEWND` on the menu class), strips the default frame, and calls `SetWindowCompositionAttribute` with the acrylic accent. Pairs naturally with ALTaleX531/TranslucentFlyouts (#63), which does the same job for combobox/tooltip flyouts; together they cover most of the legacy USER32 surface that Microsoft never modernised.

## Source Shape

The source-shaped route is CBT discovery plus per-menu-window treatment. `TrackPopupMenu` creates transient menu HWNDs, so the hook watches creation rather than subclassing a stable control.

```cpp
LRESULT CALLBACK CbtProc(int code, WPARAM wParam, LPARAM lParam) {
    if (code == HCBT_CREATEWND) {
        HWND hwnd = reinterpret_cast<HWND>(wParam);
        wchar_t cls[32];
        GetClassNameW(hwnd, cls, ARRAYSIZE(cls));
        if (wcscmp(cls, L"#32768") == 0) {
            SetWindowSubclass(hwnd, MenuSubclassProc, 1, 0);
            EnableAcrylicAccent(hwnd);
        }
    }
    return CallNextHookEx(nullptr, code, wParam, lParam);
}
```

The actual material step is the same private accent-policy branch used by other Win32 acrylic experiments; the hook only finds the otherwise-hidden menu HWND.

## Source Code Reading

`krlvm/AcrylicMenus` separates menu discovery from material application:

- `AcrylicMenus/amapi.cpp` exports `RegisterHook`, `UnregisterHook`, and `IsHookInstalled`.
- `RegisterHook` calls `SetWinEventHook(EVENT_OBJECT_CREATE, EVENT_OBJECT_SHOW, ..., WINEVENT_INCONTEXT)`.
- `MenuHandler.cpp` receives `EVENT_OBJECT_CREATE`, tests whether the HWND is a popup menu, subclasses it, and calls `MenuManager::SetCurrentMenu`.
- `MenuManager.cpp` chooses tint based on Windows version and dark mode.
- `AcrylicHelper.h` builds `ACCENT_POLICY` and calls `SetWindowCompositionAttribute`.

The popup-menu test is stronger than the placeholder CBT sketch:

```cpp
IsPopupMenu(hwnd) =
    GetClassLong(hwnd, GCW_ATOM) == 32768 ||
    (IsTopLevelWindow(hwnd) && className == L"#32768");
```

`EnableAcrylicAccent(hwnd)` is therefore:

```cpp
policy = {
    ACCENT_ENABLE_ACRYLICBLURBEHIND,
    ACCENT_WINDOWS11_LUMINOSITY | ACCENT_BORDER_ALL,
    tintColorWithAlpha,
    0
};
data = { WCA_ACCENT_POLICY, &policy, sizeof(policy) };
SetWindowCompositionAttribute(hwnd, &data);
```

Dark-mode tint is derived from the menu owner, not from a random global. `ThemeHelper::IsMenuUseDarkMode` uses `GetGUIThreadInfo` to find the owner and `DwmGetWindowAttribute(hwnd, 20, ...)` to read immersive dark mode. When auto tint is enabled on Windows 10, `MenuManager::RefreshCurrentMenuBackground` asks UxTheme for `ImmersiveStartDark::Menu` or `ImmersiveStart::Menu` fill color.

### Discussion Claim -> Probe

Claim: "classic context menus are hidden `#32768` windows." Source confirmation: AcrylicMenus checks both the window atom and class string. Probe it by installing only an out-of-context WinEvent hook and logging class atom/class name on `EVENT_OBJECT_CREATE` and `EVENT_OBJECT_SHOW`. Interpretation: if your target app uses owner-drawn or custom popup windows, the class test fails and SWCA never runs.

Claim: "Windows 11 needs a different acrylic tint recipe." Source confirmation: `ApplyAcrylicEffect` switches to fixed Windows 11 luminosity tints; Windows 10 uses configured/auto menu fill plus opacity. Probe it by logging `g_bIsWindows11`, tint ABGR, and `ACCENT_WINDOWS11_LUMINOSITY`. Interpretation: the same `ACCENT_ENABLE_ACRYLICBLURBEHIND` state can look different because the flags and tint payload differ.

## References
- <https://github.com/krlvm/AcrylicMenus>

## Connections
- `../Common Controls/Modify Context Menu.md` obtains the same popup menu's `HMENU` for command mutation instead of visual treatment.
- `../Common Controls/Custom Menubar.md` is the top-level menu-bar drawing route, not the popup route.
- `../Hooks/SetWindowsHookEx.md` explains the `WH_CBT` hook contract used to catch menu creation.
- `Translucent Win32 Flyouts.md` broadens the same legacy-flyout modernization problem beyond menus.
