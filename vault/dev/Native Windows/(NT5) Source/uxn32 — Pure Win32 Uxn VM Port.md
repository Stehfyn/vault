# uxn32 - Pure Win32 Uxn VM Port

`uxn32` is a useful small specimen of "raw Win32 as a multimedia runtime": create a window, keep a framebuffer, paint with GDI/DIB operations, read keyboard and character messages, drive time with the message system, and use WinMM-style audio rather than a cross-platform toolkit. Its value is the absence of framework abstraction.

The note belongs near message-queue and NTUSER material because a tiny emulator still has to respect the same old contracts: the render surface is invalidated and repainted through window messages, keyboard input splits between virtual-key and character translation, and timer-driven work competes with the pump. It is a practical companion to `dtc`, which asks what happens when rendering should not stall inside modal USER32 loops.

## Connections
- `System-Defined Messages` explains the keyboard, paint, timer, and close traffic such an app handles.
- `Caption Rendering` and `System Command Processing` define the default top-level window behavior around the emulator surface.

## References
- <https://github.com/randrew/uxn32>
