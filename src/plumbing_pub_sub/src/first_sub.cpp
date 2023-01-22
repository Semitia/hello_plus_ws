/*
    1：包含头文件
        文本类型 std_msgs/String.h
    2：初始化一个节点
    3：创建句柄
    4：创建订阅者对象
    5：处理订阅到的数据
    6：声明spin()函数
*/



/*


#include "ros/ros.h"
#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr &msg)
{   
    //ConstPtr:常量指针
    ROS_INFO("the data we got:%S",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter",10,callback);

    ros::spin();


}
*/
/*
    需求: 实现基本的话题通信，一方发布数据，一方接收数据，
         实现的关键点:
         1.发送方
         2.接收方
         3.数据(此处为普通文本)


    消息订阅方:
        订阅话题并打印接收到的消息

    实现流程:
        1.包含头文件 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 订阅者 对象
        5.处理订阅的消息(回调函数)
        6.设置循环调用回调函数

*/
// 1.包含头文件 
#include "ros/ros.h"
#include "std_msgs/String.h"

//类似于中断，收到消息则调用此函数
void doMsg(const std_msgs::String::ConstPtr& msg_p){
    ROS_INFO("我听见:%s",msg_p->data.c_str());
    // ROS_INFO("我听见:%s",(*msg_p).data.c_str());
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"listener");
    //3.实例化 ROS 句柄
    ros::NodeHandle nh;

    //4.实例化 订阅者 对象                   话题类型          话题    消息长度    绑定回调函数 
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter",10,        doMsg);
    //5.处理订阅的消息(回调函数)

    //     6.设置循环调用回调函数
    //关于spin()函数： https://www.cnblogs.com/liu-fa/p/5925381.html
    ros::spin();//循环读取接收的数据，并调用回调函数处理

    return 0;
}
