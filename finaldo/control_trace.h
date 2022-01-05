#pragma once
#include<Windows.h>
#include <gl/GL.h>
#include<math.h>
class control_trace//�����˶���ϵͳ--ģ��
{
private:
	//double speed;//����������ʱ����ÿһ����λʱ����һ��
	int total_time;//���������߶��
	double total_len_x;
	double step;
	double qiut_z;
	
	//����z=10.7*ln(x-5);��Ϊ�켣����

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
			 return false;//�����Ƴ���
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
		GLdouble& centerz,int curent_t );//������һʱ�̵�λ�ú���̬
	
	bool loc_pos01(//�ڶ����켣����--���ڱ궨
		GLdouble& eyex,
		GLdouble& eyey,
		GLdouble& eyez,
		GLdouble& centerx,
		GLdouble& centery,
		GLdouble& centerz, int curent_t
	);



};

