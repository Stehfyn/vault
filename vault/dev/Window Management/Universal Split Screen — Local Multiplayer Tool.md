<!-- generated-from-dump2 -->
# Universal Split Screen — Local Multiplayer Tool

Bypasses the dead state of local split-screen on PC by running N copies of the same game side-by-side, each routed to its own keyboard/mouse/controller, with the windows borderless-fullscreened and tiled across the screen. Uses RawInput interception to bind specific HID devices to specific game instances, plus per-instance handle/window manipulation so each game thinks it owns the foreground. Practical for the kinds of games that shipped with online multiplayer but never local co-op (modern shooters, racing games, MMO leveling buddies on one machine). Works best with games that tolerate multiple instances and don't rely on exclusive fullscreen or single-instance mutexes.

```text
Typical setup:
  1. Launch UniversalSplitScreen as administrator (RawInput hooking needs it).
  2. Add the game executable; pick a layout (2x1, 2x2, etc.).
  3. Plug in each player's input devices and bind device IDs to instance slots.
  4. Hit Launch — each game window is moved, resized, and given input from
     only its assigned devices. Audio routing is on you (Voicemeeter, etc.).
Common breakage: anti-cheat (will refuse to run multiple instances) and any
game that probes WM_ACTIVATE to pause itself when not focused.
```

## References
- <https://github.com/UniversalSplitScreen/UniversalSplitScreen>
