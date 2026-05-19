<!-- generated-from-dump2 -->
# MD4C — Fast CommonMark Parser in C

Strict CommonMark parser written in C with a **SAX-style callback interface** — instead of building a DOM you receive `enter_block`/`leave_block`/`enter_span`/`leave_span`/`text` events as the parser walks the input, which means you can render directly to HTML/PDF/your-own-AST without ever allocating an intermediate tree. ~5-10x faster than cmark and far smaller. Ships an `md2html` renderer as a sample callback consumer. Also implements popular extensions guarded by flags: tables, strikethrough, task lists, GitHub-flavored autolinks, math (`$...$`), wikilinks. Used as the Markdown engine in Qt's `QTextDocument`. Excellent reading for "what does a fast streaming parser actually look like in C."

```c
#include "md4c.h"

static int enter_block(MD_BLOCKTYPE t, void* detail, void* user) {
    if (t == MD_BLOCK_H) fputs("<h>", stdout);
    return 0;
}
static int leave_block(MD_BLOCKTYPE t, void* detail, void* user) {
    if (t == MD_BLOCK_H) fputs("</h>\n", stdout);
    return 0;
}
static int text(MD_TEXTTYPE t, const MD_CHAR* p, MD_SIZE n, void* user) {
    fwrite(p, 1, n, stdout);
    return 0;
}

MD_PARSER parser = { .enter_block = enter_block, .leave_block = leave_block,
                     .text = text };
md_parse(input, input_len, &parser, /*userdata=*/NULL);
```

## References
- <https://github.com/mity/md4c>
