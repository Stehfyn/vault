# kernelbase!GetStartupInfoW Disassembly (PEB Read)

Full reverse of `GetStartupInfoW`. It performs **no syscall and takes no lock** — it is a straight field copy out of the PEB's `ProcessParameters` (`RTL_USER_PROCESS_PARAMETERS`). `kernel32!GetStartupInfoW` (export RVA `0x3E410`) is only a thunk, `jmp qword ptr [__imp]`, into the real implementation in `kernelbase.dll` (RVA `0xF2F50`). Disassembled from Win11 `C:\Windows\System32\kernelbase.dll` (image base `0x180000000`).

## Annotated disassembly (x64)

```asm
00F2F50  mov   rax, gs:[60h]            ; rax = PEB                  (TEB->ProcessEnvironmentBlock @ gs:[0x60])
00F2F59  mov   rdx, rcx                 ; rdx = lpStartupInfo (arg1, save; rcx reused later)
00F2F5C  mov   r8,  [rax+20h]           ; r8  = PEB->ProcessParameters  (RTL_USER_PROCESS_PARAMETERS)
00F2F60  mov   dword [rcx], 68h         ; si->cb = 0x68 (104 = sizeof STARTUPINFOW) -- HARDCODED
00F2F66  mov   rax, [r8+0D8h]           ; si->lpReserved   (+08) = PP->ShellInfo.Buffer    (PP+0xD8)
00F2F6D  mov   [rcx+08h], rax
00F2F71  mov   rax, [r8+0C8h]           ; si->lpDesktop    (+10) = PP->DesktopInfo.Buffer  (PP+0xC8)
00F2F78  mov   [rcx+10h], rax
00F2F7C  mov   rax, [r8+0B8h]           ; si->lpTitle      (+18) = PP->WindowTitle.Buffer  (PP+0xB8)
00F2F83  mov   [rcx+18h], rax
00F2F87  mov   eax, [r8+088h]           ; si->dwX          (+20) = PP->StartingX    (PP+0x88)
00F2F8E  mov   [rcx+20h], eax
00F2F91  mov   eax, [r8+08Ch]           ; si->dwY          (+24) = PP->StartingY    (PP+0x8C)
00F2F98  mov   [rcx+24h], eax
00F2F9B  mov   eax, [r8+090h]           ; si->dwXSize      (+28) = PP->CountX       (PP+0x90)
00F2FA2  mov   [rcx+28h], eax
00F2FA5  mov   eax, [r8+094h]           ; si->dwYSize      (+2C) = PP->CountY       (PP+0x94)
00F2FAC  mov   [rcx+2Ch], eax
00F2FAF  mov   eax, [r8+098h]           ; si->dwXCountChars(+30) = PP->CountCharsX  (PP+0x98)
00F2FB6  mov   [rcx+30h], eax
00F2FB9  mov   eax, [r8+09Ch]           ; si->dwYCountChars(+34) = PP->CountCharsY  (PP+0x9C)
00F2FC0  mov   [rcx+34h], eax
00F2FC3  mov   eax, [r8+0A0h]           ; si->dwFillAttribute(+38)= PP->FillAttribute (PP+0xA0)
00F2FCA  mov   [rcx+38h], eax
00F2FCD  mov   ecx, [r8+0A4h]           ; ECX = PP->WindowFlags  (PP+0xA4) -- kept for the test below
00F2FD4  mov   [rdx+3Ch], ecx           ; si->dwFlags      (+3C)
00F2FD7  movzx eax, word [r8+0A8h]      ; si->wShowWindow  (+40) = PP->ShowWindowFlags (PP+0xA8, WORD)
00F2FDF  mov   [rdx+40h], ax
00F2FE3  movzx eax, word [r8+0E0h]      ; si->cbReserved2  (+42) = PP->RuntimeData.Length (PP+0xE0, WORD)
00F2FEB  mov   [rdx+42h], ax
00F2FEF  mov   rax, [r8+0E8h]           ; si->lpReserved2  (+48) = PP->RuntimeData.Buffer (PP+0xE8)
00F2FF6  mov   [rdx+48h], rax
00F2FFA  test  ecx, 700h                ; WindowFlags & (USESTDHANDLES|USEHOTKEY|HASSHELLDATA)?
00F3000  je    00F301A                  ;   none set -> skip std handles
00F3002  mov   rax, [r8+20h]            ; si->hStdInput  (+50) = PP->StandardInput  (PP+0x20)
00F3006  mov   [rdx+50h], rax
00F300A  mov   rax, [r8+28h]            ; si->hStdOutput (+58) = PP->StandardOutput (PP+0x28)
00F300E  mov   [rdx+58h], rax
00F3012  mov   rax, [r8+30h]            ; si->hStdError  (+60) = PP->StandardError  (PP+0x30)
00F3016  mov   [rdx+60h], rax
00F301A  ret
```

