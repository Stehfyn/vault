# perfect-loader - LdrLoadDll Spoofing

perfect-loader is interesting because it tries to keep the official loader in the loop while changing what the loader maps. That is the opposite end of the spectrum from crude manual mapping: rather than reimplement every loader responsibility, it manipulates the inputs so `LdrLoadDll` still performs initialization, loader-list participation, import handling, and other normal side effects.

The research lesson is that "loaded by the loader" and "loaded from the expected file" are separate claims. Defensive analysis has to compare path identity, section object provenance, image bytes, loader metadata, and telemetry rather than trusting any one indicator. This note connects PE loader internals to ETW image-load and memory-forensics checks.

## Source Code Reading

The `EvanMcBroom/perfect-loader` repository makes a strong claim, so read it as a claim/probe target.

Files read:
- `include/perfect_loader.h`
- `include/perfect_loader.hpp`
- `source/loader.cpp`
- `source/mmap.cpp`
- `source/hook.cpp`
- `source/options.cpp`
- `source/run.cpp`
- `source/CMakeLists.txt`

The public API in `perfect_loader.hpp` centers on `Pl::LoadLibrary(fileName, bytes, flags, modListName, nativeFlags)`. Internally, `source/loader.cpp` constructs a `LoadLibraryRedirector`, installs selected hooks around native section-loading functions, then calls `LoadLibraryExW(fileName, nullptr, nativeFlags)`. The destructor removes hooks/restores process state after the load attempt.

Relevant composition:

```text
Pl::LoadLibrary(fileName, bytes, flags)
  -> LoadLibraryRedirector(fileName, bytes, flags)
     -> choose manual-map / TxF module doppelganging / section hollowing path
     -> hook NtCreateSection and/or NtMapViewOfSection
     -> prepare mapped bytes/section state
  -> LoadLibraryExW(fileName, nullptr, nativeFlags)
  -> redirector destructor restores hooks/state
```

`source/mmap.cpp` contains the fallback manual-mapping mechanics: copy headers/sections, set per-section memory protection from section characteristics, and use PE helpers from `include/pl/pe.hpp`. `source/hook.cpp` supplies detour/hardware-breakpoint hook abstractions and architecture-specific trampoline construction.

Claim -> source/probe -> interpretation:
- Claim: "Feature parity with the native loader because `LoadLibrary` is still used."
- Source/probe: load a DLL with imports, TLS, delay-loads, CFG/load-config, and exception-unwind metadata; compare ETW image-load, loader list membership, mapped file path, section object source, headers, and `GetModuleFileName`.
- Interpretation: using `LoadLibraryExW` preserves more loader behavior than a pure manual mapper, but redirection paths still change provenance and create observable differences. The actionable defensive question is which signal diverges, not whether the phrase "native loader" appears.

## Discussion Claim Verification

Claim: "Because `LoadLibraryExW` is still called, this path is indistinguishable from a normal DLL load."

Why it matters for new code: the loader may perform normal initialization while the provenance of the section object, bytes, and path identity diverge. Diagnostic and defensive code must compare multiple artifacts instead of trusting one API result.

How to verify:

```powershell
dumpbin /headers target.dll
dumpbin /imports target.dll
logman start ImageLoadProbe -p "{2cb15d1d-5fc1-11d2-abe1-00a0c911f518}" 0x10 0x5 -ets
.\loader_probe.exe
logman stop ImageLoadProbe -ets
```

Minimal code/pseudocode:

```text
normal load:
  LoadLibraryExW(path)
redirected load:
  Pl::LoadLibrary(path, replacementBytes, flags)
compare:
  GetModuleFileName
  PEB loader entry path
  image-load ETW
  mapped bytes hash
  section protections
```

Interpretation: the supported, verified statement is narrower: redirection can retain more native-loader side effects than a pure manual mapper. Unsupported claim nullified: "native loader in the call stack means normal provenance." Provenance must be measured separately from initialization.

## Connections
- `Proxy-DLL-Loads` maps images through native section calls with a different relationship to loader metadata.
- `In-Memory Module Loading` and manual-map notes show what happens when the official loader is bypassed instead.

## References
- <https://github.com/EvanMcBroom/perfect-loader>
