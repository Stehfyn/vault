"""
Enumerate every .dll under C:\\Windows\\System32, list the exported
function NAMES, and flag any name that does NOT appear as an identifier
in any header file under the Windows SDK include tree (10.0.19041.0,
10.0.22621.0, 10.0.26100.0) or the WDF include tree.

Output: a single Markdown file grouping the hidden exports by DLL.

Method:
  - Build a giant set of ASCII identifiers (>=3 chars) found in every
    .h/.inl/.idl file under the SDK include roots. This is intentionally
    over-broad: identifiers in comments, macro bodies, type names, struct
    fields, etc. all count as "publicly mentioned". The point is to
    minimise false-positive "hidden" hits — if SDK mentions the name at
    all, we don't call it hidden.
  - For each System32 DLL, walk its export table via pefile.
  - For every named export whose name is not in the SDK identifier set,
    emit it.
  - Ordinal-only exports (no name) are skipped.

Caveats:
  - C++ name-mangled exports (`?Foo@Bar@@...`) tend to land in "hidden"
    because the SDK doesn't typically declare mangled symbols. That's the
    correct outcome — most mangled exports are internal.
  - Some "hidden" exports are actually documented in the WDK (kernel-mode
    side) and the WDF tree only contains the WDF subset. So a few of the
    flagged exports are technically documented for kernel callers. The
    output marks the DLL the export came from, so consumers can judge.
"""
import os, re, sys, time
from pathlib import Path

import pefile

SYSTEM32 = Path(r"C:\Windows\System32")
SDK_ROOTS = [
    Path(r"C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0"),
    Path(r"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0"),
    Path(r"C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0"),
    Path(r"C:\Program Files (x86)\Windows Kits\10\Include\wdf"),
]
OUT = Path(r"C:\dev\vault\vault\dev\hidden.md")

IDENT_RX = re.compile(rb"[A-Za-z_][A-Za-z0-9_]{2,}")

def build_sdk_ids():
    ids = set()
    n_files = 0
    n_bytes = 0
    for root in SDK_ROOTS:
        if not root.exists():
            print(f"  (missing) {root}", flush=True)
            continue
        for pat in ("*.h", "*.inl", "*.hpp", "*.idl"):
            for f in root.rglob(pat):
                try:
                    txt = f.read_bytes()
                except OSError:
                    continue
                n_files += 1
                n_bytes += len(txt)
                for m in IDENT_RX.finditer(txt):
                    ids.add(m.group(0))
    return ids, n_files, n_bytes

def exports_of(dll_path):
    try:
        pe = pefile.PE(str(dll_path), fast_load=True)
    except Exception as e:
        return None
    try:
        pe.parse_data_directories(
            directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_EXPORT"]]
        )
        if not hasattr(pe, "DIRECTORY_ENTRY_EXPORT"):
            return []
        out = []
        for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
            if exp.name is None:
                continue
            name = exp.name.decode("ascii", "ignore")
            if not name:
                continue
            fwd = getattr(exp, "forwarder", None)
            fwd = fwd.decode("ascii", "ignore") if fwd else None
            out.append((name, fwd))
        return out
    finally:
        pe.close()

