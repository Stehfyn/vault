# Win32 No-CRT C Template

This template is valuable because it makes the no-CRT contract visible in C rather than hiding it in linker folklore. The entry point is owned by the application, Win32 imports are linked directly, and startup does only what the program actually needs. The template also demonstrates the sharp edges: MSVC may still synthesize helper calls for stack probing, memory intrinsics, security cookies, or floating point, so the build flags and source style have to be audited together.

Treat it as a base for small tools, launchers, droppers, recovery utilities, or experiments where the UCRT dependency is unacceptable. Do not treat it as a drop-in replacement for normal C/C++; as soon as you need C++ exceptions, locale-aware formatting, standard I/O, global object lifetimes, or cross-DLL allocation, the omitted CRT behavior becomes application logic you must reimplement.

## Connections
- `No-CRT Win32` describes the broader design constraint.
- `win32asm` shows the same boundary with the compiler removed entirely.
- `GetOEMCP` and `processenv.h` matter when the template starts parsing command-line or environment bytes itself.

## Source Code Reading

The linked `alexandru-cazacu/win32-template-no-crt` repository is most useful when read as a list of responsibilities the CRT normally absorbs.

Source files read:
- `src/app.c`
- `src/win32.c`
- `src/win32_crt_memory.c`
- `src/win32_crt_float.c`
- `src/win32_crt_math.c`

`src/app.c` composes the whole program by directly including the support files, then defining `WinMainCRTStartup`. The entry point does not parse a command line, initialize global constructors, run `atexit`, or construct `argv`; it calls `WinMain(GetModuleHandleA(0), 0, 0, SW_SHOW)` and terminates with `ExitProcess(result)`. That is the concrete boundary to copy for a tiny GUI probe and the concrete missing behavior to list before using it in a real tool.

```c
// Pseudocode from src/app.c
WinMainCRTStartup:
  hinst = GetModuleHandleA(0)
  rc = WinMain(hinst, 0, 0, SW_SHOW)
  ExitProcess(rc)
```

The helper files explain why no-CRT examples often break after "just one more feature":
- `win32_crt_memory.c` supplies compiler-emitted `memset` and `memcpy` via `#pragma function`.
- `win32_crt_float.c` defines `_fltused` and x86 `_ftol2` / `_ftol2_sse`.
- `win32_crt_math.c` carries x86 long-division helpers such as `_alldiv`; this is the price of using 64-bit arithmetic in 32-bit no-CRT builds.
- `win32.c` sets `_WIN32_WINNT 0x0601`, `WIN32_LEAN_AND_MEAN`, `STRICT`, and a large `NO*` macro set before `windows.h`; these macros are build-surface control, not runtime logic.

Actionable experiment: build once with only integer/window code, then add floating point and 64-bit division on x86. Inspect unresolved externals. Every new missing symbol is an implicit CRT dependency the source has forced you either to avoid or implement.

## Discussion Claim Verification

Claim: "A no-CRT template is a reusable application skeleton."

Why it matters for new code: a template that works for `MessageBox` can become wrong the moment code adds stack-heavy functions, floating point, global state, formatting, command-line parsing, or C++ object lifetime. The template should be treated as a probe harness until the missing runtime surface is enumerated.

How to verify:

```powershell
cl /nologo /c /GS- /GR- /EHs-c- src\app.c
link /nologo app.obj kernel32.lib user32.lib /NODEFAULTLIB /ENTRY:WinMainCRTStartup /MAP:app.map
dumpbin /imports app.exe
dumpbin /symbols app.obj | findstr /i "fltused ftol alldiv chkstk memcpy memset"
```

Minimal code/pseudocode:

```text
feature added -> object symbol check -> missing helper?
  no  -> keep source feature
  yes -> avoid feature, implement helper with exact ABI, or restore CRT
```

Interpretation: the linked template verifies a narrow GUI startup path. It does not verify `argv`, `environ`, C++ constructors, `atexit`, locale, standard I/O, exception handling, or cross-DLL allocator behavior. Unsupported claim nullified: "copy this template and you have a complete tiny CRT."

## References
- <https://github.com/alexandru-cazacu/win32-template-no-crt>
