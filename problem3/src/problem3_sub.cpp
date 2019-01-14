#include <ros/ros.h>

#include "problem3/problem3_msg.h"

using namespace std;

int64_t sum =0;


void subCallback(const problem3::problem3_msgPtr& msg){
    if(msg->id == "first_message"){ 
        sum = msg->data;// sum 값 = 첫 메시지 값
    }
    else{
        sum += msg->data;// 첫 메시지 값에 나머지 값, 즉 2번째 메시지 값 더함
    }
    ROS_INFO_STREAM("first message & second message sum is " << sum);
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "problem3_sub");
    ros::NodeHandle nh;

    ros::Subscriber first = nh.subscribe("problem3", 1000, subCallback);
    ros::Subscriber second = nh.subscribe("problem3", 1000, subCallback);
    
    ros::spin();
    return 0;
}
