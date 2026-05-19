# Graphics Programming Notes

This is a small holding note for graphics references that do not deserve their own Native Windows page yet. Keep only links with an actionable technical reason: a profiling visualization concept, a shader technique, or a rendering/debugging trick that connects to Win32 graphics work.

Brendan Gregg's flamegraph comparison matters for Windows because ETW/WPA traces still need a readable aggregation form; flamegraphs answer "where did sampled CPU time go" more directly than treemaps or sunbursts. The Game Boy palette shader link is useful as a compact example of palette quantization, which connects to DIB/GDI/software-rendering notes even when implemented in HLSL.

Code contribution: map flamegraph output to ETW stack samples, and map the palette shader to `Texture2D`, lookup-table quantization, and indexed-color/DIB palette thinking.

## References
- <https://www.brendangregg.com/blog/2017-02-06/flamegraphs-vs-treemaps-vs-sunburst.html>
- <https://blog.otterstack.com/posts/202512-gbshader/>
