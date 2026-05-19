# MessageDispatcherApi.h

Lower-level entry points for `coremessaging.dll`'s message dispatcher -- the post-Win32-message-loop primitive that backs `DispatcherQueue`, `CoreDispatcher`, and the WinUI 3 / Composition pump. Where `DispatcherQueue.h` is the consumer-facing surface, this is closer to the metal: raw `IMessageDispatcher` / `IDispatcherHandler` interfaces, hooks for setting the message-pump callback, awakening primitives the kernel uses to wake an idle Core dispatcher when a new piece of work arrives. Almost nobody outside Microsoft's own UI frameworks should be touching this directly; the modern user path is `DispatcherQueueController::CreateOnDedicatedThread` / `DispatcherQueue::TryEnqueue`.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/dispatcherqueue/>
