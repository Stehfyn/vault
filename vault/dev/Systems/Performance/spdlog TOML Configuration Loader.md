<!-- generated-from-dump2 -->
# spdlog TOML Configuration Loader

Header-only wrapper that initializes `spdlog` loggers, sinks, formatters, and async pools from a TOML config file at startup, replacing dozens of hand-rolled factory calls. Useful when shipping the same binary into prod/staging/dev with different sink layouts.

```cpp
#include "spdlog_setup/conf.h"

int main() {
    spdlog_setup::from_file("config/log.toml");
    auto root = spdlog::get("root");
    root->info("started; level={}", spdlog::level::to_string_view(root->level()));
}
```

```toml
# log.toml
[[sink]]
name = "console"
type = "stdout_sink_st"

[[logger]]
name = "root"
sinks = ["console"]
level = "info"
```

## References
- <https://github.com/guangie88/spdlog_setup>
