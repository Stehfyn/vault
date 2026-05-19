# Theme Stream

`GetThemeStream` is the UxTheme escape hatch for binary theme resources, especially PNG payloads embedded in `.msstyles`. For DWM work it matters when you are trying to reproduce system chrome rather than approximate it: caption glyphs, frame art, and high-DPI assets live in theme resources, not in `dwmapi.h`.

The gotcha is handle ownership and class selection. `OpenThemeData(hwnd, L"DWMWINDOW")` chooses the themed part namespace; `LoadLibraryEx(..., LOAD_LIBRARY_AS_DATAFILE)` lets UxTheme read resources from a specific theme file. The API returns a pointer/size into theme-managed memory, so treat it as borrowed data and copy it before caching across theme changes.

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
- Related: `Title Bar Customization.md`, `DWM Colorization.md`
