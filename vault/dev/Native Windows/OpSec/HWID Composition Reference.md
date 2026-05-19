# HWID Composition Reference

`hwidinfo` is a compact reference for the machine identifiers anti-cheat, licensing, and inventory systems commonly combine: SMBIOS UUIDs, baseboard and disk serials, CPU data, MAC addresses, and Windows install identifiers. Its value is showing that "HWID" is rarely one value.

For defensive or privacy review, the useful question is which identifiers are stable, spoofable, privileged, virtualized, or likely to collide. This connects directly to WMI usage, registry inventory, and OpSec discussions about why partial spoofing often fails: changing one layer leaves correlating identifiers behind.

## References
- <https://github.com/ReFo0/hwidinfo>
