<!-- generated-from-dump2 -->
# GIMP Beautify — One-Click Photo Filter Scripts

GIMP Script-Fu / Python-Fu plugin bundle that adds one-click "beautify photo" filters in the style of mid-2010s phone camera apps: skin smoothing, eye enhance, whitening, sharpening, "filters" presets, blemish removal. Implemented as compositions of GIMP's existing primitives (Gaussian blur, levels, selective recolor, hue/saturation) rather than custom C plugins — so it's a useful read for "how do I script complex multi-layer manipulations in GIMP." Installs as drop-in scripts under `~/.config/GIMP/2.10/scripts/` and registers a "Beautify" menu.

```scheme
; Conceptual: skin-smooth via frequency separation, the recipe most
; one-click beauty filters reproduce. (Real impl is more elaborate.)
(define (beautify-skin-smooth image drawable amount)
  (let* ((blur (car (gimp-layer-copy drawable TRUE))))
    (gimp-image-insert-layer image blur 0 -1)
    (plug-in-gauss RUN-NONINTERACTIVE image blur amount amount 0)
    (gimp-layer-set-mode blur LAYER-MODE-GRAIN-MERGE-LEGACY)
    (gimp-image-flatten image)))

(script-fu-register
  "beautify-skin-smooth" "Beautify Skin"
  "Skin-smoothing filter" "author" "MIT" "2026"
  "RGB*" SF-IMAGE "" SF-DRAWABLE "" SF-VALUE "Amount" "10")
(script-fu-menu-register "beautify-skin-smooth" "<Image>/Beautify")
```

## References
- <https://github.com/hejiann/beautify>
