# aux_ulib.h

`AuxiliaryUserLibrary` -- a tiny pre-Vista helper in `auxiliaryuserlib.dll` (later `auxulib.dll`) used by Win32 console and other subsystems to ask "is this module a console image, a GUI image, or a native subsystem image?" via `AuxUlibIsDLLSynchronizationHeld` and friends. Effectively a vestigial header: most of its surface (`AuxUlibInitialize`, `AuxUlibIsDLLSynchronizationHeld`) was a workaround for the long-since-fixed loader-lock detection problem and is documented as "do not use." If you're seeing this in real code, it was probably copied out of a 2002 KB article and nobody since has needed to look at it.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/aux_ulib/>
