# InputEventFlags.h - Raw Input Bitfields

`InputEventFlags.h` is a low-level constants header for classifying keyboard, mouse, pen, and pointer event flags as they travel through the raw-input/HID path. The value is not in a public helper API; it is in naming the bits you see when inspecting input traces, brokered pointer stacks, or compatibility shims.

Use it beside `Mouse Input` and `InteractionContext.h`: raw flags describe device facts, mouse/window messages describe the classic HWND contract, and Interaction Context turns pointer streams into gestures and inertia.

## Source Shape

Read these constants as trace labels, not as a replacement input API. They become useful when a log or reverse-engineered header exposes packed event state.

```cpp
struct InputTraceEvent {
    UINT32 device_type;   // keyboard, mouse, pointer, pen
    UINT32 message;       // WM_INPUT, WM_POINTERUPDATE, translated mouse message
    UINT32 flags;         // bitfield named by InputEventFlags.h
    UINT32 raw_code;      // scan code, button code, pointer id, or HID usage
};

if (event.flags & INPUT_FLAG_INJECTED) {
    MarkAsSynthetic(event);
}
```

## References
- `InputEventFlags.h`

## Connections
- `Mouse Input.md` is the higher-level HWND message contract after translation.
- `InteractionContext.h - Pointer Gesture Interpreter.md` consumes pointer facts and emits gestures.
- `../Hooks/Hook Examples.md` is the route when the flags are observed through injected or hooked instrumentation.
