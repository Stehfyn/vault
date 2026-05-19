# perfect-loader - LdrLoadDll Spoofing

perfect-loader is interesting because it tries to keep the official loader in the loop while changing what the loader maps. That is the opposite end of the spectrum from crude manual mapping: rather than reimplement every loader responsibility, it manipulates the inputs so `LdrLoadDll` still performs initialization, loader-list participation, import handling, and other normal side effects.

The research lesson is that "loaded by the loader" and "loaded from the expected file" are separate claims. Defensive analysis has to compare path identity, section object provenance, image bytes, loader metadata, and telemetry rather than trusting any one indicator. This note connects PE loader internals to ETW image-load and memory-forensics checks.

## Connections
- `Proxy-DLL-Loads` maps images through native section calls with a different relationship to loader metadata.
- `In-Memory Module Loading` and manual-map notes show what happens when the official loader is bypassed instead.

## References
- <https://github.com/EvanMcBroom/perfect-loader>
