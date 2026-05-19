# Personalization Registry Keys

Windows personalization settings are scattered across per-user Explorer, DWM, and theme keys, commonly including `HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent`, `HKCU\Software\Microsoft\Windows\DWM`, and `HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize`. Values such as `AppsUseLightTheme`, `SystemUsesLightTheme`, `EnableTransparency`, `ColorPrevalence`, and accent-color DWORDs are real but not a stable public contract in the same sense as `SHGetKnownFolderPath` or MSI tables.

The practical nuance is notification and ownership. Writing a DWORD may change stored preference without making the shell, DWM, or UWP settings UI re-read it immediately; many callers need `WM_SETTINGCHANGE`, user logoff, Explorer restart, or a supported Settings/UI path. These keys are useful for inventory, lab automation, and controlled images, but they are a poor application preference API.

## Connections
- `RegStr.h` is the headerized version of older shell/setup registry paths; personalization keys are the undocumented policy/preferences side.
- `AccessMask Decoder` matters when a tool fails under standard-user HKCU virtualization or writes HKLM policy keys instead.

## References
- <https://superuser.com/questions/1245923/registry-keys-to-change-personalization-settings>
