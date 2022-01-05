#include<Windows.h>
#include <gl/GL.h>
#include"util.h"

void set_drone_black()
{
	GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };  //������ʵĻ�������ɫ��Ϊ0
	GLfloat mat_diffuse[] = { 0.1f, 0.1f, 0.1f, 1.0f };  //������ʵ����������ɫ��Ϊ0
	GLfloat mat_specular[] = { 0.05f, 0.05f, 0.05f, 1.0f };   //������ʵľ��淴�����ɫ��Ϊ0
	//GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊƫ��ɫ
	GLfloat mat_shininess = 100;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}
void set_drone_white()
{
	GLfloat mat_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };  //������ʵĻ�������ɫ��Ϊ0
	GLfloat mat_diffuse[] = { 0.7f, 0.7f,0.7f, 1.0f };  //������ʵ����������ɫ��Ϊ0
	GLfloat mat_specular[] = { 0.4f, 0.4f,0.4f, 1.0f };   //������ʵľ��淴�����ɫ��Ϊ0
	//GLfloat mat_specular[] = { 1.f, 1.f, 1.f, 1.0f };
	//GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊƫ��ɫ
	GLfloat mat_shininess = 100;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
 }

void set_screw()
{
	GLfloat mat_ambient[] = { 0.19f, 0.19f, 0.19f, 1.0f };  //������ʵĻ�������ɫ��Ϊ0
	GLfloat mat_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };  //������ʵ����������ɫ��Ϊ0
	GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };   //������ʵľ��淴�����ɫ��Ϊ0
	//GLfloat mat_specular[] = { 1.f, 1.f, 1.f, 1.0f };
	//GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊƫ��ɫ
	GLfloat mat_shininess = 56;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}

void set_bg_mat()//���ñ����ķ�������
{
	GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };  //������ʵĻ�������ɫ��Ϊ0
	GLfloat mat_diffuse[] = { .5f, .5f, .5f, 1.0f };  //������ʵ����������ɫ��Ϊ0
	GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };   //������ʵľ��淴�����ɫ��Ϊ0
	////GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊƫ��ɫ
	//GLfloat* mat_ambient;  //������ʵĻ�������ɫ��Ϊ0
	
	//rand_num(4, mat_ambient);
	//GLfloat *mat_diffuse;  //������ʵ����������ɫ��Ϊ0
	//GLfloat *mat_specular;   //������ʵľ��淴�����ɫ��Ϊ0
	//rand_num(4, mat_diffuse);
	//rand_num(4, mat_specular);
	GLfloat mat_shininess = 56;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}