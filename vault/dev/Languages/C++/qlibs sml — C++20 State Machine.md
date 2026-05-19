<!-- generated-from-dump2 -->
# qlibs sml — C++20 State Machine

Kris Jusiak's smaller / newer take on his own `boost-ext/sml` state machine library — C++20 only, simpler implementation, fewer features, faster compile. Same DSL idea: write transitions as `src + event [guard] / action = dst`, get back a state machine type with zero runtime overhead (no virtual dispatch, no `std::variant`, no heap). If you can use C++20 throughout and don't need the full `boost-ext/sml` feature set (orthogonal regions, history, etc.), `qlibs/sml` cuts compile time materially. If you need those features or you're stuck on C++14/17, use `boost-ext/sml`.

```cpp
#include <sml>
namespace sml = boost::sml;

struct connect {};
struct disconnect {};

struct connection {
    auto operator()() const {
        using namespace sml;
        return make_transition_table(
            *"idle"_s    + event<connect>    = "connected"_s,
             "connected"_s + event<disconnect> = "idle"_s
        );
    }
};

sml::sm<connection> sm;
sm.process_event(connect{});
sm.process_event(disconnect{});
```

## References
- <https://github.com/qlibs/sml>
