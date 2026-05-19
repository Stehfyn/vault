<!-- generated-from-dump2 -->
# Hacktical C — Patterns and Techniques

A book-length tour of patterns C books usually don't teach — intrusive linked lists, vector/deque/heap implementations, error-handling chains, dynamic arrays with realloc growth strategies, an arena allocator, a Forth-style virtual machine, coroutines, and a Lisp interpreter — written from the perspective of someone who works the language, not a CS101 syllabus. Each chapter ships with runnable code in its own subdir. Sits in the same niche as "21st Century C" and Hanson's "C Interfaces and Implementations" but more idiosyncratic and more about the tricks than the libraries.

```c
// Flavour: intrusive linked list (chapters 1-3) using container_of.
// Lists never own elements - elements embed the link.
struct list { struct list *prev, *next; };

#define container_of(ptr, type, member) \
    ((type*)((char*)(ptr) - offsetof(type, member)))

struct item { int v; struct list link; };

void list_init(struct list* l) { l->prev = l->next = l; }
void list_push(struct list* l, struct list* n) {
    n->prev = l->prev; n->next = l;
    l->prev->next = n; l->prev = n;
}

struct list q; list_init(&q);
struct item a = {.v = 42};
list_push(&q, &a.link);
// Walk:
for (struct list* it = q.next; it != &q; it = it->next)
    printf("%d\n", container_of(it, struct item, link)->v);
```

## References
- <https://github.com/codr7/hacktical-c>
