# TabCtrl - Owner-Drawn Win32 Tab Control

This repository exists because `SysTabControl32` only gives partial owner draw. `TCS_OWNERDRAWFIXED` can hand you label painting, but the themed frame, metrics, close-button behavior, overflow behavior, and modern IDE/browser visual states remain awkward or unreachable. A from-scratch tab HWND lets the control own hit testing, hover/pressed state, close glyphs, drag/reorder policy, and notification semantics.

Use it beside mCtrl, WTL Examples, and Win32xx. All of those entries revolve around the same decision: keep the HWND/message model but replace stock common controls when COMCTL32's theming and behavior are too fixed.

## References
- <https://github.com/baradzenka/TabCtrl> - small custom Win32 tab-control implementation focused on owner-painted behavior.
