#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <fs_msgs/PIDControlled.h>
#include <fs_msgs/SlamState.h>

#include <iostream>
using namespace std;

class Car{
    float speed, steering_angle, torque, brake;
    int laps;
    bool lidar;

    ros::NodeHandle n;
    // ros::Time old_time, new_time;
    ros::Subscriber subscriber;

    public: 

    Car(){
        readTopics();
    }

    void readTopics(){
        subscriber = n.subscribe<nav_msgs::Odometry>("/slam/prefiltering/odom_filtered", 1, &Car::updateSpeed, this);
        // subscriber = n.subscribe<fs_msgs::SlamState>("/slam/slam/slam_state", 1, &Car::updateLapCount, this);
        
        // subscriber = n.subscribe("/can/command/...", 1000, &Car::updatePID, this);

        // subscriber = n.subscribe("/slam/prefiltering/odom_filtered", 1000, updateGPS);
        // subscriber = n.subscribe("/slam/prefiltering/odom_filtered", 1000, updateEFK);
        // subscriber = n.subscribe("/sensors/lidar/velodyne_points", 1000, updateSignalLIDAR);
    }

    void updateSpeed(const nav_msgs::Odometry::ConstPtr& msg){
        cout << msg;
    }
   
    /* void updateLapCount(const fs_msgs::SlamState::ConstPtr& msg){
        laps = msg.lap_counter;
    } */
    
    /* void updateSignalLIDAR(){
        old_time = new_time;
        int new_time = ros::Time::now();

        if (abs(old_time - new_time) < 30){
            lidar = true;
        }

        else {
            lidar = false
        }
    } */

    // void updateGPS();
    // void updateEKF();

    /* void updatePID(const fs_msgs::PIDControlled::ConstPtr& msg){
        torque = msg.torque;
        steering_angle = msg.steering;
        brake = msg.brake;
    }*/
};

int main (int argc, char **argv){
    ros::init(argc, argv, "listener", ros::init_options::AnonymousName);
    Car car = Car();
    ros::spin();
}