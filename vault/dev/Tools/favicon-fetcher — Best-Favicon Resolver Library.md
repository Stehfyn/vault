<!-- generated-from-dump2 -->
# favicon-fetcher — Best-Favicon Resolver Library

Tiny library/service that resolves the "best" favicon for an arbitrary URL - handles the four ways a site can declare one (legacy `/favicon.ico`, `<link rel="icon">`, `<link rel="apple-touch-icon">`, Web App Manifest `icons[]`) plus the Google-favicon shortcut as fallback. Returns the absolute URL or the binary data. Useful when building a bookmark manager / link previewer / chat-link-card feature without rolling your own HTML parser.

```js
import faviconFetcher from "favicon-fetcher";

const url = await faviconFetcher("https://github.com");
// -> "https://github.githubassets.com/favicons/favicon.png"

// Or get the blob directly:
const data = await faviconFetcher("https://news.ycombinator.com", { raw: true });
// -> { contentType: "image/x-icon", buffer: <Uint8Array> }
```

## References
- <https://github.com/victrme/favicon-fetcher>
