# AlphaVSS - .NET Binding for Volume Shadow Copy

AlphaVSS wraps the COM-heavy Volume Shadow Copy Service API behind a stable .NET surface. It matters because VSS is both powerful and version-fussy: requester, writer metadata, snapshot sets, provider behavior, and OS-specific interface differences are tedious to handle directly.

Keep it near the PowerShell VSS module. AlphaVSS is the library path for application code; the module is the admin scripting path. Both clarify why backup tools need coordinated snapshots rather than naive file copies when databases or locked files are involved.

Code contribution: inspect requester/writer coordination, `IVssBackupComponents`, snapshot-set creation, COM interop wrappers, and provider-specific error handling around VSS APIs.

Requester flow to compare against the PowerShell module:

```cpp
IVssBackupComponents* backup = nullptr;
CreateVssBackupComponents(&backup);
backup->InitializeForBackup();
backup->GatherWriterMetadata(&async);
backup->StartSnapshotSet(&snapshot_set_id);
backup->AddToSnapshotSet(volume_name, provider_id, &snapshot_id);
backup->DoSnapshotSet(&async);
```

The legitimate mechanism is coordination with writers and providers. That makes it relevant to backup, forensic collection, and locked-file copy notes; the defensive question is whether snapshots are created by expected backup software under expected policy.

## Source Code Reading

AlphaVSS is a managed facade over `IVssBackupComponents`, not an alternate VSS implementation. The wrapper body is in `src/AlphaVSS.Platform/VssBackupComponents.cpp`; the factory entry is `src/AlphaVSS.Platform/VssFactory.cpp`.

```text
VssFactory::CreateVssBackupComponents()
  -> gcnew VssBackupComponents()

VssBackupComponents::VssBackupComponents()
  -> CreateVssBackupComponents(&m_backup)
```

The useful detail is method-by-method translation. AlphaVSS preserves the VSS state machine while turning COM HRESULTs into managed exceptions and VSS async objects into blocking waits/tasks:

```text
InitializeForBackup(xml) -> m_backup->InitializeForBackup(...)
GatherWriterMetadata()   -> m_backup->GatherWriterMetadata(&IVssAsync) -> wait/check/release
StartSnapshotSet()       -> m_backup->StartSnapshotSet(&snapshotSetId)
AddToSnapshotSet(...)    -> m_backup->AddToSnapshotSet(..., &snapshotId)
PrepareForBackup()       -> m_backup->PrepareForBackup(&IVssAsync) -> wait/check/release
DoSnapshotSet()          -> m_backup->DoSnapshotSet(&IVssAsync) -> wait/check/release
ExposeSnapshot(...)      -> m_backup->ExposeSnapshot(..., &pwszExposed)
DeleteSnapshot(...)      -> m_backup->DeleteSnapshots(...)
```

The hidden body of "wraps VSS" is mostly lifetime and state-machine enforcement. The implementation keeps raw COM pointers (`m_backup`, `m_IVssBackupComponentsEx*`) and releases them in the finalizer/destructor. Async-producing COM calls are paired with wait/check/release or task conversion.

The native control group is `vss/vshadow/cpp/create.cpp`. `VssClient::CreateSnapshotSet` gathers writer metadata, selects components, starts the set, adds volumes, prepares for backup, does the snapshot, optionally saves the backup-components document, then queries created shadows.

Verifiable assertions to drive:

```text
claim: AlphaVSS does not bypass the VSS state machine
probe: call `DoSnapshotSet` before `StartSnapshotSet`/`AddToSnapshotSet`; confirm wrapped VSS error

claim: async calls must be waited and checked
probe: log elapsed time around `GatherWriterMetadata`, `PrepareForBackup`, and `DoSnapshotSet`

claim: snapshot set ID and snapshot ID are different evidence
probe: log both IDs and verify them through `QuerySnapshots()`/`vssadmin list shadows`
```

Source files read:
- `AlphaVSS/src/AlphaVSS.Platform/VssFactory.cpp`
- `AlphaVSS/src/AlphaVSS.Platform/VssBackupComponents.cpp`
- `AlphaVSS/src/AlphaVSS.Common/Interfaces/IVssBackupComponents.cs`
- `vss/vshadow/cpp/create.cpp`

## Experiment Harness

Goal: observe requester shape and writer/provider coordination without building a backup product.

Procedure:

```text
1. Baseline: vssadmin list writers; vssadmin list providers; vssadmin list shadows
2. Run a requester flow that gathers metadata and creates a short-lived snapshot set.
3. Record writer state before and after the snapshot.
4. Expose or query the snapshot path only long enough to prove point-in-time reads.
5. Delete the snapshot; verify list shadows returns to baseline.
```

Code shape:

```cpp
CreateVssBackupComponents(&backup);
backup->InitializeForBackup();
backup->GatherWriterMetadata(&async);
backup->StartSnapshotSet(&set_id);
backup->AddToSnapshotSet(volume, GUID_NULL, &snapshot_id);
backup->DoSnapshotSet(&async);
backup->GetSnapshotProperties(snapshot_id, &props);
backup->DeleteSnapshots(snapshot_id, VSS_OBJECT_SNAPSHOT, FALSE, &deleted, &failed);
```

Signals to record: requester process, volume, provider ID/name, snapshot-set GUID, snapshot GUID, writer count/states, freeze/thaw duration if available, exposed path, deletion result, and VSS event-log entries. Expected baseline: metadata gathering precedes snapshot creation, writers return to stable states, and snapshots disappear after deletion. Failure usually means writer error, provider limitation, permissions, diff-area pressure, or a volume name mismatch; do not interpret every VSS failure as file-lock behavior.

## Discussion Claim Verification

Claim: "AlphaVSS makes VSS simple."

Why it matters for new diagnostic code: the wrapper removes COM friction, but it does not remove the VSS state machine. A correct application still has to prove writer metadata, snapshot-set identity, async completion, provider behavior, and cleanup.

How to verify:
1. Run the same snapshot lifecycle through AlphaVSS and through `vssadmin`/native requester diagnostics.
2. Log snapshot set ID and per-volume snapshot IDs separately.
3. Time `GatherWriterMetadata`, `PrepareForBackup`, and `DoSnapshotSet`.
4. Query VSS event-log rows and `vssadmin list shadows` before and after cleanup.

Minimal code/pseudocode:

```csharp
using var components = VssFactory.Provider.CreateVssBackupComponents();
components.InitializeForBackup(null);
components.GatherWriterMetadata();
Guid setId = components.StartSnapshotSet();
Guid snapId = components.AddToSnapshotSet(@"C:\", Guid.Empty);
components.PrepareForBackup();
components.DoSnapshotSet();
var props = components.GetSnapshotProperties(snapId);
components.DeleteSnapshot(snapId, false);
```

Interpretation: the AlphaVSS link supports managed access to the VSS requester surface. It does not support bypassing writer/provider coordination, ignoring async state, or treating a snapshot GUID as the same thing as a snapshot-set GUID. The Microsoft VSS links are the authority for the state machine.

## References
- <https://github.com/alphaleonis/AlphaVSS>
- <https://learn.microsoft.com/en-us/windows-server/storage/file-server/volume-shadow-copy-service>
- <https://learn.microsoft.com/en-us/windows/win32/vss/requestors>
- <https://learn.microsoft.com/en-us/windows/win32/api/vsbackup/nl-vsbackup-ivssbackupcomponents>