def main():
    print("Building SDK identifier set ...", flush=True)
    t0 = time.time()
    sdk_ids_bytes, nf, nb = build_sdk_ids()
    print(
        f"  scanned {nf} files, {nb/1e6:.1f} MB; "
        f"unique identifiers: {len(sdk_ids_bytes):,} ({time.time()-t0:.1f}s)",
        flush=True,
    )
    # Cast once
    sdk_ids = {b.decode("ascii", "ignore") for b in sdk_ids_bytes}

    print("Walking System32 DLLs ...", flush=True)
    dlls = sorted(p for p in SYSTEM32.glob("*.dll"))
    print(f"  {len(dlls)} DLLs", flush=True)

    results = {}        # dll_name -> [hidden_names]
    mangled = {}        # dll_name -> [mangled_names]
    forwarders = {}     # dll_name -> [(name, fwd)]
    no_exports = 0
    pe_errors = 0
    t0 = time.time()
    for i, dll in enumerate(dlls):
        if i % 250 == 0:
            print(f"  [{i:4d}/{len(dlls)}] {dll.name}", flush=True)
        exps = exports_of(dll)
        if exps is None:
            pe_errors += 1
            continue
        if not exps:
            no_exports += 1
            continue
        hid = []
        mng = []
        fwd_list = []
        for name, fwd in exps:
            if fwd:
                fwd_list.append((name, fwd))
            if name.startswith("?") or name.startswith("_Z"):
                # C++ / Itanium-style mangled
                mng.append(name)
                continue
            if name in sdk_ids:
                continue
            hid.append(name)
        if hid:
            results[dll.name] = sorted(set(hid))
        if mng:
            mangled[dll.name] = sorted(set(mng))
        if fwd_list:
            forwarders[dll.name] = sorted(set(fwd_list))
    print(f"  walked in {time.time()-t0:.1f}s; "
          f"pe-errors={pe_errors}, no-exports-dlls={no_exports}", flush=True)

    # Write output
    OUT.parent.mkdir(parents=True, exist_ok=True)
    total_hidden = sum(len(v) for v in results.values())
    total_mangled = sum(len(v) for v in mangled.values())
    with OUT.open("w", encoding="utf-8") as f:
        f.write("# Hidden Win32 Exports\n\n")
        f.write(
            "Exported function names from every `.dll` under `C:\\Windows\\System32\\` "
            "that do NOT appear as an identifier in any header file under the Windows "
            "SDK include tree (versions 10.0.19041.0 / 22621.0 / 26100.0 / WDF).\n\n"
        )
        f.write(
            "The matcher is intentionally permissive: every alphanumeric identifier "
            "found anywhere in any .h/.inl/.hpp/.idl file across the SDK is treated as "
            "'publicly mentioned'. If an export name still does not appear, it is "
            "genuinely absent from the public SDK.\n\n"
        )
        f.write(f"- DLLs scanned: **{len(dlls):,}**\n")
        f.write(f"- DLLs with hidden exports: **{len(results):,}**\n")
        f.write(f"- Total hidden exports: **{total_hidden:,}**\n")
        f.write(f"- C++ mangled exports (separately listed below): **{total_mangled:,}** across **{len(mangled):,}** DLLs\n")
        f.write(f"- Generated by `scratch/find_hidden_exports.py`.\n\n")
        f.write("Caveats:\n")
        f.write(
            "- Some 'hidden' names are documented in the WDK (kernel-mode) headers that "
            "are NOT under the Win32 SDK tree, and not under the included WDF subset. A "
            "few entries below are therefore documented for kernel callers only.\n"
            "- Forwarders point to another DLL+name and are listed in the dedicated "
            "section at the bottom of each DLL block.\n"
            "- Ordinal-only exports (no name) are excluded entirely.\n\n"
        )
        f.write("---\n\n")
        f.write("## Hidden exports by DLL\n\n")
        for dll_name in sorted(results.keys()):
            exps = results[dll_name]
            f.write(f"### {dll_name}  ({len(exps)})\n\n")
            # Group into a code-block for compactness
            f.write("```\n")
            for e in exps:
                f.write(f"{e}\n")
            f.write("```\n\n")

        if mangled:
            f.write("---\n\n")
            f.write("## C++ mangled exports by DLL\n\n")
            f.write(
                "These names are decorated by the MSVC C++ ABI (`?Name@Class@@QAE...`) "
                "and are essentially never declared in the public SDK. Listed for "
                "completeness; demangle with `undname.exe` if you need a readable form.\n\n"
            )
            for dll_name in sorted(mangled.keys()):
                exps = mangled[dll_name]
                f.write(f"### {dll_name}  ({len(exps)})\n\n")
                f.write("```\n")
                for e in exps:
                    f.write(f"{e}\n")
                f.write("```\n\n")

        if forwarders:
            f.write("---\n\n")
            f.write("## Forwarders by DLL\n\n")
            f.write(
                "Forwarders re-export a name to a different DLL's function (handled at "
                "load time by the Windows loader). The arrow shows where the name "
                "actually resolves.\n\n"
            )
            for dll_name in sorted(forwarders.keys()):
                fws = forwarders[dll_name]
                f.write(f"### {dll_name}  ({len(fws)})\n\n")
                f.write("```\n")
                for n, fw in fws:
                    f.write(f"{n} -> {fw}\n")
                f.write("```\n\n")

    print(f"Wrote {OUT}")
    print(f"DLLs with hidden exports: {len(results)}")
    print(f"Total hidden exports: {total_hidden}")
    print(f"Total mangled exports: {total_mangled}")

if __name__ == "__main__":
    main()
