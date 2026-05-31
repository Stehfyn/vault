# gamingtcui.h - Xbox Game UI API

`gamingtcui.h` exposes Xbox title-callable UI entry points such as profile cards, friends UI, and related account/social overlays. It is a shell-owned user experience surface: the title requests a task, the platform owns the modal UI, account context, and policy checks.

This is the UI counterpart to `xbox-live-api`. Use the service bindings when you need data, and the TCUI functions when the correct result is to hand the user to a trusted Xbox experience rather than recreating it inside a Win32 or Game Bar widget.

## References
- `gamingtcui.h`

## Experiment Harness

Goal: confirm when the platform accepts ownership of trusted Xbox UI.

Probe shape:

```cpp
auto start = GetTickCount64();
HRESULT hr = ShowProfileCardUI(/* user/account target */);
printf("tcui=%08lx elapsed=%llu\n", hr, GetTickCount64() - start);
```

Measured signal: HRESULT, elapsed time until callback/completion, foreground/focus transition, account state.

Failure interpretation: failures usually mean missing Xbox services/account context/title identity, not a rendering bug in the caller.
