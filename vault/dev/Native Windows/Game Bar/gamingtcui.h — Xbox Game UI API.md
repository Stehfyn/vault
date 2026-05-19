# gamingtcui.h - Xbox Game UI API

`gamingtcui.h` exposes Xbox title-callable UI entry points such as profile cards, friends UI, and related account/social overlays. It is a shell-owned user experience surface: the title requests a task, the platform owns the modal UI, account context, and policy checks.

This is the UI counterpart to `xbox-live-api`. Use the service bindings when you need data, and the TCUI functions when the correct result is to hand the user to a trusted Xbox experience rather than recreating it inside a Win32 or Game Bar widget.

## References
- `gamingtcui.h`
