# Win32 No-CRT C Template

This template is valuable because it makes the no-CRT contract visible in C rather than hiding it in linker folklore. The entry point is owned by the application, Win32 imports are linked directly, and startup does only what the program actually needs. The template also demonstrates the sharp edges: MSVC may still synthesize helper calls for stack probing, memory intrinsics, security cookies, or floating point, so the build flags and source style have to be audited together.

Treat it as a base for small tools, launchers, droppers, recovery utilities, or experiments where the UCRT dependency is unacceptable. Do not treat it as a drop-in replacement for normal C/C++; as soon as you need C++ exceptions, locale-aware formatting, standard I/O, global object lifetimes, or cross-DLL allocation, the omitted CRT behavior becomes application logic you must reimplement.

## Connections
- `No-CRT Win32` describes the broader design constraint.
- `win32asm` shows the same boundary with the compiler removed entirely.
- `GetOEMCP` and `processenv.h` matter when the template starts parsing command-line or environment bytes itself.

## References
- <https://github.com/alexandru-cazacu/win32-template-no-crt>
