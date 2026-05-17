# Native Windows

Grab-bag index of Win32/NT references and repositories. Each link below has a brief summary and a tiny C/C++ snippet relevant to that resource.

## Minimal Win32 skeleton
```cpp
// Minimal Win32 window + message loop
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
    const wchar_t kClass[] = L"NativeWindowsSample";
    WNDCLASSW wc = {};
    wc.lpfnWndProc = DefWindowProcW;
    wc.hInstance = hInstance;
    wc.lpszClassName = kClass;
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowW(kClass, L"Sample", WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
                              nullptr, nullptr, hInstance, nullptr);
    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return (int)msg.wParam;
}
```

## References
### 1) Windows Embedded legacy MSDN page
URL: https://learn.microsoft.com/ja-jp/previous-versions/windows/embedded/cc399059(v=msdn.10)?redirectedfrom=MSDN

Archived MSDN page for Windows Embedded/CE APIs and platform notes. Useful for older devices and legacy headers.
```cpp
#include <windows.h>

int main() {
  HANDLE evt = CreateEventW(nullptr, TRUE, FALSE, L"CeEvent");
  SetEvent(evt);
  WaitForSingleObject(evt, 100);
  CloseHandle(evt);
  return 0;
}
```

### 2) OpenWireSec metasploit tree
URL: https://github.com/OpenWireSec/metasploit/tree/master

Forked Metasploit source tree with Windows payload code and tooling references.
```cpp
#include <windows.h>
#include <tlhelp32.h>

int main() {
  HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  PROCESSENTRY32W pe = { sizeof(pe) };
  for (BOOL ok = Process32FirstW(snap, &pe); ok; ok = Process32NextW(snap, &pe)) { }
  CloseHandle(snap);
  return 0;
}
```

### 3) Meterpreter base_inject.c
URL: https://github.com/OpenWireSec/metasploit/blob/master/external/source/meterpreter/source/common/arch/win/i386/base_inject.c

Specific source file showing Win32 injection helper routines used by meterpreter.
```cpp
#include <windows.h>

int main() {
  HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 1234);
  BYTE payload[4] = {0, 0, 0, 0};
  LPVOID remote = VirtualAllocEx(proc, nullptr, sizeof(payload), MEM_COMMIT, PAGE_READWRITE);
  SIZE_T written = 0;
  WriteProcessMemory(proc, remote, payload, sizeof(payload), &written);
  CloseHandle(proc);
  return 0;
}
```

### 4) Win32 API index
URL: https://learn.microsoft.com/en-us/windows/win32/api/

Main Win32 API documentation index for functions, structs, and constants.
```cpp
#include <windows.h>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
  MessageBoxW(nullptr, L"Hello Win32", L"Win32 API", MB_OK);
  return 0;
}
```

### 5) Legacy Win32 desktop API (aa366124)
URL: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/aa366124(v=vs.85)

Previous-versions desktop API reference page; handy for older file and handle routines.
```cpp
#include <windows.h>

int main() {
  HANDLE h = CreateFileW(L"legacy.txt", GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
  if (h != INVALID_HANDLE_VALUE) CloseHandle(h);
  return 0;
}
```

### 6) Legacy Win32 desktop API (dd940357)
URL: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/dd940357(v=vs.85)

Previous-versions desktop API reference page, often used with legacy multimedia timing.
```cpp
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main() {
  timeBeginPeriod(1);
  Sleep(5);
  timeEndPeriod(1);
  return 0;
}
```

### 7) CodeProject screen capture methods
URL: https://www.codeproject.com/Articles/5051/Various-methods-for-capturing-the-screen

Article showing different Win32 screen capture techniques and common pitfalls.
```cpp
#include <windows.h>

int main() {
  HDC screen = GetDC(nullptr);
  HDC mem = CreateCompatibleDC(screen);
  HBITMAP bmp = CreateCompatibleBitmap(screen, 200, 120);
  SelectObject(mem, bmp);
  BitBlt(mem, 0, 0, 200, 120, screen, 0, 0, SRCCOPY);
  DeleteObject(bmp);
  DeleteDC(mem);
  ReleaseDC(nullptr, screen);
  return 0;
}
```

