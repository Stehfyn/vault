<!-- generated-from-dump2 -->
# obs-rs — OBS Frame Capture Plugin (Rust)

Capture game / window frames using OBS Studio's plugin SDK from Rust. Loads as an `.obs-plugin` DLL and exposes captured texture data over a shared-memory IPC interface so a separate Rust consumer process can read frames in real time without an extra encode/decode round-trip. Useful if you want OBS to do the heavy lifting (game-capture hooks, scene composition, virtual-camera output) but you need the *raw frame data* in another process for ML inference, cheat-detection, or live overlays. Niche — most people will reach for the OBS WebSocket plugin or NDI output, but those re-encode or compress. obs-rs gives you the un-encoded GPU texture.

```rust
// Sketch — consumer side reading from shared memory the plugin populates
use shared_memory::ShmemConf;

let shm = ShmemConf::new().os_id("obs-rs-frames").open()?;
let frame_data: &[u8] = unsafe { shm.as_slice() };

// frame_data is BGRA or NV12 depending on plugin config;
// feed to ML model, on-screen overlay, etc.
process_frame(frame_data);
```

## References
- <https://github.com/not-matthias/obs-rs>
