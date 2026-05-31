# IddSampleDriver - Virtual Monitor Driver (Win10)

Microsoft's indirect display driver model lets a UMDF driver publish a synthetic monitor without pretending to be a full WDDM display miniport. `roshkins/IddSampleDriver` is a forkable sample of that model: it creates an indirect display adapter, reports monitor modes, and accepts desktop frames that can be consumed by VR, capture, or remote-desktop software. The important part is not `DriverEntry`; it is the IDDCX handshake among adapter initialization, monitor arrival, mode enumeration, and swap-chain assignment.

Use this as a virtual-monitor starting point, not as a display-control utility. Installation, signing, device identity, and frame transport are the hard parts once the sample works. For user-mode layout changes after the virtual monitor appears, the relevant APIs are still `QueryDisplayConfig` and `SetDisplayConfig` from `Examples.md`.

## Source Code Reading

`roshkins/IddSampleDriver/IddSampleDriver/Driver.cpp` is the file to read. The IDD handshake is explicit:

1. `DriverEntry` creates the WDF driver with `WdfDriverCreate`.
2. `IddSampleDeviceAdd` registers IDDCX callbacks in `IDD_CX_CLIENT_CONFIG`, including adapter init, parse monitor description, mode query, commit modes, assign swap chain, and unassign swap chain.
3. `WdfDeviceCreate` creates the device and attaches an `IndirectDeviceContext`.
4. `IddSampleDeviceD0Entry` calls `IndirectDeviceContext::InitAdapter`.
5. `InitAdapter` fills `IDDCX_ADAPTER_CAPS`, including max monitors and endpoint diagnostics, then exposes monitor identity/modes.

The rendering side is the code readers usually miss. `Direct3DDevice` receives an adapter `LUID`, creates a DXGI factory, calls `EnumAdapterByLuid`, and creates a D3D11 device with `D3D11_CREATE_DEVICE_BGRA_SUPPORT`. `SwapChainProcessor::Run` joins MMCSS task `"Distribution"`, enters `RunCore`, deletes the IDDCX swap-chain object on exit, and reverts MMCSS.

`RunCore` is the frame pump:

```cpp
dxgi_device = d3d_device.QueryInterface(IDXGIDevice);
IddCxSwapChainSetDevice(swapchain, dxgi_device);
for (;;) {
    wait(new_frame_event or terminate_event);
    out = IddCxSwapChainReleaseAndAcquireBuffer(swapchain);
    if (out.MetaData.Status == STATUS_PENDING) continue;
    acquired = out.MetaData.pSurface;       // DXGI surface for this frame
    // copy/encode/send/inspect here, but keep it bounded
    acquired.Reset();
    IddCxSwapChainFinishedProcessingFrame(swapchain);
}
```

This is the probe foundation for virtual display latency: timestamp acquire, processing, finish, and any later encode/send stage. The sample's comments explicitly call this the performance-critical section; if you add CPU readback or encode here without a queue, the virtual monitor will miss frames.

## References
- <https://github.com/roshkins/IddSampleDriver> - Win10-oriented IDD sample used by desktop sharing and VR workflows.
