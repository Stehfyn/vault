<!-- generated-from-dump2 -->
# MASM32 Demoscene Graphical Effects

Collection of classic 90s warez-scene graphical effects rewritten in MASM32 assembly: plasma, fire, tunnel, metaballs, rotozoom, sine-scrollers. Each is a complete tiny Win32 program that opens a GDI/DirectDraw window and runs the effect in tight asm. Useful as a study of (a) the kind of integer-math tricks demosceners used pre-pixel-shaders (fixed-point sine LUTs, palette rotation, dirty-rect updates), and (b) how to do raw-Win32 DirectDraw blits from MASM.

```asm
; Conceptual fragment from a tunnel effect (paraphrased):
;   per pixel (x, y) precompute:
;       angle = atan2(y - cy, x - cx)
;       depth = sqrt((x-cx)^2 + (y-cy)^2)
;   per frame:
;       offset_a = frame * SPEED
;       offset_d = frame * DEPTH_SPEED
;       texel    = texture[(angle + offset_a) & 0xff,
;                          (depth + offset_d) & 0xff]
mov   esi, OFFSET LUT_angle
mov   edi, framebuf
xor   ebx, ebx       ; pixel index
.loop:
    mov   eax, [esi + ebx*4]
    add   eax, frame_phase
    and   eax, 0FFh
    mov   al, [texture + eax]
    mov   [edi + ebx], al
    inc   ebx
    cmp   ebx, 320*200
    jl    .loop
```

## References
- <https://github.com/Xyl2k/MASM32-graphical-effects>