### 8) mingw-bundledlls
URL: https://github.com/bvernoux/mingw-bundledlls

List of MinGW runtime DLLs to bundle with native binaries.
```cpp
#include <windows.h>

int main() {
  HMODULE dll = LoadLibraryW(L"libstdc++-6.dll");
  FARPROC sym = dll ? GetProcAddress(dll, "_ZSt4cout") : nullptr;
  if (dll) FreeLibrary(dll);
  return sym ? 0 : 1;
}
```

### 9) TinyWinSpyOff
URL: https://github.com/federicadomani/TinyWinSpyOff

Tiny Win32 window spy/inspector tool with a very small footprint.
```cpp
#include <windows.h>

BOOL CALLBACK EnumProc(HWND hwnd, LPARAM) {
  wchar_t title[128] = {};
  GetWindowTextW(hwnd, title, 128);
  return TRUE;
}

int main() {
  EnumWindows(EnumProc, 0);
  return 0;
}
```

### 10) Win2DinMFC
URL: https://github.com/fobrs/Win2DinMFC

MFC-based demo for 2D drawing and UI work.
```cpp
#include <afxwin.h>

class CMyView : public CView {
public:
  void OnDraw(CDC* pDC) override { pDC->Ellipse(10, 10, 120, 80); }
};
```

### 11) c-win32
URL: https://github.com/mity/c-win32

Minimal C helpers and examples for Win32 programming.
```cpp
#include <windows.h>

int main() {
  WNDCLASSW wc = {};
  wc.lpfnWndProc = DefWindowProcW;
  wc.lpszClassName = L"CWin32";
  RegisterClassW(&wc);
  HWND hwnd = CreateWindowW(wc.lpszClassName, L"c-win32", WS_OVERLAPPEDWINDOW,
                            0, 0, 200, 100, nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);
  DestroyWindow(hwnd);
  return 0;
}
```

### 12) win32-console-docs
URL: https://github.com/rprichard/win32-console-docs

Docs and samples for Windows console I/O and VT mode.
```cpp
#include <windows.h>

int main() {
  HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD mode = 0;
  GetConsoleMode(out, &mode);
  SetConsoleMode(out, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  return 0;
}
```

### 13) Serial-Programming-Win32API-C
URL: https://github.com/rrmhearts/Serial-Programming-Win32API-C

Examples of configuring serial ports using Win32 APIs.
```cpp
#include <windows.h>

int main() {
  HANDLE h = CreateFileW(L"\\\\.\\COM3", GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
  DCB dcb = {};
  dcb.DCBlength = sizeof(dcb);
  GetCommState(h, &dcb);
  dcb.BaudRate = CBR_115200;
  SetCommState(h, &dcb);
  CloseHandle(h);
  return 0;
}
```

### 14) W3C libwww
URL: https://github.com/w3c/libwww

W3C libwww HTTP client library source and history.
```cpp
#include <windows.h>
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")

int main() {
  HINTERNET session = WinHttpOpen(L"libwww-sample/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, nullptr, nullptr, 0);
  HINTERNET conn = WinHttpConnect(session, L"example.com", INTERNET_DEFAULT_HTTP_PORT, 0);
  HINTERNET req = WinHttpOpenRequest(conn, L"GET", L"/", nullptr, nullptr, nullptr, 0);
  WinHttpSendRequest(req, nullptr, 0, nullptr, 0, 0, 0);
  WinHttpReceiveResponse(req, nullptr);
  WinHttpCloseHandle(req);
  WinHttpCloseHandle(conn);
  WinHttpCloseHandle(session);
  return 0;
}
```

### 15) ReactOS
URL: https://github.com/reactos/reactos

