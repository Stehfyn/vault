# WindowCustomizer - Cross-Process Window Mutator

WindowCustomizer is essentially Spy++ with mutation: inspect another process's top-level windows and change selected properties such as title text or styles through USER32-mediated calls. The interesting nuance is that some window-manager state is intentionally cross-process addressable through HWNDs; not every customization requires injection.

Use it beside `WinHier`, `WindowDetective`, and `Windows Explorer Integration`. It is valuable for debugging window ownership, styles, z-order, and operator labeling workflows, while also reminding you that HWNDs are capabilities of a sort and should not be treated as private object references.

USER32 boundary shape:

```cpp
EnumWindows(callback, context);
GetWindowThreadProcessId(hwnd, &owner_pid);
LONG_PTR style = GetWindowLongPtrW(hwnd, GWL_STYLE);
SetWindowTextW(hwnd, L"diagnostic label");
SetWindowPos(hwnd, nullptr, x, y, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
```

This connects cleanly to Spy++-style inspection, shell integration, and `Ghost Window Prevention`: HWND-mediated mutation is cross-process but still brokered by USER32/window-manager rules. It should not be confused with remote memory writes or injected window procedures.

## Discussion Claim To Verify

Claim implied by cross-process window customizers: if you have an `HWND`, you can mutate another process's UI state.

Why it matters: some state is intentionally reachable through USER32 messages and window-manager APIs; other state is owned by the target process, control implementation, integrity level, or framework. The useful distinction is what changes synchronously, what is ignored, and what is later overwritten by the owner.

Verification route:

```cpp
EnumWindows(EnumProc, 0);
GetWindowThreadProcessId(hwnd, &pid);

wchar_t before[256] = {};
GetWindowTextW(hwnd, before, ARRAYSIZE(before));

BOOL renamed = SetWindowTextW(hwnd, L"probe title");
LONG_PTR style = GetWindowLongPtrW(hwnd, GWL_STYLE);
SetWindowPos(hwnd, nullptr, 0, 0, 640, 480,
             SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
```

Interpretation:
- Title/style changes and stays changed: USER32-mediated mutation is supported enough for that window class.
- Change succeeds but target immediately restores it: the owner framework has its own state model.
- Call fails or returns partial data across integrity/UIAccess boundaries: `HWND` is not a universal write capability.

## References
- <https://github.com/mikeage/WindowCustomizer>
