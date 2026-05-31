# Toast Notifications

Windows "toast" is a naming trap. There is the modern WinRT notification stack (`Windows.UI.Notifications` / app notifications) that wants an AppUserModelID or packaged identity, XML payloads, activation handling, and notification-platform state. There is also the older tray-icon balloon path (`Shell_NotifyIcon` with `NIF_INFO`) that Action Center can surface as a compatibility toast. Mixing those two paths creates most desktop-app confusion.

WinToast is valuable because it wraps the modern desktop-toast ceremony for C++ apps: AUMID setup, template XML, notification creation, and activation callbacks. ThunderbirdToasts is valuable for the opposite reason: it shows the raw native path through `RoInitialize`, `WindowsCreateStringReference`, `RoGetActivationFactory`, and `IToastNotificationManagerStatics`, which is what a no-C++/WinRT or C-facing bridge needs to understand.

## Source Code Reading

`mohabouje/WinToast` and `valinet/ThunderbirdToasts` teach the same stack from opposite ends.

WinToast's production value is not just "show a toast." In `src/wintoastlib.cpp`, `WinToast::initialize` validates or creates the Start-menu shortcut, writes `PKEY_AppUserModel_ID` through `IPropertyStore`, calls `SetCurrentProcessExplicitAppUserModelID`, and only then marks the singleton initialized. `createShellLinkHelper` uses `CLSID_ShellLink`, `IShellLinkW`, `IPropertyStore`, `InitPropVariantFromString`, `Commit`, then `IPersistFile::Save`. That is the hidden prerequisite behind reliable desktop toasts.

```cpp
// WinToast source shape.
CoCreateInstance(CLSID_ShellLink, ..., IID_PPV_ARGS(&link));
link->SetPath(exePath);
link.As(&store);
InitPropVariantFromString(aumid, &v);
store->SetValue(PKEY_AppUserModel_ID, v);
store->Commit();
link.As(&persist)->Save(shortcutPath, TRUE);
```

`WinToast::showToast` then uses WinRT notification factories: get `IToastNotificationManagerStatics`, call `CreateToastNotifierWithId(aumid)`, get `IToastNotificationFactory`, get or build an `IXmlDocument`, attach event handlers, create the notification, and call `IToastNotifier::Show`.

```cpp
GetActivationFactory(ToastNotificationManager, &manager);
manager->CreateToastNotifierWithId(aumid, &notifier);
GetActivationFactory(ToastNotification, &factory);
factory->CreateToastNotification(xml, &notification);
notifier->Show(notification.Get());
```

The event handler shape matters. `setEventHandlers` creates WRL callback COM objects for `Activated`, `Dismissed`, and `Failed`. The activation callback queries `IToastActivatedEventArgs`, optionally `IToastActivatedEventArgs2` for inline reply input, then dispatches back to the user's `IWinToastHandler`. In other words, notification activation is another COM event-source contract; it is not a Windows message.

ThunderbirdToasts shows the no-wrapper ABI. In `src/native-app/thunderbird_toasts/thunderbird_toasts.c`, `PopulateToastMessage` converts UTF-8 JSON into `HSTRING`, activates `Windows.Data.Json.JsonObject`, activates `Windows.Data.Xml.Dom.XmlDocument`, queries `IXmlDocument` / `IXmlDocumentIO`, and loads the generated toast XML. `ShowToastMessage` separately creates HSTRING references for the AUMID, `ToastNotificationManager`, and `ToastNotification`, obtains both factories with `RoGetActivationFactory`, and releases every interface on labeled exit paths.

```c
RoGetActivationFactory(managerName, &IID_IToastNotificationManagerStatics, &statics);
statics->lpVtbl->CreateToastNotifierWithId(statics, appId, &notifier);
RoGetActivationFactory(notificationName, &IID_IToastNotificationFactory, &factory);
factory->lpVtbl->CreateToastNotification(factory, xml, &toast);
notifier->lpVtbl->Show(notifier, toast);
```

A good experiment therefore has three independent checks: AUMID/shortcut property store, WinRT factory activation, and callback delivery. If `Shell_NotifyIcon(NIF_INFO)` works but `CreateToastNotifierWithId` fails, the issue is not "notifications"; it is identity or WinRT activation.

## Discussion Claim To Verify

Claim: a desktop toast can report successful WinRT calls and still not appear because app identity is incomplete.

Why it matters to code: this is the common forum failure mode. Developers prove `RoGetActivationFactory` and XML parsing, then assume the platform swallowed the notification. WinToast's source shows the missing work: Start-menu shortcut, AUMID property, current process AUMID, optional activator CLSID, and event-handler lifetime.

Verification route:

1. Create or locate the Start-menu shortcut for the executable.
2. Read `PKEY_AppUserModel_ID` and `PKEY_AppUserModel_ToastActivatorCLSID` through `IPropertyStore`.
3. Call `GetCurrentProcessExplicitAppUserModelID`.
4. Activate `ToastNotificationManager` and call `CreateToastNotifierWithId(aumid)`.
5. Attach `Failed` and `Dismissed` handlers and keep the COM handler objects alive until the event fires or the process exits.

```cpp
wil::com_ptr<IShellLinkW> link;
wil::com_ptr<IPersistFile> persist;
wil::com_ptr<IPropertyStore> store;
CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&link));
link.query_to(&persist);
persist->Load(shortcutPath, STGM_READ);
link.query_to(&store);

PROPVARIANT appid{};
store->GetValue(PKEY_AppUserModel_ID, &appid);
wprintf(L"AUMID=%ls\n", appid.pwszVal ? appid.pwszVal : L"<missing>");
PropVariantClear(&appid);
```

Interpretation: factory activation success proves the WinRT ABI path. A missing or mismatched AUMID proves the notification identity path is broken. A `Failed` event means the platform accepted the notification object and rejected display/delivery later; that is a different failure than `RoGetActivationFactory`.

Claim: `win10toast`-style Python "toasts" are notification-area balloons, not evidence that WinRT toast identity can be ignored.

Verification route: compare API calls. The compatibility path calls `Shell_NotifyIcon(NIF_INFO)` against a tray icon. The modern path calls WinRT factories and creates `ToastNotification` objects from XML.

Interpretation: if a script notification appears via `NIF_INFO`, that says nothing about desktop app AUMIDs, COM activation callbacks, inline reply input, or Windows App SDK app notifications.

## Connections
- For packaged/unpackaged modern notifications, see Windows App SDK Feature Samples.
- For Python compatibility balloons, see `win10toast`; it is not the same API surface as WinRT toasts.

## References
- <https://github.com/mohabouje/WinToast> - C++ wrapper for desktop apps that need WinRT toast notifications without hand-writing all activation plumbing.
- <https://github.com/valinet/ThunderbirdToasts/blob/master/src/native-app/thunderbird_toasts/thunderbird_toasts.c> - C/native acquisition of the WinRT toast manager activation factory.
- <https://stackoverflow.com/questions/65387849/consume-windows-runtime-apis-from-pure-c> - useful failure report for raw WinRT toast plumbing from C.
