## INSTALL ROS

```
lsb_release -a
sudo sh -c 'echo "deb  http://packages.ros.org/ros/ubuntu  $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
sudo apt-get update
sudo apt-get install -y python-rosdep python-rosinstall-generator python-wstool python-rosinstall build-essential  cmake

sudo rosdep init
rosdep update

mkdir rpi_ros
cd rpi_ros

rosinstall_generator desktop --rosdistro melodic --deps --wet-only --tar > melodic-desktop-wet.rosinstall

wstool init -j8 src melodic-desktop-wet.rosinstall
```
If broken
```
wstool update -j4 -t src
```
## Assimp (Open Asset Import Library) to fix collada_urdf dependency problem.
```
mkdir -p ~/rpi_ros/external_src 
cd ~/rpi_ros/external_src

wget  http://sourceforge.net/projects/assimp/files/assimp-3.1/assimp-3.1.1_no_test_models.zip/download -O assimp-3.1.1_no_test_models.zip
unzip assimp-3.1.1_no_test_models.zip
cd assimp-3.1.1
cmake .
make
sudo make install
```
## OGRE for RVIZ
```
sudo apt-get install  libogre-1.9-dev
```
## FINAL install
```
rosdep install --from-paths src --ignore-src --rosdistro melodic -y

sudo ./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release --install-space /opt/ros/melodic -j2
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
```

## VNC INSTALL AND USE

```
remmina
```
## USB dev bind

```
dmesg | grep ttyUSB 
udevadm info --name=/dev/ttyUSB0 --attribute-walk

sudo cp -rf 99-usb-serial.rules ~/../../etc/udev/rules.d/
sudo udevadm trigger
ls -l /dev/UART_mbee
```
```
# MBEE Amperka -> PL2303 USB-UART
ACTION=="add", SUBSYSTEM=="tty", ATTRS{idVendor}=="067b", ATTRS{idProduct}=="2303", SYMLINK+="UART_mbee"
# STORM32 -> FTDI FT232 USB-UART
ACTION=="add", SUBSYSTEM=="tty", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", SYMLINK+="UART_storm"
# U2D2 Dynamixel -> FTDI USB-UART
ACTION=="add", SUBSYSTEM=="tty", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6014", SYMLINK+="UART_dynamixel"
```
## Other
```
export LC_NUMERIC="en_US.UTF-8"


rqt_graph --force-discover

sudo apt-get install ros-melodic-rqt
sudo apt-get install ros-melodic-qt-gui
```

```
sudo usermod -a -G dialout username
sudo chmod a+rw /dev/ttyUSB0
ls -l /dev/ttyUSB0

ls -ld /run/lock
cp /usr/lib/tmpfiles.d/legacy.conf /etc/tmpfiles.d/
chmod /run/lock 0775 root lock

ls -ld /var/lock
chmod o+rwx /var/lock
```

```
sudo apt-get install ros-indigo-rosserial-arduino
sudo apt-get install ros-indigo-rosserial

rosrun rosserial_arduino make_libraries.py .
rosrun rosserial_client make_libraries  ~/Arduino/libraries /taticoma_msgs

rosrun rosserial_python serial_node.py /dev/ttyUSB0
```
