#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <apriltag_ros/AprilTagDetectionArray.h>

class TurtleBot3DriveNode {
public:
  TurtleBot3DriveNode() : original_pose_received_(false) {
    tag_detection_sub_ = nh_.subscribe("tag_detections", 1, &TurtleBot3DriveNode::tagDetectionCallback, this);
    priority_sub_ = nh_.subscribe("priority_list", 1, &TurtleBot3DriveNode::priorityCallback, this);
    move_base_client_ = new actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>("move_base", true);
    ROS_INFO("Waiting for the move_base action server to come up");
    move_base_client_->waitForServer();
  }

  ~TurtleBot3DriveNode() {
    delete move_base_client_;
  }

  void tagDetectionCallback(const apriltag_ros::AprilTagDetectionArray::ConstPtr& msg) {
    for (const auto& detection : msg->detections) {
      int id = detection.id[0];
      const geometry_msgs::PoseStamped& tag_pose = detection.pose;
      tag_poses_[id] = tag_pose.pose;
    }

    // If the original pose yet, save the current pose as the original pose.
    if (!original_pose_received_) {
      original_pose_ = msg->detections[0].pose.pose;
      original_pose_received_ = true;
    }

    // If detected all 5 AprilTags, start the sequence.
    if (tag_poses_.size() == 5) {
      // executeSequence();
    }
  }

  void priorityCallback(const std_msgs::String::ConstPtr& msg) {
    // Parse the priority list with number id
    std::vector<std::string> priority_list;
    boost::split(priority_list, msg->data, boost::is_any_of(","));

    // Go to water base
    int water_base_id = 0;  // assuming water base has ID 0
    moveToGoal(tag_poses_[water_base_id]);

    // Go to fire locations based on priority list
    for (const auto& fire : priority_list) {
      int fire_id = std::stoi(fire);
      moveToGoal(tag_poses_[fire_id]);

      // Go back to water base to refill
      moveToGoal(tag_poses_[water_base_id]);
    }
  }

  void moveToGoal(const geometry_msgs::Pose& goal_pose) {
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose = goal_pose;
    move_base_client_->sendGoal(goal);
    move_base_client_->waitForResult();
    if (move_base_client_->getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
      ROS_INFO("Goal reached!");
    } else {
      ROS_INFO("Failed to reach goal");
    }
  }

private:
  ros::NodeHandle nh_;
  ros::Subscriber tag_detection_sub_;
  ros::Subscriber priority_sub_;
  actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>* move_base_client_;
  std::map<int, geometry_msgs::Pose> tag_poses_;
  geometry_msgs::Pose original_pose_;
  bool original_pose_received_;
};

int main(int argc, char** argv) {
  ros::init(argc, argv, "turtlebot3_drive_node");
  TurtleBot3DriveNode node;
  ros::spin();
  return 0;
}
