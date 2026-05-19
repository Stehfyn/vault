# dinputd.h

DirectInput device-manager and joystick-configuration interfaces, not the main game-input API. The oddball surface here is `IDirectInputJoyConfig`, which exposes system joystick calibration, type metadata, and remapping state that used to live behind the Game Controllers control-panel applet. It is legacy because XInput, Raw Input, HID, and GameInput now cover nearly every real input path; its remaining value is old game-controller utilities, compatibility layers, and tools that need to understand how DirectInput enumerated pre-XInput devices.

Connections: compare with `Input/InputEventFlags.h -- Raw Input Bitfields.md`, `Input/Mouse Input.md`, and the Game Bar/Xbox entries. DirectInput's abstraction is device-centric; modern Windows input splits keyboard/mouse through window messages or Raw Input, gamepads through XInput/GameInput, and touch through pointer messages.

## References
- dinputd.h
