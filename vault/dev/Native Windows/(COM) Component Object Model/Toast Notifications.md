# Toast Notifications

## WinToast (C++ wrapper for WinRT toasts)
https://github.com/mohabouje/WinToast  
Brief: Initialize WinToast once and send a templated toast with a simple handler.
```cpp
class MyHandler : public WinToastLib::IWinToastHandler {
public:
    void toastActivated() const override {}
    void toastDismissed(WinToastLib::WinToastDismissalReason) const override {}
    void toastFailed() const override {}
};
WinToastLib::WinToastTemplate t(WinToastLib::WinToastTemplate::Text02);
t.setTextField(L"Build complete", WinToastLib::WinToastTemplate::FirstLine);
WinToastLib::WinToast::instance()->showToast(t, new MyHandler());
```

## ThunderbirdToasts native sample
https://github.com/valinet/ThunderbirdToasts/blob/master/src/native-app/thunderbird_toasts/thunderbird_toasts.c  
Brief: Acquire the toast manager activation factory through WinRT APIs.
```cpp
#include <roapi.h>
#include <windows.ui.notifications.h>
using namespace ABI::Windows::UI::Notifications;
HRESULT hr = RoInitialize(RO_INIT_MULTITHREADED);
HSTRING header{};
WindowsCreateStringReference(
    RuntimeClass_Windows_UI_Notifications_ToastNotificationManager,
    (UINT32)wcslen(RuntimeClass_Windows_UI_Notifications_ToastNotificationManager),
    &header);
IToastNotificationManagerStatics* statics = nullptr;
RoGetActivationFactory(header, IID_PPV_ARGS(&statics));
```
