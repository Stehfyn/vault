# CRT Startup Hooks

The MSVC CRT runs global C++ constructors via the `.CRT$XCU` section before calling `main`. You can inject code into any CRT startup phase by placing function pointers in the right linker section. This is how ATL, WRL, and MFC register their global objects.

```cpp
// Run code before main via CRT initialization section
// Priority: $XCA (earliest) .. $XCZ (latest user code) .. $XCZ+1 (ATL etc.)
static void EarlyInit() {
    // Runs before main, after CRT heap init
    OutputDebugStringA("EarlyInit called\n");
}

// C linkage required - these are function pointers in a section array
typedef void (__cdecl *_PVFV)();
#pragma section(".CRT$XCT", long, read)  // T = just before user $XCU
__declspec(allocate(".CRT$XCT")) static _PVFV p_early_init = EarlyInit;

// Alternatively with a static object:
struct Initializer {
    Initializer()  { /* runs before main */ InitializeCriticalSection(&g_cs); }
    ~Initializer() { /* runs after main */  DeleteCriticalSection(&g_cs); }
};
static Initializer g_init;
```

Key CRT sections (MSVC):
- `.CRT$XIA` / `.CRT$XIZ` — C initializers (lowest level)
- `.CRT$XCA` / `.CRT$XCZ` — C++ constructor table
- `.CRT$XPA` / `.CRT$XPZ` — Pre-termination
- `.CRT$XTA` / `.CRT$XTZ` — Termination (atexit)

## References
- https://stackoverflow.com/questions/728939/how-to-execute-some-code-before-entering-the-main-routine-in-vc
