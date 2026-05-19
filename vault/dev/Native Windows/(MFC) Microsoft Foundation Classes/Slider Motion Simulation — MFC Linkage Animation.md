# Slider Motion Simulation - MFC Linkage Animation

Despite the name, this is not a `CSliderCtrl` sample. It is an MFC visualization of a crank-slider linkage: model state advances on timer ticks, the dialog invalidates its client area, and `OnPaint` redraws the mechanism. That makes it a compact example of the traditional MFC animation loop rather than a controls tutorial.

The useful detail is flicker control and ownership of paint. Timer-driven `Invalidate(FALSE)` avoids background erase before repaint; `CPaintDC` scopes `BeginPaint`/`EndPaint`; any serious version should add double buffering when geometry or frame rate grows. Place it near GDI, Direct2D-in-MFC, and Win32xx notes as the baseline "MFC/GDI animation before GPU composition" pattern.

## References
- <https://github.com/DennisLiu1993/Slider_Motion_Simulation_MFC> - MFC crank-slider linkage visualization using timer-driven repaint.
