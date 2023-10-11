#include "smb_highlevel_controller/SmbHighlevelControllerPointCloud.hpp"

namespace smb_highlevel_controller {

SmbHighlevelControllerPointCloud::SmbHighlevelControllerPointCloud(ros::NodeHandle& nh)
    : nodeHandle(nh) {
    // get param from config file
    std::string rslidar_points;
    int pointcloud_queue_size;
    if (!nodeHandle.getParam("pointcloud_topic", rslidar_points) || !nodeHandle.getParam("pointcloud_queue_size", pointcloud_queue_size)) {
        ROS_ERROR("Could not find pointcloud subscriber params!");
        ros::requestShutdown();
    }
    // pointcloud subscriber
    pointcloudSubscriber = nodeHandle.subscribe(rslidar_points, pointcloud_queue_size, &SmbHighlevelControllerPointCloud::pointcloudCallback, this);
    ROS_INFO("Smb highlevel controller (pointcloud) node launched!");
}

void SmbHighlevelControllerPointCloud::pointcloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg) {
    int numPoints = msg->width * msg->height;
    std::cout<< "==============================================================================================\n";
    ROS_INFO_STREAM("Nombre de points dans le nuage de points : " << numPoints <<"\n");
    std::cout<< "==============================================================================================\n";
}

}