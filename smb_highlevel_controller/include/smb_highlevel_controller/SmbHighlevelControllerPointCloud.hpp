#pragma once

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

namespace smb_highlevel_controller {

/* @brief: Smb Highlevel Controller for Point Cloud */
class SmbHighlevelControllerPointCloud {
public:
    /* @brief: Constructor */
    SmbHighlevelControllerPointCloud(ros::NodeHandle& nh);

    SmbHighlevelControllerPointCloud(const SmbHighlevelControllerPointCloud&) = delete;
    /* @brief: no assignment = */
    SmbHighlevelControllerPointCloud& operator=(const SmbHighlevelControllerPointCloud&) = delete;

    /* @brief: Destructor */
    ~SmbHighlevelControllerPointCloud() = default;

private:
    /* data */
    ros::NodeHandle nodeHandle;
    ros::Subscriber pointcloudSubscriber;

    void pointcloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg);
};

}