Open source Windows-compatible OS and API reimplementation.
```cpp
#include <windows.h>

typedef LONG (WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

int main() {
  HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
  RtlGetVersionPtr fn = (RtlGetVersionPtr)GetProcAddress(ntdll, "RtlGetVersion");
  RTL_OSVERSIONINFOW info = {};
  info.dwOSVersionInfoSize = sizeof(info);
  if (fn) fn(&info);
  return 0;
}
```

### 16) wsspi sspicred.h
URL: https://github.com/tomasr/wsspi/blob/master/inc/sspicred.h

Header defining SSPI credential structures and helpers.
```cpp
#include <windows.h>
#include <sspi.h>

int main() {
  CredHandle cred = {};
  TimeStamp exp = {};
  AcquireCredentialsHandleW(nullptr, (LPWSTR)L"Negotiate", SECPKG_CRED_OUTBOUND,
                            nullptr, nullptr, nullptr, nullptr, &cred, &exp);
  FreeCredentialsHandle(&cred);
  return 0;
}
```

### 17) numlock.c
URL: https://github.com/myfreeer/numlock/blob/master/numlock.c

Tiny program for toggling NumLock state.
```cpp
#include <windows.h>

int main() {
  keybd_event(VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY, 0);
  keybd_event(VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
  return 0;
}
```

### 18) sendinput command.h
URL: https://github.com/myfreeer/sendinput/blob/master/command.h

Header with key sending helpers using SendInput.
```cpp
#include <windows.h>

int main() {
  INPUT in = {};
  in.type = INPUT_KEYBOARD;
  in.ki.wVk = VK_F5;
  SendInput(1, &in, sizeof(in));
  in.ki.dwFlags = KEYEVENTF_KEYUP;
  SendInput(1, &in, sizeof(in));
  return 0;
}
```

### 19) input-switch
URL: https://github.com/myfreeer/input-switch

Utility for switching keyboard layouts/input languages.
```cpp
#include <windows.h>

int main() {
  HKL hkl = LoadKeyboardLayoutW(L"00000409", KLF_ACTIVATE);
  ActivateKeyboardLayout(hkl, 0);
  return 0;
}
```

### 20) Gabefrost blog (archive)
URL: https://web.archive.org/web/20120323170914/http://blog.gabefrost.com/?p=25

Archived blog post on accurate Sleep timing and timer resolution tuning.
```cpp
#include <windows.h>

int main() {
  HANDLE timer = CreateWaitableTimerW(nullptr, TRUE, nullptr);
  LARGE_INTEGER due;
  due.QuadPart = -10 * 1000 * 5;
  SetWaitableTimer(timer, &due, 0, nullptr, nullptr, FALSE);
  WaitForSingleObject(timer, INFINITE);
  CloseHandle(timer);
  return 0;
}
```

### 21) ReactOS clock.c source
URL: https://doxygen.reactos.org/d0/db9/ntoskrnl_2ke_2clock_8c_source.html#l00228

ReactOS kernel clock source showing timekeeping logic.
```cpp
#include <windows.h>

int main() {
  LARGE_INTEGER freq = {};
  LARGE_INTEGER now = {};
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&now);
  return (int)(now.QuadPart % (freq.QuadPart ? freq.QuadPart : 1));
}
```

### 22) Accurate sleep function blog
URL: https://blat-blatnik.github.io/computerBear/making-accurate-sleep-function/

Blog post about refining Sleep accuracy and timer resolution.
```cpp
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main() {
  timeBeginPeriod(1);
  Sleep(16);
  timeEndPeriod(1);
  return 0;
}
```

### 23) Windows API function cheatsheets
URL: https://github.com/7etsuo/windows-api-function-cheatsheets

Quick reference cheat sheets for common Win32 APIs.
```cpp
#include <windows.h>

int main() {
  SetLastError(ERROR_ACCESS_DENIED);
  wchar_t buf[128] = {};
  FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, GetLastError(), 0, buf, 128, nullptr);
  return 0;
}
```

