#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<sstream>
#include<math.h>

ros::Publisher vel_pub;

const double PI = acos(-1);

void move(double , double, bool);
void rotate(double, double, bool);
double deg2rad(double);
void dibujar();

using namespace std;

int main(int argc, char **argv){
	ros::init(argc, argv, "mover");
	ros::NodeHandle n;
	vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
	move(2.0, 2.0, 1);
	dibujar();
}

void move(double speed, double distance, bool isf){
	geometry_msgs::Twist vel_msg;
	double t0, t1, cur_dis=0;
	if(isf){
		vel_msg.linear.x = abs(speed);
		vel_msg.linear.y = abs(speed);
	}
	else{
		vel_msg.linear.x = -abs(speed);
		vel_msg.linear.y = -abs(speed);
	}
	t0 = ros::Time::now().toSec();
	ros::Rate rate(10);	// Loop at 10 Hz
	while(cur_dis < distance){
		vel_pub.publish(vel_msg);
		t1 = ros::Time::now().toSec();
		cur_dis = speed * (t1 - t0);
		ros::spinOnce();
		rate.sleep();
	}
}

void rotate(double ang_speed, double rel_ang, bool clockwise){
	geometry_msgs::Twist vel_msg;
	vel_msg.linear.x = 0;
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	double cur_ang = 0.0;
	double t0, t1;
	ros::Rate rate(10);
	if (clockwise)	vel_msg.angular.z = -abs(ang_speed);
	else	vel_msg.angular.z = abs(ang_speed);
	t0 = ros::Time::now().toSec();
	while(cur_ang < rel_ang){
		vel_pub.publish(vel_msg);
		t1 = ros::Time::now().toSec();
		cur_ang = ang_speed * (t1 - t0);
		ros::spinOnce();
		rate.sleep();
	}
	vel_msg.angular.z = 0;
	vel_pub.publish(vel_msg);
}

double deg2rad(double input){
	return input * PI / 180.0;
}

void dibujar(){
	int i;
	double a_speed = 30, ang; 
	a_speed = deg2rad(a_speed);
	ang = 36;
	ang = deg2rad(ang);
	move(2.0, 2.0, 1);
	for(i = 0; i < 4; i++){
		rotate(a_speed, ang, 0);
		if(i %2 == 0)	move(2.0, 2.0, 0);
		else	move(2.0, 2.0, 1);
	}
}