#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"
/*
    头文件
    初始化节点
    创建句柄
    创建发布者对象
    编写发布逻辑，发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"HuTao");
    ros::NodeHandle nh;
    //               猜测是 句柄 广播
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::person>("basic_information",10);
    //创建发布的数据
    plumbing_pub_sub::person tao;
    tao.name="Hutao";
    tao.age=16;
    tao.height=163.25;
    //设置频率
    ros::Rate rate(1);
    //循环
    while(ros::ok())
    {
        ROS_INFO("published");
        pub.publish(tao);
        rate.sleep();
        ros::spinOnce;
    }
    return 0;
}