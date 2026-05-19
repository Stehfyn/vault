# WoW64Injection - 64-bit Into 32-bit Process

WoW64Injection is notable because cross-architecture process work is not just pointer-size inconvenience. WoW64 has a 32-bit user-mode view, a 64-bit native layer, separate loader/module assumptions, thunking boundaries, and different register/context handling. Techniques that are straightforward within one architecture often fail at the WoW64 boundary.

The defensive/research value is understanding artifact ambiguity. A 32-bit process can contain 32-bit modules while also executing through 64-bit transition machinery; tools that inspect only one view can miss state. This connects PE architecture flags, PEB/TEB variants, thread contexts, and loader lists.

## Connections
- `WOW Message Dispatching` is the USER32-side historical compatibility analogue.
- phnt and System Informer are better references for inspecting both native and WoW64 process views.

## References
- <https://github.com/Flawww/WoW64Injection>
