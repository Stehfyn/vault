<!-- generated-from-dump2 -->
# MS-DOS Original Sources

Official Microsoft-released sources of MS-DOS 1.25 (1982), 2.0 (1983), and 4.0 (1988). MIT-licensed, original 8086 assembly. Read this if you ever wondered (a) what an OS looked like before C was viable as a kernel language, or (b) how single-tasking, 640 KB-limited systems actually managed FAT, files-as-numbered-FCBs (1.x) vs files-as-handles (2.x), int 21h services, and TSRs. v1.x is FAT12-only and FCB-based, just slightly more than CP/M. v2.0 adds hierarchical directories, file handles, installable device drivers, and pipes — the Unix-influenced rewrite. v4.0 adds FAT16-large-partition support and a graphical DOS Shell. Most interesting file is `MSDOS.SYS` (the kernel proper); `COMMAND.COM` is the userland shell.

```asm
; Flavor: a famous chunk of int 21h dispatch from MSDOS.ASM (paraphrased).
; AH = function number, switch on it, jump to handler.
;
; FUNC_TABLE:
;   DW    func_00_terminate
;   DW    func_01_char_input
;   DW    func_02_char_output
;   ...
;   DW    func_3C_create_file
;   DW    func_3D_open_file
;   DW    func_3E_close_file
;   DW    func_3F_read_handle
;   DW    func_40_write_handle
;   ...
;
; INT21H_DISPATCH:
;   MOV   BX, AX
;   AND   BX, 00FFh
;   SHL   BX, 1
;   JMP   WORD PTR [FUNC_TABLE + BX]
```

## References
- <https://github.com/microsoft/MS-DOS>
