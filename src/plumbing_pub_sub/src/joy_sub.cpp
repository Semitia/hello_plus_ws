#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

/*
class TeleopTurtle
{
    public:
        TeleopTurtle();

    private:
        void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

        ros::NodeHandle nh_;

        int linear_, angular_;
        double l_scale_, a_scale_;
        ros::Publisher vel_pub_;
        ros::Subscriber joy_sub_;

};


TeleopTurtle::TeleopTurtle():
  linear_(1),
  angular_(2)
{
  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);


  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::joyCallback, this);//这个this是什么？

}

void TeleopTurtle::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
    ROS_INFO("Got the ps2");
  geometry_msgs::Twist twist;
  twist.angular.z = a_scale_*joy->axes[angular_];
  twist.linear.x = l_scale_*joy->axes[linear_];
  vel_pub_.publish(twist);
}

*/
int buf_i[10];
float buf_f[8];
//对应按键:   左摇杆     右摇杆    上下左右键    
const int lx=0,ly=1,rx=2,ry=3,l_r=4,u_d=5,triangle=0,circle=1,cross=2,square=3,L2=4,R2=5,L1=6,R1=7;

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy_s)
{
    for(int i=0;i<=5;i++) {buf_f[i]=joy_s->axes[i];}
    for(int i=0;i<=7;i++) {buf_i[i]=joy_s->buttons[i];}
    ROS_INFO("Got it!");
    ROS_INFO("lx%.3f ly%.3f",buf_f[lx],buf_f[ly]);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL,"");  
    ros::init(argc, argv, "joy_sub");
    ros:: NodeHandle nh;
    //ros::Publisher 
    ros::Subscriber sub = nh.subscribe<sensor_msgs::Joy>("joy", 10,joyCallback);
    ros::spin();
}