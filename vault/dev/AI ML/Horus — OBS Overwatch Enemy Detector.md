<!-- generated-from-dump2 -->
# Horus — OBS Overwatch Enemy Detector

OBS plugin that detects enemy player silhouettes in Overwatch frames using OpenCV + CUDA, intended for VOD review / highlight extraction. Pipeline: grab the OBS source frame in BGRA, upload to GPU, run a tuned color/edge classifier against Overwatch's red-outline enemy shader, and write detected ROIs back to the host. Notable for being one of the cleaner OBS C++ plugins to read end-to-end.

```cpp
// OBS plugin entry -- register the filter source.
struct horus_source { /* OpenCV / CUDA state, model handles, etc. */ };
static obs_source_info horus_filter = {
    .id           = "horus_enemy_detect",
    .type         = OBS_SOURCE_TYPE_FILTER,
    .output_flags = OBS_SOURCE_VIDEO,
    .get_name     = [](void*){ return "Horus Enemy Detector"; },
    .create       = horus_create,
    .destroy      = horus_destroy,
    .filter_video = horus_filter_video,   // processes each frame
};
OBS_DECLARE_MODULE()
bool obs_module_load() { obs_register_source(&horus_filter); return true; }
```

## References
- <https://github.com/qis/horus>
