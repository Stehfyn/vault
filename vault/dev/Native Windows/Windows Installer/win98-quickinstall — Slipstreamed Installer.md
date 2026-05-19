# win98-quickinstall — Slipstreamed Win98 Installer

`win98-quickinstall` is outside modern MSI/MSIX thinking, but useful for understanding older Windows setup at the bytes-on-disk level. It bootstraps through DOS media, lays down a prepared Windows 98 filesystem, unpacks cabinet payloads, and relies on first-boot hardware detection rather than a transactional installer database.

The entry belongs here as contrast. Win9x installation is closer to image deployment plus registry hive seeding than to Windows Installer component management. That context helps explain why older setup archives, LZ/CAB files, INF scripts, and registry templates still appear in native Windows maintenance work.

## Connections
- `lzexpand.h` and `Cabinet Files (FDI)` cover the payload formats that old setup media used.
- `SetupAPI.h` is the NT-line descendant for device/INF installation, with a much stricter driver-store and signing model.

## References
- <https://github.com/oerg866/win98-quickinstall>
