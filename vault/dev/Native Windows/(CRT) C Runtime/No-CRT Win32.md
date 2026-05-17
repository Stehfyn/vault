## References
- https://github.com/chizhaolin/Simple-CRT
- https://github.com/alexandru-cazacu/win32-template-no-crt
- https://github.com/alexandru-cazacu/win32-template-no-crt/blob/main/src/win32.c
- https://raw.githubusercontent.com/alexandru-cazacu/win32-template-no-crt/d797c6855942ff5732965af1f4f2fc649ce663bd/src/win32.c
- https://raw.githubusercontent.com/alexandru-cazacu/win32-template-no-crt/d797c6855942ff5732965af1f4f2fc649ce663bd/src/app.c

This template includes win32.c directly and supplies a custom WinMainCRTStartup entry point to avoid linking the CRT.

```c
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow);

void CALLBACK WinMainCRTStartup()
{
    int result = WinMain(GetModuleHandleA(0), 0, 0, SW_SHOW);
    ExitProcess(result);
}

https://web.archive.org/web/20020205030547/http://www.hailstorm.net/papers/smallwin32.htm#linker
Archived guide on linker settings for tiny Win32 programs. Key: /NODEFAULTLIB, /ENTRY:WinMainCRTStartup (or custom), /MERGE:.rdata=.text, /OPT:REF,ICF. A minimal no-CRT entry point calls SetErrorMode then ExitProcess.
```cpp
// Custom CRT startup stub - replaces the full CRT startup
// Link with /NODEFAULTLIB /ENTRY:Startup
extern "C" void WINAPI Startup() {
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
    SetProcessDPIAware();
    // Call your WinMain equivalent directly
    int result = App_Run();
    ExitProcess((UINT)result);
}
```

http://in4k.untergrund.net/various%20web%20articles/Creating_Small_Win32_Executables_-_Fast_Builds.htm
Technique for ultra-small Win32 executables: avoid the CRT, use MessageBox as the only API, link with /SUBSYSTEM:WINDOWS /ENTRY:main. Each CRT function pulled in adds kilobytes.
```cpp
// Absolute minimum Win32 executable - no CRT, no imports except user32
// Compile: cl /O1 /GS- tiny.cpp /link /NODEFAULTLIB /ENTRY:WinMain
// /SUBSYSTEM:WINDOWS user32.lib
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return MessageBoxA(nullptr, "Hi", "Tiny", MB_OK);
}
```
```
