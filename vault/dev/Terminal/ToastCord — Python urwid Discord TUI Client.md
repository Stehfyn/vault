<!-- generated-from-dump2 -->
# ToastCord — Python urwid Discord TUI Client

Deprecated Python TUI Discord client built on `discord.py-self` (self-bot library) and `urwid` for the terminal interface. Reads channels, sends messages, shows typing indicators in a 80x24 box. Abandoned because Discord ToS-bans self-bots, but still useful as a reference for building TUI chat clients over WebSocket protocols.

```python
import urwid

palette = [("header", "white", "dark blue"), ("msg", "light gray", "black")]
body = urwid.SimpleFocusListWalker([urwid.Text(("msg", "hello"))])
frame = urwid.Frame(urwid.ListBox(body),
                    header=urwid.AttrMap(urwid.Text("#general"), "header"),
                    footer=urwid.Edit("> "))
urwid.MainLoop(frame, palette).run()
```

## References
- <https://github.com/lhitori/ToastCord>
