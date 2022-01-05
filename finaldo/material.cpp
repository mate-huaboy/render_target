#include<Windows.h>
#include <gl/GL.h>
#include"util.h"

void set_drone_black()
{
	GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };  //定义材质的环境光颜色，为0
	GLfloat mat_diffuse[] = { 0.1f, 0.1f, 0.1f, 1.0f };  //定义材质的漫反射光颜色，为0
	GLfloat mat_specular[] = { 0.05f, 0.05f, 0.05f, 1.0f };   //定义材质的镜面反射光颜色，为0
	//GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射广颜色，为偏红色
	GLfloat mat_shininess = 100;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}
void set_drone_white()
{
	GLfloat mat_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };  //定义材质的环境光颜色，为0
	GLfloat mat_diffuse[] = { 0.7f, 0.7f,0.7f, 1.0f };  //定义材质的漫反射光颜色，为0
	GLfloat mat_specular[] = { 0.4f, 0.4f,0.4f, 1.0f };   //定义材质的镜面反射光颜色，为0
	//GLfloat mat_specular[] = { 1.f, 1.f, 1.f, 1.0f };
	//GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射广颜色，为偏红色
	GLfloat mat_shininess = 100;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
 }

void set_screw()
{
	GLfloat mat_ambient[] = { 0.19f, 0.19f, 0.19f, 1.0f };  //定义材质的环境光颜色，为0
	GLfloat mat_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };  //定义材质的漫反射光颜色，为0
	GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };   //定义材质的镜面反射光颜色，为0
	//GLfloat mat_specular[] = { 1.f, 1.f, 1.f, 1.0f };
	//GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射广颜色，为偏红色
	GLfloat mat_shininess = 56;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}

void set_bg_mat()//设置背景的反射属性
{
	GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };  //定义材质的环境光颜色，为0
	GLfloat mat_diffuse[] = { .5f, .5f, .5f, 1.0f };  //定义材质的漫反射光颜色，为0
	GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };   //定义材质的镜面反射光颜色，为0
	////GLfloat mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射广颜色，为偏红色
	//GLfloat* mat_ambient;  //定义材质的环境光颜色，为0
	
	//rand_num(4, mat_ambient);
	//GLfloat *mat_diffuse;  //定义材质的漫反射光颜色，为0
	//GLfloat *mat_specular;   //定义材质的镜面反射光颜色，为0
	//rand_num(4, mat_diffuse);
	//rand_num(4, mat_specular);
	GLfloat mat_shininess = 56;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}