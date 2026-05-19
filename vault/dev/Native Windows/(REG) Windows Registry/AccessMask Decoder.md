# AccessMask Decoder

Pavel Yosifovich's pedagogical decoder for the 32-bit `ACCESS_MASK`: the layout is the same regardless of object type (16 bits of specific rights, 5 standard rights, 4 generic rights, plus `ACCESS_SYSTEM_SECURITY` and `MAXIMUM_ALLOWED`), but the *meaning* of bits 0..15 is per-type and only resolves once you apply that type's `GENERIC_MAPPING`. The tool exists because reading a raw `0x001F0FFF` out of Process Explorer or a handle dump tells you nothing without a per-object decode table — process, thread, token, file, registry key, and section objects all reuse the same bits for different rights. Note that `MapGenericMask` translates GENERIC_* into specific bits and *clears* the generic bits in place; if you forget that and OR the original mask back in you'll get a "double mapping" that grants more than intended.

For registry work, the practical link is `KEY_READ`, `KEY_WRITE`, `KEY_QUERY_VALUE`, `KEY_SET_VALUE`, `KEY_ENUMERATE_SUB_KEYS`, and `KEY_NOTIFY`: these are just object-specific low bits inside the same `ACCESS_MASK` framework. That is why security descriptors, handle dumps, service ACLs, and token rights all look deceptively similar until decoded against the right object type.

## Connections
- `winnt.h` defines `ACCESS_MASK`, standard rights, generic rights, and the security descriptor vocabulary.
- Registry entries in this directory use the same mask model when opening keys with `RegOpenKeyExW`.

## References
- <https://github.com/zodiacon/AccessMask>
