# Shell Utilities (shlwapi)

`shlwapi.dll` is the grab-bag layer that accumulated path, URL, registry, association, formatting, and lifetime helpers around Internet Explorer and the shell. New code should not blindly import it for string work, but some functions still encode shell-specific behavior better than a homegrown replacement.

## Host lifetime pinning
Link: https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-setprocessreference

Contribution: `SetProcessReference` is a COM-server lifetime hook. A shell extension or hosted component can hand the shell an `IUnknown` whose reference count keeps the process alive while asynchronous shell work is outstanding. It is not a generic keepalive for normal executables.

```cpp
struct ProcessRef : IUnknown {
    std::atomic<ULONG> refs{1};
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override {
        if (riid == IID_IUnknown) { *ppv = static_cast<IUnknown*>(this); AddRef(); return S_OK; }
        *ppv = nullptr; return E_NOINTERFACE;
    }
    ULONG STDMETHODCALLTYPE AddRef() override { return ++refs; }
    ULONG STDMETHODCALLTYPE Release() override {
        ULONG r = --refs;
        if (!r) delete this;
        return r;
    }
};

SetProcessReference(new ProcessRef());
```

## Tiny shell hash
Link: https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-hashdata

Contribution: `HashData` is useful only as a legacy shell-compatible checksum over a small byte buffer. It is not cryptographic and not a modern hash-table primitive; keep it when matching Explorer/IE-era persisted values.

```cpp
BYTE digest[16] = {};
const BYTE bytes[] = { 0x10, 0x20, 0x30 };
HashData(bytes, sizeof(bytes), digest, sizeof(digest));
```

## Human-readable byte formatting
Link: https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-strformatbytesize64a

Contribution: `StrFormatByteSize64*` preserves Explorer-style byte-size wording. Use it when matching shell UI; avoid it for protocols/logs where exact units and localization must be controlled.

```cpp
wchar_t text[64] = {};
StrFormatByteSizeW(1536000, text, ARRAYSIZE(text)); // shell-style localized text
```

Connections: `Shlwapi Utilities.md` in `(NT5) Source` covers the old implementation lineage; `Shell File Icons.md`, `Shell Execute.md`, and `Legacy Shell References.md` are the neighboring shell helper surfaces. Prefer `PathCch*`/`Url*` replacements when the problem is pure path normalization rather than shell compatibility.
