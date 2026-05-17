# cbClsExtra and cbWndExtra

https://stackoverflow.com/questions/13330225/cbclsextra-and-cbwndextra

`cbWndExtra` reserves extra bytes per *window instance*; `cbClsExtra` reserves extra bytes per *window class* (shared by all windows of that class). You access these bytes with `GetWindowLongPtr` / `SetWindowLongPtr` (window instance) and `GetClassLongPtr` / `SetClassLongPtr` (class). Offsets are **byte offsets**, but each accessor reads/writes `sizeof(LONG_PTR)` bytes, so you must align offsets to `sizeof(LONG_PTR)` and ensure `offset <= cbWndExtra - sizeof(LONG_PTR)`.

```cpp
// Per-window extra bytes (cbWndExtra) — layout in multiples of LONG_PTR.
enum : int {
    WNDX_PTR_USER = 0,                          // LONG_PTR (pointer-sized)
    WNDX_FLAGS    = WNDX_PTR_USER + sizeof(LONG_PTR),
    WNDX_COUNT    = WNDX_FLAGS + sizeof(LONG_PTR)
};

// WNDCLASSEXW wc = { ... };
// wc.cbWndExtra = WNDX_COUNT;
// RegisterClassExW(&wc);

struct WindowState {
    int lineNumberWidth;
    bool resizable;
};

// Store a pointer in the extra bytes (recommended for rich state):
SetWindowLongPtrW(hwnd, WNDX_PTR_USER, (LONG_PTR)statePtr);

auto state = reinterpret_cast<WindowState*>(
    GetWindowLongPtrW(hwnd, WNDX_PTR_USER));

// Store small flags directly:
SetWindowLongPtrW(hwnd, WNDX_FLAGS, (LONG_PTR)0x1);
LONG_PTR flags = GetWindowLongPtrW(hwnd, WNDX_FLAGS);
```

```cpp
// Per-class extra bytes (cbClsExtra) — shared across all windows of the class.
enum : int {
    CLSX_PTR_SHARED = 0,
    CLSX_COUNT      = sizeof(LONG_PTR)
};

// WNDCLASSEXW wc = { ... };
// wc.cbClsExtra = CLSX_COUNT;
// RegisterClassExW(&wc);

struct ClassState {
    HBRUSH background;
    UINT   refCount;
};

// SetClassLongPtr operates on the class of a given HWND.
SetClassLongPtrW(hwnd, CLSX_PTR_SHARED, (LONG_PTR)sharedClassState);
auto shared = reinterpret_cast<ClassState*>(
    GetClassLongPtrW(hwnd, CLSX_PTR_SHARED));
```

### Practical rules (from the thread)
1. **Use LONG_PTR-sized slots only.** There is no `GetWindowByte` or `GetWindowShort`. If you want a `bool`, pack it into a LONG_PTR slot.
2. **Use `GetWindowLong` only for 32-bit LONG values.** Use `GetWindowLongPtr` for pointers and to be 64-bit safe.
3. **The offset is in bytes.** If `cbWndExtra = 12`, you can use offsets `0` and `8` on x64, but **not** `10`.
4. **Prefer GWLP_USERDATA for one pointer.** Use `cbWndExtra` when you need multiple slots or want to avoid heap allocations for small fixed data.

## References
- https://stackoverflow.com/questions/13330225/cbclsextra-and-cbwndextra
