Python/C utility that maps Win32 error codes to their symbolic names and human-readable descriptions. Useful for decoding cryptic DWORD error values returned by Win32 APIs. The `FormatMessageW` function is the standard Win32 approach for converting a raw error code into a readable string.

```cpp
DWORD err = GetLastError();
LPWSTR buf = nullptr;
FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
               nullptr, err, 0, (LPWSTR)&buf, 0, nullptr);
// buf now contains the error string, e.g. "Access is denied."
wprintf(L"Error %lu: %s\n", err, buf);
LocalFree(buf);
```

## References

- <https://github.com/p0dalirius/win32errorcodes>
