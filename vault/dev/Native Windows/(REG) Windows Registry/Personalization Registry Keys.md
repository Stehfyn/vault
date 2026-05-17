# Personalization Registry Keys

Common HKCU paths used for Windows personalization settings (from SuperUser):
- `HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent` — `AccentColorMenu` (DWORD)
- `HKCU\Software\Microsoft\Windows\DWM` — `AccentColor`, `AccentColorInactive`, `ColorPrevalence` (DWORD)
- `HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize` — `EnableTransparency`, `ColorPrevalence`, `AppsUseLightTheme` (DWORD)

Sample (placeholder key/value) using `RegOpenKeyEx` / `RegSetValueEx`:
```c
HKEY hKey = NULL;
const wchar_t* subKey = L"<PersonalizationKeyPath>"; // e.g., ...\\Themes\\Personalize
DWORD value = 1; // enable

if (RegOpenKeyExW(HKEY_CURRENT_USER, subKey, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
    RegSetValueExW(hKey, L"<ValueName>", 0, REG_DWORD,
                   (const BYTE*)&value, sizeof(value));
    RegCloseKey(hKey);
}
```

Reference: https://superuser.com/questions/1245923/registry-keys-to-change-personalization-settings
