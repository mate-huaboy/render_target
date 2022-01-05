
#include <Windows.h>
#include <gl/GL.h>
#include <glfw3.h>
#include"util.h"

void goballight()//设置全局光照
{
	GLfloat* v3;
	rand_num2(3, v3);

	//GLfloat light_ambient[] = { 0.1,.1,.1,1 };
	GLfloat light_ambient[] = { 1,1,1,1 };

	//GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 1,1,1,1 };

	GLfloat light_specular[] = { 0.9, 0.7, 0.7, 1.0 };
	//设置平行光

	/*GLfloat light_pos[] = { v3[0],v3[1],v3[2],0 };*/
	GLfloat light_pos[] = { 0.5,-1,0.2,0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}

void light_focus()//设置聚光灯--几何没有环境光的情况
{

	GLfloat light_ambient[] = { 0.05,0.05,0.05,1 };
	GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_specular[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat light_pos[] = { 2,-0.5,3 };//设置位置
	GLfloat direc[] = { 1,0,-3 };//方向设置
	GLfloat cutoff = 60;//聚光灯截止角
	GLfloat exponent = 50;//聚集指数
	GLfloat liner_attenuation = 0.;//线性衰减因子。

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, exponent);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

}

void light_spot()//设置点光源
{

}





