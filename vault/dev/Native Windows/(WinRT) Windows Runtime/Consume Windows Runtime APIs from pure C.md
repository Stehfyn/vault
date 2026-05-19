# Consume Windows Runtime APIs from Pure C

Pure C can consume WinRT because WinRT's binary contract is COM plus metadata conventions. The mechanical sequence is `RoInitialize`, build an `HSTRING` runtime-class name, call `RoGetActivationFactory`, `QueryInterface` for the factory or static interface you need, then call vtable slots directly. No C++/WinRT, C++/CX, or WRL projection is required.

The hard part is not the first activation call; it is declaring the exact ABI structs, IIDs, inherited `IInspectable` slots, async interfaces, and ownership rules without the projection generator. That makes pure C useful for tiny repros, language bindings, and "prove the ABI" work, while real applications should usually use C++/WinRT or a generated binding unless the build constraints are severe.

## Connections
- `COM in Plain C` explains the vtable mechanics.
- `WinUI 3 in Pure C` applies the same idea to a much larger XAML/WinAppSDK surface.

## References
- <https://stackoverflow.com/questions/65387849/consume-windows-runtime-apis-from-pure-c> - discussion of direct C consumption of WinRT ABI interfaces.
- <https://stackoverflow.com/questions/7436144/using-winrt-from-c> - older but still relevant explanation that WinRT activation is COM-style activation.
