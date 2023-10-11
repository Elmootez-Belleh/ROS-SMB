#include <ros/ros.h>
#include "smb_highlevel_controller/SmbHighlevelController.hpp"
#include "smb_highlevel_controller/SmbHighlevelControllerPointCloud.hpp"


int main(int argc, char** argv)
{
  ros::init(argc, argv, "smb_highlevel_controller");
  ros::NodeHandle nodeHandle("~");

  smb_highlevel_controller::SmbHighlevelController smbHighlevelController(nodeHandle);
  smb_highlevel_controller::SmbHighlevelControllerPointCloud smbHighlevelControllerPointCloud(nodeHandle);

  ros::spin();
  return 0;
}

