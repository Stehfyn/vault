<!-- generated-from-dump2 -->
# Single-Header C JSON Parser (abdimoallim)

Single-header C JSON parser/serialiser claiming RFC 8259 conformance. This particular space is crowded — jsmn, cJSON, jansson, parson, json-c, yyjson, RapidJSON (C++), simdjson (C++) — so any new entry has to justify itself on size, parsing speed, allocation behaviour, or API ergonomics. Verify the usual things before depending on it: how it handles numeric precision (doubles vs. arbitrary precision), whether it allocates per-node or uses an arena, whether it accepts trailing commas / comments (an RFC violation many libs allow), and how it reports errors with line/column information.

```c
// Conceptual sketch — the exact symbol names live in the project header.
// Most single-header C JSON libs share the same shape: a parse function
// returning a tree of tagged-union nodes, plus accessors and a serialiser.
#include "json.h"

const char *src = "{\"name\":\"test\",\"values\":[1,2,3]}";
json_value *root = json_parse(src, strlen(src));
if (root && root->type == json_object) {
    json_value *v = json_object_get(root, "values");
    for (size_t i = 0; i < v->u.array.length; i++) {
        printf("%g\n", v->u.array.values[i]->u.dbl);
    }
}
json_free(root);
```

## References
- <https://github.com/abdimoallim/json>
