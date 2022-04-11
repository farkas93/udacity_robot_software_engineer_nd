#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <move_base_msgs/MoveBaseAction.h>
#include "add_markers/AddMarker.h"

visualization_msgs::Marker marker;

ros::Publisher marker_pub;

visualization_msgs::Marker create_marker()
{
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = visualization_msgs::Marker::CUBE;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();
    return marker;
}

void send_new_marker_position(double x, double y)
{

    // Set mode to add since we want to see the message
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker_pub.publish(marker);
    ROS_INFO("Added the marker. ( %.3f, %.3f)", x, y);
}

void disable_marker()
{

    // Simulate picking up the object
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    ROS_INFO("Deleted the marker. ( %.3f, %.3f)", marker.pose.position.x, marker.pose.position.y);
}

bool handle_add_marker(add_markers::AddMarker::Request &req, add_markers::AddMarker::Response &res)
{
    if (req.add)
    {
        send_new_marker_position(req.pos_x, req.pos_y);
        res.msg_feedback = "Adding a new marker.";
    }
    else
    {
        disable_marker();
        res.msg_feedback = "Disabled the marker.";
    }

    //ROS_INFO(res.msg_feedback);
    return true;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "add_markers");
    ros::NodeHandle n;
    ros::Rate r(10);
    marker =create_marker();

    marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    ros::ServiceServer service = n.advertiseService("/add_markers", handle_add_marker);

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
        if (!ros::ok())
        {
            return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
    }

    ros::spin();
}