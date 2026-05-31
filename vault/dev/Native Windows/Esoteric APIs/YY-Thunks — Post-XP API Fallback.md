# YY-Thunks — Post-XP API Fallback Library

Static-link "thunk" library that provides software fallbacks for Win32 APIs introduced after XP RTM (e.g. `DecodePointer`/`EncodePointer`, `RegDeleteKeyExW`, `GetTickCount64`, `InitializeCriticalSectionEx`). At link time the thunked entry replaces the import; at runtime it `GetModuleHandle`+`GetProcAddress`'s the real export and forwards if available, otherwise runs an in-library emulation. Pairs with `Chuyu-Team/VC-LTL5` for shipping modern MSVC builds that run down to XP.

Thunk shape:

```cpp
using Fn = BOOL (WINAPI*)(PCRITICAL_SECTION, DWORD, DWORD);
auto dll = GetModuleHandleW(L"kernel32.dll");
auto real = dll ? reinterpret_cast<Fn>(GetProcAddress(dll, "InitializeCriticalSectionEx")) : nullptr;
return real ? real(cs, spin_count, flags) : FallbackInitializeCriticalSectionEx(cs, spin_count, flags);
```

This belongs with app-compat and `File API From App` because both are API-boundary stories. One checks OS export availability at runtime; the other checks package capability and identity. In both cases, importing the familiar function name is not the same as having the same behavior everywhere.

## Discussion Claim To Verify

Claim implied by downlevel thunk libraries: a modern binary can run on older Windows if missing imports are emulated.

Why it matters: resolving an import is only the first boundary. Semantics, structure sizes, flags, side effects, loader behavior, and dependent DLL imports can still break the program.

Verification route:

```powershell
dumpbin /imports .\app.exe | findstr /i "InitializeCriticalSectionEx RegDeleteKeyExW GetTickCount64"
dumpbin /dependents .\app.exe
```

Runtime probe:

```cpp
HMODULE k32 = GetModuleHandleW(L"kernel32.dll");
auto real = GetProcAddress(k32, "InitializeCriticalSectionEx");
printf("real export=%p path=%s\n", real, real ? "os" : "thunk");
```

Interpretation:
- Import table no longer names the downlevel-missing export and runtime probe succeeds: thunking solved that import boundary.
- Dependent DLL still imports unsupported APIs: the source does not support the whole-application compatibility claim.
- Fallback returns success but behavior diverges under stress: the claim becomes semantic compatibility, not loader compatibility.

## References
- <https://github.com/Chuyu-Team/YY-Thunks>
