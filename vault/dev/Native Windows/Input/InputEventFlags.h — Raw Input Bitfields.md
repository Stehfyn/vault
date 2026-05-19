# InputEventFlags.h - Raw Input Bitfields

`InputEventFlags.h` is a low-level constants header for classifying keyboard, mouse, pen, and pointer event flags as they travel through the raw-input/HID path. The value is not in a public helper API; it is in naming the bits you see when inspecting input traces, brokered pointer stacks, or compatibility shims.

Use it beside `Mouse Input` and `InteractionContext.h`: raw flags describe device facts, mouse/window messages describe the classic HWND contract, and Interaction Context turns pointer streams into gestures and inertia.

## References
- `InputEventFlags.h`
