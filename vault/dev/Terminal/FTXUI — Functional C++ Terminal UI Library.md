<!-- generated-from-dump2 -->
# FTXUI — Functional C++ Terminal UI Library

Functional Terminal UI library for C++17. Composes `Element`s and `Component`s like a React render tree, draws via Unicode box-drawing + 24-bit ANSI color, and handles input/focus declaratively. Cross-platform (Linux/macOS via termios, Windows via Console API). The most polished modern C++ TUI option.

```cpp
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
using namespace ftxui;

int main() {
    int value = 0;
    auto add = Button("+", [&]{ ++value; });
    auto sub = Button("-", [&]{ --value; });
    auto layout = Container::Horizontal({sub, add});
    auto renderer = Renderer(layout, [&]{
        return vbox({ text("count: " + std::to_string(value)),
                      hbox({sub->Render(), add->Render()}) }) | border;
    });
    ScreenInteractive::TerminalOutput().Loop(renderer);
}
```

## References
- <https://github.com/ArthurSonzogni/FTXUI>
