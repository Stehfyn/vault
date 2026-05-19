# InteractionContext.h - Pointer/Gesture Interpreter

Interaction Context is the native gesture recognizer underneath the modern pointer stack. You feed it pointer frames, configure manipulations/inertia, and receive callbacks for translation, scale, rotation, tap, and hold without adopting XAML or WinUI.

It is most useful for custom controls, frameless windows, canvases, and Direct2D surfaces that want touchpad/touch semantics but still live in a Win32 message loop. Connect it to `InputEventFlags.h` for raw event classification, `Mouse Input` for HWND coordinate conversion, and `Custom Chrome Sample (NCCALCSIZE)` where draggable non-client regions often collide with gesture handling.

## References
- `InteractionContext.h`
