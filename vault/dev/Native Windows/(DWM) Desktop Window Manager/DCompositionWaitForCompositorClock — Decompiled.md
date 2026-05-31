# DCompositionWaitForCompositorClock — Decompiled

Win11-only (build 22000+) compositor-clock wait. Public docs at <https://learn.microsoft.com/en-us/windows/win32/api/dcomp/nf-dcomp-dcompositionwaitforcompositorclock> describe the signature but omit the validation rules, the 32-handle cap, the access-denied path, and the timeout encoding. This is the DirectComposition counterpart to the vblank notes in this folder: it waits on the compositor's scheduling clock, not raw scanout, so it is the right primitive for DComp animations and the wrong primitive for beam-racing a physical raster. Below is the actual three-tier call chain pulled apart with `dumpbin /disasm` on `C:\Windows\System32\{dcomp,win32u,win32k,win32kbase}.{dll,sys}` (Win11 Pro 10.0.26200).

## Three-tier call chain

```
dcomp.dll!DCompositionWaitForCompositorClock      ← public export, RVA 0xC0E60
    │ 48 FF 25 A9 94 0F 00     jmp qword ptr [RIP + 0xF94A9]   ; → IAT slot 0x1801BA310
    │ (IAT slot's on-disk value is the RVA of an IMAGE_IMPORT_BY_NAME
    │  struct: hint=0x42, name="NtDCompositionWaitForCompositorClock")
    ▼
win32u.dll!NtDCompositionWaitForCompositorClock   ← syscall stub, RVA 0x3AF0
    │ mov   r10, rcx                       ; SYSCALL clobbers rcx with RIP, so save it
    │ mov   eax, 0x1142                    ; ← syscall number (build-specific)
    │ test  byte ptr [0x7FFE0308h], 1      ; KUSER_SHARED_DATA.SystemCall fastpath flag
    │ jne   slow
    │ syscall                              ; → ring 0
    │ ret
    │ slow: int 2Eh; ret                   ; legacy fallback, never taken on x64 CPUs
    ▼
win32k.sys!__win32kstub_NtDCompositionWaitForCompositorClock   ← SSDT entry (ordinal 349) — tail-calls →
    ▼
win32kbase.sys!NtDCompositionWaitForCompositorClock            ← real body, RVA 0xCE410
```

## Annotated body (`win32kbase.sys` @ RVA 0xCE410)

```asm
; --- prologue: save args, /GS cookie, 352 bytes of locals ---
mov   [rsp+20h], rbx
push  rsi  ; push rdi  ; push r12  ; push r14  ; push r15
sub   rsp, 160h
mov   rax, [security_cookie]
xor   rax, rsp
mov   [rsp+150h], rax
mov   edi, r8d              ; edi = timeoutInMs
mov   r12, rdx              ; r12 = handles pointer
mov   esi, ecx              ; esi = count

; --- zero a 256-byte stack buffer to receive probed user handles ---
xor   edx, edx
mov   r8d, 100h             ; 256 = 32 * sizeof(HANDLE)
lea   rcx, [rsp+50h]
call  memset

; --- argument validation ---
test  esi, esi              ; count == 0 ?
je    .check_timeout
cmp   esi, 20h              ; count > 32 ?
ja    .invalid_param        ;   → STATUS_INVALID_PARAMETER (0xC000000D)
test  r12, r12              ; handles == NULL ?
je    .invalid_param

; --- probe + copy from user-mode into kernel stack buffer (SEH-guarded) ---
mov   r8d, esi
shl   r8, 3                 ; byte count = count * 8
mov   rdx, r12
lea   rcx, [rsp+50h]
call  ProbeAndCopyMemory    ; @ 0x1401A14B8
; on user-mode access fault: SEH lands here with eax = exception code → ebx

.check_timeout:
cmp   edi, 0FFFFFFFFh       ; timeoutInMs == INFINITE ?
je    .acquire_compositor
mov   eax, edi
imul  rcx, rax, -10000      ; ms → 100-ns LARGE_INTEGER, negate (= relative)
mov   [rsp+38h], rcx
lea   r15, [rsp+38h]        ; r15 = &timeout (or NULL when INFINITE)

.acquire_compositor:
test  ebx, ebx
js    .epilogue             ; abandon on prior failure

call  KeEnterCriticalRegion ; disables normal kernel APCs around the setup

call  GetThreadCompositor   ; @ 0x140093F00 — per-thread compositor lookup
mov   rdi, rax
test  rax, rax
je    .no_compositor        ;   → STATUS_ACCESS_DENIED (0xC0000022)

lea   rdx, [rsp+30h]        ; out: pointer slot for wait object
mov   rcx, rax              ; in:  compositor
call  ResolveWaitObject     ; @ 0x1400CA378 — builds the kernel wait sub-object
mov   ebx, eax              ; status
mov   rcx, rdi
call  ReleaseCompositorRef  ; @ 0x140093ED0
mov   r14, [rsp+30h]        ; r14 = wait object
jmp   .leave_critical

.no_compositor:
mov   ebx, 0C0000022h       ; STATUS_ACCESS_DENIED

.leave_critical:
call  KeLeaveCriticalRegion
test  ebx, ebx
js    .epilogue

; --- the actual blocking wait ---
mov   r9, r15               ; &timeout (or NULL = INFINITE)
lea   r8, [rsp+50h]         ; probed handles buffer
mov   edx, esi              ; count
mov   rcx, r14              ; compositor wait object
call  DoCompositorClockWait ; @ 0x140192A58 — KeWaitForMultipleObjects + clock tick
mov   ebx, eax              ; final NTSTATUS

mov   rcx, r14
call  ReleaseWaitObject     ; @ 0x1400EAB40

.epilogue:
mov   eax, ebx
mov   rcx, [rsp+150h]
xor   rcx, rsp
call  __security_check_cookie
mov   rbx, [rsp+1A8h]
add   rsp, 160h
pop   r15  ; pop r14  ; pop r12  ; pop rdi  ; pop rsi
ret
```

