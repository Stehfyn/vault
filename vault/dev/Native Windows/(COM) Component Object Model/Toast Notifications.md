# Toast Notifications

Windows "toast" is a naming trap. There is the modern WinRT notification stack (`Windows.UI.Notifications` / app notifications) that wants an AppUserModelID or packaged identity, XML payloads, activation handling, and notification-platform state. There is also the older tray-icon balloon path (`Shell_NotifyIcon` with `NIF_INFO`) that Action Center can surface as a compatibility toast. Mixing those two paths creates most desktop-app confusion.

WinToast is valuable because it wraps the modern desktop-toast ceremony for C++ apps: AUMID setup, template XML, notification creation, and activation callbacks. ThunderbirdToasts is valuable for the opposite reason: it shows the raw native path through `RoInitialize`, `WindowsCreateStringReference`, `RoGetActivationFactory`, and `IToastNotificationManagerStatics`, which is what a no-C++/WinRT or C-facing bridge needs to understand.

## Connections
- For packaged/unpackaged modern notifications, see Windows App SDK Feature Samples.
- For Python compatibility balloons, see `win10toast`; it is not the same API surface as WinRT toasts.

## References
- <https://github.com/mohabouje/WinToast> - C++ wrapper for desktop apps that need WinRT toast notifications without hand-writing all activation plumbing.
- <https://github.com/valinet/ThunderbirdToasts/blob/master/src/native-app/thunderbird_toasts/thunderbird_toasts.c> - C/native acquisition of the WinRT toast manager activation factory.
