1. https://stackoverflow.com/questions/65714442/direct-x-cropping-bitmap-based-on-window-position-and-rendering-it-back-to-windo

Snippet (use lParam RECT + DwmFlush to avoid flicker):

```cpp
case WM_MOVING:
{
    RECT* hostRect = reinterpret_cast<RECT*>(lParam);
    // use hostRect for crop bounds
    DwmFlush(); // blocks until next present
    Render();
    return 0;
}
```
