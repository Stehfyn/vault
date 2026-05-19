<!-- generated-from-dump2 -->
# Universal ImGui Game-Overlay Hook

Game-overlay starter: hooks the swap-chain `Present` / `vkQueuePresentKHR` of a target process via a vtable swap (MinHook) so an injected DLL can render Dear ImGui on top of D3D9/10/11/12 and Vulkan games. The hot bit is detecting the API at runtime — typically by walking loaded modules (`d3d11.dll`, `dxgi.dll`, `vulkan-1.dll`) and dummy-creating a swap chain to extract the vtable.

```cpp
// D3D11 swapchain Present hook (sketch).
HRESULT WINAPI hkPresent(IDXGISwapChain* sc, UINT sync, UINT flags) {
    if (!g_init) {
        sc->GetDevice(__uuidof(ID3D11Device), (void**)&g_dev);
        g_dev->GetImmediateContext(&g_ctx);
        ImGui_ImplDX11_Init(g_dev, g_ctx);
        g_init = true;
    }
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    DrawOverlay();
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    return oPresent(sc, sync, flags);
}
```

## References
- <https://github.com/Sh0ckFR/Universal-Dear-ImGui-Hook>
