# Dxgkrnl Syscall Hook Driver

`NullHook` represents a class of game-cheat drivers that abuse graphics-kernel call paths as a command channel for memory access or overlay drawing. The concrete hook target matters less than the design pattern: a user-mode client talks through an unusual kernel surface instead of a conventional named device interface.

Defensive analysis should focus on modified executable sections, unexpected graphics-kernel dispatch changes, suspicious client call frequency, and overlap with overlay/ESP behavior. Keep this connected to `Cheat Driver (IOCTL Memory R W)` and the DWM/graphics overlay notes: both are attempts to move cheat state across the user/kernel/display boundary.

## References
- <https://github.com/NullTerminatorr/NullHook>
