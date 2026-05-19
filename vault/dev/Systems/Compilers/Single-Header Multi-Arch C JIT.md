<!-- generated-from-dump2 -->
# Single-Header Multi-Arch C JIT

Single-header C JIT engine that emits machine code into an executable page and lets you call it as a function pointer. Targets i386, x86-64, ARM32, ARM64, and RISC-V 64 with a simple ISA-agnostic IR. Useful as a starting point for tracing JITs, regex compilers, or DSL backends.

```c
#define JIT_IMPL
#include "jit.h"

jit_ctx ctx; jit_init(&ctx);
jit_emit_prolog(&ctx);
jit_emit_load_arg(&ctx, JIT_REG_A, 0);          // a = arg0
jit_emit_load_arg(&ctx, JIT_REG_B, 1);          // b = arg1
jit_emit_add(&ctx, JIT_REG_A, JIT_REG_B);       // a += b
jit_emit_ret(&ctx);

int (*add)(int, int) = (int(*)(int,int))jit_finalize(&ctx);
int s = add(2, 3); // 5
jit_destroy(&ctx);
```

## References
- <https://github.com/abdimoallim/jit>
