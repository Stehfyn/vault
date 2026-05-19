# Acrylic Popup Menus

Process-wide shim that retrofits acrylic onto every classic `HMENU` popup the host app creates — the menus `TrackPopupMenu` spawns are owner-drawn `#32768` windows that normally ignore DWM accent policy. The hack subclasses each popup as it appears (via a `WH_CBT` hook watching for `HCBT_CREATEWND` on the menu class), strips the default frame, and calls `SetWindowCompositionAttribute` with the acrylic accent. Pairs naturally with ALTaleX531/TranslucentFlyouts (#63), which does the same job for combobox/tooltip flyouts; together they cover most of the legacy USER32 surface that Microsoft never modernised.

## References
- <https://github.com/krlvm/AcrylicMenus>
