<!-- generated-from-dump2 -->
# pokerom-trader — Gen 1/2 Save Trade Tool

Tool for trading Pokemon between Generation-1 and Generation-2 Game Boy / GBC save files. Implements the link-cable trade protocol against in-memory save-file structures: parses the save (PARTY_DATA, BOX_DATA structures at well-known offsets, both Gen-I and Gen-II layouts), runs the IR/SIO handshake state machine in software, and writes the modified slot back. Useful as a reference of Gen-1/2 save-file internals - those structs are otherwise documented mostly in Bulbapedia and disassembly projects.

```text
# Conceptual flow:
#  1. Load source.sav and target.sav.
#  2. Parse PartyData (offset 0x2F2C in Red/Blue) -> list of trainer's Pokemon.
#  3. User picks indices to trade; tool verifies legality (no glitches, etc).
#  4. Swap byte ranges between the two saves, recompute the per-slot checksum
#     (1-byte sum at end of each save block), recompute the global save-file
#     checksum (2 bytes at 0x3523/0x2D6B).
#  5. Write modified saves back.
```

## References
- <https://github.com/savaughn/pokerom-trader>
