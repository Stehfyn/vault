<!-- generated-from-dump2 -->
# Kernel VGA Framebuffer Drawing Demo

Tutorial WDM driver that maps the legacy VGA/framebuffer region from kernel mode and renders a line directly to it, bypassing GDI. Mostly an academic curiosity for understanding `MmMapIoSpace`, physical memory access, and the historical contiguous VGA buffer at 0xA0000.

```cpp
PHYSICAL_ADDRESS pa; pa.QuadPart = 0xA0000;
PVOID vga = MmMapIoSpace(pa, 64 * 1024, MmNonCached);
if (vga) {
    UCHAR* fb = (UCHAR*)vga;
    for (int x = 0; x < 320; ++x) fb[100 * 320 + x] = 0x0F; // white horizontal line
    MmUnmapIoSpace(vga, 64 * 1024);
}
```

## References
- <https://github.com/azurespheredev/KernelDriver2DrawLine>
