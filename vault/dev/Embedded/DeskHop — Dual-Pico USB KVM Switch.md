<!-- generated-from-dump2 -->
# DeskHop — Dual-Pico USB KVM Switch

Hardware KVM-style mouse/keyboard switcher built on two Raspberry Pi Pico boards: one Pico is wired between your keyboard+mouse and "Computer A" via USB; the second Pico is between the same input devices and "Computer B." The two Picos talk over a UART link. Move the mouse to the edge of Computer A's screen and the firmware seamlessly hands off the HID stream to Computer B — same input devices, two hosts, zero software install on either computer. The clever-ish bit is the latency budget: the Pico's USB stack is RP2040 PIO-driven, so the switch is sub-frame, and because both hosts see a real USB HID device (not a network share), it works in BIOS, Linux installers, anywhere a real KB/mouse works. Mostly C; reasonable read for RP2040 USB stack and dual-board pairing over UART.

```text
# Logical architecture:
#
#   Keyboard ──┐                           ┌── Computer A (USB host)
#              ├─→ Pico A  ──UART──→  Pico B ──┤
#   Mouse    ──┘    │              │           └── Computer B (USB host)
#                   ▼              ▼
#                edge-of-screen detection in firmware:
#                  if (mouse_x_cumulative > screen_width) -> switch_active = B
#                  forward HID reports to the *active* host only.
#
# Hand-off semantics: the inactive host sees the keyboard/mouse "disconnect"
# at HID-report level (no movement, all keys up) so it never gets stuck keys.
```

## References
- <https://github.com/hrvach/deskhop>
