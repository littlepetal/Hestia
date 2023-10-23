// This is the Hestia node responsible for receiving information from 
// the Bushland node for the operation of Device

//--Includes-----------------------------------------------------------
#include "ros.h"
#include "std_msgs/String.h"

#include "Device.h"

// Callback function to receive messages from Hazards topic
void hazardsCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

// Callback function to receive messages from Fires topic
void firesCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

// Send messages about the state of the bushland to Hestia
int main(int argc, char **argv)
{
    // Perform remapping of ROS arguments and names that were provided at the 
    // command line
    ros::init(argc, argv, "Hestia");

    // Fully initialise the node
    // NodeHandle is the main access point to communications with the ROS system
    ros::NodeHandle n;

    // Subscriber object for subscribing to Hazards topic
    // Set the size of the message queue to be 1000
    ros::Subscriber hazardsSub = n.subscribe("chatter", 1000, hazardsCallback);

    // Subscriber object for subscribing to Fires topic
    // Set the size of the message queue to be 1000
    ros::Subscriber firesSub = n.subscribe("chatter", 1000, firesCallback);

    // Pump callbacks
    ros::spin();

    return 0;
}