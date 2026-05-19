<!-- generated-from-dump2 -->
# tiny-nginx — Pedagogical Nginx Clone

Pedagogical reimplementation of nginx's core in a few thousand lines of C: epoll-driven event loop, non-blocking accept loop, slab-allocator-style memory pools, HTTP/1.1 parser, and static-file serving. Good companion when reading the real nginx source — the same module shape minus 20 years of features.

```c
// Minimal request handler shape used by the tutorial.
static void on_request(connection_t* c) {
    if (http_parse(&c->req, c->buf, c->n) == HTTP_OK) {
        send_file(c, c->req.uri);   // or 404
    }
    close_connection(c);
}

int main(void) {
    event_loop_t loop; loop_init(&loop);
    listener_t* l = listener_bind(&loop, "0.0.0.0", 8080, on_request);
    loop_run(&loop);
}
```

## References
- <https://github.com/gd-arnold/tiny-nginx>
