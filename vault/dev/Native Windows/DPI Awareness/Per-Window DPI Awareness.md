# Per-Window DPI Awareness

Source: https://github.com/microsoft/Windows-classic-samples/blob/main/Samples/DPIAwarenessPerWindow/client/DpiAwarenessContext.cpp

```cpp
DPI_AWARENESS_CONTEXT previousDpiContext = SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);
// create HWNDs that should run under this context
SetThreadDpiAwarenessContext(previousDpiContext);
```
