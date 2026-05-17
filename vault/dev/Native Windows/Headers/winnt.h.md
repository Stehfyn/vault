`winnt.h` is the foundational Windows NT header pulled in by `<windows.h>`. It defines primitive type aliases (`BYTE`, `WORD`, `DWORD`, `HANDLE`, etc.), NT status codes, access-rights constants (`GENERIC_READ`, `SYNCHRONIZE`, …), calling-convention macros (`WINAPI`, `CALLBACK`), and key structures (`LIST_ENTRY`, `UNICODE_STRING`, `RTL_CRITICAL_SECTION`). Almost every Win32 or NT-native program depends on it indirectly.

```c
// Key type aliases from winnt.h
typedef unsigned char   BYTE,  *PBYTE;
typedef unsigned short  WORD,  *PWORD;
typedef unsigned long   DWORD, *PDWORD;
typedef long            LONG,  *PLONG;
typedef void           *PVOID, *LPVOID;
typedef wchar_t        *LPWSTR;
typedef const wchar_t  *LPCWSTR;

// NT Status type and success macro
typedef LONG NTSTATUS;
#define NT_SUCCESS(s)   ((NTSTATUS)(s) >= 0)
#define STATUS_SUCCESS  ((NTSTATUS)0x00000000L)

// Doubly-linked list node (used pervasively in NT internals)
typedef struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY;

// Counted Unicode string (used throughout the NT native API)
typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

// Common access rights
#define GENERIC_READ    0x80000000L
#define GENERIC_WRITE   0x40000000L
#define SYNCHRONIZE     0x00100000L
```

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winnt/>
