# JUCE Direct2D Backend Discussion

The JUCE thread is valuable because it shows Direct2D integration pain in a mature cross-platform UI toolkit: device-context creation, swap-chain ownership, fallback behavior, text rendering differences, and when D2D acceleration helps or hurts. That is more instructive than another rectangle sample because UI frameworks already have invalidation, clipping, transforms, and font abstractions that do not map cleanly onto D2D.

Read it with the Direct2D and DirectWrite notes. The core question is not "can D2D draw this?" but whether the backend can preserve JUCE semantics while handling `D2DERR_RECREATE_TARGET`, DPI changes, and DirectWrite metric differences.

## Discussion Claim To Verify

The thread makes three falsifiable performance claims: Direct2D can hit high refresh rates when the backend paints from a presentation thread, per-frame `Path` to D2D `Geometry` conversion is expensive, and update-region mistakes can erase the benefit by repainting too much. It also asserts DirectWrite UTF-8 to UTF-16 conversion is probably not the main text bottleneck compared with reusable text layouts.

Probe shape for a JUCE-like renderer:

```cpp
struct DrawStats {
    uint64_t path_to_geometry_us;
    uint64_t create_brush_us;
    uint64_t draw_us;
    uint64_t present_us;
    uint64_t dirty_area_px;
    uint32_t geometries_reused;
    uint32_t text_layouts_reused;
};

// Variant A: create ID2D1Geometry/IDWriteTextLayout every paint.
// Variant B: retain geometry/text layouts until path/text changes.
// Variant C: repaint full window.
// Variant D: repaint only update region.
```

Use ETW providers for Direct2D/DirectWrite/DXGI plus app-side QPC spans around `CreatePathGeometry`, `CreateGeometrySink`, `IDWriteFactory::CreateTextLayout`, `BeginDraw`, `EndDraw`, and `Present`. The claim is confirmed only if retained geometry/text layout reduces CPU time and GPU stalls for the same dirty region. It is nullified if `EndDraw`/`Present` stalls dominate even after allocations are eliminated, in which case the problem is synchronization, batching, or GPU queue pressure rather than JUCE object churn.

The thread's strongest code-driving claim is the command-list handoff: build D2D command lists on the message thread, then let a presentation thread wait inside `Present` so the UI pump does not become the vblank waiter. That should be verified independently from geometry caching and update-region fixes.

```cpp
// Message/UI thread.
auto dirty = GetUpdateRegion();
auto cmd = BuildD2DCommandList(dirty, retained_geometry_cache, text_layout_cache);
present_queue.push({ dirty, cmd, qpc_now() });

// Presentation thread.
for (;;) {
    auto work = present_queue.pop_latest_or_wait();
    dc->BeginDraw();
    dc->DrawImage(work.command_list.Get());
    hr_end = dc->EndDraw();
    qpc_before_present = qpc_now();
    hr_present = swap_chain->Present(1, 0);
    log(work.dirty_area_px, hr_end, hr_present, qpc_now() - qpc_before_present);
}
```

Interpretation: if the UI thread remains responsive while the presentation thread blocks in `Present`, the thread split confirms the discussion's architectural claim. If jank remains but dirty-area pixels and geometry creation time drop, inspect GPU stalls and swap-chain wait behavior. If the dirty region is wrong, any Direct2D acceleration result is meaningless because the renderer is benchmarking unnecessary pixels.

## References
- <https://forum.juce.com/t/direct2d-part-deux-2-direct-2-furious/56359>
