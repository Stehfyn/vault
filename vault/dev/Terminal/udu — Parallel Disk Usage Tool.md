<!-- generated-from-dump2 -->
# udu — Parallel Disk Usage Tool

Drop-in `du -sh *`-style disk-usage tool optimized for speed: parallel directory traversal across N worker threads, batched `statx`/`lstat` calls to avoid syscall overhead per entry, and (where possible) `getdents64` directly instead of the slower `readdir`. Sits in the same niche as `dust`, `dua`, `gdu`, `ncdu` — the differentiator each project picks is some combination of traversal strategy, UI style, and whether to TUI or just print. Useful baseline read for "what does it take to make disk usage actually fast on a 10M-file tree?" (Answer: it's nearly always syscall-bound, not CPU- or IO-bound, until you fix that.)

```bash
# Basic usage:
$ udu             # current directory
$ udu /var/log    # specific path
$ udu -j 16 ~     # 16 worker threads

# Conceptual core loop:
#   - Bounded work queue of directories to scan.
#   - N workers; each pops a dir, opens with O_DIRECTORY,
#     calls getdents64 in a loop, statx each entry,
#     accumulates per-subdir sizes, pushes child dirs back to queue.
#   - Main thread renders sorted top-K when queue drains.
```

## References
- <https://github.com/gnualmalki/udu>