### 24) TaskbarX
URL: https://github.com/ChrisAnd1998/TaskbarX

TaskbarX customizes taskbar position and appearance using Win32 calls.
```cpp
#include <windows.h>

int main() {
  HWND tray = FindWindowW(L"Shell_TrayWnd", nullptr);
  if (tray) SetWindowPos(tray, nullptr, 0, 0, 800, 40, SWP_NOZORDER);
  return 0;
}
```

### 25) Rainmeter-TranslucentRM
URL: https://github.com/ozone10/Rainmeter-TranslucentRM

Rainmeter skin with translucent window effects.
```cpp
#include <windows.h>

int main() {
  HWND hwnd = CreateWindowExW(WS_EX_LAYERED, L"STATIC", L"Overlay", WS_POPUP,
                              0, 0, 200, 200, nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);
  SetLayeredWindowAttributes(hwnd, 0, 180, LWA_ALPHA);
  ShowWindow(hwnd, SW_SHOW);
  return 0;
}
```

### 26) Windows photo editor sample DetailPage.cpp
URL: https://github.com/microsoft/Windows-appsample-photo-editor/blob/d57f02afab83ad506584c71a06dc550c1d74ea95/PhotoEditor/DetailPage.cpp#L444-L480

Sample showing WinRT/WIC image loading and UI updates.
```cpp
#include <windows.h>
#include <wincodec.h>

int main() {
  CoInitializeEx(nullptr, COINIT_MULTITHREADED);
  IWICImagingFactory* factory = nullptr;
  CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
  IWICBitmapDecoder* decoder = nullptr;
  if (factory) factory->CreateDecoderFromFilename(L"photo.jpg", nullptr, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &decoder);
  if (decoder) decoder->Release();
  if (factory) factory->Release();
  CoUninitialize();
  return 0;
}
```

### 27) Microsoft STL block diagram
URL: https://github.com/microsoft/STL?tab=readme-ov-file#block-diagram

MSVC STL README with architecture diagrams and project layout notes.
```cpp
#include <numeric>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4};
  int sum = std::accumulate(v.begin(), v.end(), 0);
  return sum;
}
```

### 28) Magnification API smoothing answer
URL: https://stackoverflow.com/questions/67988506/magnification-windows-api-how-to-add-smoothing-anti-aliasing/67990364#67990364

StackOverflow answer discussing Magnification API smoothing and quality.
```cpp
#include <windows.h>
#include <magnification.h>
#pragma comment(lib, "Magnification.lib")

int main() {
  MagInitialize();
  HWND host = CreateWindowW(L"STATIC", L"MagHost", WS_OVERLAPPEDWINDOW, 0, 0, 300, 200,
                            nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);
  RECT src = {0, 0, 1920, 1080};
  MagSetWindowSource(host, src);
  MagUninitialize();
  return 0;
}
```

### 29) Multithreading mistakes on Windows
URL: https://www.codeproject.com/Articles/5377342/VCplusplus-30-Multithreading-Mistakes-on-Windows

Article listing common Windows C++ threading mistakes and best practices.
```cpp
#include <windows.h>

int main() {
  CRITICAL_SECTION cs;
  InitializeCriticalSection(&cs);
  EnterCriticalSection(&cs);
  LeaveCriticalSection(&cs);
  DeleteCriticalSection(&cs);
  return 0;
}
```

### 30) Safely exiting a multithreaded process
URL: https://handmade.network/forums/t/8892-safely_exiting_a_windows_process_with_multiple_running_threads

Forum discussion about coordinating thread shutdown and signaling.
```cpp
#include <windows.h>

DWORD WINAPI Worker(LPVOID param) {
  HANDLE stop = (HANDLE)param;
  while (WaitForSingleObject(stop, 10) == WAIT_TIMEOUT) { }
  return 0;
}

int main() {
  HANDLE stop = CreateEventW(nullptr, TRUE, FALSE, nullptr);
  HANDLE th = CreateThread(nullptr, 0, Worker, stop, 0, nullptr);
  SetEvent(stop);
  WaitForSingleObject(th, INFINITE);
  CloseHandle(th);
  CloseHandle(stop);
  return 0;
}
```

