# INI File API

## WriteProfileStringW
https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilestringw  
Brief: Write legacy win.ini-backed settings for compatibility.
```cpp
#include <windows.h>
WriteProfileStringW(L"MyApp", L"Theme", L"Dark");
WriteProfileStringW(L"MyApp", L"Font", L"Consolas");
WriteProfileStringW(L"MyApp", L"Accent", L"Blue");
WriteProfileStringW(L"MyApp", L"Font", nullptr); // delete key
```

## GetPrivateProfileStringW (legacy INI read)
https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/aa394159(v=vs.85)  
Brief: Read a key from a specific INI path with a default fallback.
```cpp
#include <windows.h>
wchar_t value[128]{};
GetPrivateProfileStringW(L"MyApp", L"Theme", L"Light", value, ARRAYSIZE(value),
    L"C:\\MyApp\\settings.ini");
OutputDebugStringW(value);
```
