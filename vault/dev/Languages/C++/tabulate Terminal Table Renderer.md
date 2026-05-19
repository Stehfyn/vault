<!-- generated-from-dump2 -->
# tabulate Terminal Table Renderer

Header-only C++17 terminal table renderer — set up rows and columns, pick borders / colors / alignment / padding, and `<<` the result to a stream. Box-drawing characters by default (works in any UTF-8 capable terminal), with fallbacks to ASCII. Comparable to Python's `tabulate` / `rich.table` in scope: produces presentation tables, not pretty-printers for data structures. Routinely paired with `p-ranav/indicators` (same author) in CLI tools that want polished output. Handles cell wrapping, multi-line cells, and merge-by-content; doesn't try to be a TUI library, just a one-shot pretty-printer.

```cpp
#include <tabulate/table.hpp>
using namespace tabulate;

Table t;
t.add_row({"Name", "Country", "Score"});
t.add_row({"Alice", "FR", "92"});
t.add_row({"Bob",   "US", "87"});

t[0].format()
    .font_color(Color::yellow)
    .font_style({FontStyle::bold});
t.column(2).format().font_align(FontAlign::right);

std::cout << t << '\n';
```

## References
- <https://github.com/p-ranav/tabulate>
