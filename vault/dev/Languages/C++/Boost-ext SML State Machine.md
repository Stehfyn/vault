<!-- generated-from-dump2 -->
# Boost-ext SML State Machine

The canonical "modern" C++14 state-machine library by Kris Jusiak. Transitions are written in an embedded DSL using `operator,`, `operator+`, `operator/`, `operator[]` so `*"idle"_s + event<connect> [guard] / action = "connected"_s` literally is C++ code that builds a transition table type. No virtual calls, no allocations, dispatch compiles down to a switch on a `current_state` index. Compared to plain function-pointer / `switch` FSMs you get exhaustiveness checks, guards, orthogonal regions, anonymous transitions; compared to Boost.MSM you get an order-of-magnitude faster compile time. Newer `qlibs/sml` is a smaller C++20 cousin.

```cpp
#include <boost/sml.hpp>
namespace sml = boost::sml;

struct connect {};
struct disconnect {};
struct establish {};
auto guard  = [](const auto& evt){ return true; };
auto action = [](const auto& evt){ /* ... */ };

struct connection {
    auto operator()() const {
        using namespace sml;
        return make_transition_table(
            *"idle"_s    + event<connect>     [guard] / action = "connecting"_s,
             "connecting"_s + event<establish>                  = "online"_s,
             "online"_s     + event<disconnect>                 = "idle"_s
        );
    }
};

sml::sm<connection> sm;
sm.process_event(connect{});
sm.process_event(establish{});
```

## References
- <https://github.com/boost-ext/sml>
