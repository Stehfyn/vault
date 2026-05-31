# Consume Windows Runtime APIs from Pure C

Pure C can consume WinRT because WinRT's binary contract is COM plus metadata conventions. The mechanical sequence is `RoInitialize`, build an `HSTRING` runtime-class name, call `RoGetActivationFactory`, `QueryInterface` for the factory or static interface you need, then call vtable slots directly. No C++/WinRT, C++/CX, or WRL projection is required.

The hard part is not the first activation call; it is declaring the exact ABI structs, IIDs, inherited `IInspectable` slots, async interfaces, and ownership rules without the projection generator. That makes pure C useful for tiny repros, language bindings, and "prove the ABI" work, while real applications should usually use C++/WinRT or a generated binding unless the build constraints are severe.

## Discussion Claims To Test

Claim: WinRT APIs can be consumed from C if you use the ABI headers directly.
Source/probe: the Stack Overflow thread includes a C toast experiment with `roapi.h`, `winstring.h`, `Windows.ui.notifications.h`, handwritten GUIDs for `IToastNotificationManagerStatics`, `IXmlDocument`, `IXmlDocumentIO`, `IToastNotificationFactory`, and direct `lpVtbl` calls. Compile a smaller probe that only activates `Windows.Data.Xml.Dom.XmlDocument`, queries `IXmlDocumentIO`, and calls `LoadXml`.
Interpretation: if the probe works, the discussion's central claim is not philosophical; it is an ABI fact. Failure is usually one of three things: wrong IID, wrong inherited vtable layout, or missing apartment/activation context.

Claim: "HRESULTs are S_OK but no toast appears" can still be an identity/notification-platform failure.
Source/probe: the same discussion code writes a Start-menu shortcut through `CLSID_ShellLink`, queries `IPropertyStore`, sets `PKEY_AppUserModel_ID` and `PKEY_AppUserModel_ToastActivatorCLSID`, then saves with `IPersistFile`. Probe the link separately: load it, read those property keys, call `SetCurrentProcessExplicitAppUserModelID`, then call `CreateToastNotifierWithId`.
Interpretation: raw WinRT activation success only proves the factory and XML path. Desktop notification display also depends on AUMID identity, shortcut registration, policy, focus assist, and activation registration.

Claim: a C ABI sample should be debugged at the interface boundary, not by staring at projection examples.
Source/probe: log every transition as `class name -> IID -> HRESULT -> returned pointer`; in WinDbg, dump the first pointer-sized field of each returned object and disassemble the first vtable slot to confirm it is a COM-style `QueryInterface`.
Interpretation: a bad cast often looks like a valid non-null pointer until the next vtable call. The probe must verify identity and inherited slot order, not just non-null returns.

Claim: `IInspectable` adds three methods after `IUnknown`; a hand-declared vtable that skips them will call the wrong function.
Why it matters to code: pure-C WinRT samples often fail only after the first successful activation because the returned pointer is real but the local struct layout is wrong. The next `lpVtbl` call then jumps into `GetIids`, `GetRuntimeClassName`, or `GetTrustLevel` when the caller thought it was invoking a type-specific method.
Verification route: activate a simple object, query `IInspectable`, call only the inherited inspection methods first, then query the type-specific interface and call the first type-specific slot. In WinDbg, compare `poi(obj)` and `dps poi(obj)` against the header-declared vtable order.

```c
IInspectable *inspect = NULL;
hr = factory->lpVtbl->ActivateInstance(factory, &inspect);
HSTRING runtimeName = NULL;
TrustLevel trust = BaseTrust;
inspect->lpVtbl->GetRuntimeClassName(inspect, &runtimeName);
inspect->lpVtbl->GetTrustLevel(inspect, &trust);

IXmlDocumentIO *io = NULL;
inspect->lpVtbl->QueryInterface(inspect, &IID_IXmlDocumentIO, (void **)&io);
```

Interpretation: `GetRuntimeClassName` succeeding proves the inherited WinRT ABI prefix is correct. A later crash in `IXmlDocumentIO` points at the type-specific IID or vtable declaration, not at `RoGetActivationFactory`.

## Connections
- `COM in Plain C` explains the vtable mechanics.
- `WinUI 3 in Pure C` applies the same idea to a much larger XAML/WinAppSDK surface.

## References
- <https://stackoverflow.com/questions/65387849/consume-windows-runtime-apis-from-pure-c> - discussion of direct C consumption of WinRT ABI interfaces.
- <https://stackoverflow.com/questions/7436144/using-winrt-from-c> - older but still relevant explanation that WinRT activation is COM-style activation.

## Experiment Harness

Goal: test only the WinRT ABI prerequisites: apartment, `HSTRING`, factory, instance.

```c
HRESULT hr0 = RoInitialize(RO_INIT_MULTITHREADED);
HSTRING s = NULL;
HRESULT hr1 = WindowsCreateString(L"Windows.Globalization.Calendar", 28, &s);
void *factory = NULL;
HRESULT hr2 = RoGetActivationFactory(s, &IID_IActivationFactory, &factory);
printf("Ro=%08lx HSTRING=%08lx Factory=%08lx\n", hr0, hr1, hr2);
WindowsDeleteString(s);
```

Measured signal: three HRESULTs and whether the same class activates from C++/WinRT on the same machine.

Failure interpretation: if raw C fails but C++/WinRT succeeds, your hand-declared IID/vtable/string ownership is wrong; if both fail, apartment or activation context is wrong. Microsoft anchor: <https://learn.microsoft.com/en-us/windows/win32/api/roapi/nf-roapi-roinitialize>.
