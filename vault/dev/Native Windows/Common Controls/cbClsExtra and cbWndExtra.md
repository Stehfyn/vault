# cbClsExtra and cbWndExtra

`cbWndExtra` reserves bytes on every instance of a window class; `cbClsExtra` reserves bytes on the class object shared by all instances. Access is through `GetWindowLongPtr` / `SetWindowLongPtr` or `GetClassLongPtr` / `SetClassLongPtr`, and the offsets are byte offsets even though each accessor reads or writes a `LONG_PTR`. On x64 that means pointer-sized alignment is not optional.

Use `GWLP_USERDATA` for one per-window pointer. Use `cbWndExtra` when a custom control wants several fixed slots without a separate map, or when compatibility with dialog/control frameworks makes property storage unattractive. Use `cbClsExtra` sparingly for immutable or shared class state; per-instance control data belongs in window extra bytes or a heap object referenced by them.

## Source Shape

Reserve aligned storage during class registration, initialize it during creation, and clear/free it during destruction.

```cpp
WNDCLASSEXW wc = { sizeof(wc) };
wc.cbWndExtra = sizeof(ControlState *);
wc.lpfnWndProc = ControlProc;
RegisterClassExW(&wc);

case WM_NCCREATE: {
    auto *state = new ControlState;
    SetWindowLongPtrW(hwnd, 0, reinterpret_cast<LONG_PTR>(state));
    return TRUE;
}

case WM_NCDESTROY: {
    auto *state = reinterpret_cast<ControlState *>(GetWindowLongPtrW(hwnd, 0));
    delete state;
    SetWindowLongPtrW(hwnd, 0, 0);
    break;
}
```

Prefer `GWLP_USERDATA` for one pointer; use extra bytes when the class contract needs fixed slots.

## Source Code Reading

The Stack Overflow thread is useful because it contains both the correct mental model and a bad maintenance trap. The claims to extract are falsifiable:

- The bytes are allocated and initialized to zero, not "zero bytes by default." Microsoft documents `cbClsExtra` as bytes after the class structure and `cbWndExtra` as bytes after each window instance.
- The index passed to `GetWindowLongPtr` / `SetWindowLongPtr` is a zero-based byte offset into extra window memory, and the valid positive range ends at `cbWndExtra - sizeof(LONG_PTR)`.
- `GetWindowLong` reads a `LONG`; `GetWindowLongPtr` reads a `LONG_PTR`. On x64, mixing the two truncates pointer state.
- Storing many primitive fields directly in extra bytes works, but it creates a brittle ABI. Storing one pointer to a heap or arena state object usually creates a cleaner control contract.

The second answer's macro scheme is a good thing to dissect, not blindly copy:

```cpp
#define SLOT_EDIT_HWND      0
#define SLOT_GUTTER_HWND    (SLOT_EDIT_HWND + sizeof(HWND))
#define SLOT_HEIGHT         (SLOT_GUTTER_HWND + sizeof(HWND))
#define SLOT_FLAGS          (SLOT_HEIGHT + sizeof(LONG))
#define EXTRA_BYTES         (SLOT_FLAGS + sizeof(LONG))
```

The scheme is only safe if every offset is aligned for the accessor used at that offset. If `SLOT_FLAGS` is read with `GetWindowLong`, it needs `sizeof(LONG)` storage; if `SLOT_EDIT_HWND` is read with `GetWindowLongPtr`, it needs `sizeof(LONG_PTR)` storage. A mixed 32/64-bit codebase should not let these offsets be hand-maintained in scattered macros.

Use typed offsets instead:

```cpp
struct ExtraSlots {
    HWND edit;
    HWND gutter;
    LONG height;
    LONG flags;
};

static_assert(offsetof(ExtraSlots, edit) % alignof(LONG_PTR) == 0);
wc.cbWndExtra = sizeof(ExtraSlots);

SetWindowLongPtrW(hwnd, offsetof(ExtraSlots, edit), (LONG_PTR)edit);
SetWindowLongW(hwnd, offsetof(ExtraSlots, flags), flags);
```

For a real custom control, prefer this unless profiling says otherwise:

```cpp
wc.cbWndExtra = sizeof(ControlState*);

WM_NCCREATE:
    auto* s = new ControlState;
    SetWindowLongPtrW(hwnd, 0, (LONG_PTR)s);

WM_NCDESTROY:
    delete (ControlState*)GetWindowLongPtrW(hwnd, 0);
    SetWindowLongPtrW(hwnd, 0, 0);
```

The nuance in IInspectable's comment is ownership: `GWLP_USERDATA` belongs to the code that creates/owns the HWND. If you are authoring a reusable control class, reserve your own `cbWndExtra` pointer slot instead of assuming the caller will not use `GWLP_USERDATA` for its own association. That gives the control private storage while leaving the owner-visible `GWLP_USERDATA` convention alone.

`cbClsExtra` is the shared-state version of the same idea. Use it for class-wide immutable data or a shared vtable/config pointer, not per-instance state:

```cpp
struct ClassState {
    HBRUSH background;
    UINT registered_message;
};

wc.cbClsExtra = sizeof(ClassState*);
RegisterClassExW(&wc);

SetClassLongPtrW(hwnd, 0, (LONG_PTR)&g_class_state);
auto *klass = (ClassState *)GetClassLongPtrW(hwnd, 0);
```

That code should make you uneasy if the class can be registered by several modules, unloaded, or re-registered with different lifetimes. A class extra pointer is shared by every HWND of that class name in the registering module's class table; it is not a hidden per-window field.

## Discussion Claim To Verify

