<!-- generated-from-dump2 -->
# GauGAN Frame-by-Frame Video Stylizer

Frame-by-frame video stylization pipeline that drives Nvidia Canvas (the GauGAN-based sketch-to-photo tool) from a script. The non-obvious trick is the color-quantization step: GauGAN expects a labeled segmentation map (each region painted in one of ~30 fixed "material" colors — grass, sky, sand, etc.), so the project has multiple `ImageConvert*` variants that try HSV thresholding, LAB nearest-neighbor, and naive color rounding to coerce arbitrary input frames into that palette before sending each one off to be hallucinated into a photo. Result is a per-frame Markov-style pipeline with no temporal coherence — flicker is part of the aesthetic.

```python
# Pipeline shape (real entry points live in GUI.py / GauganSend.py):
# 1. VideoImage.extract(input.mp4)          -> frames/*.png
# 2. ImageConvertLAB.snap_to_palette(frame) -> segmentation_map.png
# 3. GauganSend.upload_and_generate(map)    -> stylized.png   (Canvas web API)
# 4. ImageVideo.assemble(stylized/*.png)    -> output.mp4
```

## References
- <https://github.com/DuckieOnQuacks/AIGeneratedVideo>
