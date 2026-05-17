# Message Queue Implementation (queue.c)

The NT user kernel message queue dispatches input and posted messages in FIFO order. GetMessage blocks the calling thread until a message arrives; PeekMessage returns immediately. The actual ring buffer is per-thread (THREADINFO.mlPost) and is manipulated under a spinlock.

```cpp
// Standard message pump — equivalent to the dequeue path in queue.c
MSG msg = {};
while (GetMessageW(&msg, nullptr, 0, 0)) {
  TranslateMessage(&msg);
  DispatchMessageW(&msg);
}
return (int)msg.wParam;
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/queue.c#L5307
