<!-- generated-from-dump2 -->
# Pelles C Updated Windows SDK

Updated Windows SDK headers for the Pelles C compiler suite.

```c
#include <windows.h>
#pragma comment(lib, "user32.lib")

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int) {
  MessageBoxW(NULL, L"Hello from Pelles C!", L"Test", MB_OK);
  return 0;
}
```

## References
- <https://github.com/Frankie-PellesC/fSDK>
