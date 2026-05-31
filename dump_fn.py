import pefile, capstone, sys
PATH = r"C:\Windows\System32\kernelbase.dll"
RVA = int(sys.argv[1], 16)

pe = pefile.PE(PATH, fast_load=True)
pe.parse_data_directories(directories=[
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXCEPTION'],
    pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT'],
])
ib = pe.OPTIONAL_HEADER.ImageBase
iat = {}
for ent in pe.DIRECTORY_ENTRY_IMPORT or []:
    dll = ent.dll.decode(errors='ignore')
    for imp in ent.imports:
        n = imp.name.decode(errors='ignore') if imp.name else f"ord_{imp.ordinal}"
        iat[imp.address] = f"{dll}!{n}"
sym = {ib+e.address: e.name.decode(errors='ignore') for e in pe.DIRECTORY_ENTRY_EXPORT.symbols if e.name}

begin = end = None
for rf in pe.DIRECTORY_ENTRY_EXCEPTION:
    if rf.struct.BeginAddress <= RVA < rf.struct.EndAddress:
        begin, end = rf.struct.BeginAddress, rf.struct.EndAddress
        break
va = ib + begin
code = pe.get_memory_mapped_image()[begin:end]
print(f"; fn rva=0x{begin:X} va=0x{va:X} size=0x{end-begin:X}")
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64); md.detail=False; md.skipdata=True
for ins in md.disasm(code, va):
    note=""
    op=ins.op_str
    if ins.mnemonic in ("call","jmp","je","jne","jz","jnz","jl","jg","jle","jge","ja","jb","jae","jbe","js","jns"):
        try: tgt=int(op.split()[0],16) if op.startswith("0x") else None
        except ValueError: tgt=None
        if tgt is not None:
            if tgt in sym: note=f"  ; -> {sym[tgt]}"
            elif va<=tgt<va+(end-begin): note=f"  ; -> +0x{tgt-va:X}"
    if "qword ptr [rip" in op and ins.mnemonic in ("call","jmp"):
        try:
            disp=op.split('rip')[1].split(']')[0].strip()
            sign=1
            if disp.startswith('+'): disp=disp[1:].strip()
            elif disp.startswith('-'): sign=-1; disp=disp[1:].strip()
            slot=ins.address+ins.size+int(disp,16)*sign
            if slot in iat: note=f"  ; -> {iat[slot]}"
        except (IndexError,ValueError): pass
    print(f"0x{ins.address:08X}  {ins.mnemonic:<7} {op}{note}")
