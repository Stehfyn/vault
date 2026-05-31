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

Mapping prefixes are part of the API contract: `USR:` targets `HKCU`, `SYS:` targets `HKLM\Software`, `!` writes through to both registry and file, and `@` prevents fallback to the disk file. That is why installer searches and manual text-file inspection can disagree.

## Experiment Harness

Use one real INI file and one mapped INI name. Read through `GetPrivateProfileStringW`, then compare disk contents, registry contents, and MSI `IniLocator` results.

```powershell
Set-Content C:\Temp\probe.ini "[Settings]`nMode=Disk"
.\ini_probe.exe C:\Temp\probe.ini Settings Mode
reg query "HKLM\Software\Microsoft\Windows NT\CurrentVersion\IniFileMapping"
```

Signal: disk-backed reads match the file; mapped reads may match registry values instead. Failure interpretation: if an installer detects a value that a text editor cannot find, `IniFileMapping` or Windows-directory `IniLocator` behavior is the first suspect.

## Connections

- `Registry Setup (RegInstallW)` and `MSI Search Conditions`: installers still query INI data for upgrade detection, often beside registry and file searches.
- `(REG) Windows Registry`: `IniFileMapping` is the bridge between the legacy API shape and real registry-backed storage.
- `RegStr.h` is the neighboring legacy-configuration vocabulary for shell/setup code that predates modern app settings.

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilestringw>
- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestringw>
- <https://learn.microsoft.com/en-us/windows/win32/sysinfo/registry-entries-for-inifilemapping>
