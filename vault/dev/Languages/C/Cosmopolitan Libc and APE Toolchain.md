<!-- generated-from-dump2 -->
# Cosmopolitan Libc and APE Toolchain

Justine Tunney's "ape" (Actually Portable Executable) toolchain — a C library and linker recipe that produces *one* binary that runs natively on Linux, macOS, Windows, FreeBSD, OpenBSD, NetBSD, and BIOS (yes, the same `.com` file boots on bare metal). The trick: it's simultaneously a valid PE/COFF, ELF, and Mach-O — the file header is crafted so each OS' loader sees something it recognizes. Cosmopolitan's `libc` reimplements POSIX-on-top-of-each-host without depending on the system libc, then statically links everything. Used by `llamafile` (the same author's "ship an entire LLM as a single binary" project) to make weights-plus-runtime a single download. Provocative, well-engineered, and unique in the systems space.

```bash
# Build a cosmopolitan APE binary that runs everywhere
cosmocc -o hello hello.c       # cosmocc is the wrapper around clang

# The resulting `hello` runs on Linux, macOS, *BSD, Windows (no extension!)
./hello       # Linux/macOS/BSD
hello.exe     # also runs on Windows; rename or just type it
```

```c
/* hello.c — same source compiles to the universal binary */
#include <stdio.h>
int main(void) {
    printf("hello, %s\n", "world");   // works on every supported OS
    return 0;
}
```

## References
- <https://github.com/jart/cosmopolitan>
