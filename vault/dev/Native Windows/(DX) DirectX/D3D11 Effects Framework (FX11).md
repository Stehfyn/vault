# D3D11 Effects Framework (FX11)

FX11 is Microsoft's D3D11 port of the old D3DX Effects system: `.fx` files bundle shaders, techniques, passes, variables, and render-state declarations behind `ID3DX11Effect`. Microsoft deprecated the model because modern engines usually want explicit constant-buffer/root-state ownership, but it remains useful when porting D3D9/D3D10 code that was architected around effect techniques.

The practical warning is that FX11 hides binding behavior at exactly the layer where D3D11 debugging often needs clarity. Use it for legacy compatibility and sample reading; avoid it for new engines unless the productivity tradeoff is deliberate.

## References
- <https://github.com/microsoft/FX11>
