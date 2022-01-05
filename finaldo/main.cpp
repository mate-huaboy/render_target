#include <windows.h>
#include <gl/glut.h>
#include<math.h>
#include<iostream>
#include<opencv/cv.hpp>
#include<glm/common.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<string.h>
#include<fstream>
#include"bg.h"
#include"save.h"
#include"light.h"
#include"material.h"
#include"control_trace.h"
//#define DEBUG
using namespace std;
int n = 3600;  //Բ���ƴ���
//double x = PI;
float PI = 3.1415926f;
/// <summary>
/// 
/// </summary>
/// 


float l = 0.4;//set the longth of sq
float w = 0.4;//set the wide
float viewangle = 35.5;//�ӳ���
float scale = 5;//���ű���,��ʱ��úú���������һ��
float scalex;
float scaley;
int win_wideth = 4508/scale;
int win_he = 4096/scale;//���ڵĿ�Ⱥ͸߶�
float R = 0.05f / 2;  //�뾶
std::ofstream outfile;

//GLdouble eyex=10;//�ǲ������Ĳ���ԭ�������Կ����������ˣ���---��һ�ı���ӳ��
//GLdouble eyey=-0.5;
//GLdouble eyez=15;
//GLdouble centerx=0.6;
//GLdouble centery=-0.5;
//GLdouble centerz=0.05;
GLdouble eyex = 0;//�ǲ������Ĳ���ԭ�������Կ����������ˣ���---��һ�ı���ӳ��
GLdouble eyey = 3;
GLdouble eyez = 6;
GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = 0;
int cont = 0;
string file_ford = "./testpicture1";
cv::Mat Trans = (cv::Mat_<double>(3, 3) << 1, 0, 0, 0, -1, win_he, 0, 0, 1);
void init(void) {

    scalex = 4508.0 / win_wideth;//����һ��
    scaley = 4096.0 / win_he;
    //need������ͶӰ����
    //****������˵

    //glClearColor(1.0, 1.0, 1.0, 1.0);//����Ϊ��ɫ����
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //�����ӿ�
    //�ʹ���һ�¾ͺ�
   
}

void drawSquare(float l,float w)
{
    glBegin(GL_POLYGON);          //����ָ����Ҫ����ʱ�뷽��	
    glVertex3f(-1.0f*l/2, -1.0f*w/2,0.0f);      //���µ�	
    glVertex3f(1.0f * l / 2, -1.0f * w / 2,0.0f);       //���µ�	
    glVertex3f(1.0f * l / 2, 1.0f * w / 2,0.0f);        //���ϵ�	
    glVertex3f(-1.0f * l / 2, 1.0f * w / 2,0.0f);       //���ϵ�	
    glEnd();

}


void drawCircle(void)//�ǲ���Ҫ��һ�ģ�
{
    //��Բ
    //glClearColor(0, 0, 0, 0);
   // glColor4f(0, 0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glVertex3f(R * cos(2 * PI * i / n), R * sin(2 * PI * i / n),0);   //���嶥��
    }
    glEnd();

}

void drawCircle(float R,cv::Vec2f c)
{
    //��Բ
    //glClearColor(0, 0, 0, 0);
    glColor4f(0, 0, 0, 0);//�������ɫ�ǲ���Ҫ�ı�һ�£�
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glVertex3f(R * cos(2 * PI * i / n)+c[0], R * sin(2 * PI * i / n)+c[1], 0);   //���嶥��
    }
    glEnd();

}

//����������Բ--����Բ
void drawbgcircle()
{
    //׼������
    
    //������6cm
    float r=2*R;
    cv::Vec2f c;
    c[0] = -1;
    c[1] = 0.7;
    drawCircle(r, c);
    c[0] = 1;
    c[1] = 0.7;
    drawCircle(r, c);

    //׼��������˿��
    r = 0.018/2;
    float bigR = 1.3;//���ΰ뾶
    int num = 15;
    float step = PI / num;
    c[0] = 0;
    c[1] = 1.6;
    cv::Vec2f center;
    for (int i = 0; i < num; i++)
    {
        center[0] = c[0] + bigR * cos(-PI + i * step);
        center[1] = c[1] + bigR * sin(-PI + i * step);
        drawCircle(r, center);
    }


}


