# vdproj2wix — VS Installer to WiX Converter

`vdproj2wix` converts deprecated Visual Studio Installer `.vdproj` projects into WiX source. The useful part is not perfect translation; it is extracting installer intent from a brittle project format: files, registry values, shortcuts, custom actions, and component-ish groupings.

Treat the output as a migration scaffold. WiX requires explicit component identity, key paths, upgrade codes, sequencing, and ICE-clean table relationships that `.vdproj` often hid or modeled poorly. The converter saves archaeology time; it does not absolve you from rebuilding the MSI component model.

## Connections
- `MsiQuery.h` is useful after conversion to inspect the generated MSI tables.
- `MSI Search Conditions` and `Registry Setup (RegInstallW)` are common areas where legacy installer projects need hand correction.

## References
- <https://github.com/chrisoldwood/vdproj2wix>
