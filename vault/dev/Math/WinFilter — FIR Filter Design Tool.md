<!-- generated-from-dump2 -->
# WinFilter — FIR Filter Design Tool

WinFilter - desktop tool for FIR digital filter design. Lets you specify the spec (low-pass / high-pass / band-pass + passband ripple, stopband attenuation, transition width) and pick a design method (Parks-McClellan / Remez exchange, windowing with Hamming/Hann/Blackman/Kaiser), then visualizes the resulting impulse response, frequency response, and group delay. Exports the coefficient vector ready to paste into a fixed-point DSP. Useful when you'd otherwise reach for MATLAB's Filter Designer.

```text
# Typical workflow inside WinFilter (paraphrased):
#  1. New filter -> Low-pass, fs = 48000 Hz, fpass = 4000 Hz, fstop = 5000 Hz,
#     ripple 0.1 dB, attenuation 60 dB.
#  2. Method: Parks-McClellan. Tool reports needed taps ~107.
#  3. Inspect magnitude + phase plots; if fine, Export -> C array:
#       const float h[107] = { 0.00012f, 0.00031f, ... };
```

## References
- <https://github.com/wyvernSemi/winfilter>
