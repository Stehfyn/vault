<!-- generated-from-dump2 -->
# Install ROS Noetic on WSL (Guide)

Walkthrough for getting ROS Noetic (Ubuntu 20.04-targeted, the last ROS 1 LTS) running under WSL2 on Windows. The non-obvious gotcha that motivates writing this down: ROS 1 GUIs (rviz, gazebo, rqt_plot) need an X server, and `roscore`/`rosrun` need a working hostname↔IP mapping that survives WSL's auto-generated `/etc/hosts`. The recipe sets `ROS_HOSTNAME=$(hostname).local`, exports `DISPLAY=$(grep nameserver /etc/resolv.conf | awk '{print $2}'):0` (pre-WSLg) or uses WSLg directly (post-Win11), and writes a `.bashrc` block to source `/opt/ros/noetic/setup.bash`. Useful template for any ROS 1 / WSL setup; ROS 2 is mostly less painful but the X / hostname tricks still apply.

```bash
# Core install steps:
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
curl -sSL 'https://raw.githubusercontent.com/ros/rosdistro/master/ros.key' | sudo apt-key add -
sudo apt update
sudo apt install -y ros-noetic-desktop-full
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

# GUI fix (pre-WSLg Windows 10): point DISPLAY at an X server running on Windows (VcXsrv).
echo "export DISPLAY=\$(grep -m1 nameserver /etc/resolv.conf | awk '{print \$2}'):0.0" >> ~/.bashrc
echo "export LIBGL_ALWAYS_INDIRECT=1" >> ~/.bashrc

# Hostname stability so roscore/master URI is reachable from same WSL distro:
echo "export ROS_HOSTNAME=localhost"  >> ~/.bashrc
echo "export ROS_MASTER_URI=http://localhost:11311" >> ~/.bashrc
```

## References
- <https://github.com/ishkapoor2000/Install_ROS_Noetic_On_WSL>
