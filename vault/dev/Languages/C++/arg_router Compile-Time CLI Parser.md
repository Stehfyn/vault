<!-- generated-from-dump2 -->
# arg_router Compile-Time CLI Parser

C++17 header-only CLI parser that's structurally different from `CLI11`/`cxxopts`/`argparse`: the entire grammar and dispatch table is a compile-time tree of strongly-typed nodes (`flag`, `arg`, `positional_arg`, `mode`, `root`) built with operator overloads, and each leaf is bound to a function via `policy::router{}`. The parser is generated from that tree at compile time — argument types are known statically, parsing errors are reported with the actual policy that failed, and there's no runtime registration. The downside is the usual: template error messages are eye-watering. Useful if you want CLIs to fail to compile rather than at runtime.

```cpp
#include <arg_router/arg_router.hpp>
namespace ar = arg_router;
using namespace ar::policy;

const auto root = ar::root(
    ar::flag(long_name<S_("help")>,
             short_name<'h'>,
             description<S_("show help")>),
    ar::arg<int>(long_name<S_("count")>,
                 default_value(1),
                 description<S_("count")>),
    router{[](bool help, int count){
        if (help) std::cout << "...\n";
        else      std::cout << "count=" << count << '\n';
    }}
);

int main(int argc, char** argv) { ar::parse(root, argc, argv); }
```

## References
- <https://github.com/cmannett85/arg_router>