//���ù�Դ
void setlightsource()
{
    //�����ܶ�Ŀ��ǹ�������
    //����
    goballight();
    // 
    //����
    //Զ�����
    //���Դ
   //light_focus();
}

void drawbg()
{
    //����ɫ�����,�Լ��õ����в�����Ĭ��ֵ
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   /* setlightsource();
    set_bg_mat();*/
    playdg(win_wideth, win_he);
}

void myDraw(void) {  
    //  playdg(400, 200);
    drawbg();
    setlightsource();
    set_bg_mat();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(-5.0, 5.0, -5.0, 5.0);  //������ʾ�ķ�Χ��X:-5.0~5.0, Y:-5.0~5.0	,���������ͶӰ�й�
    glLoadIdentity();
    //��Ϊ͸��ͶӰ--��Ҫ�ڲ�
    gluPerspective(viewangle, win_wideth / win_he, 4, 25);//��ʵ���ǲ�֪�������߱�
    glMatrixMode(GL_MODELVIEW);    //���õ�ǰ�����ľ���Ϊ��ģ����ͼ����

    //playdg();
   // glClear(GL_COLOR_BUFFER_BIT);
   // glClear(GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//����ģ����ͼ����

    //�����ӵ�
    gluLookAt(
        eyex,
        eyey,
        eyez,
        centerx,
        centery,
        centerz, 0, 1, 0);//�Դ�����

    //glScalef(10.0, 10.8, 10.0);//���������ţ�������ȥ��

    //glRotatef(0, 1, 0, 0);//��ת
  


    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(scalex, scaley, 1);//��������

   // glColor4f(0.0, 0.0, 0.0, 0.0);//�ڵ�
    set_drone_black();

   /* glPushMatrix();*/
    drawSquare(l,w);
    glDisable(GL_DEPTH_TEST);
   // glColor4f(1.0, 1.0, 1.0, 1.0);//�׵�
    set_drone_white();
    drawSquare(l - 2*R, w - 2*R);
    glEnable(GL_DEPTH_TEST);
    /*glPopMatrix();*/  //�¾���

 /*  glPushMatrix();
    glTranslatef(0.8f, 1.2f, 1.0f);
    glScalef(0.8, 0.4, 0.8);
    glColor3f(0.0, 1.0, 0.0);
    drawSquare();
    glPopMatrix();    //�Ͼ���
*/
    //����Բ��ƽ�ƾ���
    float T[9][3] = {

        {-4 * R,4 * R,0},
         {0,4 * R,0},
          {4 * R,4 * R,0},
           {-4 * R,0,0},
            {0,0,0},
             {4*R ,0,0},
              {-4 * R,-4 * R,0},
               {0,-4 * R,0},
               {4 * R,-4 * R,0}

    };
    
    glClear(GL_DEPTH_BUFFER_BIT);

    set_drone_black();//���ò���
    for (int i = 0; i < 9; i++)
    {
        glPushMatrix();
        glTranslatef(T[i][0], T[i][1], T[i][2]);
        //glScalef(0.6, 0.6, 1.0);
       // glColor3f(0.0, 0.0, 0.0);//��Ϊ��
        
        drawCircle();
        glPopMatrix();   //��Բ
    }


    //�����ü���Բ*********************
    set_screw();
    drawbgcircle();

    //**************************

    glFlush();
       //����ͼƬ
    glutSwapBuffers();
    string s = file_ford + "/test" + to_string(cont) + ".bmp";
    SaveImage(s.c_str(), win_wideth, win_he);

    //***********************����Բ�ĵ���������
    GLdouble a[16];
    GLint c[4];
    GLdouble b[16];
    glGetDoublev(GL_PROJECTION_MATRIX, a);
    glGetDoublev(GL_MODELVIEW_MATRIX, b);
    glGetIntegerv(GL_VIEWPORT, c);

    //for (int i = 0; i < 16; i++)//ͶӰ����
    //{
    //    if (i % 4 == 0)
    //    {
    //        outfile << endl;

    //    }
    //    outfile << a[i] << " ";
    //}
    for (int i = 0; i < 16; i++)//ģ����ͼ����
    {
       
        outfile << b[i] << " ";
        if ((i + 1) % 4 == 0)
        {
            outfile << endl;

        }
    }
    //for (int i = 0; i < 4; i++)//�ӿ�
    //{
    //    if (i % 4 == 0)
    //    {
    //        outfile << endl;

    //    }
    //    outfile << c[i] << " ";
    //}
    //outfile << endl;

#ifdef DEBUG
    glm::mat4x4 pro = glm::make_mat4(a);
    glm::mat4 model = glm::make_mat4(b);
    glm::vec4 view = glm::make_vec4(c);


    outfile << "���ԭʼͶӰ����" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i%4==0)
        {
            outfile << endl;

        }
        outfile << a[i] << "\t";
    }
    outfile << "���glmͶӰ����" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << pro[i/4][i%4] << "\t";
    }
    outfile << "���ԭʼģ�;���" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << b[i] << "\t";
    }
    outfile << "���glmģ�;���" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << model[i / 4][i % 4] << "\t";
    }
    outfile << "���ԭʼshitu" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << c[i] << "\t";
    }
    outfile << "���glm��ͼ����" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << view[i] << "\t";
    }
    /* glm::vec3 org = glm::vec3(T[i][0], T[i][1], T[i][2]);
       glm::vec3 propos;
       propos=glm::project(org, pro, model, view);*/
       //д���ļ�
       //outfile << propos[0] << "," << propos[1] << "," << propos[2] << endl;

    
