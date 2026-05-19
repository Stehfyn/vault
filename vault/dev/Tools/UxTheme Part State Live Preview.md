<!-- generated-from-dump2 -->
# UxTheme Part State Live Preview

Also Martin Mitáš (cf. mity/windrawlib #30, mity/mctrl #44, mity/old-new-win32api #49). Enumerates every (class, part, state) triple uxtheme.dll knows about for the currently active visual style and renders each one — so you can see exactly what `DrawThemeBackground(h, dc, BP_PUSHBUTTON, PBS_HOT, &r, nullptr)` actually looks like under Aero vs. Classic vs. a third-party .msstyles. Indispensable when you're hand-drawing themed controls and the docs only give you the constant names with no visual reference. The constants live in vsstyle.h / vssym32.h; this tool is essentially a live preview of those headers.

```c
// Theme-explorer's loop is, conceptually:
HTHEME h = OpenThemeData(hwnd, L"BUTTON");
for (int part = BP_PUSHBUTTON; part <= BP_COMMANDLINKGLYPH; ++part) {
    for (int state = PBS_NORMAL; state <= PBS_DEFAULTED_ANIMATING; ++state) {
        RECT r = layout_cell(part, state);
        DrawThemeBackground(h, hdc, part, state, &r, nullptr);
        // Label with the symbolic name so you can map pixels -> constant.
    }
}
CloseThemeData(h);
```

## References
- <https://github.com/mity/theme-explorer>
