# warning.h

SDK-internal preamble that disables a fixed set of MSVC warnings before the rest of the Windows headers are pulled in. The headers themselves use C constructs that, under `-Wall` / `/W4`, trip warnings the OS team does not want every downstream user to see -- anonymous struct/union in C++, named type with no name, nonstandard zero-sized array, ENUMs mixed with ints, etc. So `warning.h` does the equivalent of `#pragma warning(push)` + a long list of `#pragma warning(disable: 4201 4214 4514 ...)` at the top of the SDK and `#pragma warning(pop)` at the bottom. You shouldn't include it directly; it gets pulled in transitively from `windows.h`. There's no functional API here.

## References
- warning.h
