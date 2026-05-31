/*
 * tiny_target.c — a Windows PE with no CRT, no imports, no anything.
 *
 * Built with /ENTRY:my_entry /NODEFAULTLIB /SUBSYSTEM:CONSOLE.
 *
 * Used by 08_skip_loader_init: when launched with
 * THREAD_CREATE_FLAGS_SKIP_LOADER_INIT, the kernel jumps the first
 * thread directly to my_entry without running LdrInitializeThunk.
 * The infinite loop here gives the parent a chance to suspend the
 * thread and inspect the child's PEB to confirm that PEB->Ldr is
 * still NULL (loader never initialized).
 */

void my_entry(void)
{
    /* Spin forever. The parent terminates us. We use __nop so the
     * compiler doesn't optimize the loop body away even at /O2. */
    for (;;) {
        __nop();
    }
}
