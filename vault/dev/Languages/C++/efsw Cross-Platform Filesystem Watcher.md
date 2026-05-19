<!-- generated-from-dump2 -->
# efsw Cross-Platform Filesystem Watcher

Cross-platform filesystem watcher in C++. Worth knowing because the three OS APIs are genuinely different: Linux is `inotify` (file descriptor + read), macOS is `FSEvents` (callback-based, coalesces events), Windows is `ReadDirectoryChangesW` with overlapped I/O. efsw papers over all three with one `FileWatchListener` callback. Gotcha to remember: `inotify` watches are per-directory and don't recurse — efsw adds watches on every subdir at startup and dynamically as new dirs appear.

```cpp
#include <efsw/efsw.hpp>

struct Listener : efsw::FileWatchListener {
    void handleFileAction(efsw::WatchID id, const std::string& dir,
                          const std::string& file, efsw::Action act,
                          std::string old = "") override
    {
        // act: Add, Delete, Modified, Moved (old is the prior name on rename)
        std::cout << dir << "/" << file << " act=" << act << "\n";
    }
};

efsw::FileWatcher w;
Listener l;
w.addWatch("/path/to/dir", &l, /*recursive=*/true);
w.watch();
```

## References
- <https://github.com/SpartanJ/efsw>
