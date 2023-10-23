// This is the Bushland node responsible for sending information about 
// Maps, Bush and Reservoir to the Hestia node

//--Includes-----------------------------------------------------------
#include "ros.h"
#include "std_msgs/String.h"

#include "Maps.h"

#include <sstream>

// Send messages about the state of the bushland to Hestia
int main(int argc, char **argv)
{
    // Perform remapping of ROS arguments and names that were provided at the 
    // command line
    ros::init(argc, argv, "Bushland");

    // Fully initialise the node
    // NodeHandle is the main access point to communications with the ROS system
    ros::NodeHandle n;

    // Publisher object for publishing messages on Hazards topic
    // Set the size of the message queue to be 1000
    ros::Publisher hazardsPub = n.advertise<std_msgs::String>("Hazards", 1000);

    // Publisher object for publishing messages on Fires topic
    // Set the size of the message queue to be 1000
    ros::Publisher firesPub = n.advertise<std_msgs::String>("Fires", 1000);

    // Read the data every 100ms
    ros::Rate loop_rate(10);

    // Count of the number of sent messages
    int sentMessagesCount = 0;

    // Check that the thread has not been terminated
    while(ros::ok)
    {
        // Message object to be published
        std_msgs::String msg;

        // Create messages
        std::stringstream ss;
        ss << "Hazards detected " << sentMessagesCount;
        msg.data = ss.str();

        // Format messages
        ROS_INFO("%s", msg.data.c_str());

        // Broadcast messages to subscribers
        chatterPub.publish(msg);

        // Call all the callbacks waiting to be called at that point in time
        // Block the main thread from exiting until ROS invokes a shutdown
        ros::spinOnce();

        // Thread sleep
        loop_rate.sleep();

        // Increment the number of sent messages
        sentMessagesCount++;
    }

    return 0;
}