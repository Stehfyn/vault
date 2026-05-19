# NT User Message Definitions

The NTUSER `messages.h` file is useful because it shows the internal message vocabulary that sits beneath public `WM_*` documentation. Public message ranges, control-private `WM_USER` traffic, shell/window-manager notifications, and user/kernel coordination all share the same numeric transport, so range discipline is not cosmetic.

The concrete takeaway is to treat message numbers as scoped contracts. `WM_USER` belongs to a window class or common-control implementation, `WM_APP` belongs to the application, and registered messages belong to cross-component rendezvous. NTUSER's private definitions explain why sloppy constants can collide with controls or future system behavior even when the app appears to work.

## Connections
- `System-Defined Messages` covers the public classification.
- `Message Queue Implementation` shows how those numbers move through a thread queue.

## References
- https://github.com/tongzx/nt5src/blob/master/Source/XPSP1/NT/windows/core/ntuser/inc/messages.h
