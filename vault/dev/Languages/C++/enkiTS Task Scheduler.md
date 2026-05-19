<!-- generated-from-dump2 -->
# enkiTS Task Scheduler

Doug Binks' permissive C/C++ task scheduler — work-stealing thread pool aimed at games and tools. Distinguished from typical thread pools by `ITaskSet` (a divisible task: scheduler decides how to split the index range across cores) and `IPinnedTask` (a task that must run on a *specific* thread, e.g. a thread that owns an OS resource like an OpenGL context or a Win32 window). Both make it a much better fit for engine work than `std::async` or a plain pool, because GPU APIs frequently demand "must call from the thread that created the context" and OS message pumps demand "must run on the UI thread." MIT, no dependencies, C interface available alongside the C++ one. Maintained, used in real games.

```cpp
#include <TaskScheduler.h>
enki::TaskScheduler g_TS;

struct ParallelSum : enki::ITaskSet {
    int*   data;
    int64_t partials[64]{};

    void ExecuteRange(enki::TaskSetPartition r, uint32_t threadnum) override {
        int s = 0;
        for (uint32_t i = r.start; i < r.end; ++i) s += data[i];
        partials[threadnum] += s;
    }
};

g_TS.Initialize();
ParallelSum task;
task.m_SetSize = 1'000'000;
task.data      = buffer;
g_TS.AddTaskSetToPipe(&task);
g_TS.WaitforTask(&task);
```

## References
- <https://github.com/dougbinks/enkiTS>
