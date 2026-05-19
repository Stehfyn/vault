<!-- generated-from-dump2 -->
# BSZGW — PyGObject Widget Helpers

Thin Python wrapper around PyGObject / GTK that replaces the verbose GTK widget construction with one-liner helpers — `Button(label, callback)`, `Entry(label, default)`, `Checkbox(label, default)` etc., plus container helpers that pack them with sensible defaults. Author's own toolkit for cranking out small GTK dialogs without learning the full GTK builder/signal/box-packing dance. Not a full framework, deliberately small — for anything beyond simple settings dialogs you'd still fall back to raw `Gtk.*`. Sibling to `Beinsezii/bsz-gimp-plugins` (which uses BSZGW for plugin UIs).

```python
import bszgw

def on_ok(button):
    print("name:", name.get_text(), "subscribe:", sub.get_active())

win   = bszgw.Window("Demo", 320, 160)
name  = bszgw.Entry("Name", default="anon")
sub   = bszgw.Checkbox("Subscribe", default=True)
ok    = bszgw.Button("OK", on_ok)

win.add(bszgw.VBox([name, sub, ok]))
win.run()
```

## References
- <https://github.com/Beinsezii/BSZGW>