### 31) WM_QUIT vs WM_CLOSE vs WM_DESTROY
URL: https://stackoverflow.com/questions/3155782/what-is-the-difference-between-wm-quit-wm-close-and-wm-destroy-in-a-windows-pr

Q&A explaining message semantics during window shutdown.
```cpp
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM w, LPARAM l) {
  if (msg == WM_CLOSE) DestroyWindow(hwnd);
  if (msg == WM_DESTROY) PostQuitMessage(0);
  return DefWindowProcW(hwnd, msg, w, l);
}
```

### 32) Creating stream buffer graphs
URL: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/mstv/creating-stream-buffer-graphs

Legacy DirectShow stream buffer graph creation docs.
```cpp
#include <windows.h>
#include <dshow.h>

int main() {
  CoInitialize(nullptr);
  IGraphBuilder* graph = nullptr;
  CoCreateInstance(CLSID_FilterGraph, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&graph));
  if (graph) graph->Release();
  CoUninitialize();
  return 0;
}
```

### 33) UWP media playback
URL: https://learn.microsoft.com/en-us/windows/uwp/audio-video-camera/media-playback

UWP MediaPlayer and MediaPlaybackItem documentation.
```cpp
#include <winrt/Windows.Media.Playback.h>
#include <winrt/Windows.Foundation.h>

int main() {
  winrt::init_apartment();
  winrt::Windows::Media::Playback::MediaPlayer player;
  player.Source(nullptr);
  return 0;
}
```

### 34) Legacy stream buffer topic (ee415253)
URL: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ee415253(v=vs.85)

Older desktop API reference for stream buffer configuration.
```cpp
#include <windows.h>
#include <strmif.h>

int main() {
  CoInitialize(nullptr);
  IStreamBufferInitialize* init = nullptr;
  CoCreateInstance(CLSID_StreamBufferConfig, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&init));
  if (init) init->Release();
  CoUninitialize();
  return 0;
}
```

### 35) Legacy stream buffer topic (ee415252)
URL: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ee415252(v=vs.85)

Companion legacy doc for stream buffer sink usage.
```cpp
#include <windows.h>
#include <strmif.h>

int main() {
  CoInitialize(nullptr);
  IStreamBufferSink* sink = nullptr;
  CoCreateInstance(CLSID_StreamBufferSink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&sink));
  if (sink) sink->Release();
  CoUninitialize();
  return 0;
}
```

### 36) Designing 64-bit compatible interfaces
URL: https://learn.microsoft.com/en-us/windows/win32/winprog64/designing-64-bit-compatible-interfaces?source=recommendations

Guidance on pointer sizes and ABI-safe interfaces.
```cpp
#include <windows.h>

int main() {
  SIZE_T bytes = 4096;
  UINT_PTR handle = (UINT_PTR)bytes;
  return handle != 0;
}
```

### 37) 64-bit tools
URL: https://learn.microsoft.com/en-us/windows/win32/winprog64/the-tools

Overview of 64-bit tooling and diagnostics.
```cpp
#include <windows.h>

int main() {
  USHORT proc = 0;
  USHORT native = 0;
  IsWow64Process2(GetCurrentProcess(), &proc, &native);
  return 0;
}
```

### 38) Rules for using pointers
URL: https://learn.microsoft.com/en-us/windows/win32/winprog64/rules-for-using-pointers

Rules and tips for safe pointer usage in 64-bit Windows.
```cpp
#include <cstdint>

int main() {
  int value = 42;
  uintptr_t p = reinterpret_cast<uintptr_t>(&value);
  int* back = reinterpret_cast<int*>(p);
  return *back;
}
```

