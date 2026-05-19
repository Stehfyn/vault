# INI File API

The profile APIs are compatibility surfaces, not a modern configuration system. `GetPrivateProfileStringW` and `WritePrivateProfileStringW` still parse real INI files, but `GetProfileStringW` / `WriteProfileStringW` target the historical `win.ini` profile namespace and can be redirected through registry mapping under `HKLM\Software\Microsoft\Windows NT\CurrentVersion\IniFileMapping`. That redirection is the important trick: some "INI" reads are really registry reads, and installer searches for INI values can therefore disagree with what a text editor shows on disk.

## Robust Reads

The API references contribute the enumeration/truncation contract. A near-full buffer is a retry signal, and enumeration returns a double-NUL-terminated multi-string.

```cpp
std::wstring ReadIniValue(const wchar_t* section, const wchar_t* key, const wchar_t* path) {
    std::wstring buffer(256, L'\0');
    for (;;) {
        DWORD n = GetPrivateProfileStringW(section, key, L"", buffer.data(),
                                           static_cast<DWORD>(buffer.size()), path);
        if (n < buffer.size() - 2) {
            buffer.resize(n);
            return buffer;
        }
        buffer.resize(buffer.size() * 2);
    }
}
```

## Mapping and Flush

The IniFileMapping reference contributes the registry bridge. Writes may be cached through profile machinery; a NULL/NULL/NULL write flushes the mapping for that file.

```cpp
WritePrivateProfileStringW(L"Settings", L"Mode", L"Fast", path);
WritePrivateProfileStringW(nullptr, nullptr, nullptr, path);
```

## Connections

- `Registry Setup (RegInstallW)` and `MSI Search Conditions`: installers still query INI data for upgrade detection, often beside registry and file searches.
- `(REG) Windows Registry`: `IniFileMapping` is the bridge between the legacy API shape and real registry-backed storage.

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilestringw>
- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestringw>
- <https://learn.microsoft.com/en-us/windows/win32/sysinfo/registry-entries-for-inifilemapping>
