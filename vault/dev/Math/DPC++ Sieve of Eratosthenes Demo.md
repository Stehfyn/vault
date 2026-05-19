<!-- generated-from-dump2 -->
# DPC++ Sieve of Eratosthenes Demo

Sieve of Eratosthenes written in Intel's Data Parallel C++ (DPC++ / SYCL) - basically C++ with parallel_for kernels that target CPU, GPU, or FPGA via oneAPI. Tiny code; useful as a "hello world" for SYCL: shows how `sycl::queue::parallel_for` over a 1D range maps to GPU lanes, and how to use a shared buffer accessor that auto-syncs host<->device.

```cpp
#include <sycl/sycl.hpp>
using namespace sycl;

int main() {
    constexpr size_t N = 1'000'000;
    std::vector<uint8_t> is_prime(N, 1);
    is_prime[0] = is_prime[1] = 0;

    queue q;
    {
        buffer<uint8_t> buf(is_prime.data(), range(N));
        q.submit([&](handler& h){
            auto a = buf.get_access<access::mode::read_write>(h);
            h.parallel_for(range<1>(N), [=](id<1> i){
                if (a[i]) for (size_t j = 2*i; j < N; j += i) a[j] = 0;
            });
        });
    }
    // is_prime[k] == 1 iff k is prime
}
```

## References
- <https://github.com/roshkins/DPCPPSieve>
