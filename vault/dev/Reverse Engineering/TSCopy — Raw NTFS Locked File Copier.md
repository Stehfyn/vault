<!-- generated-from-dump2 -->
# TSCopy — Raw NTFS Locked File Copier

TSCopy - TrustedSec's utility for copying NTFS files that the OS otherwise won't let you read (locked files like SYSTEM hive, registry hives, `pagefile.sys`, antivirus quarantine stores). Works by opening the volume directly (`\\.\C:`) with `GENERIC_READ` + `FILE_SHARE_*` so you bypass the file-locking layer entirely, walking the NTFS structures (MFT, INDEX_ROOT, DATA attributes - including non-resident runlists) to locate the target file's clusters, and reading those clusters raw. The pattern is exactly what forensics tools (FTK Imager, Velociraptor) use for live acquisition.

```text
# Conceptual usage:
$ tscopy.exe -file C:\Windows\System32\config\SYSTEM -out ./SYSTEM.hive
# Internally:
#   1. Open \\.\C: with raw access.
#   2. Read $MFT -> find the file's record by traversing $INDEX_ROOT.
#   3. Walk the file's $DATA non-resident runlist (offset/length pairs of clusters).
#   4. ReadFile each run into the output buffer.
#   No interaction with the file-system locking layer.
```

## References
- <https://github.com/trustedsec/tscopy>
