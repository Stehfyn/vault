<!-- generated-from-dump2 -->
# PythonRobotics — Robotics Algorithms in Python

Atsushi Sakai's de-facto reference collection of robotics algorithm implementations in pure Python — path planning (A*, RRT, RRT*, Dubins curves, hybrid A*), localization (EKF, UKF, particle filter), SLAM (FastSLAM, GraphSLAM, ICP), control (LQR, MPC, pure pursuit), trajectory tracking, manipulation. Each file is self-contained, matplotlib-animated, and explicitly meant as a *learning* artifact — the algorithms are written for clarity and visual debugability, not for speed (no Cython, no `numba`). Heavily cited in robotics coursework worldwide; the companion `arXiv:1808.10703` paper formalizes it as a teaching aid. For production code people port these to C++/Rust afterwards — but for understanding the math + control flow, this is the canonical Python source.

```bash
git clone https://github.com/AtsushiSakai/PythonRobotics
cd PythonRobotics
pip install -r requirements/requirements.txt

# Each example is a runnable script with built-in matplotlib animation
python PathPlanning/RRTStar/rrt_star.py
python Localization/extended_kalman_filter/extended_kalman_filter.py
python PathTracking/model_predictive_speed_and_steer_control/model_predictive_speed_and_steer_control.py
```

## References
- <https://github.com/AtsushiSakai/PythonRobotics>
