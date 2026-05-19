<!-- generated-from-dump2 -->
# cbyge — Cync Smart Bulb Go Client

Reverse-engineered Go client for "Cync" (formerly "C by GE") Wi-Fi smart bulbs and plugs. Talks the proprietary TCP protocol to GE's cloud directly — no Alexa/HomeKit shim — so you can script color/brightness/scene changes locally. Also documents the protocol in `protocol.md` for anyone porting to ESPHome/Home Assistant.

```go
import "github.com/unixpickle/cbyge"

s, _ := cbyge.NewSession("user@example.com", "password")
devs, _ := s.Devices()
for _, d := range devs {
    s.SetDeviceStatus(d, true)               // on
    s.SetDeviceLum(d, 80)                    // 80% brightness
    s.SetDeviceRGB(d, 255, 64, 0)            // orange
}
```

## References
- <https://github.com/unixpickle/cbyge>
