<!-- generated-from-dump2 -->
# YOLOv10 — NMS-Free Object Detector

YOLOv10 (NeurIPS 2024) — Tsinghua's object detector that drops the long-time YOLO crutch of post-hoc NMS by training with a *consistent dual assignment*: a one-to-many head (rich gradient signal) plus a one-to-one head (NMS-free inference). On COCO it's faster than YOLOv9 at the same AP. Ships in N/S/M/B/L/X sizes and is API-compatible with Ultralytics.

```python
from ultralytics import YOLOv10

model = YOLOv10.from_pretrained("jameslahm/yolov10n")
results = model.predict(source="image.jpg", conf=0.25, iou=0.45)
for r in results:
    for box in r.boxes:
        print(box.xyxy, box.conf, box.cls)
```

## References
- <https://github.com/THU-MIG/yolov10>
