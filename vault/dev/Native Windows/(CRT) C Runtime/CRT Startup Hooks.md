# CRT Startup Hooks

MSVC discovers pre-`main` work by walking linker-sorted subsections such as `.CRT$XIA..XIZ` for C initializers and `.CRT$XCA..XCZ` for C++ dynamic initializers. User code normally lands in `.CRT$XCU`; manually allocating a function pointer into `.CRT$XCT` or another alphabetically adjacent subsection changes ordering, which is why this technique is powerful and brittle at the same time. The hook runs only if the CRT startup path runs; `/ENTRY` plus `/NODEFAULTLIB` bypasses it entirely unless you implement the same table walk yourself.

Use this as a diagnostic or bootstrap escape hatch, not as hidden application architecture. At hook time, loader lock may still matter for DLLs, global object order across translation units is intentionally weak, and failure paths are ugly because the process has not reached user code yet. It also interacts badly with static CRT duplication: every statically linked DLL has its own initializer tables and teardown callbacks.

## Discussion Claim Triage

The linked discussion is valuable because it names the trick; the proof is in the object file and map.

```cpp
static void before_main(void) { /* trace */ }
#pragma section(".CRT$XCT", read)
__declspec(allocate(".CRT$XCT"))
static void (*p_before_main)(void) = before_main;
```

```text
claim: "this code runs before main."
source/disassembly/probe:
  build with normal CRT startup
  dumpbin /all hook.obj | findstr /i ".CRT$XCT before_main"
  link /MAP and inspect .CRT subsection order
  run and print from hook and main
interpretation:
  it runs only because CRT startup walks the initializer tables.
  rebuild with /ENTRY:custom /NODEFAULTLIB and it disappears unless your entry
  point walks the tables manually.
```

Test `/MD` and `/MT` separately. With static CRTs, each statically linked DLL has its own initializer walk, so "before main" becomes "before this module's user code under this module's startup path."

## Discussion Claim Verification

Claim: "Allocating a function pointer into `.CRT$XCU` or `.CRT$XCT` makes it run before `main`."

Why it matters for new code: this is not a loader feature. It is CRT startup behavior. If the project switches to `/ENTRY`, no-CRT startup, a different toolchain, or a DLL with its own startup path, the hook can silently stop running or run in a different module phase.

How to verify:

```powershell
cl /nologo hook.cpp /link /MAP:hook_crt.map
dumpbin /all hook.obj | findstr /i ".CRT$XC before_main"
dumpbin /disasm hook.exe | findstr /i "before_main mainCRTStartup"
cl /nologo hook.cpp /link /ENTRY:raw_start /NODEFAULTLIB kernel32.lib /MAP:hook_raw.map
```

Minimal code/pseudocode:

```cpp
static int marker;
static void before_main(void) { marker = 123; }

#pragma section(".CRT$XCT", read)
__declspec(allocate(".CRT$XCT"))
static void (*hook)(void) = before_main;
```

Interpretation: the Stack Overflow trick is verified only when the map shows the pointer in a walked CRT subsection and runtime output proves ordering. Nullify the broader claim "Windows runs this before main"; Windows maps the image, then the selected CRT entry point walks the table. No CRT walk, no hook.

## Connections
- `No-CRT Win32` and `Win32 No-CRT C Template` are the cases where these tables disappear unless you recreate CRT startup.
- `CRT Linkage (MD MT DLL)` determines whether a module shares the process CRT DLL or owns a private static CRT instance.

## References
- <https://stackoverflow.com/questions/728939/how-to-execute-some-code-before-entering-the-main-routine-in-vc>
