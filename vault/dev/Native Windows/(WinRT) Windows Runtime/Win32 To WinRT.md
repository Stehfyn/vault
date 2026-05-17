# Win32 To WinRT

Source: https://github.com/tgraupmann/Cpp_Win32_To_WinRT/blob/main/main.cpp

```cpp
RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
if (FAILED(initialize)) { return -1; }

ComPtr<IUriRuntimeClassFactory> uriFactory;
HRESULT hr = GetActivationFactory(
    HStringReference(RuntimeClass_Windows_Foundation_Uri).Get(),
    &uriFactory);
```
