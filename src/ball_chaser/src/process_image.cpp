#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

ball_chaser::DriveToTarget turn_right;
ball_chaser::DriveToTarget turn_left;
ball_chaser::DriveToTarget go_straight;
ball_chaser::DriveToTarget stop_robot;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(int r, int s, int l)
{
    ROS_INFO("Right %d pixels, Mid %d pixels, left %d pixels", r, s, l);
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget command_request;
    if(r > s && r > l) command_request = turn_right;
    else if (s > r && s > l) command_request = go_straight;
    else if (l > s && l > r) command_request = turn_left;
    else command_request = stop_robot;

    if(!client.call(command_request))
        ROS_ERROR("Failed to call service drive_bot");
}


// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    uint8_t white_pixel = 255;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    uint32_t w = img.width;
    uint32_t h = img.height;
    uint32_t channels = img.step / w;
    
    uint32_t left = w/3;
    uint32_t straight = 2*left;
    int r_count = 0, s_count = 0, l_count = 0; 

    for(uint32_t i = 0; i+(channels-1) < channels*w*h; i+= channels)
    {
        bool is_white = true;
        for(int c = 0; c < channels; ++c){
            // check all channels if they are white
            is_white = is_white && (white_pixel == img.data[i+c]);
        } 
        if(is_white){
            uint32_t col = (i % img.step)/3;
            if (col < left) ++l_count;
            else if (col < straight) ++s_count;
            else ++r_count;
            //ROS_INFO("i %d, step, img.step %d, col : %d, left %d, straight %d", i, img.step, col, left, straight);
        }
    }
    drive_robot(r_count, s_count, l_count);

}

/**
 * @brief Initialize the standard controls which are allowed to drive the robot.
 * 
 */
void init_control_messages(){

    go_straight.request.linear_x = 0.3;
    go_straight.request.angular_z = 0.0;

    turn_right.request.linear_x = 0.1;
    turn_right.request.angular_z = -0.7;

    turn_left.request.linear_x = 0.1;
    turn_left.request.angular_z = 0.7;

    stop_robot.request.linear_x = 0.0;
    stop_robot.request.angular_z = 0.0;
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;
    init_control_messages();
    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}