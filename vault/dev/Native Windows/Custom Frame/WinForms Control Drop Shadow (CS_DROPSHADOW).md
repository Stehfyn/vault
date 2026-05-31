# WinForms Control Drop Shadow (CS_DROPSHADOW)

Stack Overflow Q&A on giving WinForms controls a real drop shadow. The trick is to OR `CS_DROPSHADOW` (0x00020000) into the window class style by overriding `CreateParams.ClassStyle`. This is the same class style that gives Win32 tooltips/menus their drop shadow at the OS level (no GDI/manual blur work, DWM handles it). Caveat: only applies to top-level windows / popups; for child controls inside a form, the class-style approach won't do anything — you need a layered popup or owner-drawn shadow.

## Source Code Reading

The Stack Overflow answer is a falsifiable claim about a window class style, not a painting recipe. The proposed WinForms shape is:

```csharp
protected override CreateParams CreateParams {
    get {
        var cp = base.CreateParams;
        cp.ClassStyle |= 0x00020000; // CS_DROPSHADOW
        return cp;
    }
}
```

The interesting detail is when this code runs. `CreateParams` contributes to the class/window creation path; it is not a runtime repaint flag. If you add it after handle creation, you need to recreate the handle or create a separate popup window class that already has the style.

### Discussion Claim -> Probe

Claim from the discussion: `CS_DROPSHADOW` is a class style, and similar styles live in `WinUser.h`. Probe it with a minimal WinForms `Form`, Spy++/WinDbg `!hwnd`, or `GetClassLongPtr(hwnd, GCL_STYLE)` before and after handle creation. Interpretation: if `GCL_STYLE & CS_DROPSHADOW` is set on a top-level popup/form, USER/DWM may draw the shadow; if the HWND is a child control, the class style alone is not enough.

Claim from the alternate answer: child-control shadows are usually drawn on the parent surface. Probe it by drawing a parent `Paint` shadow behind child panels, then clipping/overlapping sibling controls. Interpretation: GDI parent painting gives deterministic pixels but no DWM shadow semantics, no real elevation, and no separate occlusion surface.

## References
- <https://stackoverflow.com/questions/2463519/drop-shadow-in-winforms-controls>
