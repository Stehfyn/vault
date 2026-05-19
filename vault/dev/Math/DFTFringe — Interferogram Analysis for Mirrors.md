<!-- generated-from-dump2 -->
# DFTFringe — Interferogram Analysis for Mirrors

Niche but technically gorgeous: takes interferogram photos of a polished telescope mirror under a Bath / Newton interferometer and recovers the surface figure to sub-wavelength precision via 2D **Fourier-transform fringe analysis**. The pipeline: image -> FFT -> isolate the +1 side-lobe -> shift to DC -> IFFT -> get the phase map, unwrap it, fit a Zernike polynomial basis to model figure error, and report Strehl ratio + RMS wavefront error. C++/Qt desktop app. This is exactly the FTM (Takeda 1982) technique that earned its inventor a citation in every modern interferometry paper. Read for an honest reference implementation of fringe analysis end-to-end — most published code is locked inside expensive commercial metrology suites.

```text
# Pipeline (Takeda fringe analysis, real code paths in dftfringe.cpp):
#   1. Read interferogram image (grayscale).
#   2. Apply a Hann window to suppress edge artifacts.
#   3. FFT 2D.
#   4. Mask the spectrum: keep only the +1 carrier lobe.
#   5. Shift the lobe to DC.
#   6. IFFT to get the complex analytic signal A(x,y) e^{i*phi(x,y)}.
#   7. phi = atan2(Im, Re); 2D phase unwrap.
#   8. Subtract the spherical reference; convert to surface height (lambda/2).
#   9. Fit Zernike polynomials (Z4..Z36) to the unwrapped phase.
#  10. Report figures of merit: RMS wavefront, P-V, Strehl.
```

## References
- <https://github.com/githubdoe/DFTFringe>
