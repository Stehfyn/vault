# Dialog Units

Dialog units are font-relative layout units used by Win32 dialog templates: horizontal units are based on one quarter of the dialog font's average character width, and vertical units on one eighth of its height. `MapDialogRect` converts a DLU rectangle to pixels using the dialog's current font, which is why changing `DS_SETFONT` changes the apparent geometry of the whole dialog.

DLUs are not obsolete just because DPI APIs exist. Legacy dialogs, property sheets, and resource templates still express sizes this way, and DPI-aware code often has to preserve that behavior while mixing in pixel-based custom controls. Convert at the boundary, after the dialog font is set, and do not cache DLU-to-pixel results across font or DPI changes.

## Source Shape

Use the dialog as the conversion context after its font is final. `MapDialogRect` is not a global DPI conversion helper.

```cpp
RECT dlu = { 7, 7, 180, 14 };
MapDialogRect(hwnd_dialog, &dlu);

SetWindowPos(child, nullptr,
             dlu.left, dlu.top,
             dlu.right - dlu.left,
             dlu.bottom - dlu.top,
             SWP_NOZORDER | SWP_NOACTIVATE);
```

On `WM_DPICHANGED` or font changes, recompute from the original DLU values instead of scaling already-scaled pixels.

## Source Code Reading

`andlabs/windlgunits` is a measurement program, not just a conversion snippet. `main.c` creates a dialog, stores a `struct mainwin*` in `DWLP_USER`, lets the user choose a font, and calls `runCalculations` whenever X/Y DLU inputs or the selected font changes. The results are displayed through a virtual-ish ListView filled on `LVN_GETDISPINFO`.

The core comparison is in `dlgunits.c`. It computes five modes:

- average width from `GetTextExtentPoint32W("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")`
- average width from `TEXTMETRICW.tmAveCharWidth`
- the same two formulas adjusted against system-font base units
- the actual `MapDialogRect(hwnd, &rect)` result

The direct formula branch is:

```cpp
xs[i] = MulDiv(xDlu, xbase, 4);
ys[i] = MulDiv(yDlu, ybase, 8);
```

The `MapDialogRect` branch creates `RECT{0, 0, x, y}`, calls `MapDialogRect`, asserts the origin stays at zero, then records `right` and `bottom`. `runCalculations` gets a DC, samples system base units before selecting the chosen font, selects the chosen font, samples font base units, runs every mode, restores the old font, and releases the DC.

The falsifiable claim: `MapDialogRect` is not identical to every hand formula people repeat in forum answers. Run the sample with different dialog fonts and compare the mode rows. If your custom layout must match dialog templates, treat `MapDialogRect` as the authority for a real dialog HWND; use formulas only for diagnostics or when no dialog context exists.

## Verification Route

Claim: dialog units are font-context units, not DPI units wearing an old name. The `windlgunits` source is valuable because it compares `MapDialogRect` against several hand formulas and shows where approximation enters.

Why it matters for new code: a DPI-aware dialog should preserve original DLU intent, then convert from the current dialog font/context after DPI or font changes. Scaling already-converted pixels compounds rounding and drifts away from resource-template layout.

How to verify:

- Run the `windlgunits` sample, choose fonts with visibly different average widths, and compare `MapDialogRect()` with `GetTextExtentPoint32()` and `tmAveCharWidth` rows.
- On `WM_DPICHANGED`, rebuild the dialog font, then convert the original DLU rectangle again. Do not multiply the previous pixel rectangle.
- Use a ListView/result table like the sample so the differences are visible rather than hidden in one layout pass.

Minimal code/pseudocode:

```text
struct ControlSpec { RECT dlu; int id; };

RelayoutDialog(hwnd, specs):
    for spec in specs:
        RECT px = spec.dlu
        MapDialogRect(hwnd, &px)
        MoveWindow(GetDlgItem(hwnd, spec.id),
                   px.left, px.top, px.right - px.left, px.bottom - px.top, TRUE)
```

Interpretation: if two formulas disagree with `MapDialogRect`, the article should teach the disagreement, not pick a folklore equation. If your relayout changes when only the font changes, the claim is verified: DLU conversion belongs after font/context selection.

## References
- <https://github.com/andlabs/windlgunits/blob/master/main.c> - compact experiment showing how dialog-unit conversion behaves.

## Connections
- `DPI Awareness/Per-Monitor V2 DPI Reference.md` explains the modern DPI notification layer.
- `ListView.md`, `Toolbar and Status Bar.md`, and `Splitter Control.md` are the common places where DLU-derived dialog layout meets pixel-sized child controls.
- `../DPI Awareness/Per-Window DPI Awareness.md` covers creating legacy dialog subtrees under a scoped DPI context.
