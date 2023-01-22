#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

//                                    接收到的消息的名字 而非类型，别搞混了
/*
void reply(const plumbing_pub_sub::person::ConstPtr& tao)
{
    //ROS_INFO("七七听到了，是%s,身高%.2f,年龄%d",tao->name.c_str(),tao->height.c_str(),tao->age.c_str());
    ROS_INFO("%d",tao->age.c_str());
}*/

/* 这个函数哪里出问题了
void doMsg(const plumbing_pub_sub::person::ConstPtr& msg_p){
    ROS_INFO("我听见:%s",msg_p->data.c_str());
    // ROS_INFO("我听见:%s",(*msg_p).data.c_str());
}

int main(int argc ,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"QiQi");
    ros::NodeHandle nh;
    //                     句柄 订阅
    ros::Subscriber sub = nh.subscribe("basic_information",10, doMsg);
    ros::spin();
    return 0;
}
*/
/*
    需求: 订阅人的信息

*/

void doPerson(const plumbing_pub_sub::person::ConstPtr& person_p){
    ROS_INFO("七七听到了，是%s,年龄 %d, 身高%.2f", person_p->name.c_str(), person_p->age, person_p->height);
}

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");

    //1.初始化 ROS 节点
    ros::init(argc,argv,"QiQi");
    //2.创建 ROS 句柄
    ros::NodeHandle nh;
    //3.创建订阅对象
    ros::Subscriber sub = nh.subscribe("basic_information",10,doPerson);

    //4.回调函数中处理 person

    //5.ros::spin();
    ros::spin();    
    return 0;
}
