# YY-Thunks — Post-XP API Fallback Library

Static-link "thunk" library that provides software fallbacks for Win32 APIs introduced after XP RTM (e.g. `DecodePointer`/`EncodePointer`, `RegDeleteKeyExW`, `GetTickCount64`, `InitializeCriticalSectionEx`). At link time the thunked entry replaces the import; at runtime it `GetModuleHandle`+`GetProcAddress`'s the real export and forwards if available, otherwise runs an in-library emulation. Pairs with `Chuyu-Team/VC-LTL5` for shipping modern MSVC builds that run down to XP.

## References
- <https://github.com/Chuyu-Team/YY-Thunks>
