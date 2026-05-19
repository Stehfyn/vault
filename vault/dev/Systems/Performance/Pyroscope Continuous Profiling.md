<!-- generated-from-dump2 -->
# Pyroscope Continuous Profiling

Continuous profiling platform; use the Go SDK or eBPF for native apps.

```go
import "github.com/grafana/pyroscope-go"

pyroscope.Start(pyroscope.Config{
  ApplicationName: "my-service",
  ServerAddress:   "http://pyroscope:4040",
  ProfileTypes: []pyroscope.ProfileType{
    pyroscope.ProfileCPU,
    pyroscope.ProfileAllocObjects,
  },
})
```

## References
- <https://github.com/grafana/pyroscope>
