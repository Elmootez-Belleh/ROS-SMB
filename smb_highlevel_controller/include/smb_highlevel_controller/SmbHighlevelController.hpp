#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <vector>

namespace smb_highlevel_controller {

/* @brief: Smb Highlevel Controller */
class SmbHighlevelController {
public:
    /* @brief: Constructor */
    SmbHighlevelController(ros::NodeHandle& nh);

    SmbHighlevelController(const SmbHighlevelController &) = delete;
    /* @brief: no assignment = */
    SmbHighlevelController& operator=(const SmbHighlevelController &) = delete;

    /* @brief: Destructor */
    ~SmbHighlevelController() = default;

private:
    /* data */
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber;

    void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
};

}
