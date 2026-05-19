<!-- generated-from-dump2 -->
# daniele77 cli — Interactive REPL Menu Library

C++ library for *interactive* command-line interfaces — REPL-style menus, sub-menus, auto-completion, history, in the style of Cisco IOS / `(gdb)` / network device shells. Distinct from argv-parsing libraries (CLI11, cxxopts) — `daniele77/cli` is for the runtime menu loop after your program is already up. The interesting design choice is the local-vs-telnet decoupling: the same menu tree can be exposed on stdin or on a TCP socket via the bundled session class, so you can SSH into a long-running daemon and get the same shell you'd get locally. Useful for embedded supervisor apps and game console-style admin tools.

```cpp
#include <cli/cli.h>
#include <cli/clilocalsession.h>
#include <cli/loopscheduler.h>

using namespace cli;

int main() {
    auto rootMenu = std::make_unique<Menu>("cli");
    rootMenu->Insert("hello",
        [](std::ostream& out){ out << "hello world\n"; },
        "Print hello");
    rootMenu->Insert("add",
        [](std::ostream& out, int a, int b){ out << a + b << '\n'; },
        "Add two numbers");

    Cli cli(std::move(rootMenu));
    LoopScheduler s;
    CliLocalTerminalSession session(cli, s, std::cout, 200);
    session.ExitAction([&s](auto& out){ out << "bye\n"; s.Stop(); });
    s.Run();
}
```

## References
- <https://github.com/daniele77/cli>
