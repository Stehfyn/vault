# IddSampleDriver - Virtual Monitor Driver (Win10)

Microsoft's indirect display driver model lets a UMDF driver publish a synthetic monitor without pretending to be a full WDDM display miniport. `roshkins/IddSampleDriver` is a forkable sample of that model: it creates an indirect display adapter, reports monitor modes, and accepts desktop frames that can be consumed by VR, capture, or remote-desktop software. The important part is not `DriverEntry`; it is the IDDCX handshake among adapter initialization, monitor arrival, mode enumeration, and swap-chain assignment.

Use this as a virtual-monitor starting point, not as a display-control utility. Installation, signing, device identity, and frame transport are the hard parts once the sample works. For user-mode layout changes after the virtual monitor appears, the relevant APIs are still `QueryDisplayConfig` and `SetDisplayConfig` from `Examples.md`.

## References
- <https://github.com/roshkins/IddSampleDriver> - Win10-oriented IDD sample used by desktop sharing and VR workflows.