### 39) XPAccApps
URL: https://github.com/qqkookie/XPAccApps

Legacy XP accessory apps source and build references.
```cpp
#include <windows.h>

int main() {
  STARTUPINFOW si = { sizeof(si) };
  PROCESS_INFORMATION pi = {};
  CreateProcessW(nullptr, (LPWSTR)L"calc.exe", nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
  return 0;
}
```

### 40) Legacy desktop API (aa376738)
URL: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/aa376738(v=vs.85)

Previous-versions shell and desktop API reference.
```cpp
#include <windows.h>
#include <shlobj.h>

int main() {
  wchar_t path[MAX_PATH] = {};
  SHGetFolderPathW(nullptr, CSIDL_APPDATA, nullptr, SHGFP_TYPE_CURRENT, path);
  return 0;
}
```

### 41) System32 directory index
URL: https://renenyffenegger.ch/notes/Windows/dirs/Windows/System32/index

Index of System32 binaries and DLLs for quick lookup.
```cpp
#include <windows.h>

int main() {
  wchar_t sys[MAX_PATH] = {};
  GetSystemDirectoryW(sys, MAX_PATH);
  return 0;
}
```

### 42) MSVC vectorizer/parallelizer messages
URL: https://learn.microsoft.com/en-us/cpp/error-messages/tool-errors/vectorizer-and-parallelizer-messages?view=msvc-170

MSVC diagnostics for auto-vectorization and parallelization.
```cpp
#include <cstddef>

void scale(float* data, size_t n) {
#pragma loop(ivdep)
  for (size_t i = 0; i < n; ++i) data[i] *= 2.0f;
}
```

### 43) UNICODE_STRING (winternl)
URL: https://learn.microsoft.com/en-us/windows/win32/api/winternl/ns-winternl-string?source=recommendations

Native NT string structure reference used by low-level APIs.
```cpp
#include <windows.h>
#include <winternl.h>

int main() {
  UNICODE_STRING us;
  RtlInitUnicodeString(&us, L"Native");
  return us.Length;
}
```

### 44) LibWinCo libwinco.c
URL: https://github.com/fuyijun1989/LibWinCo/blob/master/libwinco.c

Small Win32 coroutine/fiber helpers written in C.
```cpp
#include <windows.h>

void __stdcall FiberProc(void*) { }

int main() {
  ConvertThreadToFiber(nullptr);
  LPVOID fiber = CreateFiber(0, FiberProc, nullptr);
  SwitchToFiber(fiber);
  DeleteFiber(fiber);
  return 0;
}
```

### 45) Gapslock main.c
URL: https://github.com/ZaneA/Win32-Hacks/blob/master/Gapslock/main.c

Sample for toggling or remapping CapsLock behavior.
```cpp
#include <windows.h>

int main() {
  INPUT in = {};
  in.type = INPUT_KEYBOARD;
  in.ki.wVk = VK_CAPITAL;
  SendInput(1, &in, sizeof(in));
  in.ki.dwFlags = KEYEVENTF_KEYUP;
  SendInput(1, &in, sizeof(in));
  return 0;
}
```

### 46) hard_assert.h
URL: https://github.com/CesarBerriot/hard_assert/blob/master/include/hard_assert.h

Header-only hard assert macro for debug breaks.
```cpp
#include <windows.h>

#define HARD_ASSERT(x) do { if (!(x)) __debugbreak(); } while (0)

int main() {
  HARD_ASSERT(1 + 1 == 2);
  return 0;
}
```

### 47) ThreadWin
URL: https://github.com/endurodave/ThreadWin

C++ threading wrapper around Win32 APIs.
```cpp
#include <windows.h>

DWORD WINAPI Worker(LPVOID) { return 0; }

int main() {
  HANDLE t = CreateThread(nullptr, 0, Worker, nullptr, 0, nullptr);
  WaitForSingleObject(t, INFINITE);
  CloseHandle(t);
  return 0;
}
```

