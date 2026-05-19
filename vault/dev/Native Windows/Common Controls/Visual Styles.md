# Visual Styles

Visual styles are the UxTheme/comctl32 v6 layer that makes classic controls draw with the active Windows theme. A manifest selects comctl32 v6, `InitCommonControlsEx` loads the requested control classes, and APIs such as `SetWindowTheme`, `OpenThemeData`, `DrawThemeBackground`, and `DrawThemeText` let custom or subclassed controls borrow the same theme parts and states as stock controls. Without that setup, many examples silently fall back to old comctl32 behavior.

The linked material separates three concerns that are often mixed together. Microsoft's common-control styles page is about control class/style availability. The Aero parts/states reference maps UxTheme class names and state IDs to drawable pieces. Samples like `win32ctrl.cpp` and the CodeProject article show how to apply those pieces to custom drawing. Undocumented functions such as `GetThemeTimingFunction` are a different category: useful for shell-like animation spelunking, not a stable theme dependency.

## Control Initialization

The common-control styles reference contributes the setup contract: comctl32 v6 must be selected by manifest, and `InitCommonControlsEx` must request the classes used by the process.

```cpp
INITCOMMONCONTROLSEX icc = { sizeof(icc) };
icc.dwICC = ICC_STANDARD_CLASSES | ICC_WIN95_CLASSES | ICC_BAR_CLASSES;
InitCommonControlsEx(&icc);
```

## Drawing Theme Parts

The Aero parts/states reference contributes the lookup table for class, part, and state IDs. The custom-control examples contribute the paint shape: open theme data for the class you are emulating, draw the proper part/state, then close the handle.

```cpp
HTHEME theme = OpenThemeData(hwnd, L"BUTTON");
RECT rc;
GetClientRect(hwnd, &rc);

int state = hot ? PBS_HOT : PBS_NORMAL;
DrawThemeBackground(theme, hdc, BP_PUSHBUTTON, state, &rc, nullptr);
DrawThemeText(theme, hdc, BP_PUSHBUTTON, state, text, -1,
              DT_CENTER | DT_VCENTER | DT_SINGLELINE, 0, &rc);

CloseThemeData(theme);
```

## References
- <https://learn.microsoft.com/en-us/windows/win32/controls/common-control-styles> - common-control style and initialization reference.
- <https://learn.microsoft.com/en-us/windows/win32/controls/aero-style-classes-parts-and-states> - UxTheme class/part/state map.
- <https://www.codeproject.com/Articles/620045/Custom-Controls-in-Win32-API-Visual-Styles> - custom control drawing with visual styles.
- <https://github.com/mykola2312/win32ctrl/blob/master/win32ctrl.cpp> - applying themes to stock/subclassed controls.

## Connections
- `Darkmode.md` covers undocumented dark-mode gaps beyond ordinary visual styles.
- `Custom Controls.md` covers when to use themed drawing inside a custom class.
