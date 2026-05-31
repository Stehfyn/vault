# Low-Latency Audio - ASIO Driver Samples

Microsoft's `low-latency-audio` samples are useful because ASIO lives outside the normal WASAPI shared-mode comfort zone: small buffers, strict callback timing, and driver/user-mode boundaries become visible immediately. The repo is a concrete reference for the plumbing around a low-latency audio path rather than another explanation of what latency is.

Read it beside `MMCSS Research`. ASIO, WASAPI exclusive mode, and pro-audio engines all end up caring about thread priority, timer behavior, CPU contention, and avoiding page faults in the hot path; MMCSS is the Windows mechanism that keeps real-time-ish audio work from being starved without giving arbitrary code true hard-real-time priority.

## Source Code Reading

The repo has two useful sides. `src/uac2-asio` is the user-facing ASIO/control surface, while `src/uac2-driver` is the ACX/driver side where timing and buffer movement matter. For scheduler experiments, read `src/uac2-driver/WorkerThread.cpp` first: `WorkerThread::CreateThread` calls `PsCreateSystemThread`, references the returned thread object, sets priority with `KeSetPriorityThread`, waits until the thread reports ready, then releases it with a start event. `Terminate` sets a kill event and waits for the thread object before dereferencing it.

The kernel worker shape is:

```cpp
KeInitializeEvent(&ready, NotificationEvent, FALSE);
KeInitializeEvent(&kill, NotificationEvent, FALSE);
KeInitializeEvent(&wake, SynchronizationEvent, FALSE);
PsCreateSystemThread(&thread, THREAD_ALL_ACCESS, ..., ThreadRoutine, this);
ObReferenceObjectByHandle(thread, THREAD_ALL_ACCESS, ..., KernelMode, &thread_object, ...);
KeSetPriorityThread(thread_object, priority);
KeWaitForMultipleObjects(... ready/thread ...);
KeSetEvent(&start, EVENT_INCREMENT, FALSE);
```

The code contribution for user-mode ASIO/MMCSS probes is the same structure with different APIs: create the hot thread once, raise it into the appropriate media task only inside that thread, wait on a cheap event, process one bounded buffer, and exit through a clean revert path. Do not allocate, enumerate devices, parse settings, or touch UI state in the callback loop.

## References
- <https://github.com/microsoft/low-latency-audio>