Claim: the forum comment that `GetWindowLongPtr` / `SetWindowLongPtr` can cross into kernel mode is the actionable part of the thread, not a side remark. It means extra bytes are a stable storage contract, but not a replacement for a local state pointer inside hot paint/layout code.

Why it matters for new code: a custom control that reads four extra-byte slots on every line draw has turned an ABI storage trick into a per-pixel tax. The better pattern is one extra-byte pointer loaded once at the top of the window procedure, then ordinary C/C++ field access while handling the message.

How to verify:

- Disassemble `user32!GetWindowLongPtrW` / `user32!SetWindowLongPtrW` on the target OS build and look for the user-mode wrapper, fast-path branches, and calls into `win32u`/USER kernel service stubs.
- In WinDbg, break on the exported wrappers while a tiny custom control paints; count how often your code asks USER for the same pointer during one `WM_PAINT`.
- Microbenchmark one cached pointer load against repeated `GetWindowLongPtrW(hwnd, 0)` calls outside the paint path. Treat the timing as machine-specific; the stable result is call-shape, not an absolute nanosecond number.

Minimal code/pseudocode:

```cpp
case WM_PAINT: {
    auto* s = (ControlState*)GetWindowLongPtrW(hwnd, 0); // one boundary read
    PaintRows(s->rows, s->colors, s->font);              // no more USER storage reads
    return 0;
}
```

```text
0:000> u user32!GetWindowLongPtrW
0:000> bp user32!GetWindowLongPtrW
0:000> g
```

Interpretation: if the breakpoint fires once per message, the extra-byte slot is being used as an object association. If it fires inside inner loops, the design is leaking storage mechanics into rendering. If the disassembly differs across Windows builds, keep the article claim at the level of "verify the wrapper path on your build" rather than hard-coding one private implementation.

## Probe and Disassembly Checks

Build a tiny class with `cbWndExtra = 2 * sizeof(LONG_PTR)` and log these cases:

```cpp
SetLastError(0);
auto old0 = SetWindowLongPtrW(hwnd, 0, 0x1111);
auto err0 = GetLastError();

SetLastError(0);
auto old1 = SetWindowLongPtrW(hwnd, sizeof(LONG_PTR), 0x2222);
auto err1 = GetLastError();

SetLastError(0);
auto bad = SetWindowLongPtrW(hwnd, 2 * sizeof(LONG_PTR), 0x3333);
auto errBad = GetLastError();
```

Expected result: offsets `0` and `sizeof(LONG_PTR)` succeed; the out-of-range offset fails with a nonzero `GetLastError`. Because a successful set can return zero when the previous value was zero, the probe must clear last error before each call.

To test the forum performance claim, do not debate it abstractly. Confirm the call path:

1. In WinDbg, break on `user32!GetWindowLongPtrW` and run `uf user32!GetWindowLongPtrW`.
2. Step until the call leaves the user-mode wrapper; on modern Windows expect a USER/NTUSER transition path rather than a plain field load.
3. Compare a tight loop of `GetWindowLongPtrW(hwnd, 0)` against one local `ControlState*` cached at the top of `WndProc`.
4. If the disassembly or timings differ by Windows version, record the version. The advice still stands: read extra bytes at message boundaries, not repeatedly inside inner paint/layout loops.

Spy++ can confirm the ownership model but not the internal storage. Create two windows of the same class, set different `cbWndExtra` values at offset 0, and verify their behavior diverges. Then set `cbClsExtra` through `SetClassLongPtr` and verify both instances observe the shared class value. That proves per-window versus per-class without requiring private symbols.

A no-symbol `dumpbin` check is enough to teach the same habit. On the current test machine, `user32.dll` exports `GetWindowLongPtrW` at an RVA visible in `/exports`, imports `NtUserSetWindowLong` / `NtUserSetWindowLongPtr` from `win32u.dll`, and the disassembly around the `GetWindowLongPtrW` export contains client-handle fast-path checks plus fallback calls through USER32's import table. The exact RVA is build-specific; the durable article detail is the verification recipe:

```powershell
$u = "$env:windir\System32\user32.dll"
dumpbin /exports $u | findstr /i "GetWindowLongPtr SetWindowLongPtr"
dumpbin /imports $u | findstr /i "NtUserSetWindowLong NtUserSetWindowLongPtr"
dumpbin /headers $u | findstr /i "image base"
# Add image base + exported RVA, then disassemble a small range around it.
dumpbin /disasm /range:0x18000D5E0,0x18000D780 $u
```

That is the broader contribution of the forum thread: it turns a storage-layout note into a habit for all Win32 notes. When someone claims an accessor is "just storage" or "expensive", inspect the export, import, and surrounding function body before repeating it.

## References
- <https://stackoverflow.com/questions/13330225/cbclsextra-and-cbwndextra> - clarifies per-class versus per-window storage and byte-offset access.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassexw> - `cbClsExtra` and `cbWndExtra` definitions and zero-initialization contract.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowlongptrw> - positive-offset range and pointer-sized retrieval contract.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowlongptrw> - positive-offset range, previous-value return, and `SetLastError(0)` failure check pattern.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclasslongptrw> - class extra-byte accessor contract.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setclasslongptrw> - class extra-byte setter contract.

## Connections
- `Atoms.md` sits at the same `RegisterClassEx` layer.
- `Custom Controls.md` is where `cbWndExtra` becomes useful for storing a control's state pointer.
- `WinSpy++ — Open-Source Spy++ Clone.md` is the observation route for class names, handles, and message flow while probing this.
- `../Headers/winnt.h.md` explains why `LONG`, `LONG_PTR`, pointer width, and ABI-sized storage are not interchangeable.
