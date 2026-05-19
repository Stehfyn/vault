<!-- generated-from-dump2 -->
# PSPNet — Plant and Soil Property Classifier Stack

Research platform for classifying plant and soil properties pre- and post-wildfire from field images. Not just a model — a full stack: a Vue frontend for public image contribution and dataset browsing, a Python backend that queues classification jobs, GPU worker processes (CUDA/PyTorch) that run the classifier, and a Docker-compose deployment story for spinning the whole thing up. Despite the name, the architecture is not necessarily the canonical PSPNet (pyramid scene parsing) from CVPR 2017 — the name appears to be reused for "Plant and Soil Property NETwork." Useful as a reference for a small research-group ML web app that doesn't try to be Kubernetes-native.

```text
# Service layout (per docker-compose):
#   pspnet-vue       - Vue/Vite frontend
#   pspnet-server    - Python (FastAPI/Flask) API + auth + job queue
#   pspnet-worker    - GPU worker pulling jobs, running the classifier
#   pspnet-db        - Postgres or similar for users/datasets/jobs
#
# Upload flow:
#   1. User uploads image via Vue UI
#   2. server stores image + enqueues classification job
#   3. worker pulls job, runs model on image, writes predicted labels
#   4. UI polls for completion, displays segmentation overlays
```

## References
- <https://github.com/cantiado/pspnet>
