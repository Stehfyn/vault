<!-- generated-from-dump2 -->
# CIB — Compile-Time Init Build (Firmware)

Intel's "CIB" — a C++20 library for declaring firmware features as types and letting the compiler stitch them together into a single optimised init/dispatch flow at build time, with zero runtime registration cost. The conceptual model is: features publish typed services and subscribe to typed events; the framework computes the topological order and inlines everything, so what would normally be a vtable-dispatched plugin system collapses to direct calls. Intel uses it internally for connectivity firmware where every byte of flash and every cycle of boot matters; in practice you trade compile times and template error legibility for runtime determinism.

```cpp
// Sketch only — the library uses constexpr type-based registration; consult
// the project's examples for the actual cib::config / cib::nexus spellings.
#include <cib/cib.hpp>

struct say_hello : public cib::callback_meta<>{};

struct hello_feature {
    constexpr static auto config = cib::config(
        cib::extend<say_hello>([] { /* runs at the registered hook point */ })
    );
};

struct my_project {
    constexpr static auto config = cib::components<hello_feature>;
};

cib::nexus<my_project> nexus{};
int main() { nexus.service<say_hello>(); }
```

## References
- <https://github.com/intel/compile-time-init-build>
