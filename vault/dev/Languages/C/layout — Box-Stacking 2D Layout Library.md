<!-- generated-from-dump2 -->
# layout — Box-Stacking 2D Layout Library

Single-file C99/C++ library for box-stacking 2D layout: build a tree of boxes with `LAY_HFILL`/`LAY_VFILL`/`LAY_TOP`/etc flags, call `lay_run_context`, and read back the computed positions/sizes. Roughly Yoga / oui-blendish in functionality but ~1000 lines, no dependencies. Useful when you have an immediate-mode UI (Nuklear, microui) and need real layout instead of manual cursor math.

```c
lay_context ctx;
lay_init_context(&ctx);
lay_reserve_items_capacity(&ctx, 1024);

lay_id root = lay_item(&ctx);
lay_set_size_xy(&ctx, root, 800, 600);
lay_set_contain(&ctx, root, LAY_ROW);

lay_id a = lay_item(&ctx);
lay_set_size_xy(&ctx, a, 200, 0);
lay_set_behave(&ctx, a, LAY_VFILL);
lay_insert(&ctx, root, a);

lay_run_context(&ctx);
lay_vec4 r = lay_get_rect(&ctx, a);  // x,y,w,h
```

## References
- <https://github.com/randrew/layout>
