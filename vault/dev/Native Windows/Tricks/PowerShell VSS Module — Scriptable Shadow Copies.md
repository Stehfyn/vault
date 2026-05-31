# PowerShell VSS Module - Scriptable Shadow Copies

This module wraps Volume Shadow Copy Service operations in PowerShell so administrators can create, expose, inspect, and remove snapshots without fighting `vssadmin` or writing COM requester code. It is useful as an operations reference for consistent point-in-time reads of otherwise live files.

The distinction from AlphaVSS is audience: this is scriptable maintenance and backup glue, while AlphaVSS is an application library. Both belong with file-copy and backup notes because VSS changes the problem from "copy bytes now" to "coordinate writers, freeze state, then copy a stable view."

Operational shape to keep explicit:

```text
create snapshot set
  -> expose snapshot path or drive alias
  -> copy from stable view
  -> remove exposure
  -> delete snapshot when retention policy says so
```

Cross-reference this with OpSec notes only at the telemetry level: snapshot creation, exposure path, caller identity, targeted volumes, and whether activity matches known backup windows. Do not collapse legitimate backup requesters and suspicious shadow-copy access into one bucket.

## Source Code Reading

The linked `albertony/vss` repository carries a native `vshadow` requester that is useful even when the operational path is PowerShell. It shows the lifecycle a script should expose instead of hiding under one "snapshot" verb.

`vshadow/cpp/create.cpp`:

```text
VssClient::CreateSnapshotSet(...)
  -> GatherWriterMetadata()
  -> SelectComponentsForBackup(...)
  -> StartSnapshotSet(&m_latestSnapshotSetID)
  -> AddToSnapshotSet(volumeList)
  -> PrepareForBackup()
  -> DoSnapshotSet()
  -> SaveBackupComponentsDocument(...)
  -> QuerySnapshotSet(m_latestSnapshotSetID)
```

`VssClient::AddToSnapshotSet` loops volumes, calls `m_pVssObject->AddToSnapshotSet(volume, GUID_NULL, &SnapshotID)`, and records every snapshot ID for later script generation/cleanup. A snapshot set and each volume snapshot have different IDs; scripts should log both.

`vshadow/cpp/expose.cpp` is the body behind "expose snapshot." `ExposeSnapshotLocally` calls `GetSnapshotProperties`, rejects unsupported/existing exposure cases, checks drive-letter reuse with `QueryDosDeviceW`, validates that a mount directory exists and is empty with `GetFileAttributes`/`FindFirstFile`, and only then calls `ExposeSnapshot(... VSS_VOLSNAP_ATTR_EXPOSED_LOCALLY ...)`.

Verifiable assertions to drive:

```text
claim: exposure has preconditions independent of VSS success
probe: try an already-used drive letter and an empty directory; compare failure location

claim: cleanup can be proven
probe: log snapshot GUID, expose path, unexpose/delete result, and before/after `vssadmin list shadows`

claim: writer coordination is observable
probe: save VSS/VolSnap event-log rows around `PrepareForBackup` and `DoSnapshotSet`
```

Source files read:
- `vss/vshadow/cpp/create.cpp`
- `vss/vshadow/cpp/expose.cpp`
- `vss/vshadow/cpp/delete.cpp`
- `vss/vshadow/cpp/query.cpp`

## Experiment Harness

Goal: script the same requester lifecycle and verify cleanup through first-party tools.

Procedure:

```powershell
vssadmin list writers
vssadmin list providers
vssadmin list shadows

# Module-specific cmdlets vary; keep the invariant lifecycle:
# New snapshot -> expose/query -> read one known file -> unexpose -> delete.

vssadmin list shadows
Get-WinEvent -LogName Application |
  Where-Object ProviderName -match 'VSS|VolSnap' |
  Select-Object -First 20 TimeCreated, ProviderName, Id, LevelDisplayName, Message
```

Signals to record: command transcript, snapshot count before/after, target volume, exposure path, file-read proof from the snapshot namespace, event IDs/messages, cleanup result, and elapsed time between create and delete. Expected baseline: a clean harness leaves no extra exposed path and no unexpected persistent snapshots. If writers remain failed after the test, the result is an environmental VSS health issue until proven otherwise.

## Discussion Claim Verification

Claim: "The PowerShell module proves scriptable shadow-copy operations."

Why it matters for new diagnostic code: the linked native requester proves the VSS lifecycle, not a particular PowerShell cmdlet contract. New tooling should preserve the lifecycle explicitly: create, expose/query, read, unexpose, delete, verify.

How to verify:
1. Record `vssadmin list shadows`, `vssadmin list writers`, and Application log VSS/VolSnap rows before the script.
2. Create one snapshot of a test volume.
3. Expose it to a temporary mount path or drive letter.
4. Read a known file through the snapshot path.
5. Remove exposure and delete the snapshot.
6. Re-run `vssadmin list shadows` and event-log query.

Minimal code/pseudocode:

```powershell
$before = vssadmin list shadows
$writers = vssadmin list writers

# module-specific command names belong here:
# New-ShadowCopy C: -> $snapshot
# Mount-ShadowCopy $snapshot C:\ShadowProbe
# Get-Content C:\ShadowProbe\known.txt
# Dismount-ShadowCopy $snapshot
# Remove-ShadowCopy $snapshot

$after = vssadmin list shadows
Get-WinEvent -LogName Application |
  Where-Object ProviderName -match "VSS|VolSnap" |
  Select-Object -First 20 TimeCreated, ProviderName, Id, LevelDisplayName, Message
```

Interpretation: the `albertony/vss` link supports native VSS requester mechanics, not the existence or behavior of every PowerShell wrapper. The Microsoft VSS links support the snapshot/set model. If the module note claims a specific cmdlet, verify against the module source or local help before citing it as evidence.

## References
- <https://github.com/albertony/vss>
- <https://learn.microsoft.com/en-us/windows-server/storage/file-server/volume-shadow-copy-service>
- <https://learn.microsoft.com/en-us/windows/win32/vss/shadow-copies-and-shadow-copy-sets>