## Things the docs don't tell you

1. **`count` is hard-capped at 32.** `cmp esi, 20h ; ja invalid_param`. Larger values yield `STATUS_INVALID_PARAMETER` (0xC000000D). The kernel buffer is exactly 256 bytes = 32 × `HANDLE`. No mention in MS Learn.

2. **`count == 0` is fine** (skips probe entirely; `handles` can be NULL). But `count > 0 && handles == NULL` → `STATUS_INVALID_PARAMETER`.

3. **`timeoutInMs == 0xFFFFFFFF` is INFINITE.** Otherwise converted to a *relative* `LARGE_INTEGER` by `× -10000` (ms → 100-ns units, negated to signal "relative" to `KeWaitFor*`).

4. **Undocumented `STATUS_ACCESS_DENIED` (0xC0000022) path.** If the caller has no per-thread compositor (typical: session-0 services, processes that never initialised DComp), the function returns access-denied. Not in MS Learn's enumeration.

5. **`STATUS_GRAPHICS_PRESENT_OCCLUDED`** (which MS Learn does mention for "display off") doesn't appear directly in `NtDCompositionWaitForCompositorClock` — it surfaces from the inner `DoCompositorClockWait` (`@ 0x140192A58`), which is shared with the present pipeline and detects powered-off displays.

6. **The probe + setup is APC-bounded but the wait isn't.** `KeEnterCriticalRegion` / `KeLeaveCriticalRegion` wrap only the compositor-handle resolution. The actual wait is fully alertable — a `QueueUserAPC` to the calling thread will return early with `STATUS_USER_APC`.

7. **Syscall number `0x1142` is per-build.** Stable across patches within one Windows build but renumbered freely across major builds (compare to ReactOS' historical tracking of SSDT churn). Always call through `dcomp.dll` — never hand-roll the syscall.

## Reconstructed signature (matches MS Learn exactly)

```cpp
NTSTATUS WINAPI DCompositionWaitForCompositorClock(
    UINT          count,         // 0..32 inclusive; >32 → STATUS_INVALID_PARAMETER
    const HANDLE* handles,       // event handles to also wait on
    DWORD         timeoutInMs);  // 0xFFFFFFFF = INFINITE; else ms (× -10000 → relative 100ns)
```

Return is **NTSTATUS** (typed as `DWORD` in the header), *not* a Win32 `WAIT_OBJECT_0`-style index. The caller doesn't get told which handle satisfied the wait; they have to poll signaled state on the handles afterwards if they need to know.

## Experiment Harness

Goal: validate the public wait contract at runtime: clock cadence, timeout behavior, handle-count limits, and access-denied contexts.

Procedure:
1. In a normal interactive desktop process, call `DCompositionWaitForCompositorClock(0, nullptr, 100)` in a loop and timestamp returns.
2. Repeat with 1 event handle, 32 event handles, and 33 event handles.
3. Repeat before/after creating a DComp device/target, with display on/off if safe, and from a non-interactive/service-like context if available.

```cpp
auto before = qpc();
DWORD st = DCompositionWaitForCompositorClock(count, handles, timeout_ms);
log(st, qpc() - before, count, timeout_ms);
```

Metric: return status, interval distribution, timeout hit rate, and status transition after invalid handle count or no compositor.

Failure interpretation: `STATUS_INVALID_PARAMETER` confirms bad count/handle shape. `STATUS_ACCESS_DENIED` points at no per-thread compositor/desktop context. Immediate occluded/display-off status is a display state result, not a timing result. Jitter here is compositor-clock jitter, not physical scanline jitter.

## Sibling syscalls in the same family

Confirmed from `win32u.dll` exports on the same build:

| Function | Syscall # | win32u RVA |
|---|---|---|
| `NtDCompositionBoostCompositorClock` | 0x1115 | 0x3550 |
| `NtDCompositionGetFrameId` | 0x1129 | 0x37D0 |
| `NtDCompositionGetFrameIdFromBatchId` | 0x112A | 0x37F0 |
| `NtDCompositionWaitForCompositorClock` | **0x1142** | 0x3AF0 |

Kernel-side counterparts all exist in `win32kbase.sys` exports.

## How to reproduce

```powershell
# 1. Confirm the user-mode thunk
dumpbin /exports C:\Windows\System32\dcomp.dll | findstr CompositorClock

# 2. Walk to the kernel thunk
dumpbin /imports C:\Windows\System32\dcomp.dll | findstr CompositorClock
dumpbin /exports C:\Windows\System32\win32u.dll | findstr CompositorClock

# 3. Walk to the body
dumpbin /exports C:\Windows\System32\win32k.sys      | findstr CompositorClock
dumpbin /exports C:\Windows\System32\win32kbase.sys  | findstr CompositorClock

# 4. Disasm
dumpbin /disasm:nobytes /section:.text C:\Windows\System32\win32kbase.sys > out.txt
# Open out.txt, search for "00000001400CE410:"
```

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/dcomp/nf-dcomp-dcompositionwaitforcompositorclock>
- <https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55> (NTSTATUS list)
- Related vault notes: `VBlank Wait.md`, `Lagless VSYNC ON via Beam Racing.md`, `Linux DRM Vertical Blank.md`
