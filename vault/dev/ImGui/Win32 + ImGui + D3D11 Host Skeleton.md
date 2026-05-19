<!-- generated-from-dump2 -->
# Win32 + ImGui + D3D11 Host Skeleton

A bare-metal Win32 + Dear ImGui + D3D11 host loop, useful as a starting skeleton because it shows the *order* the three init/teardown phases must happen in — the bug everyone hits is calling `ImGui_ImplDX11_Init` before the device exists, or shutting down the platform backend before the renderer backend (which leaves dangling font textures on the device). The other piece worth studying is the `WndProc` chain: ImGui's `ImGui_ImplWin32_WndProcHandler` must run *first* so it can swallow input events that hit ImGui widgets, then forward to your own handler. Per-frame, the canonical order is `NewFrame` (renderer) -> `NewFrame` (platform) -> `ImGui::NewFrame` -> your UI -> `ImGui::Render` -> `RenderDrawData`. Getting the resize path right is the next gotcha: invalidate the render target view *before* `ResizeBuffers`, recreate it after, and route `WM_SIZE` even when minimized to avoid a zero-sized swap chain. (cf. Stehfyn/imgui-borderless-win32 for the same loop integrated with a custom titlebar.)

```cpp
// Forward declarations from the imgui_impl_win32.cpp backend.
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wp, lp)) return true;
    switch (msg) {
    case WM_SIZE:
        if (g_pd3dDevice && wp != SIZE_MINIMIZED) {
            CleanupRenderTarget();                       // release RTV first
            g_pSwapChain->ResizeBuffers(0, LOWORD(lp), HIWORD(lp),
                                        DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wp & 0xfff0) == SC_KEYMENU) return 0;       // disable Alt menu
        break;
    case WM_DESTROY: PostQuitMessage(0); return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

// Per-frame:
ImGui_ImplDX11_NewFrame();
ImGui_ImplWin32_NewFrame();
ImGui::NewFrame();
ImGui::ShowDemoWindow();
ImGui::Render();
const float clear[4] = { 0.10f, 0.10f, 0.10f, 1.0f };
g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRTV, nullptr);
g_pd3dDeviceContext->ClearRenderTargetView(g_mainRTV, clear);
ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
g_pSwapChain->Present(1, 0);

// Teardown order matters: renderer first (owns GPU resources), platform second.
ImGui_ImplDX11_Shutdown();
ImGui_ImplWin32_Shutdown();
ImGui::DestroyContext();
```

## References
- <https://github.com/tbindi723/IMGuiTool>
