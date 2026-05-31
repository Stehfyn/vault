# InteractionContext.h - Pointer/Gesture Interpreter

Interaction Context is the native gesture recognizer underneath the modern pointer stack. You feed it pointer frames, configure manipulations/inertia, and receive callbacks for translation, scale, rotation, tap, and hold without adopting XAML or WinUI.

It is most useful for custom controls, frameless windows, canvases, and Direct2D surfaces that want touchpad/touch semantics but still live in a Win32 message loop. Connect it to `InputEventFlags.h` for raw event classification, `Mouse Input` for HWND coordinate conversion, and `Custom Chrome Sample (NCCALCSIZE)` where draggable non-client regions often collide with gesture handling.

## Source Shape

The API is a bridge: `WM_POINTER*` delivers pointer IDs to the HWND, `GetPointerInfo` expands them, and Interaction Context turns the frames into semantic gestures.

```cpp
case WM_POINTERDOWN:
case WM_POINTERUPDATE:
case WM_POINTERUP: {
    POINTER_INFO info = {};
    if (GetPointerInfo(GET_POINTERID_WPARAM(wParam), &info)) {
        if (msg == WM_POINTERDOWN) {
            AddPointerInteractionContext(context, info.pointerId);
        }
        ProcessPointerFramesInteractionContext(context, 1, 1, &info);
        if (msg == WM_POINTERUP) {
            RemovePointerInteractionContext(context, info.pointerId);
        }
    }
    break;
}
```

Register the callback where the custom control can translate gesture deltas into its own scrolling, zooming, or selection model.

```cpp
INTERACTION_CONTEXT_CONFIGURATION configs[] =
    INTERACTION_CONTEXT_CONFIGURATION_DEFAULT;

SetInteractionConfigurationInteractionContext(context,
    ARRAYSIZE(configs), configs);
RegisterOutputCallbackInteractionContext(context, OnInteractionOutput, hwnd);
```

## References
- `InteractionContext.h`

## Connections
- `Mouse Input.md` covers the classic client-coordinate path this replaces or supplements.
- `InputEventFlags.h - Raw Input Bitfields.md` names the low-level flags you may see before gesture recognition.
- `../Custom Frame/Custom Chrome Sample (NCCALCSIZE).md` is where caption hit testing and gesture handling often collide.
