#include <ros/ros.h>
//#include <pigpio.h> 
#include <pigpiod_if2.h>

#include <std_msgs/Bool.h>


int main(int argc, char** argv){
  ros::init(argc, argv, "Groovy_moter_tast");
  
  ros::NodeHandle n;

  int pi;
  pi = pigpio_start(NULL,NULL);

  char i = 0;

  char m = 0x6d;
  char s = 0x73;
  char space = 0x20;
  char zero = 0x30;
  char one = 0x31;
  char two = 0x32;
  char three = 0x33;
  char five = 0x35;
  
  char enter = 0x0D;

  //serial initialize
  int serial_flag = serial_open(pi,"/dev/ttyACM0",57600,0);
  //int serial_flag = serial_open(pi,"/dev/serial/by-id",57600,0);
  if(serial_flag < 0){
	ROS_ERROR("Serial initialize Fail");
	return 0;
  }



  ros::Rate rate(0.5);
  
  serial_write(pi,serial_flag,&m,1);
  time_sleep(0.1);
  serial_write(pi,serial_flag,&space,1);
  time_sleep(0.1);
  serial_write(pi,serial_flag,&zero,1);
  time_sleep(0.1);
  serial_write(pi,serial_flag,&enter,1);
  time_sleep(0.1);

  time_sleep(0.1);
  while(ros::ok()){
	  if(i == 0){
	    serial_write(pi,serial_flag,&s,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&space,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&space,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&enter,1);
		i = 1;
	  }else if(i == 1){
	    serial_write(pi,serial_flag,&s,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&space,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&space,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&one,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&enter,1);
		i = 2;
	  }else{
	    serial_write(pi,serial_flag,&s,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&space,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&space,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&five,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
		serial_write(pi,serial_flag,&zero,1);
		time_sleep(0.1);
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
