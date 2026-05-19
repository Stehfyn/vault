<!-- generated-from-dump2 -->
# nxdk — Open-Source Original Xbox SDK

The "new" open-source SDK for the original Xbox — descendant of OpenXDK, built around a cross-platform LLVM/clang toolchain that produces `.xbe` executables runnable on real hardware and emulators (xemu, Cxbx-Reloaded). Provides POSIX-flavored SDL, GL-like NXDK-GL, and direct access to the Xbox's NV2A GPU. Lets you build homebrew on Linux/macOS/Windows without the original Microsoft XDK.

```c
#include <hal/video.h>
#include <hal/xbox.h>
#include <pbkit/pbkit.h>

int main(void) {
    XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);
    pb_init();
    pb_show_front_screen();
    while (1) {
        pb_wait_for_vbl();
        // ... push NV2A command-buffer ops via pb_begin/pb_end ...
    }
}
```

## References
- <https://github.com/XboxDev/nxdk>
