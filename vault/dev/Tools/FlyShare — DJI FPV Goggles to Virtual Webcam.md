<!-- generated-from-dump2 -->
# FlyShare — DJI FPV Goggles to Virtual Webcam

Bridges the DJI FPV Goggles V1/V2 (which expose a UVC-style USB video feed only on Windows after the right driver dance) into Discord/Teams/Zoom by appearing as a normal webcam. The annoying-thing-it-solves: the goggles' raw feed has wrong aspect, wrong refresh, and the audio channel is on a separate USB device — FlyShare composites them, rescales, and routes everything through OBS's virtual camera so the conferencing app just sees a 1080p webcam. Built to let drone pilots have spectators on a call without raw screen-sharing the entire desktop.

```text
# Setup flow (per README):
#   1. Install DJI Assistant 2 and the goggles' USB UVC driver.
#   2. Install OBS + obs-virtualcam.
#   3. Run FlyShare; pick the goggles' UVC source and the audio mic device.
#   4. In Discord/Zoom, select "OBS Virtual Camera" as the webcam.
```

## References
- <https://github.com/DuckieOnQuacks/FlyShare>
