# Including ntdef.h - User-Mode NT Types

`ntdef.h` brings NT-flavored base types into code that normally lives behind the Win32 facade: `UNICODE_STRING`, `OBJECT_ATTRIBUTES`, `CLIENT_ID`, `NTSTATUS`, alignment macros, and related definitions. The main reason to include it directly is not convenience; it is to make native API declarations type-correct when the Windows SDK's `winternl.h` is incomplete.

The risk is header ordering. `windows.h`, WDK headers, and phnt can define overlapping names or status macros, so user-mode NTAPI projects should decide one header strategy early instead of mixing snippets. phnt is usually the better path for broad native work; direct `ntdef.h` inclusion is for narrow cases.

## Connections
- `Including ntstatus.h` covers the common status-code macro collision.
- `phnt` provides a more complete native API surface built around these types.

## References
- Windows SDK/WDK `ntdef.h`
