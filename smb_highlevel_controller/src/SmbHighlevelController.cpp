#include "smb_highlevel_controller/SmbHighlevelController.hpp"

namespace smb_highlevel_controller {

SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nh)
    : nodeHandle(nh) {
    // get param from config file
    std::string topic;
    int queue_size;
    if ( !nodeHandle.getParam("subscriber_topic", topic) 
        || !nodeHandle.getParam("queue_size", queue_size) ) 
    {
        ROS_ERROR("Could not find subscriber params!"); 
        ros::requestShutdown();
    }
    // create subscriber
    subscriber = nodeHandle.subscribe(topic, queue_size, 
        &SmbHighlevelController::laserCallback, this);
    ROS_INFO("Smb highlevel controller node launched!");
}


void SmbHighlevelController::laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    auto min_elem = std::min_element(msg->ranges.cbegin(), msg->ranges.cend());
    ROS_INFO_STREAM("La distance la plus proche est : " << *min_elem);
}

} // namespace smb_highlevel_controller