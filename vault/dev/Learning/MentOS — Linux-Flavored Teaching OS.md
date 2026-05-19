<!-- generated-from-dump2 -->
# MentOS — Linux-Flavored Teaching OS

32-bit POSIX-flavor toy OS used as the teaching artifact in University of Verona's bachelor and master OS courses. Same niche as xv6 (MIT), JOS (older MIT), Pintos (Stanford), but explicitly modeled after Linux semantics (`fork`/`exec`/`waitpid`, ext2 filesystem, signals, process groups, virtual memory with paging), not the Unix V6 baseline xv6 inherits. Includes the full course slide decks in the repo, which is the actual value vs. the other teaching OSes: you can follow along step by step. Runs under QEMU. C + a touch of x86 assembly. The right thing to read if you want to write a real (educational) kernel from `_start` upward and prefer the Linux mental model.

```text
# Build + run (QEMU x86):
$ cmake -B build -S .
$ cmake --build build
$ ./build/qemu.sh                # boots the kernel image in QEMU

# Notable directories:
#   mentos/inc/system/scheduler.h   - O(1)-ish priority scheduler
#   mentos/src/mem/                 - paging, kmalloc, slab
#   mentos/src/fs/                  - VFS + ext2 driver
#   mentos/src/process/             - elf loader, fork/execve/wait
#   mentos/src/system/signal.c      - POSIX-ish signal delivery
#   doc/slides/                     - lecture-by-lecture PDFs
```

## References
- <https://github.com/mentos-team/MentOS>
