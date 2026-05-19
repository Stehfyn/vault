# Windows App SDK Feature Samples

The WindowsAppSDK-Samples repository is the practical matrix for modern desktop Windows features after Project Reunion: AppLifecycle, AppNotifications, PushNotifications, DynamicDependencies, MRT Core/resource management, windowing, and WinUI 3 integration. Its value is in the per-feature folders because the official API surface is broad and each feature has different identity, packaging, and bootstrap requirements.

Use it to answer "what replaced the old Win32 workaround?" AppLifecycle replaces ad hoc mutex/FindWindow/WM_COPYDATA single-instance patterns; AppNotifications replace hand-rolled WinRT toast plumbing for many desktop apps; DynamicDependencies explain how unpackaged code binds framework packages. It is the companion repository to the bootstrapper note.

Code contribution: follow sample folders for `AppInstance`, `AppNotificationManager`, `MddBootstrapInitialize`, MRT Core resource lookup, and WinUI 3 windowing calls.

## References
- <https://github.com/microsoft/WindowsAppSDK-Samples> - official feature samples for Windows App SDK desktop APIs.
