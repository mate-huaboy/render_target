#pragma once
#include<Windows.h>
#include <gl/GL.h>
#include<math.h>
class control_trace//控制运动的系统--模拟
{
private:
	//double speed;//定义走完总时长，每一个单位时间拍一张
	int total_time;//定义至少走多久
	double total_len_x;
	double step;
	double qiut_z;
	
	//定义z=10.7*ln(x-5);作为轨迹函数

	double funz(double x)
	{
		return -7.0 / 72 * pow(x, 2) + 7.0 / 3 * x + 6;
	}
	double funx(int curent_t)
	{
		double x_last = this->total_len_x - step * (curent_t - 1);
		double dif = -7.0 / 36 * pow(x_last, 1) + 7.0 / 3;
		double ang=atan(dif);
		return x_last - step * cos(ang);
	}
	
	bool get_x_z(int curent_t,double &x, double &z)
	{
		 x= funx(curent_t);
		 z = funz(x);
		 if (z<qiut_z)
		 {
			 return false;//可以推出了
		 }
		 return true;
	}
public:
	control_trace(int total_t, double qiut_z, double total_len_x = 12)
	{
		this->total_time = total_t;
		this->total_len_x = total_len_x;
		step = total_len_x / total_time;
		this->qiut_z = qiut_z;
	}
	bool loc_pos(GLdouble& eyex,
		GLdouble& eyey,
		GLdouble& eyez,
		GLdouble& centerx,
		GLdouble& centery,
		GLdouble& centerz,int curent_t );//返回下一时刻的位置和姿态
	
	bool loc_pos01(//第二个轨迹函数--用于标定
		GLdouble& eyex,
		GLdouble& eyey,
		GLdouble& eyez,
		GLdouble& centerx,
		GLdouble& centery,
		GLdouble& centerz, int curent_t
	);



};

