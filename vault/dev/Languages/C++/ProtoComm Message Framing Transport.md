<!-- generated-from-dump2 -->
# ProtoComm Message Framing Transport

Modern C++ framing/transport library for multi-message, multi-channel protocols over an arbitrary byte stream (TCP socket, serial line, named pipe). Handles the bits people get wrong when they roll their own: length-prefixed framing, partial reads, sync byte / magic recovery after corruption, channel multiplexing, and optional CRC/checksum validation, with both sync and async APIs. Sits in the same niche as nanopb / Cap'n Proto's RPC layer but smaller in scope — it does not define a wire schema, just delivers complete, validated messages to your callback so your domain code never deals with partial frames.

```cpp
#include <ProtoComm/ProtoComm.h>

protocomm::Channel ch(/* transport = */ tcp_stream);

ch.on_message([](protocomm::Frame f) {
    // f.payload is a complete, length-prefixed, CRC-validated buffer
    handle(std::span<const std::byte>(f.payload));
});

ch.send(protocomm::Frame{
    .channel_id = 1,
    .payload    = make_packet(),
});
```

## References
- <https://github.com/ozguronsoy/ProtoComm>
