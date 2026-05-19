# Metro-style App Activation

The gist demonstrates `IApplicationActivationManager`, the COM API desktop code can use to launch packaged Store/UWP apps by AppUserModelID. This is a pre-Windows-App-SDK view of app activation: the caller is a classic COM client, the target is a package identity, and the result is a process id plus whatever activation contract the target app implements.

This belongs with shell/app-lifecycle notes because it explains why launching a packaged app is not equivalent to `CreateProcess`. The identity, activation kind, protocol/file arguments, and brokered lifecycle are owned by the app model; desktop code only asks the activation manager to perform the launch.

## References
- <https://gist.github.com/fincs/2732608> - compact sample of `IApplicationActivationManager::ActivateApplication` from desktop code.
