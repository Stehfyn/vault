<!-- generated-from-dump2 -->
# eventpp Callback Dispatch Library

Three flavors of callback dispatch: `CallbackList<R(Args...)>` (Qt signals), `EventDispatcher<EventKey, R(Args...)>` (key→callbacks map), `EventQueue<EventKey, R(Args...)>` (async — enqueue from any thread, drain on one). Notable for the policy-based design: lock type, list type, argument-passing-mode are all template-policy traits, so you can have a single-threaded zero-allocation dispatcher and a multi-threaded one out of the same code.

```cpp
#include <eventpp/eventqueue.h>

eventpp::EventQueue<int, void(const std::string&)> q;
q.appendListener(1, [](const std::string& s){ std::cout << "A: " << s << "\n"; });
q.appendListener(2, [](const std::string& s){ std::cout << "B: " << s << "\n"; });

// Producer threads — non-blocking enqueue
q.enqueue(1, "hello");
q.enqueue(2, "world");

// Consumer thread — drains
q.process();
```

## References
- <https://github.com/wqking/eventpp>
