<!-- generated-from-dump2 -->
# TRELLIS Image-to-3D Diffusion

Structured 3D asset generation pipeline using a diffusion model in a latent 3D space.

```python
from trellis.pipelines import TrellisImageTo3DPipeline
pipeline = TrellisImageTo3DPipeline.from_pretrained("JeffreyXiang/TRELLIS-image-large")
pipeline.cuda()
outputs = pipeline.run(image, seed=42)
mesh = outputs["mesh"]
```

## References
- <https://github.com/microsoft/TRELLIS>
