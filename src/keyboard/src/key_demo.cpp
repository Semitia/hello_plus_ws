#include "ros/ros.h"
#include <termio.h>
#include <stdio.h>
#include "std_msgs/Int32.h"

int scanKeyboard()
{
 
	int in;
 
	struct termios new_settings;
	struct termios stored_settings;
    //设置终端参数
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	tcgetattr(0,&stored_settings);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&new_settings);
	in = getchar();
	tcsetattr(0,TCSANOW,&stored_settings);
 
	return in;//返回的是字符对应的ascii码
 
}
 
//测试函数
int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"");
    ros::init(argc,argv,"Keyboard_listener");
    ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::Int32>("keyboard",10);
	ros::Rate rate(10);
	while(1)
	{
		std_msgs::Int32 key; 
		key.data=scanKeyboard();
		pub.publish(key);
		printf("%d\n",key.data);
		//rate.sleep();
	}
	return 0;
}