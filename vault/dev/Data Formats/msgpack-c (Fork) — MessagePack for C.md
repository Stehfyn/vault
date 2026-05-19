<!-- generated-from-dump2 -->
# msgpack-c (Fork) — MessagePack for C

Fork of the official `msgpack/msgpack-c` reference C implementation. MessagePack is a JSON-equivalent binary format ("schema-less, but compact") with the same data model (nil, bool, int, float, string, bin, array, map, ext) packed into a much smaller byte stream — typical payloads end up 30-50% the size of equivalent JSON, and parsing is faster because there's no string lexing on numbers and no UTF-8 validation on bin types. Used heavily by Redis (RESP3 / msgpack replies), Pinterest, Fluentd, and as the on-wire format for Neovim's RPC. The C library is the lowest common denominator; ports exist for every language.

```c
#include <msgpack.h>

// pack
msgpack_sbuffer sb;
msgpack_sbuffer_init(&sb);
msgpack_packer pk;
msgpack_packer_init(&pk, &sb, msgpack_sbuffer_write);
msgpack_pack_map(&pk, 2);
msgpack_pack_str(&pk, 4); msgpack_pack_str_body(&pk, "name", 4);
msgpack_pack_str(&pk, 5); msgpack_pack_str_body(&pk, "hello", 5);
msgpack_pack_str(&pk, 3); msgpack_pack_str_body(&pk, "val", 3);
msgpack_pack_int(&pk, 42);

// unpack
msgpack_unpacked res;
msgpack_unpacked_init(&res);
size_t off = 0;
while (msgpack_unpack_next(&res, sb.data, sb.size, &off) == MSGPACK_UNPACK_SUCCESS) {
    msgpack_object_print(stdout, res.data);
    putchar('\n');
}
msgpack_unpacked_destroy(&res);
msgpack_sbuffer_destroy(&sb);
```

## References
- <https://github.com/ysc3839/msgpack-c>
