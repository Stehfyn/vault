# Theme Stream

Load theme resources as a data file and use `GetThemeStream` to extract the PNG stream.

## Snippet
```c
HTHEME hTheme = OpenThemeData(hwnd, L"DWMWINDOW");
HMODULE hLib = LoadLibraryExW(themePath, nullptr, LOAD_LIBRARY_AS_DATAFILE);
void* buffer = nullptr;
DWORD size = 0;
GetThemeStream(hTheme, 0, 0, TMT_DISKSTREAM, &buffer, &size, hLib);
```

## References
- https://stackoverflow.com/questions/34222021/getthemestream-usage
