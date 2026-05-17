# Shell Utilities (shlwapi)

Per-link references for shlwapi helpers.

## SetProcessReference
Link: https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-setprocessreference
Brief: Extend host lifetime while a component is active.
```cpp
IUnknown* host = GetMyHostObject();
if (host) {
  SetProcessReference(host);
  host->Release();
}
```

## HashData
Link: https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-hashdata
Brief: Hash a small byte buffer (<= 256 bytes).
```cpp
BYTE data[] = { 1, 2, 3, 4 };
BYTE hash[20] = {};
DWORD cbHash = sizeof(hash);
HRESULT hr = HashData(data, sizeof(data), hash, cbHash);
if (SUCCEEDED(hr)) { /* use hash */ }
```

## StrFormatByteSize64A
Link: https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-strformatbytesize64a
Brief: Format human-readable sizes (base-10 on Win10+).
```cpp
char buf[32] = {};
LONGLONG bytes = 123456789LL;
StrFormatByteSize64A(bytes, buf, ARRAYSIZE(buf));
if (buf[0] != '\0') { printf("%s\n", buf); }
```

