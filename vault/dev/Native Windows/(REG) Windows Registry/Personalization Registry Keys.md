# Personalization Registry Keys

Windows personalization settings are scattered across per-user Explorer, DWM, and theme keys, commonly including `HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent`, `HKCU\Software\Microsoft\Windows\DWM`, and `HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize`. Values such as `AppsUseLightTheme`, `SystemUsesLightTheme`, `EnableTransparency`, `ColorPrevalence`, and accent-color DWORDs are real but not a stable public contract in the same sense as `SHGetKnownFolderPath` or MSI tables.

The practical nuance is notification and ownership. Writing a DWORD may change stored preference without making the shell, DWM, or UWP settings UI re-read it immediately; many callers need `WM_SETTINGCHANGE`, user logoff, Explorer restart, or a supported Settings/UI path. These keys are useful for inventory, lab automation, and controlled images, but they are a poor application preference API.

## Connections
- `RegStr.h` is the headerized version of older shell/setup registry paths; personalization keys are the undocumented policy/preferences side.
- `AccessMask Decoder` matters when a tool fails under standard-user HKCU virtualization or writes HKLM policy keys instead.

## Discussion Claim To Verify

Claim from the SuperUser registry discussion: changing personalization DWORDs is enough to change the active Windows light/dark/transparency state.

Why it matters: if this is true, a configuration tool can be a pure registry writer. If it is false, code must separate stored preference mutation from shell/DWM/UI refresh mechanics.

Verification route:

```powershell
reg query HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize
reg query HKCU\Software\Microsoft\Windows\DWM

reg add HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize /v AppsUseLightTheme /t REG_DWORD /d 0 /f
reg add HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 0 /f

# ProcMon filters:
#   Path contains \Themes\Personalize
#   Path contains \Explorer\Accent
#   Path contains \DWM
#   Process Name is explorer.exe OR SystemSettings.exe OR dwm.exe
```

Minimal refresh probe:

```cpp
DWORD_PTR ignored = 0;
SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0,
                    (LPARAM)L"ImmersiveColorSet",
                    SMTO_ABORTIFHUNG, 2000, &ignored);
```

Interpretation:
- Registry write succeeds but no UI changes: the key is stored state, not a live notification contract.
- UI changes only after `WM_SETTINGCHANGE`, Explorer restart, sign out, or Settings interaction: document the refresh dependency instead of calling the registry key an API.
- ProcMon shows no consumer reread after the write: the linked discussion supports "these values exist," not "the shell will immediately react."

## References
- <https://superuser.com/questions/1245923/registry-keys-to-change-personalization-settings>
