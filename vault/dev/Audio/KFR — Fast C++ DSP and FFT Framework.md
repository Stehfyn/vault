<!-- generated-from-dump2 -->
# KFR — Fast C++ DSP and FFT Framework

KFR — fast modern C++ DSP framework: FFT, FIR/IIR/biquad filter design, resampling, windowing functions, audio I/O. Hand-tuned SIMD kernels (SSE/AVX/AVX-512/NEON/RVV), competitive with FFTW for sizes that fit in cache, often faster on AVX-512. Apache-2 license. The non-obvious thing is its expression-template DSL: `dft(input * window(len, hann))` builds a graph that fuses passes.

```cpp
#include <kfr/dsp.hpp>
using namespace kfr;

univector<float> signal = sinenorm(phasor(440.0, 44100.0), 4096);
auto spectrum = realdft(signal * window_hann(signal.size()));

// Design a 4th-order Butterworth low-pass at 1 kHz, fs = 44.1 kHz.
biquad_params<fbase> bq[2];
zpk<fbase> z = iir_lowpass(butterworth<fbase>(4), 1000.0, 44100.0);
to_sos(z, bq);
univector<float> filtered = biquad(bq, signal);
```

## References
- <https://github.com/kfrlib/kfr>
