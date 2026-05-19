<!-- generated-from-dump2 -->
# YOLOv9 Object Detector (PGI + GELAN)

YOLOv9 by Chien-Yao Wang's group — same lineage as YOLOv4/v7. Two contributions: PGI (Programmable Gradient Information) to fight the information bottleneck in deep networks, and GELAN (Generalized Efficient Layer Aggregation Network) replacing CSP-Net for the backbone. On COCO it matches/beats v8 at lower FLOPs at comparable input sizes.

```python
# Inference with the project's CLI:
# python detect.py --weights yolov9-c.pt --source data/images --conf 0.25

# Or load programmatically:
import torch
model = torch.hub.load('WongKinYiu/yolov9', 'custom', path='yolov9-c.pt')
results = model('image.jpg')
results.print()
```

## References
- <https://github.com/WongKinYiu/yolov9>
