#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <add_markers/AddMarker.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

const int arr_size = 2;
double positions[arr_size][2] ={{3.5, 4.0}, {0.0, 4.0}};


move_base_msgs::MoveBaseGoal create_goal_msg(double x, double y)
{

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = x;
  goal.target_pose.pose.position.y = y;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Position: (%.2f, %.2f, %.2f)", goal.target_pose.pose.position.x, goal.target_pose.pose.position.y, goal.target_pose.pose.position.z);
  return goal;
}

int main(int argc, char **argv)
{
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");
  ros::NodeHandle n;
  ros::Rate r(10);

  // Define a global client that can request services
  ros::ServiceClient client;
  client = n.serviceClient<add_markers::AddMarker>("/add_markers");
  // tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while (!ac.waitForServer(ros::Duration(5.0)))
  {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  int goal_ind = 0;

  add_markers::AddMarker marker_request;
  marker_request.request.pos_x = positions[goal_ind][0];
  marker_request.request.pos_y = positions[goal_ind][1];
  marker_request.request.add = true;
  client.call(marker_request);
  // TODO: send display marker

  for (; goal_ind < arr_size; ++goal_ind){


    // Send the goal position and orientation for the robot to reach
    move_base_msgs::MoveBaseGoal goal = create_goal_msg(positions[goal_ind][0], positions[goal_ind][1]);
    if (goal_ind % 2 == 0)
      ROS_INFO("Pick-up location sent.");
    else
      ROS_INFO("Load-off location sent.");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its goal
    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      if (goal_ind % 2 == 0){
        ROS_INFO("The robot started picking up the target.");
        ros::Duration(5.0).sleep();
        // TODO: pick up the marker
        marker_request.request.add = false;
        client.call(marker_request);
        ROS_INFO("The robot has picked up the target.");
      }
      else{
        //TODO: load off the marker

        ROS_INFO("Load-off location reached");
        marker_request.request.pos_x = positions[goal_ind][0];
        marker_request.request.pos_y = positions[goal_ind][1];
        marker_request.request.add = true;
        client.call(marker_request);

      }
      

    }
    else
      ROS_INFO("The robot failed to find a valid route to the pickup location.");
  }


}