<!-- generated-from-dump2 -->
# choc — Header-Only C++ Utilities (Tracktion)

Tracktion's "Classes of Header-Only Cunning" — a permissively-licensed grab-bag of single-header C++17 utilities used inside Tracktion Engine: WebView wrappers, MIDI parsers, OSC, JSON/YAML, audio buffer helpers, MessagePack, value trees, javascript engines (QuickJS/Duktape wrappers). Notable because *every* class is meant to compile with zero external deps. Useful as a piecemeal alternative to JUCE for audio-tool plumbing.

```cpp
#include <gui/choc_WebView.h>
choc::ui::WebView::Options opts;
opts.enableDebugMode = true;
choc::ui::WebView webview(opts);
webview.setHTML("<h1>hello from choc</h1>");

webview.bind("nativeAdd", [](const choc::value::ValueView& args) {
    return choc::value::createInt32(args[0].getInt32() + args[1].getInt32());
});
```

## References
- <https://github.com/Tracktion/choc>
