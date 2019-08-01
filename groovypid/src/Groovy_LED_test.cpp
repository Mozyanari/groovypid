#include <ros/ros.h>
//#include <pigpio.h> 
#include <pigpiod_if2.h>

#include <std_msgs/Bool.h>


int main(int argc, char** argv){
  ros::init(argc, argv, "Groovy_LED_tast");
  
  ros::NodeHandle n;

  int pi;
  pi = pigpio_start(NULL,NULL);

  char i = 0;

  char l = 0x6c;
  char space = 0x20;
  char zero = 0x30;
  char one = 0x31;
  char enter = 0x0D;

  //serial initialize
  int serial_flag = serial_open(pi,"/dev/ttyACM0",57600,0);
  if(serial_flag < 0){
	ROS_ERROR("Serial initialize Fail");
	return 0;
  }

  ros::Rate rate(1);
  while(ros::ok()){
	  if(i == 0){
	    serial_write(pi,serial_flag,&l,1);
		serial_write(pi,serial_flag,&space,1);
		serial_write(pi,serial_flag,&zero,1);
		serial_write(pi,serial_flag,&enter,1);
		i = 1;
	  }else{
	    serial_write(pi,serial_flag,&l,1);
		serial_write(pi,serial_flag,&space,1);
		serial_write(pi,serial_flag,&one,1);
		serial_write(pi,serial_flag,&enter,1);
		i = 0;
	  }
	  ROS_INFO("%d",i);
	  ros::spinOnce();
	  rate.sleep();
  }
  serial_close(pi,serial_flag);
  return 0;
}