### 48) chatter-cli
URL: https://github.com/kinetic-flow/chatter-cli

Console chat client for Windows using pipes and console I/O.
```cpp
#include <windows.h>

int main() {
  HANDLE pipe = CreateFileW(L"\\\\.\\pipe\\chatter", GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
  const char msg[] = "hi\n";
  DWORD written = 0;
  if (pipe != INVALID_HANDLE_VALUE) WriteFile(pipe, msg, sizeof(msg) - 1, &written, nullptr);
  if (pipe != INVALID_HANDLE_VALUE) CloseHandle(pipe);
  return 0;
}
```

### 49) win32_sem
URL: https://github.com/FabienCarmagnac/win32_sem

Semaphore usage examples for Win32.
```cpp
#include <windows.h>

int main() {
  HANDLE sem = CreateSemaphoreW(nullptr, 0, 3, L"MySem");
  ReleaseSemaphore(sem, 1, nullptr);
  WaitForSingleObject(sem, 10);
  CloseHandle(sem);
  return 0;
}
```

### 50) win32-experiments
URL: https://github.com/yottaawesome/win32-experiments/tree/master/src

Collection of small Win32 experiments and tests.
```cpp
#include <windows.h>

int main() {
  HANDLE evt = CreateEventW(nullptr, TRUE, FALSE, nullptr);
  SetEvent(evt);
  WaitForSingleObject(evt, 10);
  CloseHandle(evt);
  return 0;
}
```

### 51) PreventSleep.c
URL: https://github.com/mmozeiko/stuff/blob/master/Utils/PreventSleep/PreventSleep.c

Sample that prevents system sleep using execution state flags.
```cpp
#include <windows.h>

int main() {
  SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED);
  Sleep(1000);
  SetThreadExecutionState(ES_CONTINUOUS);
  return 0;
}
```

### 52) Previous-versions Windows desktop index
URL: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/

Index to legacy Windows desktop docs and APIs.
```cpp
#include <windows.h>

int main() {
  OSVERSIONINFOW info = {};
  info.dwOSVersionInfoSize = sizeof(info);
  GetVersionExW(&info);
  return (int)info.dwMajorVersion;
}
```

### 53) Proxmox Windows 10 guest best practices
URL: https://pve.proxmox.com/wiki/Windows_10_guest_best_practices

Hypervisor guest tuning guidance for Windows 10. Open it in a browser when you need configuration details.
```cpp
#include <windows.h>
#include <shellapi.h>

int main() {
  ShellExecuteW(nullptr, L"open", L"https://pve.proxmox.com/wiki/Windows_10_guest_best_practices",
                nullptr, nullptr, SW_SHOWNORMAL);
  return 0;
}
```

### 54) PJ Naughter Freeware Library
URL: https://www.codeproject.com/Articles/519/PJ-Naughter-s-Freeware-Library

Index of PJ Naughter MFC/Win32 utility classes and libraries.
```cpp
#include <afx.h>

int main() {
  CFile file;
  if (file.Open(L"sample.txt", CFile::modeRead | CFile::shareDenyNone)) {
    file.Close();
  }
  return 0;
}
```

### 55) OpenMP examples
URL: https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/parallel/openmp/a-examples.md

OpenMP examples for MSVC, showing parallel loops and reductions.
```cpp
#include <omp.h>
#include <vector>

int main() {
  std::vector<int> v(100, 1);
#pragma omp parallel for
  for (int i = 0; i < (int)v.size(); ++i) v[i] += 1;
  return v[0];
}
```

### 56) MFC desktop applications
URL: https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/mfc/mfc-desktop-applications.md

MFC desktop application documentation and patterns.
```cpp
#include <afxwin.h>

class CMyDialog : public CDialog {
public:
  CMyDialog() : CDialog(IDD_DIALOG1) {}
};

int main() { return 0; }
```

