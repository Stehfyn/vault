# File API From App

Source: https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/nf-fileapifromapp-movefilefromappw

```cpp
BOOL ok = MoveFileFromAppW(L"C:\\data\\old.txt", L"C:\\data\\new.txt");
if (!ok) {
    DWORD err = GetLastError();
}
```
