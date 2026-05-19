<!-- generated-from-dump2 -->
# libsigc++ Typesafe Signal-Slot Library

`libsigc++` — typesafe signal/slot library, the C++ underlay of the gtkmm / glibmm bindings. Pre-C++11, this was *the* answer to "I want Qt-style signals without inheriting from `QObject` or running a meta-object compiler." Connection objects carry lifetime so disconnecting is automatic when either side dies; supports binding, hiding, retyping of slot arguments. Less relevant in a greenfield C++17+ codebase (you'd use `std::function` + an `eventpp` / `boost::signals2` if you need bookkeeping), but unavoidable if you touch gtkmm: the entire GTK-from-C++ binding tree is built on it.

```cpp
#include <sigc++/sigc++.h>

struct Counter : public sigc::trackable {
    void on_clicked(int n) { count += n; }
    int  count = 0;
};

sigc::signal<void(int)> clicked;

Counter c;
auto conn = clicked.connect(sigc::mem_fun(c, &Counter::on_clicked));

clicked.emit(5);          // c.count == 5
conn.disconnect();        // or just let c go out of scope - trackable handles it
```

## References
- <https://github.com/libsigcplusplus/libsigcplusplus>
