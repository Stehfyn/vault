<!-- generated-from-dump2 -->
# RT-Thread — Chinese-Origin RTOS

Chinese-origin RTOS that is genuinely a peer to FreeRTOS/Zephyr in scope: preemptive priority scheduler, kernel objects (threads, semaphores, mutexes, mailboxes, message queues, event sets), a POSIX-ish device driver framework, a virtual filesystem, lwIP-based networking, USB stacks, and a packaging system (RT-Thread Studio + Env) that pulls in components from a registry. Strong board support inside China (GD32, AT32, HC32, Renesas RA, plus the usual STM32/NXP/Nordic) and a finsh/MSH CLI shell that drops you into a Unix-like prompt on the target. The trade-off against Zephyr is a smaller English-language community and documentation; against FreeRTOS, a much bigger and more opinionated stack.

```c
#include <rtthread.h>

#define THREAD_STACK_SIZE  512
#define THREAD_PRIORITY    25
#define THREAD_TIMESLICE   5

static void blink_entry(void *param) {
    while (1) {
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}

int main(void) {
    rt_thread_t t = rt_thread_create("blink", blink_entry, RT_NULL,
                                     THREAD_STACK_SIZE, THREAD_PRIORITY, THREAD_TIMESLICE);
    if (t) rt_thread_startup(t);
    return 0;
}
```

## References
- <https://github.com/RT-Thread/rt-thread>
