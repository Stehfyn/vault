import pefile, capstone, sys
PATH = r"C:\Windows\System32\kernelbase.dll"
TARGET = "FreeConsole"

pe = pefile.PE(PATH, fast_load=True)
pe.parse_data_directories(directories=[
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXCEPTION'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT'],
])
ib = pe.OPTIONAL_HEADER.ImageBase

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

sym = {ib+e.address: e.name.decode(errors='ignore') for e in pe.DIRECTORY_ENTRY_EXPORT.symbols if e.name}

rva = next(e.address for e in pe.DIRECTORY_ENTRY_EXPORT.symbols if e.name and e.name.decode()==TARGET)
begin = end = None
for rf in pe.DIRECTORY_ENTRY_EXCEPTION:
    if rf.struct.BeginAddress == rva:
        begin, end = rf.struct.BeginAddress, rf.struct.EndAddress
        break

va = ib + begin
size = end - begin
print(f"; {TARGET} rva=0x{rva:X} va=0x{va:X} size=0x{size:X}")
code = pe.get_memory_mapped_image()[begin:end]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64); md.detail=False; md.skipdata=True
for ins in md.disasm(code, va):
    note=""
    op=ins.op_str
    if ins.mnemonic in ("call","jmp","je","jne","jz","jnz","jl","jg","jle","jge","ja","jb","jae","jbe","js","jns"):
        try:
            tgt = int(op.split()[0],16) if op.startswith("0x") else None
        except ValueError: tgt=None
        if tgt is not None:
            if tgt in sym: note=f"  ; -> {sym[tgt]}"
            elif va<=tgt<va+size: note=f"  ; -> +0x{tgt-va:X}"
    if ("qword ptr [rip" in op) and ins.mnemonic in ("call","jmp"):
        try:
            disp=op.split('rip')[1].split(']')[0].strip()
            sign=1
            if disp.startswith('+'): disp=disp[1:].strip()
            elif disp.startswith('-'): sign=-1; disp=disp[1:].strip()
            slot = ins.address + ins.size + int(disp,16)*sign
            if slot in iat: note=f"  ; -> {iat[slot]}"
        except (IndexError,ValueError): pass
    print(f"0x{ins.address:08X}  {ins.mnemonic:<7} {op}{note}")