#endif // DEBUG


    for (int i = 0; i < 9; i++)
    {   
        //******************��һ������һ�ַ���
        GLdouble winx, winy, winz, x = T[i][0], y = T[i][1], z = T[i][2];
        gluProject(x, y, z, b, a, c, &winx, &winy, &winz);
        cv::Mat t = (cv::Mat_<double>(3, 1) << winx , winy , 1);
        t = Trans * t;
        double t_x = t.at<double>(0, 0);
        double t_y = t.at<double>(1, 0);
        outfile << t_x << " " << t_y << " " << winz<<endl;

    }

    //�ر��ļ�
    outfile.flush();
  
   

    //*****************************

/*
    glPushMatrix();
    glTranslatef(-1.0f, -0.8f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    drawCircle();
    glPopMatrix();   //��Բ



    glPushMatrix();
    glTranslatef(1.0f, -0.8f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    drawCircle();
    glPopMatrix();  //��Բ
*/

 

}

void myidle()//����ÿ��ѭ��,���Ĳ���
{
     control_trace a= control_trace(60, 6, 12);
     
     while (a.loc_pos(eyex,
          eyey,
          eyez,
           centerx,
           centery,
           centerz, cont))
     {
         cont++;
         cout << " " << eyez;
         myDraw();
     }
     outfile.close();
   
     exit(1);
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(win_wideth,win_he);
    glutCreateWindow("��Ⱦ");
    init();
   
    //��д���txt************
    
    outfile= std::ofstream (file_ford + "/realPos.txt", std::ios::app);
    if (outfile.bad())
    {
        std::cout << "cannot open file" << std::endl;;
    }
   
   // outfile.open("flow.txt", std::ios::app);


    //glutDisplayFunc(drawbg);
    glutDisplayFunc(myDraw);
    glutIdleFunc(myidle);
    glutMainLoop();

}



