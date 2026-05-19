# ColorAdjustLuma (HLS Luminance Helper)

`ColorAdjustLuma` is a small Shell helper for adjusting a `COLORREF` through HLS luminance rather than naive RGB channel addition. It is useful in old owner-drawn controls, classic theme code, and shell-extension UI where a highlight/shadow color must stay perceptually related to the system color.

The helper belongs with custom-frame and visual-style notes because it shows the pre-Fluent era of Windows theming: lots of native UI code derived secondary colors from `GetSysColor` rather than owning a full design-token system. Use it for compatibility reading, not as a modern color-science recommendation.

## References
- `ColorAdjustLuma()`
