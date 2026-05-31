# msdelta.h - MS Delta Compression API

`msdelta.h` exposes the native Delta Compression API: `CreateDelta*`, `ApplyDelta*`, `GetDeltaInfo*`, and `DeltaFree`. It is the SDK-facing header for the binary-delta format used by Windows servicing scenarios, where a compact transform between source and target files is more useful than a general archive.

The API is easy to misuse because buffers returned by the library have their own allocation contract and the file-type/flag choices affect patch compatibility. Pair this with `MSDelta.md` for call flow and with shell copy/archive entries when distinguishing content-addressed file transfer from compression.

Header-level anchors:

```cpp
typedef struct _DELTA_INPUT {
    LPVOID lpStart;
    SIZE_T uSize;
    BOOL Editable;
} DELTA_INPUT;

typedef struct _DELTA_OUTPUT {
    LPVOID lpStart;
    SIZE_T uSize;
} DELTA_OUTPUT;
```

Use these structures to explain ownership: caller-owned inputs go in, library-owned output comes back, and `DeltaFree` closes the loop. That memory contract is the main API boundary to preserve in examples.

## References
- `msdelta.h`
