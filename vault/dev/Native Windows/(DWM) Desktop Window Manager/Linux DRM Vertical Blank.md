# Linux DRM Vertical Blank

Kernel documentation (Linux 3.16 era, but still substantively current) for how the DRM subsystem manages vertical-blank interrupts on display controllers. Useful as the Linux-side counterpart to Windows' `D3DKMTWaitForVerticalBlankEvent` / `IDXGIOutput::WaitForVBlank` (see `VBlank Wait.md`) — both kernels solve the same problem (efficiently letting one or many clients block until the next scanout-completion event) but the ABIs differ a lot.

The interesting design choice in Linux DRM is **reference-counted interrupts**: the vblank IRQ is *not* always enabled. Clients call `drm_vblank_get(dev, crtc)` to bump a refcount, which forces the driver to call its `enable_vblank` hook and program the hardware to fire IRQs. When the last client calls `drm_vblank_put`, a 5-second timer (`drm.vblankoffdelay`) arms; if no one re-grabs the vblank by then, the IRQ is turned back off via `disable_vblank`. The 5-second hysteresis avoids thrashing the hardware when GL apps repeatedly grab/release between swaps.

The driver writes very little vblank code itself — only three callbacks (`enable_vblank`, `disable_vblank`, `get_vblank_counter`) and a single `drm_handle_vblank(dev, crtc)` call from the IRQ handler. The DRM core does the rest: hands out monotonic per-CRTC vblank counts (`drm_vblank_count`, `drm_vblank_count_and_time`) using a 64-bit accumulator that wraps cleanly past the hardware register's 16- or 32-bit width, dispatches `DRM_IOCTL_WAIT_VBLANK` ioctls and `drmGetVBlank` events to user-space, and races against `drm_vblank_pre_modeset`/`post_modeset` so a modeset doesn't corrupt the counter.

Counter race story (the load-bearing detail): the kernel reads the hardware counter, then takes a timestamp, then re-reads the counter; if the second read advanced, the timestamp belongs to the new frame, not the old one. This three-step pattern is what guarantees `(count, timestamp)` pairs returned to user-space are consistent and not from a half-finished refresh.

For Windows comparisons, map this to `VBlank Wait.md` for the raw wait, `DCompositionWaitForCompositorClock — Decompiled.md` for compositor-clock waiting, and `Lagless VSYNC ON via Beam Racing.md` for the extreme case where even one queued refresh is too much latency.

User-space (Mesa, Xorg, Wayland compositors) consumes vblank in three modes:

1. **Blocking wait** — `DRM_IOCTL_WAIT_VBLANK` with `_DRM_VBLANK_RELATIVE` or `_DRM_VBLANK_ABSOLUTE`. Used by GLX/EGL `swapInterval`.
2. **Event delivery** — same ioctl with `_DRM_VBLANK_EVENT`, plus reading the DRM fd; user-space gets a packet on the fd with the count and microsecond timestamp.
3. **Page-flip ioctl** — `DRM_IOCTL_MODE_PAGE_FLIP` with `DRM_MODE_PAGE_FLIP_EVENT`, the modern Wayland path; the kernel both schedules the buffer swap *at* the next vblank and delivers the completion event in one shot. This is the lowest-latency option.

```c
/* User-space: block until next vblank on CRTC 0, then read counter + time. */
#include <xf86drm.h>

drmVBlank vbl = {
    .request = {
        .type     = DRM_VBLANK_RELATIVE,
        .sequence = 1,           /* "1 vblank from now" */
    },
};
drmWaitVBlank(drm_fd, &vbl);     /* blocks; returns updated sequence + tval */
printf("count=%u  t=%ld.%06ld\n",
       vbl.reply.sequence, vbl.reply.tval_sec, vbl.reply.tval_usec);

/* Or non-blocking with an event: ask for the count, get poll()ed back later. */
drmVBlank evt = {
    .request = {
        .type     = DRM_VBLANK_RELATIVE | DRM_VBLANK_EVENT,
        .sequence = 1,
        .signal   = (unsigned long)user_cookie,
    },
};
drmWaitVBlank(drm_fd, &evt);     /* returns immediately */
/* poll(drm_fd) ... then drmHandleEvent(drm_fd, &ctx) dispatches the callback. */

/* Driver side (illustrative): the three callbacks the DRM core needs. */
static int my_enable_vblank(struct drm_device *dev, unsigned int crtc) {
    /* Unmask the vblank IRQ in the display engine. */
    DISPLAY_REG_WRITE(IMR, DISPLAY_REG_READ(IMR) & ~VBLANK_IRQ_BIT);
    return 0;
}
static void my_disable_vblank(struct drm_device *dev, unsigned int crtc) {
    DISPLAY_REG_WRITE(IMR, DISPLAY_REG_READ(IMR) | VBLANK_IRQ_BIT);
}
static u32 my_get_vblank_counter(struct drm_device *dev, unsigned int crtc) {
    return DISPLAY_REG_READ(FRAME_COUNT); /* 16/32-bit hw counter, core extends to 64 */
}

static irqreturn_t my_irq(int irq, void *arg) {
    struct drm_device *dev = arg;
    if (status & VBLANK_IRQ_BIT) {
        drm_handle_vblank(dev, /*crtc*/0);  /* core does the rest */
        ack_irq(VBLANK_IRQ_BIT);
    }
    return IRQ_HANDLED;
}
```

Cross-platform comparison worth keeping in mind:

| OS | Wait API | Event API | Counter |
|----|----------|-----------|---------|
| Linux DRM | `DRM_IOCTL_WAIT_VBLANK` | `_DRM_VBLANK_EVENT` + read fd | `drm_vblank_count*` |
| Windows DXGI | `IDXGIOutput::WaitForVBlank` | `IDXGISwapChain::Present(1, ...)` | `DXGI_FRAME_STATISTICS::PresentCount` |
| Windows DXGK (kernel) | `D3DKMTWaitForVerticalBlankEvent` | callback on `KEVENT` | `D3DKMTGetScanLine` |
| Windows DWM | `DwmGetCompositionTimingInfo` | `DwmFlush` | `DWM_TIMING_INFO::cRefresh` |

## References
- <http://www.chiark.greenend.org.uk/doc/linux-doc-3.16/html/drm/drm-vertical-blank.html>
- <https://www.kernel.org/doc/html/latest/gpu/drm-kms.html#vertical-blanking> (current upstream equivalent)
- See also: `VBlank Wait.md`, `Lagless VSYNC ON via Beam Racing.md`
