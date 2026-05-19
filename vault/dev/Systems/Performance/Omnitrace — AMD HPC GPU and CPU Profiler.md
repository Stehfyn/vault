<!-- generated-from-dump2 -->
# Omnitrace — AMD HPC GPU and CPU Profiler

AMD's HPC profiler/tracer (now rebranded as part of `rocprof-sys`). Combines CPU sampling, ROCm HIP/HSA GPU tracing, MPI/OpenMP regions, and binary instrumentation (Dyninst) into a single Perfetto-compatible trace. Aimed at heterogeneous CPU+GPU clusters on MI200/MI300-class hardware.

```bash
# Sample-mode profile of an existing binary with no source changes.
omnitrace-sample -- ./my_hip_app
# Or instrument and run; emits .proto/.json for Perfetto and roofline.
omnitrace-instrument -o my_hip_app.inst -- ./my_hip_app
omnitrace-run -- ./my_hip_app.inst
```

## References
- <https://github.com/ROCm/omnitrace>
