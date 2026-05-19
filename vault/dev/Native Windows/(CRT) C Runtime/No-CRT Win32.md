# No-CRT Win32

A no-CRT Win32 program is not just a small program; it is a program that accepts responsibility for the work normally hidden behind `mainCRTStartup`: stack cookie setup or deliberate removal, TLS callbacks, global C++ constructors, command-line parsing, environment access, floating-point helpers, memory intrinsics, `atexit`, and process termination. The minimal pattern is `/NODEFAULTLIB` plus an explicit `/ENTRY`, then call Win32 directly and end with `ExitProcess`. Anything that quietly emits calls to `memcpy`, `_fltused`, `__chkstk`, `_security_check_cookie`, exception helpers, or C++ RTTI can pull the runtime back in.

The linked templates matter because they show two sane variants: a tiny didactic CRT replacement (`Simple-CRT`) and a practical Win32 template that supplies only the missing glue it uses. Old demoscene guides add useful linker tricks such as section merging and import minimization, but those optimizations are secondary; the hard boundary is owning startup and never crossing allocator or exception semantics with normal CRT-linked modules.

## Minimal Startup

The no-CRT templates contribute the real entry contract: the process starts at your symbol, no `argv` exists until you parse it, and termination must go through Win32 or `NtTerminateProcess`.

```c
#pragma comment(linker, "/entry:WinMainCRTStartup")
#pragma comment(linker, "/nodefaultlib")

void WinMainCRTStartup(void) {
    HINSTANCE instance = GetModuleHandleW(NULL);
    int result = WinMain(instance, NULL, GetCommandLineW(), SW_SHOWDEFAULT);
    ExitProcess((UINT)result);
}
```

## Missing Runtime Helpers

`Simple-CRT` is valuable because it makes the hidden runtime surface visible. If the compiler emits helpers, either avoid the feature or provide the exact helper with the expected ABI.

```c
void* __cdecl memset(void* dst, int value, size_t size) {
    unsigned char* p = (unsigned char*)dst;
    while (size--) {
        *p++ = (unsigned char)value;
    }
    return dst;
}

int _fltused;
```

## Linker Size Tricks

The old small-executable guides contribute linker mechanics, but they are last-mile optimizations. Use them only after the startup boundary is stable.

```text
/OPT:REF /OPT:ICF /MERGE:.rdata=.text /ALIGN:16
```

## Connections
- `Win32 No-CRT C Template` is the concrete C version of this pattern.
- `CRT Startup Hooks` explains what you lose when CRT startup is skipped.
- `Binary Size Reduction` covers less invasive linker optimization before removing the CRT entirely.

## References
- <https://github.com/chizhaolin/Simple-CRT>
- <https://github.com/alexandru-cazacu/win32-template-no-crt>
- <https://web.archive.org/web/20020205030547/http://www.hailstorm.net/papers/smallwin32.htm#linker>
- <http://in4k.untergrund.net/various%20web%20articles/Creating_Small_Win32_Executables_-_Fast_Builds.htm>