### 57) YouTube video (-vJQv4rgHYE)
URL: https://www.youtube.com/watch?v=-vJQv4rgHYE

Video resource on a Windows topic; open it in a browser for the walkthrough.
```cpp
#include <windows.h>
#include <shellapi.h>

int main() {
  ShellExecuteW(nullptr, L"open", L"https://www.youtube.com/watch?v=-vJQv4rgHYE",
                nullptr, nullptr, SW_SHOWNORMAL);
  return 0;
}
```

### 58) RG-Adguard file listing
URL: https://files.rg-adguard.net/version/f0bd8307-d897-ef77-dbd6-216fefbe94c5#:~:text=Windows%207%20with%20Service%20Pack%201%20(Updated%20August%202018)

File listing for Windows update packages and download variants.
```cpp
#include <windows.h>
#include <shellapi.h>

int main() {
  ShellExecuteW(nullptr, L"open",
                L"https://files.rg-adguard.net/version/f0bd8307-d897-ef77-dbd6-216fefbe94c5#:~:text=Windows%207%20with%20Service%20Pack%201%20(Updated%20August%202018)",
                nullptr, nullptr, SW_SHOWNORMAL);
  return 0;
}
```

### 59) MSN Ultimate Performance power plan
URL: https://www.msn.com/en-us/news/technology/windows-has-a-hidden-ultimate-performance-power-plan-here-s-how-to-enable-it/ar-AA1pdxGb

Article about enabling the hidden Ultimate Performance power plan in Windows.
```cpp
#include <windows.h>
#include <shellapi.h>

int main() {
  ShellExecuteW(nullptr, L"open",
                L"https://www.msn.com/en-us/news/technology/windows-has-a-hidden-ultimate-performance-power-plan-here-s-how-to-enable-it/ar-AA1pdxGb",
                nullptr, nullptr, SW_SHOWNORMAL);
  return 0;
}
```

### 60) YouTube video (CTUMNtKQLl8)
URL: https://www.youtube.com/watch?v=CTUMNtKQLl8

Video resource related to Windows UI or features; open it in a browser.
```cpp
#include <windows.h>
#include <shellapi.h>

int main() {
  ShellExecuteW(nullptr, L"open", L"https://www.youtube.com/watch?v=CTUMNtKQLl8",
                nullptr, nullptr, SW_SHOWNORMAL);
  return 0;
}
```

### 61) Microsoft Answers context menu thread
URL: https://answers.microsoft.com/en-us/windows/forum/all/restore-old-right-click-context-menu-in-windows-11/a62e797c-eaf3-411b-aeec-e460e6e5a82a

Community support thread for restoring the old right-click context menu in Windows 11.
```cpp
#include <windows.h>
#include <shellapi.h>

int main() {
  ShellExecuteW(nullptr, L"open",
                L"https://answers.microsoft.com/en-us/windows/forum/all/restore-old-right-click-context-menu-in-windows-11/a62e797c-eaf3-411b-aeec-e460e6e5a82a",
                nullptr, nullptr, SW_SHOWNORMAL);
  return 0;
}
```

### 62) VS Build Tools container docs
URL: https://learn.microsoft.com/en-us/visualstudio/install/build-tools-container?view=vs-2022

Docs for installing Visual Studio Build Tools in containers.
```cpp
#include <windows.h>

int main() {
  STARTUPINFOW si = { sizeof(si) };
  PROCESS_INFORMATION pi = {};
  CreateProcessW(nullptr, (LPWSTR)L"vs_buildtools.exe --quiet --wait",
                 nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
  return 0;
}
```

## Notes
- Wtf is COMDAT folding
- There was a version of File Explorer made in UWP (WinUI 2). It was used for stranges versions of W10, but was not removed from the original Windows.
- Comment image. Here it is.
- You can launch it with this command: `explorer shell:AppsFolder\c5e2524a-ea46-4f67-841f-6a9465d9d515_cw5n1h2txyewy!App`
