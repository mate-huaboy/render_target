
#include <Windows.h>
#include <gl/GL.h>
#include <glfw3.h>
#include"util.h"

void goballight()//����ȫ�ֹ���
{
	GLfloat* v3;
	rand_num2(3, v3);

	//GLfloat light_ambient[] = { 0.1,.1,.1,1 };
	GLfloat light_ambient[] = { 1,1,1,1 };

	//GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 1,1,1,1 };

	GLfloat light_specular[] = { 0.9, 0.7, 0.7, 1.0 };
	//����ƽ�й�

	/*GLfloat light_pos[] = { v3[0],v3[1],v3[2],0 };*/
	GLfloat light_pos[] = { 0.5,-1,0.2,0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}

void light_focus()//���þ۹��--����û�л���������
{

	GLfloat light_ambient[] = { 0.05,0.05,0.05,1 };
	GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_specular[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat light_pos[] = { 2,-0.5,3 };//����λ��
	GLfloat direc[] = { 1,0,-3 };//��������
	GLfloat cutoff = 60;//�۹�ƽ�ֹ��
	GLfloat exponent = 50;//�ۼ�ָ��
	GLfloat liner_attenuation = 0.;//����˥�����ӡ�

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, exponent);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

}

void light_spot()//���õ��Դ
{

}





