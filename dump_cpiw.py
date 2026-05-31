"""Disassemble CreateProcessInternalW from kernelbase.dll with import
resolution for indirect calls / jumps."""
import pefile, capstone, sys

PATH = r"C:\Windows\System32\kernelbase.dll"
TARGET = "CreateProcessInternalW"

pe = pefile.PE(PATH, fast_load=True)
pe.parse_data_directories(directories=[
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXCEPTION'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT'],
])

img_base = pe.OPTIONAL_HEADER.ImageBase

# Build IAT slot map: VA of slot -> "dll!api"
iat = {}
for ent in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []) or []:
    dll = ent.dll.decode(errors='ignore')
    for imp in ent.imports:
        name = imp.name.decode(errors='ignore') if imp.name else f"ord_{imp.ordinal}"
        iat[imp.address] = f"{dll}!{name}"
for ent in getattr(pe, 'DIRECTORY_ENTRY_DELAY_IMPORT', []) or []:
    dll = ent.dll.decode(errors='ignore')
    for imp in ent.imports:
        name = imp.name.decode(errors='ignore') if imp.name else f"ord_{imp.ordinal}"
        iat[imp.address] = f"DELAY:{dll}!{name}"

# Build export map (for intra-module calls to other kernelbase functions)
sym = {}
for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
    if exp.name:
        sym[img_base + exp.address] = exp.name.decode(errors='ignore')

# Locate target
rva = None
for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
    if exp.name and exp.name.decode(errors='ignore') == TARGET:
        rva = exp.address; break
if rva is None: sys.exit("export not found")

# pdata bounds
begin = end = unwind = None
for rf in pe.DIRECTORY_ENTRY_EXCEPTION:
    if rf.struct.BeginAddress == rva:
        begin, end, unwind = rf.struct.BeginAddress, rf.struct.EndAddress, rf.struct.UnwindData
        break
if begin is None: sys.exit("no pdata")

size = end - begin
va_begin = img_base + begin
print(f"; {TARGET}")
print(f"; rva=0x{rva:X}  va=0x{va_begin:X}  size=0x{size:X} ({size} bytes)")
print(f"; unwind_rva=0x{unwind:X}")
print()

code = pe.get_memory_mapped_image()[begin:end]

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
md.detail = False
md.skipdata = True

for ins in md.disasm(code, va_begin):
    note = ""
    op = ins.op_str

    # direct branches with hex immediate
    if ins.mnemonic in ("call","jmp","je","jne","jz","jnz","jl","jg","jle","jge",
                        "ja","jb","jae","jbe","js","jns","jo","jno","jp","jnp",
                        "jcxz","jecxz","jrcxz","loop","loope","loopne"):
        try:
            tgt = int(op.split()[0], 16) if op.startswith("0x") else None
        except ValueError:
            tgt = None
        if tgt is not None:
            if tgt in sym:
                note = f"  ; -> {sym[tgt]}"
            elif va_begin <= tgt < va_begin + size:
                note = f"  ; -> +0x{tgt-va_begin:X}"

    # indirect calls/jumps via rip-relative IAT slots
    if ("qword ptr [rip" in op) and ins.mnemonic in ("call","jmp"):
        # form: call qword ptr [rip + 0xNNNN]
        try:
            disp = op.split('rip')[1].split(']')[0].strip()
            sign = 1
            if disp.startswith('+'): disp = disp[1:].strip()
            elif disp.startswith('-'):
                sign = -1; disp = disp[1:].strip()
            d = int(disp, 16) * sign
            tgt_slot = ins.address + ins.size + d
            if tgt_slot in iat:
                note = f"  ; -> {iat[tgt_slot]}"
        except (IndexError, ValueError):
            pass

    print(f"0x{ins.address:08X}  {ins.mnemonic:<6} {op}{note}")
