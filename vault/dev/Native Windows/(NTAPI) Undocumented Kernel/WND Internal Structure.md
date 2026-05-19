# WND Internal Structure

The internal `WND`/`WF` material is valuable as a reverse-engineering map of USER32 and win32k window state: styles, extended styles, state flags, server-side procedure markers, destruction state, fullscreen hints, shell-hook registration, and control `fnid` classifications. It explains why public calls such as `GetWindowLongPtr`, `GetWindowRect`, class queries, and message inspection expose only a curated projection of a larger object.

Treat the offsets and flag values as version-sensitive diagnostics, not a programming interface. Geoff Chappell's notes, ReactOS headers, reverse-engineering answers, and tinysec's `fnID` list are useful because they triangulate the same object family from different evidence. Writing through these structures or assuming a fixed layout across builds is the wrong lesson.

## Supported Projection

The reverse-engineering references contribute names for internal state, but ordinary tools should stay on supported projections: handles, styles, class names, thread/process IDs, and messages.

```cpp
DWORD pid = 0;
DWORD tid = GetWindowThreadProcessId(hwnd, &pid);

LONG_PTR style = GetWindowLongPtrW(hwnd, GWL_STYLE);
LONG_PTR ex_style = GetWindowLongPtrW(hwnd, GWL_EXSTYLE);

wchar_t class_name[256];
GetClassNameW(hwnd, class_name, ARRAYSIZE(class_name));
```

## Diagnostic Record

Geoff Chappell, ReactOS, and the `fnID` list are best used to label observations from supported APIs and debugger output. Keep version-specific offsets out of normal code paths.

```cpp
struct WindowDiagnosticRecord {
    HWND hwnd;
    DWORD owner_thread;
    DWORD owner_process;
    LONG_PTR style;
    LONG_PTR ex_style;
    std::wstring class_name;
    std::wstring title;
};
```

## Connections

- `Win32k Kernel Structures` is the NT5 source-side counterpart.
- WinSpy++ observes window hierarchy and messages from the supported side, using handles and hooks rather than raw structure mutation.

## References

- <https://reverseengineering.stackexchange.com/a/21135>
- <https://www.geoffchappell.com/studies/windows/win32/user32/structs/wnd/index.htm>
- <https://doxygen.reactos.org/dd/d79/include_2ntuser_8h_source.html#l00572>
- <https://github.com/tinysec/public/blob/master/win32k/fnID.md>
