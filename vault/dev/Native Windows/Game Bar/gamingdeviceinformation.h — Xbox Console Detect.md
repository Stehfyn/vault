# gamingdeviceinformation.h - Xbox Console Detection

`GetGamingDeviceModelInformation` is a small Gaming Runtime probe for distinguishing desktop Windows from Xbox-family hardware at runtime. It matters for codebases that share binaries across PC and console but need different behavior for storage, input assumptions, entitlement flow, or performance defaults.

The header is thin, but it belongs next to `gamingtcui.h` and `xbox-live-api`: device model, Xbox UI affordances, and service identity are usually queried together during startup. Treat it as feature selection, not as a licensing or security boundary.

## References
- `gamingdeviceinformation.h`

## Experiment Harness

Goal: treat device model as feature selection input, not a security boundary.

```cpp
GAMING_DEVICE_MODEL_INFORMATION info{};
HRESULT hr = GetGamingDeviceModelInformation(&info);
printf("hr=%08lx vendor=%u device=%u model=%u\n",
       hr, info.vendorId, info.deviceId, info.deviceModel);
```

Measured signal: HRESULT and model fields on PC versus Xbox-family target.

Failure interpretation: unsupported API or desktop result should fall back to PC defaults; do not infer entitlement or user identity from this probe.
