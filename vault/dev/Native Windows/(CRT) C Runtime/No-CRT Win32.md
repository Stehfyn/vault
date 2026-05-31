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

## Source Code Reading

Two linked source projects illustrate different no-CRT depths.

`alexandru-cazacu/win32-template-no-crt` is the narrow Win32 version. Its `src/app.c` starts at `WinMainCRTStartup`, calls `WinMain`, and exits through `ExitProcess`; its helper files provide only compiler-required glue: `memset`, `memcpy`, `_fltused`, x86 float-to-int helpers, and x86 64-bit math helpers. Its `src/win32.c` is really a header-surface reducer: it pins `_WIN32_WINNT` to Windows 7 and defines `WIN32_LEAN_AND_MEAN`, `STRICT`, and many `NO*` macros before including `windows.h`.

`chizhaolin/Simple-CRT` is a broader toy runtime. `my_crt.c` defines `my_crt_entry`, reads `GetCommandLineA`, tokenizes a fixed-size `argv`, calls `heap_init`, then enters `main(argc, argv)` and exits with `ExitProcess`. Its companion files are the missing-library bodies: `malloc.c` for heap allocation, `stdio.c` for formatted/console-ish I/O, and `string.c` for byte/string primitives.

The implementation contrast is the useful lesson:

```text
tiny Win32 template:
  WinMainCRTStartup -> WinMain -> ExitProcess
  provide only compiler helper symbols actually emitted

Simple-CRT:
  my_crt_entry -> GetCommandLineA -> tokenize argv
  heap_init -> main(argc, argv) -> ExitProcess
  reimplement enough malloc/stdio/string for C-style programs
```

Steps to turn this into a serious probe:
1. Build with `/NODEFAULTLIB /ENTRY:WinMainCRTStartup`.
2. Run `dumpbin /imports` and confirm no `ucrtbase.dll` or `vcruntime*.dll`.
3. Add one feature at a time: command-line parsing, floating point, 64-bit division, stack-heavy functions, formatted output.
4. Treat each unresolved external as a design decision: avoid the feature, implement the exact ABI helper, or restore the CRT.

## Discussion Claim Verification

Claim: "No-CRT means the program has no runtime."

Why it matters for new code: false. No-CRT means the program supplies or avoids the runtime work the compiler and source still require. The interesting audit is not whether `/NODEFAULTLIB` appears; it is which hidden helper symbols the object files still demand.

How to verify:

```powershell
cl /nologo /c /GS- /GR- /EHs-c- tiny.c
link /nologo tiny.obj kernel32.lib /ENTRY:WinMainCRTStartup /NODEFAULTLIB /SUBSYSTEM:WINDOWS /MAP:tiny.map
dumpbin /imports tiny.exe
dumpbin /symbols tiny.obj | findstr /i "memcpy memset chkstk fltused security atexit Cxx"
dumpbin /disasm tiny.exe > tiny.disasm.txt
```

Minimal code/pseudocode:

```c
void WinMainCRTStartup(void) {
    ExitProcess(WinMain(GetModuleHandleW(0), 0, GetCommandLineW(), SW_SHOWDEFAULT));
}
```

Interpretation: the old small-executable articles are directionally useful but often oversell linker tricks. Verified no-CRT means no CRT imports and no unresolved compiler helpers after link. Nullify any "no runtime" claim when the source reintroduces helper bodies for `memcpy`, `_fltused`, division, stack probing, or security cookies; those helpers are the runtime, just locally owned.

## Connections
- `Win32 No-CRT C Template` is the concrete C version of this pattern.
- `CRT Startup Hooks` explains what you lose when CRT startup is skipped.
- `Binary Size Reduction` covers less invasive linker optimization before removing the CRT entirely.
- `winnt.h`, `sdkddkver.h`, and PE loader notes explain the headers/imports/entry-point contract that remains after the CRT is gone.
- `RTL_USER_PROCESS_PARAMETERS` is where command line and environment really come from before a CRT turns them into `argv` and `environ`.

## References
- <https://github.com/chizhaolin/Simple-CRT>
- <https://github.com/alexandru-cazacu/win32-template-no-crt>
- <https://web.archive.org/web/20020205030547/http://www.hailstorm.net/papers/smallwin32.htm#linker>
- <http://in4k.untergrund.net/various%20web%20articles/Creating_Small_Win32_Executables_-_Fast_Builds.htm>
