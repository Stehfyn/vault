The Windows Composition API (WinRT `Windows.UI.Composition`) can be hosted in a Win32 HWND via `ICompositorDesktopInterop::CreateDesktopWindowTarget`. A `DispatcherQueue` on the current STA thread drives the compositor, and `SpriteVisual` objects are composited on top of the HWND.

```cpp
#include <winrt/Windows.UI.Composition.Desktop.h>
#include <windows.ui.composition.interop.h>
#include <DispatcherQueue.h>
using namespace winrt::Windows::UI::Composition;
using namespace winrt::Windows::UI::Composition::Desktop;

// Create a dispatcher queue on the current STA thread
auto CreateDispatcherQueueController()
{
    namespace abi = ABI::Windows::System;
    DispatcherQueueOptions opts{ sizeof(opts), DQTYPE_THREAD_CURRENT, DQTAT_COM_STA };
    winrt::Windows::System::DispatcherQueueController ctrl{ nullptr };
    CreateDispatcherQueueController(opts,
        reinterpret_cast<abi::IDispatcherQueueController**>(winrt::put_abi(ctrl)));
    return ctrl;
}

// Attach the WinRT compositor to a Win32 HWND
DesktopWindowTarget CreateDesktopWindowTarget(Compositor const& compositor, HWND hwnd)
{
    namespace abi = ABI::Windows::UI::Composition::Desktop;
    auto interop = compositor.as<abi::ICompositorDesktopInterop>();
    DesktopWindowTarget target{ nullptr };
    interop->CreateDesktopWindowTarget(hwnd, true,
        reinterpret_cast<abi::IDesktopWindowTarget**>(winrt::put_abi(target)));
    return target;
}

// Wire up a colour-filled root visual that tracks the window size
void PrepareVisuals(HWND hwnd, DesktopWindowTarget& out_target)
{
    Compositor compositor;
    out_target = CreateDesktopWindowTarget(compositor, hwnd);

    auto root = compositor.CreateSpriteVisual();
    root.RelativeSizeAdjustment({ 1.0f, 1.0f });        // fill window
    root.Brush(compositor.CreateColorBrush({ 0xFF, 0xEF, 0xE4, 0xB0 }));
    out_target.Root(root);

    // Add a child visual
    auto child = compositor.CreateSpriteVisual();
    child.Size({ 100.0f, 100.0f });
    child.Offset({ 50.0f, 50.0f, 0.0f });
    child.Brush(compositor.CreateColorBrush({ 0xDC, 0x5B, 0x9B, 0xD5 }));
    root.Children().InsertAtTop(child);
}
```

## References
- https://gist.github.com/kennykerr/62923cdacaba28fedc4f3dab6e0c12ec
