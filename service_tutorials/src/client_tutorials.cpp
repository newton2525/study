#include"ros/ros.h"
#include"service_tutorials/srv.h"

int main(int argc, char *argv[]){
    ros::init(argc, argv, "service_client");

if(argc !=3){
    ROS_INFO("cmd : rosrun ros_tutorial_service service_client arg0 arg1");
    ROS_INFO("arg0 : double number, arg1 : double number");
    return 1;
}    

ros::NodeHandle nh;

ros::ServiceClient service_Client =
  nh.serviceClient<service_tutorials::srv>("service_tutorial");
  service_tutorials::srv srv;

  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);

  if(service_Client.call(srv)){
      ROS_INFO("send srv, srvRequest.a and b : %ld, %ld",static_cast<long int>(srv.request.a),static_cast<long int>(srv.request.b));
      ROS_INFO("receive srv, srv.Respond.result: %ld", (long int)srv.response.result);
    
  }
  else{
      ROS_ERROR("Faild to call service ros_tutorial_srv");
      return 1;
  }
  return 0;
}