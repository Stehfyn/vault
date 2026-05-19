<!-- generated-from-dump2 -->
# MSO Microsoft Office Shared Runtime

"Microsoft Office Shared" library — pieces of Office's internal C++ runtime that the team open-sourced, primarily because React Native for Windows / macOS depends on them. Includes a memory-management API (`Mso::Memory::*`), reference-counting types, async primitives, and a small set of cross-platform compiler-adapter macros. Not the same as `microsoft/wil` (the Windows-shop RAII/HRESULT helpers); MSO is Office-specific and most of its abstractions exist because the Office codebase predates standard `<filesystem>`, `std::variant`, etc. by 20+ years. Mostly relevant if you're working in React Native for desktop or trying to compile some piece of internal Office code outside it.

```cpp
// MSO surfaces are largely consumed indirectly via React Native Windows /
// react-native-macos. Direct standalone usage is sparse; the load-bearing
// public types are reference-counted handles, the Mso::Memory APIs, and the
// compiler-adapter macros under compilerAdapters/.
#include "compilerAdapters/cppMacrosDebug.h"
#include "memoryApi/memoryApi.h"

// Real usage examples live inside microsoft/react-native-windows.
```

## References
- <https://github.com/microsoft/mso>
