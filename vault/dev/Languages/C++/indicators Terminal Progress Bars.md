<!-- generated-from-dump2 -->
# indicators Terminal Progress Bars

Single-header C++17 terminal progress indicators — progress bars, block progress, spinners, multi-progress (several bars stacked) and `DynamicProgress<>` (bars you add at runtime). ANSI-escape-driven, so it works fine on modern Windows (Win10 1607+ Conhost / Windows Terminal) and POSIX. The handy bit vs rolling your own is that it manages cursor save/restore, color output, and concurrent updates from worker threads without garbling the terminal. Replaces `indicators::ProgressBar` with `indicators::BlockProgressBar` / `IndeterminateProgressBar` based on whether you know total work upfront.

```cpp
#include <indicators/progress_bar.hpp>
using namespace indicators;

ProgressBar bar{
    option::BarWidth{50},
    option::Start{"["},
    option::Fill{"="},
    option::Lead{">"},
    option::Remainder{" "},
    option::End{"]"},
    option::ShowPercentage{true},
    option::ShowElapsedTime{true},
    option::ShowRemainingTime{true},
    option::ForegroundColor{Color::cyan},
};

for (int i = 0; i <= 100; ++i) {
    bar.set_progress(i);
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
```

## References
- <https://github.com/p-ranav/indicators>
