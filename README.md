# Exercice 1 : 

#### Voici les notions que nous allons voir ensemble dans cette exercice : 

- ROS architecture
- ROS master, nodes, and topics
- Console commands
- Catkin workspace and build system
- Launch-files 


## 🛠️ Installations
       

#### 1 - Dans un premier temps il faut telecharger le fichier [smb_common.zip](https://github.com/Elmootez-Belleh/ROS-SMB/blob/main/smb_common.zip)
#### 2 - Se positionner dans le workspace : `cd ~/catkin_ws/src`
#### 3 - `unzip smb_common.zip`
#### 4 - `cd ..`
#### 5 - `catkin_make`
#### 6 - `source ~/catkin_ws/devel/setup.bash`


## 🧐 Simulation 

#### Nous allons lancer notre simulation avec roslaunch :

#### `roslaunch smb_gazebo smb_gazebo.launch` 

![Image](https://github.com/Elmootez-Belleh/ROS-SMB/blob/main/screens/rostopicList.png]

#### Ensuite, ouvrir un vouveau terminal et tapper les commandes suivantes : 

#### `rosnode list`
![Image](screens/rosnodeList.png)
#### `rostopic list`
![Image](screens/rostopicList.png)
#### `rostopic echo clock`
![Image](screens/rostopicEcho.png)
#### `rostopic hz clock`
![Image](screens/rostopicHz.png)        
#### `rqt_graph`
![Image](screens/rqt_graph.png)

##### Question 3 : Commandez une vitesse souhaitée au robot à partir du terminal (rostopic pub [TOPIC]).

##### `rostopic pub /cmd_vel geometry_msgs/Twist '[1.5,0,0]' '[0,0,1.0]'`
![Image](screens/cmd_vel.png)        
         
##### Question 4 : Utilisez teleop_twist_keyboard pour contrôler votre robot à l'aide du clavier. Trouvez-le en ligne et compilez-le à partir de la source ! Utilisez git clone pour cloner le dépôt.

###### `git clone https://github.com/ros-teleop/teleop_twist_keyboard.git`
###### `catkin_make`
###### `source ~/catkin_ws/devel/setup.bash`
###### `rosrun teleop_twist_keyboard teleop_twist_keyboard.py`
![Image](screens/teleop_key.png)

##### Question 5 : Launch file : 

```
<launch>
  <!-- Include another launch file or add more nodes here -->
  <include file="/home/salhi/catkin_ws/src/smb_gazebo/launch/smb_gazebo.launch">
    <!-- Change the world_file argument to a different world -->
    <arg name="world_file" value="/usr/share/gazebo-11/worlds/robocup14_spl_field.world"/>
  </include>

  <node pkg="teleop_twist_keyboard" type="/home/salhi/catkin_ws/src/teleop_twist_keyboard/teleop_twist_keyboard.py" name="Salhi_smb_teleop" output="screen"/>
</launch>
```

###### `catkin_make`
###### `source ~/catkin_ws/devel/setup.bash`
###### `roslaunch smb_gazebo different_world.launch`
![Image](screens/different_world.png)
