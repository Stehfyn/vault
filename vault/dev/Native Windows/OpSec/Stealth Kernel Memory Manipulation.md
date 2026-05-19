# Stealth Kernel Memory Manipulation

`DoubleDataPointer` represents another attempt to move memory-manipulation control traffic through a less obvious kernel communication pattern. The project is relevant because anti-cheat and EDR ecosystems increasingly key on conventional device names, IOCTL layouts, and driver-object behavior.

For research, ask what the communication channel hides and what it cannot hide: a driver still loads, kernel code still changes state, client processes still coordinate with it, and memory access still leaves timing and target-process correlations. Connect this to the IOCTL cheat-driver and dxgkrnl-hook entries.

## References
- <https://github.com/Astronaut00/DoubleDataPointer>
