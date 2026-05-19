<!-- generated-from-dump2 -->
# cpp-rotor Actor Framework

C++17 actor framework with Erlang-style supervision trees, but explicitly designed to live inside an existing event loop rather than own one — adapters ship for Boost.Asio, ev (libev), and wx (wxWidgets). Each actor is a state machine; messages are statically typed (`message::ping_t`, not opaque blobs), with `subscribe` registering a handler. The interesting decision: supervisors form a tree like Erlang/OTP, and a child crash propagates up so the parent can decide whether to restart the subtree — giving you reliability semantics inside a single C++ process that you normally have to leave the language to get.

```cpp
#include <rotor.hpp>

namespace r = rotor;

struct pong_actor_t : r::actor_base_t {
    using r::actor_base_t::actor_base_t;
    void on_start() noexcept override {
        r::actor_base_t::on_start();
        subscribe(&pong_actor_t::on_ping);
    }
    void on_ping(r::message_t<int>& msg) noexcept {
        std::cout << "got " << msg.payload << '\n';
        do_shutdown();
    }
};

r::system_context_t ctx;
auto sup = ctx.create_supervisor<r::supervisor_t>().timeout(1s).finish();
auto pong = sup->create_actor<pong_actor_t>().timeout(1s).finish();
sup->send<int>(pong->get_address(), 42);
sup->start();
```

## References
- <https://github.com/basiliscos/cpp-rotor>
