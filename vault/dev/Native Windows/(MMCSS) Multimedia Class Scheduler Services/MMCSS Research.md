# MMCSS Research

MMCSS is the compromise Windows uses for media workloads that need low jitter but cannot be allowed to monopolize the machine like a hard real-time scheduler. Threads call `AvSetMmThreadCharacteristicsW` with task names such as `Audio`, `Pro Audio`, or `Games`; policy then comes from `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile\Tasks\<TaskName>`.

The useful research detail in the linked thread is not a magic registry tweak; it is the interaction among `Scheduling Category`, `BackgroundPriority`, clock-rate behavior, and the hidden-looking `Latency Sensitive` value under load. Treat the values as workload policy: changes should be measured with ETW/audio glitch counters, not copied as universal "latency optimization."

## API Skeleton

The application-side contract is small: join a named MMCSS task for the hot thread, optionally request a relative MMCSS priority, do bounded work, then revert before thread teardown.

```cpp
#include <avrt.h>
#pragma comment(lib, "avrt.lib")

DWORD task_index = 0;
HANDLE mmcss = AvSetMmThreadCharacteristicsW(L"Pro Audio", &task_index);
if (mmcss) {
    AvSetMmThreadPriority(mmcss, AVRT_PRIORITY_HIGH);

    while (running) {
        ProcessAudioOrFrameCallback();
    }

    AvRevertMmThreadCharacteristics(mmcss);
}
```

For graphics work, MMCSS is scheduler policy, not a present primitive. It can reduce CPU-side jitter in a capture/encode or audio/render callback thread, but it does not replace `../(DWM) Desktop Window Manager/VBlank Wait.md`, `../(DWM) Desktop Window Manager/DCompositionWaitForCompositorClock — Decompiled.md`, or `../(GL) OpenGL/VSync (OpenGL).md`.

## Experiment Harness

Goal: prove whether MMCSS reduces callback jitter for one hot thread under load, not whether a registry tweak is "faster."

Procedure:
1. Start two identical periodic workers pinned to the same CPU group: baseline and MMCSS.
2. In the MMCSS worker, call `AvSetMmThreadCharacteristicsW(L"Pro Audio", &task_index)` and optionally `AvSetMmThreadPriority(..., AVRT_PRIORITY_HIGH)`.
3. Every 1 ms or 2 ms, record `QueryPerformanceCounter` deltas, missed deadlines, and max consecutive overruns while a separate process burns CPU.
4. Repeat for `Audio`, `Pro Audio`, `Games`, and no MMCSS; do not edit registry policy until this baseline exists.

```cpp
auto t0 = qpc();
for (uint64_t i = 0; i != samples; ++i) {
    wait_until_qpc(t0 + i * period_ticks);
    auto late = qpc() - (t0 + i * period_ticks);
    histogram.add(late);
    do_bounded_callback_work();
}
```

Metric: p50/p95/p99 wake lateness, max lateness, missed periods, and callback work time. Pair with WPA/ETW CPU scheduling traces if the histogram changes.

Failure interpretation: `AvSetMmThreadCharacteristicsW` returning null usually means bad task name, stopped MMCSS service, or unsupported OS. No improvement usually means the bottleneck is GPU present, blocking I/O, lock contention, timer resolution, or too much work in the callback. Worse foreground/background behavior means the selected task policy is wrong for the workload.

References: existing `AvSetMmThreadCharacteristicsW` and MMCSS overview links below; pair results with `../(DX) DirectX/Screen Capture to H.264.md` when testing capture/encode threads and `../(DWM) Desktop Window Manager/VBlank Wait.md` when testing display cadence.

## Source Code Reading

The most concrete linked-source example in this graphics/media slice is actually the IDD sample's swap-chain processor (`Display Control/IddSampleDriver - Virtual Monitor (Win10).md`, source file `IddSampleDriver/Driver.cpp`). Its `SwapChainProcessor::Run` joins MMCSS before entering the frame loop and reverts after the loop:

