# Cheat Driver (IOCTL Memory R/W)

This is the canonical shape of a kernel assist driver used by game cheats: user mode opens a device object, sends IOCTLs describing a target process/address/range, and the driver performs memory operations the user-mode process could not safely or lawfully do by handle alone. The same architecture appears in many public "learning" drivers.

The defensive lesson is the interface boundary. The driver object name, symbolic link, IOCTL codes, handle-opening process, and target-process access patterns are all observable. Modern variants try to hide or piggyback on vulnerable signed drivers, which connects this entry to `GDRV Loader`, `PPL Killer`, `PreviousMode Flip Memory R W`, and `User-Mode Physical Memory Library`.

## References
- <https://github.com/nkga/cheat-driver>
