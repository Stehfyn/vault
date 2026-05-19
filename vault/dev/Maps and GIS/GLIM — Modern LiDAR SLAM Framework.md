<!-- generated-from-dump2 -->
# GLIM — Modern LiDAR SLAM Framework

Kenji Koide's (AIST) modern LiDAR SLAM framework, a successor in spirit to his earlier hdl_graph_slam and LIO-SAM-style pipelines. Uses GICP/VGICP scan matching on the front end and a sliding-window factor-graph (typically built on g2o or GTSAM) on the back end with optional global pose-graph optimisation and loop closure. Strong on Velodyne/Ouster/Livox spinning lidars plus IMU fusion; runs on the CPU but the VGICP step is GPU-accelerated via CUDA when available. Filed here because the practical use case is mapping outdoor environments and producing georeferenced point clouds for downstream GIS work.

```bash
# Typical usage is via ROS2 with a launch file from the repo:
ros2 launch glim_ros glim_rosbag.launch.py
# Inputs:  /points (PointCloud2)  /imu (Imu)
# Outputs: /glim_ros/map (point cloud), /glim_ros/pose (TF), final dump on shutdown
```

## References
- <https://github.com/koide3/glim>
