A minimal Win32 audio/video player using MCI (Media Control Interface). `mciSendString` accepts high-level string commands—`open`, `play`, `pause`, `stop`, `close`—without managing codecs directly. Playback completion is signaled via `MM_MCINOTIFY`.

```cpp
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void MciPlay(HWND hwndCallback, LPCWSTR path) {
    WCHAR cmd[512];

    // Open the file with an alias
    wsprintfW(cmd, L"open \"%s\" type mpegvideo alias media", path);
    mciSendStringW(cmd, NULL, 0, hwndCallback);

    // Play and notify when done
    mciSendStringW(L"play media notify", NULL, 0, hwndCallback);
}

void MciStop(void) {
    mciSendStringW(L"stop media",  NULL, 0, NULL);
    mciSendStringW(L"close media", NULL, 0, NULL);
}

DWORD MciGetPositionMs(void) {
    mciSendStringW(L"set media time format milliseconds", NULL, 0, NULL);
    WCHAR buf[64] = {};
    mciSendStringW(L"status media position", buf, _countof(buf), NULL);
    return (DWORD)_wtol(buf);
}

// In WndProc:
//   case MM_MCINOTIFY:
//       if (wp == MCI_NOTIFY_SUCCESSFUL) { /* playback finished */ }
//       break;
```

## References
- https://github.com/v1nns/msplayer
