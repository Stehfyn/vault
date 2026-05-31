# MSDelta

MSDelta is Windows' native binary-delta facility: produce a delta from a known source blob to a target blob, then apply that delta later when the same source is available. That makes it closer to servicing/update technology than to ZIP-style compression; the value is minimizing update payloads while preserving exact target reconstruction.

The important operational details are source identity and memory ownership. A delta is only meaningful against the intended source version, and successful `CreateDeltaB`/`ApplyDeltaB` calls return buffers that must be released with `DeltaFree`. Connect this to `msdelta.h`, Windows servicing notes, and high-performance file-copy entries where the tradeoff is CPU and metadata discipline versus transferred bytes.

Call-flow shape:

```cpp
DELTA_INPUT source = { source_bytes, source_size, TRUE };
DELTA_INPUT target = { target_bytes, target_size, TRUE };
DELTA_OUTPUT delta = {};

BOOL made = CreateDeltaB(DELTA_FILE_TYPE_RAW, 0, 0,
                         source, target,
                         { nullptr, 0, FALSE },
                         { nullptr, 0, FALSE },
                         { nullptr, 0, FALSE },
                         nullptr, 0, &delta);
if (made) {
    DeltaFree(delta.lpStart);
}
```

The matching apply path takes the same source identity plus the delta blob and produces a target buffer that also follows the `DeltaFree` contract. That makes MSDelta a servicing/update primitive, not a general substitute for archive compression.

## Source Code Reading

This topic is first-party API driven. The "source" is the Windows MSDelta contract: `CreateDeltaB` accepts a source `DELTA_INPUT`, target `DELTA_INPUT`, optional source/options/global-data inputs, and returns a `DELTA_OUTPUT`; `ApplyDeltaB` accepts the original source plus the delta and returns a rebuilt target; every successful output buffer is released with `DeltaFree`.

The useful code body is the ownership table:

```text
source input: caller-owned, not freed by MSDelta
target input: caller-owned, not freed by MSDelta
delta output from CreateDeltaB: MSDelta-allocated, caller releases with DeltaFree
rebuilt output from ApplyDeltaB: MSDelta-allocated, caller releases with DeltaFree
```

That turns claims about "binary delta" into falsifiable probes:

```text
claim: a delta is source-specific
probe: create delta from A -> B, apply it to A and to A'; compare success/hash

claim: MSDelta is not just compression
probe: compare delta size for similar target vs unrelated target of same size

claim: output ownership is not CRT ownership
probe: release only with `DeltaFree`; use Application Verifier/PageHeap to catch wrong frees in a throwaway harness
```

Source files read:
- Microsoft MSDelta overview
- Microsoft `CreateDeltaB` documentation
- Microsoft `ApplyDeltaB` documentation
- Microsoft `DeltaFree` documentation

## Experiment Harness

Goal: prove the binary-delta contract by round-tripping known buffers and intentionally applying the delta to the wrong source.

Procedure:

```cpp
DELTA_INPUT src = { source_bytes, source_size, TRUE };
DELTA_INPUT dst = { target_bytes, target_size, TRUE };
DELTA_INPUT empty = { nullptr, 0, FALSE };
DELTA_OUTPUT delta = {};

BOOL made = CreateDeltaB(DELTA_FILE_TYPE_RAW, DELTA_FLAG_NONE, 0,
                         src, dst, empty, empty, empty, nullptr, 0, &delta);

DELTA_INPUT delta_in = { delta.lpStart, delta.uSize, FALSE };
DELTA_OUTPUT rebuilt = {};
BOOL applied = ApplyDeltaB(DELTA_FLAG_NONE, src, delta_in, &rebuilt);

bool identical = applied &&
                 rebuilt.uSize == target_size &&
                 memcmp(rebuilt.lpStart, target_bytes, target_size) == 0;
```

Signals to record: source hash, target hash, delta size, compression ratio, `CreateDeltaB`/`ApplyDeltaB` result, `GetLastError`, rebuilt hash, and whether every successful output was released with `DeltaFree`. Expected baseline: correct source plus delta reconstructs the target exactly; wrong source should fail or produce a nonmatching rebuilt hash. The useful insight is source identity discipline, not compression ratio alone.

## Discussion Claim Verification

Claim: "MSDelta is compression."

Why it matters for new diagnostic code: treating MSDelta as compression leads to the wrong tests. The real contract is source-specific reconstruction: a delta is meaningful only against the intended source.

How to verify:
1. Build three buffers: `A`, slightly changed `B`, and unrelated same-size `C`.
2. Create deltas `A -> B` and `A -> C`.
3. Apply `A -> B` to `A`, then intentionally apply it to modified `A'`.
4. Hash all outputs and record `GetLastError`.

Minimal code/pseudocode:

```cpp
auto d_ab = CreateDelta(A, B);
auto d_ac = CreateDelta(A, C);

auto rebuilt_good = ApplyDelta(A, d_ab);
auto rebuilt_wrong = ApplyDelta(A_prime, d_ab);

log(hash(A), hash(B), size(d_ab), hash(rebuilt_good), ok(rebuilt_good == B));
log(hash(A_prime), last_error(rebuilt_wrong), ok(rebuilt_wrong == B));
DeltaFree(d_ab.ptr);
DeltaFree(rebuilt_good.ptr);
```

Interpretation: the Microsoft MSDelta links support the API and ownership contract. They do not support using MSDelta as a general archive format or replacing source-version tracking. A useful MSDelta note should always name source hash, target hash, delta size, apply result, and `DeltaFree` ownership.

## References
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/msdelta>
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/msdelta-createdeltab>
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/msdelta-applydeltab>
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/msdelta-deltafree>
