# msdelta.h - MS Delta Compression API

`msdelta.h` exposes the native Delta Compression API: `CreateDelta*`, `ApplyDelta*`, `GetDeltaInfo*`, and `DeltaFree`. It is the SDK-facing header for the binary-delta format used by Windows servicing scenarios, where a compact transform between source and target files is more useful than a general archive.

The API is easy to misuse because buffers returned by the library have their own allocation contract and the file-type/flag choices affect patch compatibility. Pair this with `MSDelta.md` for call flow and with shell copy/archive entries when distinguishing content-addressed file transfer from compression.

## References
- `msdelta.h`
