# MinHook - Minimal x86/x64 Hooking Library

MinHook is the standard small Windows inline-hooking library: plain C, x86/x64 support, trampoline generation, thread-safety considerations, and a deliberately narrow API. Its importance is that it does the unglamorous hard parts that most demos omit, especially instruction decoding and building a callable gateway back to the overwritten prologue.

Use it as the baseline for user-mode function interception discussions. If a note claims to "detour" a function but does not discuss instruction boundaries, patch atomicity, executable memory protections, and unwind/calling-convention effects, MinHook is the reference that shows what is missing.

## Source Shape

MinHook's public API keeps the dangerous part out of application code: create a trampoline, store the original function pointer, then enable the patch.

```cpp
using MessageBoxW_t = int (WINAPI *)(HWND, LPCWSTR, LPCWSTR, UINT);
MessageBoxW_t RealMessageBoxW = nullptr;

int WINAPI HookMessageBoxW(HWND hwnd, LPCWSTR text, LPCWSTR caption, UINT type) {
    return RealMessageBoxW(hwnd, L"hooked", caption, type);
}

MH_Initialize();
MH_CreateHook(&MessageBoxW, &HookMessageBoxW,
              reinterpret_cast<LPVOID *>(&RealMessageBoxW));
MH_EnableHook(&MessageBoxW);
```

## Connections
- Detour is a simpler demonstration of the same family.
- Capnhook in `Hook Examples` is another inline/IAT hooking reference.
- `UniversalHookX - Universal Graphical Hook.md` is where this primitive is commonly applied to render/present calls.

## References
- <https://github.com/TsudaKageyu/minhook>
