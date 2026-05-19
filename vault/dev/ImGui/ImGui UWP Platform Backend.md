<!-- generated-from-dump2 -->
# ImGui UWP Platform Backend

Dear ImGui platform backend for **UWP** (CoreWindow / Universal Windows Platform) — the equivalent of `imgui_impl_win32` but for the WinRT-style windowing API used by Xbox apps and Windows Store apps. Pairs with the D3D11/D3D12 renderer backends. Useful if you're shipping a tool to Xbox dev kits or a Windows Store sandbox where Win32 windowing APIs are restricted.

```cpp
// Init against a CoreWindow obtained from CoreApplication::CreateNewView etc.
auto coreWindow = winrt::Windows::UI::Core::CoreWindow::GetForCurrentThread();
ImGui::CreateContext();
ImGui_ImplUwp_InitForCurrentView();   // hooks pointer / keyboard / size events
ImGui_ImplDX11_Init(d3dDevice.get(), d3dContext.get());
// Per-frame: ImGui_ImplDX11_NewFrame(); ImGui_ImplUwp_NewFrame(); ImGui::NewFrame(); ...
```

## References
- <https://github.com/ahmed605/imgui-uwp>
