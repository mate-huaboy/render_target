#include <gl/glut.h>
#include <cstdio>
#include <corecrt_malloc.h>
#include<glfw3.h>
#include<SOIL2/SOIL2.h>
//char* namef = 'C:\Users\WenhuaLiao\Desktop';
int width; int height;
GLuint LoadTexture(const char* filename)
{

	GLuint texture;
	//unsigned char* data;
	//FILE* file;

	//���ļ�
	/*file = fopen(filename, "rb");
	if (file == NULL) return 0;

	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);*/

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	//������ͼ
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	unsigned char* image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);
	//��������
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, image);
	//free(data); //�ͷ�����
	return texture;

}

void Background(GLuint texture)
{

	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0); glVertex2d(-1.0, -1.0);
	glTexCoord2d(1.0, 0.0); glVertex2d(+1.0, -1.0);
	glTexCoord2d(1.0, 1.0); glVertex2d(+1.0, +1.0);
	glTexCoord2d(0.0, 1.0); glVertex2d(-1.0, +1.0);
	glEnd();
	return;
}


//void playdg()
//{
//	//int w=400,  h=200;
//	glDisable(GL_DEPTH_TEST);
//	//ָ��Ϊ����ͶӰ
//	glLoadIdentity();
//
//
//	//��������
//	GLuint texture = LoadTexture("C:/Users/WenhuaLiao/Desktop/img.bmp");
//
//	glEnable(GL_TEXTURE_2D);
//	glPushMatrix();
//	glScalef(100, 70, 1);
//	glTranslatef(0, 0, -150);
//	Background(texture);					//��������
//	glPopMatrix();
//}


/*void playdg()
{
	float zoom = 300.0f;

	int win_width = 1920;

	int win_height = 1080;


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-zoom * win_width / win_height, zoom * win_width / win_height, -zoom, zoom, -300.0, 300.0);   //�л�Ϊ�����ӽǣ�
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.f, 1.f, 1.f);
	glDisable(GL_DEPTH_TEST);   //�ر���Ȳ���;

	GLuint texture = LoadTexture("C:/Users/WenhuaLiao/Desktop/img.jpg");    //����ͼƬ

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);      //��ͼƬ�ĸ��ǵ�λ������Ϊ�������ں�ü�����ĸ��ǣ�
	glTexCoord2d(0.0, 0.0); glVertex3d(-zoom * win_width / win_height, -zoom, -300);
	glTexCoord2d(1.0, 0.0); glVertex3d(zoom * win_width / win_height, -zoom, -300);
	glTexCoord2d(1.0, 1.0); glVertex3d(zoom * win_width / win_height, zoom, -300);
	glTexCoord2d(0.0, 1.0); glVertex3d(-zoom * win_width / win_height, zoom, -300);
	glEnd();


}*/

void playdg(int win_width,int win_geight)
{
	float zoom = 300.0f;

	/*int win_width = 1920;

	int win_height = 1080;*/


	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-zoom * win_width / win_height, zoom * win_width / win_height, -zoom, zoom, -300.0, 300.0);   //�л�Ϊ�����ӽǣ�
	//glOrtho(-300.,300.,-300.,300.,-1,-1);   //�л�Ϊ�����ӽǣ�

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glColor3f(1.f, 1.f, 1.f);
	glDisable(GL_DEPTH_TEST);   //�ر���Ȳ���;

	GLuint texture = LoadTexture("C:/Users/WenhuaLiao/Desktop/img.jpg");    //����ͼƬ

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);      //��ͼƬ�ĸ��ǵ�λ������Ϊ�������ں�ü�����ĸ��ǣ�
	/*glTexCoord2d(0.0, 0.0); glVertex3d(-zoom * win_width / win_height, -zoom, -300);
	glTexCoord2d(1.0, 0.0); glVertex3d(zoom * win_width / win_height, -zoom, -300);
	glTexCoord2d(1.0, 1.0); glVertex3d(zoom * win_width / win_height, zoom, -300);
	glTexCoord2d(0.0, 1.0); glVertex3d(-zoom * win_width / win_height, zoom, -300);*/

	/*glTexCoord2d(0.0, 0.0); glVertex3d(-1.0, -1.0,0.);
	glTexCoord2d(1.0, 0.0); glVertex3d(+1.0, -1.0,0.);
	glTexCoord2d(1.0, 1.0); glVertex3d(+1.0, +1.0,0.);
	glTexCoord2d(0.0, 1.0); glVertex3d(-1.0, +1.0,0.);*/
	glTexCoord2d(0.0, 1.0); glVertex3d(-1.0, -1.0, 0.);
	glTexCoord2d(1.0, 1.0); glVertex3d(+1.0, -1.0, 0.);
	glTexCoord2d(1.0, 0.0); glVertex3d(+1.0, +1.0, 0.);
	glTexCoord2d(0.0, 0.0); glVertex3d(-1.0, +1.0, 0.);

	glEnd();
	glutSwapBuffers();

}