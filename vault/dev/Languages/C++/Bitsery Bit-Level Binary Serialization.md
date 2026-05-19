<!-- generated-from-dump2 -->
# Bitsery Bit-Level Binary Serialization

Header-only C++14 binary serialization aimed at game-network-packet sizes — packs values at bit-level granularity, not byte-level. The distinguishing features vs. cereal/Boost.Serialization: (1) you can serialize a value in *N bits* (`s.value4b(x)` is 4 bytes; `s.bits(myEnum, 3)` is 3 bits and packs into the next byte), (2) `s.range(value, {min, max})` writes only the bits needed to encode the integer range, and (3) optional variable-length encoding via `s.text<sizeof(char)>(str, max)`. The shape is the classic free-function `serialize(s, obj)` overloads, so the same function is used for both pack and unpack — there's no DOM, no schema, just function templates. Output is non-self-describing (no field names) so it's tight but you must serialize identical versions on both ends.

```cpp
#include <bitsery/bitsery.h>
#include <bitsery/adapter/buffer.h>

struct Move { uint32_t entity; float x, y; uint8_t state; };

template<typename S>
void serialize(S& s, Move& m) {
    s.value4b(m.entity);
    s.value4b(m.x);
    s.value4b(m.y);
    s.bits(m.state, 3);            // only 3 bits!
}

using Buffer = std::vector<uint8_t>;
Buffer buf;
Move out{42, 1.5f, -2.0f, 5};
auto n = bitsery::quickSerialization(bitsery::OutputBufferAdapter<Buffer>{buf}, out);

Move in;
auto res = bitsery::quickDeserialization(
    bitsery::InputBufferAdapter<Buffer>{buf.begin(), n}, in);
```

## References
- <https://github.com/fraillt/bitsery>
