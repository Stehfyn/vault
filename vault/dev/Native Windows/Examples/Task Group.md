A `task_group` wraps the Win32 thread-pool API (`CreateThreadpoolCleanupGroup`, `CreateThreadpoolWork`, `SubmitThreadpoolWork`) to provide structured concurrency: submit arbitrary lambdas as work items, then call `get()` to wait for all of them and rethrow the first exception.

```cpp
struct task_group
{
    task_group()
    {
        InitializeThreadpoolEnvironment(&m_environment);
        m_group = CreateThreadpoolCleanupGroup();
        SetThreadpoolCallbackCleanupGroup(&m_environment, m_group,
            [](void* task_ptr, void* group_ptr) noexcept {
                auto task  = static_cast<task_base*>(task_ptr);
                auto group = static_cast<task_group*>(group_ptr);
                if (group && !group->m_exception)
                    group->m_exception = task->exception;
                delete task;
            });
    }

    ~task_group() noexcept
    {
        CloseThreadpoolCleanupGroupMembers(m_group, true, nullptr);
        CloseThreadpoolCleanupGroup(m_group);
        DestroyThreadpoolEnvironment(&m_environment);
    }

    template <typename T>
    void add(T&& callback)
    {
        auto work = CreateThreadpoolWork(
            [](PTP_CALLBACK_INSTANCE, void* p, PTP_WORK) noexcept {
                static_cast<task_base*>(p)->invoke();
            },
            static_cast<task_base*>(new task<T>(std::forward<T>(callback))),
            &m_environment);
        SubmitThreadpoolWork(work);
    }

    void get()
    {
        CloseThreadpoolCleanupGroupMembers(m_group, false, this);
        if (m_exception) std::rethrow_exception(m_exception);
    }

    // Usage:
    // task_group tg;
    // tg.add([]{ /* work A */ });
    // tg.add([]{ /* work B */ });
    // tg.get(); // blocks until A and B complete

private:
    struct task_base { virtual void invoke() noexcept = 0; std::exception_ptr exception; virtual ~task_base() = default; };
    template <typename T> struct task final : task_base, T {
        task(T&& cb) : T(std::forward<T>(cb)) {}
        void invoke() noexcept final { try { (*this)(); } catch(...) { exception = std::current_exception(); } }
    };
    TP_CALLBACK_ENVIRON m_environment{};
    PTP_CLEANUP_GROUP   m_group{};
    std::exception_ptr  m_exception{};
};
```

## References
- https://gist.github.com/kennykerr/9a44cb113c704bdec2976bdb5073ddc1
