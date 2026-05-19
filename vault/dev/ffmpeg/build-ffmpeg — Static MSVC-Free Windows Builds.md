<!-- generated-from-dump2 -->
# build-ffmpeg — Static MSVC-Free Windows Builds

Martins Mozeiko's scripts for producing **statically-linked** 64-bit Windows builds of FFmpeg with no external DLL dependencies — exactly what you want when you're shipping `ffmpeg.exe` inside a tool and can't ask users to install MSVC redistributables. Uses MSYS2/mingw-w64 toolchain, builds x264/x265/libopus/libvpx/libdav1d as static archives, then links them into a single fat `ffmpeg.exe`.

```bash
# In an MSYS2 MINGW64 shell, after running the deps script:
./ffmpeg.sh   # configures with --enable-static --disable-shared
              # --enable-gpl --enable-libx264 --enable-libx265 ...
              # then runs make -j and strips the result.
```

## References
- <https://github.com/mmozeiko/build-ffmpeg>
