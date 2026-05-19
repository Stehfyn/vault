<!-- generated-from-dump2 -->
# libnuwen — Legacy Win32 C Utility Library

Unofficial Git mirror of Steve Wells's `libnuwen` from nuwen.net — a small C utility library (string helpers, file I/O wrappers, simple sockets) originally bundled with his MinGW distro. Mainly of historical interest as an example of pre-modern-C++ Win32 helpers, but the socket wrappers still work on contemporary winsock.

```c
#include "nuwen/socket.h"
nu_socket s = nu_socket_connect("example.com", 80);
nu_socket_write(s, "GET / HTTP/1.0\r\nHost: example.com\r\n\r\n", 39);
char buf[4096]; int n = nu_socket_read(s, buf, sizeof buf);
nu_socket_close(s);
```

## References
- <https://github.com/nurettin/libnuwen>