## STARTUPINFOW <- RTL_USER_PROCESS_PARAMETERS map

| STARTUPINFOW field | si off | <- PP field | PP off |
| --- | --- | --- | --- |
| cb | +00 | (constant `0x68`) | -- |
| lpReserved | +08 | ShellInfo.Buffer | 0xD8 |
| lpDesktop | +10 | DesktopInfo.Buffer | 0xC8 |
| lpTitle | +18 | WindowTitle.Buffer | 0xB8 |
| dwX / dwY | +20 / +24 | StartingX / StartingY | 0x88 / 0x8C |
| dwXSize / dwYSize | +28 / +2C | CountX / CountY | 0x90 / 0x94 |
| dwXCountChars / dwYCountChars | +30 / +34 | CountCharsX / CountCharsY | 0x98 / 0x9C |
| dwFillAttribute | +38 | FillAttribute | 0xA0 |
| dwFlags | +3C | WindowFlags | 0xA4 |
| wShowWindow | +40 | ShowWindowFlags (WORD) | 0xA8 |
| cbReserved2 | +42 | RuntimeData.Length (WORD) | 0xE0 |
| lpReserved2 | +48 | RuntimeData.Buffer | 0xE8 |
| hStdInput/Output/Error | +50/+58/+60 | StandardInput/Output/Error (only if `WindowFlags & 0x700`) | 0x20/0x28/0x30 |

(The `.Buffer` reads are at `UNICODE_STRING+0x8`; e.g. WindowTitle is at PP+0xB0, its Buffer at PP+0xB8.)

## Takeaways

- **It is the PEB.** Everything `GetStartupInfoW` returns was placed in `ProcessParameters` by the creator at process build time. No re-query of the parent, no kernel call.
- **`cb` is forced to `0x68`** — STARTUPINFOEX's `lpAttributeList` is never populated by this API; the extended fields are yours to fill.
- **`wShowWindow` is `PP->ShowWindowFlags` (WORD @ PP+0xA8)** and `STARTF_USESHOWWINDOW` is bit 0 of `WindowFlags` (@ PP+0xA4).
- **Std handles are conditional** on `WindowFlags & 0x700`; otherwise the three handle slots are left untouched (returns garbage if your struct was uninitialized).

## Equivalent without the import (no-CRT golf)

```c
/* wShowWindow straight from the PEB; no GetStartupInfoW import */
unsigned char* pp = *(unsigned char**)((unsigned char*)__readgsqword(0x60) + 0x20);
unsigned short showFlags = *(unsigned short*)(pp + 0xA8);  /* ShowWindowFlags */
unsigned long  winFlags  = *(unsigned long*) (pp + 0xA4);  /* WindowFlags */
int nCmdShow = (winFlags & 1u) ? showFlags : SW_SHOWDEFAULT; /* bit0 = STARTF_USESHOWWINDOW */
```

## Connections
- `GetStartupInfo and Honoring nCmdShow.md` — why/when to consume this (launcher-dependence, honoring requests, the Go regression).
- `vendor/phnt/ntrtl.h` — the `RTL_USER_PROCESS_PARAMETERS` declaration these offsets come from.
- `../(NTAPI) Undocumented Kernel/` — PEB/`gs:[0x60]` access pattern.
