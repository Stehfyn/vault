<!-- generated-from-dump2 -->
# gz — Ocarina of Time In-Game Trainer

In-game "trainer" / debug overlay for The Legend of Zelda: Ocarina of Time. Patched into the game ROM (or run on real N64 hardware via Everdrive), gz hooks into the OoT game loop and adds a menu the player can summon mid-frame to manipulate state: warp anywhere, set ages, edit inventory, freeze positions, record/play back inputs, save/load state, view RAM. The community uses it as the standard speedrun practice tool — far more powerful than Bizhawk's generic memory watch because it speaks OoT's internal structs (Link's action state machine, link's collision context, the "actor list," scene segment loads) directly. Source is C + MIPS assembly for the IPL bootstrap; build pipeline produces a patch you apply to your own dumped ROM. Worth reading for an example of large-scale reverse-engineered game state representation in code.

```text
# How it integrates with OoT (high level):
#   1. Patch the game-loop entry (or an early IPL hook) to call gz_main()
#      before the original frame logic.
#   2. gz_main() reads controller state; if menu hotkey is held, render the
#      menu overlay (using the game's own font + DList drawing) and process
#      input on the menu, NOT on Link.
#   3. Cheats / warps / state load is implemented by writing directly into
#      well-known struct fields:
#        z64_game.link.pos    - Link's coordinates
#        z64_game.scene_index - current scene id (warp by changing + flag)
#        z64_file.equipment   - inventory bitmap
#   4. Save-state is a memcpy of the entire game heap to gz-managed RAM.
```

## References
- <https://github.com/glankk/gz>
