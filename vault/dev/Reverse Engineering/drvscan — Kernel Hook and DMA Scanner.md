<!-- generated-from-dump2 -->
# drvscan — Kernel Hook and DMA Scanner

Integrity scanner targeted at hunting kernel-mode hooks, hidden drivers, and PCIe DMA-attack devices. Three notable checks: (1) walks the PCI config space looking for cards whose vendor/device ID combos match known DMA-attack hardware (Screamer, FPGA dev boards used by cheaters), (2) compares loaded kernel module code pages against the on-disk image to find inline patches, (3) compares per-process IAT / EAT against image-on-disk to detect user-mode hooks. The DMA-board detection is the unusual capability — most "anti-cheat" code doesn't try to enumerate the PCI bus from user mode at all. The project demonstrates both how to do that read and how cheating ecosystems work around it.

```text
# Conceptual scans:
#   1. PCI scan: read PCI config space via a signed driver (or HwReadPciConfigDword)
#      and flag (vendor, device) tuples on a blocklist of DMA boards.
#   2. Kernel module integrity: enumerate PsLoadedModuleList, compare .text pages
#      vs same offsets in the on-disk PE (CRC over executable sections).
#   3. User-mode integrity: iterate process modules, walk IAT entries, verify each
#      thunk still points at the expected exported function in the target module.
#
# Usage (driver loaded, then user-mode scanner):
#   > drvscan.exe --pci
#   > drvscan.exe --kdrv
#   > drvscan.exe --pid 1234
```

## References
- <https://github.com/ekknod/drvscan>