```cpp
DWORD task_index = 0;
HANDLE task = AvSetMmThreadCharacteristicsW(L"Distribution", &task_index);
RunCore();                         // waits for IDDCX frames and processes them
WdfObjectDelete((WDFOBJECT)swapchain);
AvRevertMmThreadCharacteristics(task);
```

That is the right shape for display/capture work: apply MMCSS to the thread that consumes a frame queue and must not be starved under CPU load. It is not a blanket process setting. `RunCore` then binds the IDDCX swap chain to the DXGI device with `IddCxSwapChainSetDevice`, loops over `IddCxSwapChainReleaseAndAcquireBuffer`, does bounded per-frame work, calls `IddCxSwapChainFinishedProcessingFrame`, and only then reports optional frame statistics. The scheduler hint is useful only if this loop is actually missing deadlines because of CPU scheduling.

`microsoft/low-latency-audio` provides the adjacent audio-thread shape. `src/uac2-driver/WorkerThread.cpp` creates a kernel worker with `PsCreateSystemThread`, references it with `ObReferenceObjectByHandle`, sets thread priority with `KeSetPriorityThread`, gates startup with kernel events, wakes the worker with `KeSetEvent`, and waits with `KeWaitForMultipleObjects`. That is not the same API as user-mode MMCSS, but it teaches the same hot-path rule: pre-create the thread, signal it with cheap events, and do bounded work once awake.

Probe implication: for user-mode media code, combine the two patterns. Use `AvSetMmThreadCharacteristicsW` on the exact capture/audio/encode callback thread, drive wakeups from a waitable timer/event or frame-available event, and record wake lateness plus callback duration. If the event arrives late, MMCSS may help. If the event arrives on time but processing overruns, fix the work or pipeline queue first.

## Discussion Claim To Verify

The Overclock thread's valuable content is not the registry table itself; it is the assertion that task policy values such as `Scheduling Category`, `BackgroundPriority`, `Clock Rate`, and `Latency Sensitive` change behavior under load. Turn that into a controlled thread experiment before editing policy.

```cpp
for (auto task : { L"Audio", L"Pro Audio", L"Games", L"Distribution" }) {
    DWORD index = 0;
    HANDLE h = AvSetMmThreadCharacteristicsW(task, &index);
    AvSetMmThreadPriority(h, AVRT_PRIORITY_HIGH);
    RunPeriodicWorker(task, 1000us, 30000_samples, CpuLoad::SaturateOneCore);
    AvRevertMmThreadCharacteristics(h);
}
```

Verification route: collect app-side wake-lateness histograms and an ETW CPU scheduling trace in WPA. Then, only in an isolated VM or throwaway test profile, change one registry field at a time, restart the MMCSS service or reboot as required, and repeat. The claim is confirmed only if the same thread, same workload, and same load source show a statistically meaningful p95/p99 lateness change that WPA attributes to scheduling priority/quantum behavior. It is nullified if the improvement disappears when timer resolution, CPU affinity, power plan, and lock contention are controlled.

## Connections
- `Low-Latency Audio — ASIO Driver Samples.md` for a workload that actually needs MMCSS.
- `Power State APIs` because media apps often coordinate scheduler hints with sleep/display inhibition.
- `Windows-11-Latency-Optimization Scripts` as the cautionary opposite: broad tweaks without a workload model are hard to trust.
- `../(DX) DirectX/Screen Capture to H.264.md` is a graphics-adjacent workload where capture, conversion, and encode threads can benefit from measured scheduling policy.
- `../(DWM) Desktop Window Manager/VBlank Wait.md` separates display timing from CPU scheduling priority.

## References
- <https://www.overclock.net/threads/research-on-multimedia-class-scheduler-service-mmcss.1774590/>
- <https://learn.microsoft.com/en-us/windows/win32/api/avrt/nf-avrt-avsetmmthreadcharacteristicsw> - `AvSetMmThreadCharacteristicsW` reference.
- <https://learn.microsoft.com/en-us/windows/win32/procthread/multimedia-class-scheduler-service> - MMCSS service and task policy overview.
