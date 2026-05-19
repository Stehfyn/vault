# dcomp.h

DirectComposition's core COM surface: a retained visual tree submitted to the system compositor, with transforms, clips, opacity, effects, and swap-chain or surface content attached to visuals. It sits below XAML/WinUI and above DXGI/DWM: your process builds and commits a tree through `IDCompositionDevice`, then DWM composes it with the desktop. The critical distinction from GDI/D2D immediate painting is lifetime: visuals persist until changed, and updates cross a commit boundary, so bugs look like stale tree state or synchronization issues rather than missed `WM_PAINT`.

Connections: `dcomptypes.h` and `dcompanimation.h` are the value/animation sidecars; see `(DWM) Desktop Window Manager/DWM Thumbnail - VirtualDesktop IDCompositionVisual.md`, `(DX) DirectX/DirectComposition + D3D12 Interop.md`, and `Custom Frame/Acrylic with DirectComposition.md` for real composition-boundary examples.

## References
- dcomp.h
