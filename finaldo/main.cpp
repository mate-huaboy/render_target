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
int n = 3600;  //圆绘制次数
//double x = PI;
float PI = 3.1415926f;
/// <summary>
/// 
/// </summary>
/// 


float l = 0.4;//set the longth of sq
float w = 0.4;//set the wide
float viewangle = 35.5;//视场角
float scale = 5;//缩放倍数,到时候得好好算算修正一下
float scalex;
float scaley;
int win_wideth = 4508/scale;
int win_he = 4096/scale;//窗口的宽度和高度
float R = 0.05f / 2;  //半径
std::ofstream outfile;

//GLdouble eyex=10;//是不是中心不在原点了所以看不到背景了？？---改一改背景映射
//GLdouble eyey=-0.5;
//GLdouble eyez=15;
//GLdouble centerx=0.6;
//GLdouble centery=-0.5;
//GLdouble centerz=0.05;
GLdouble eyex = 0;//是不是中心不在原点了所以看不到背景了？？---改一改背景映射
GLdouble eyey = 3;
GLdouble eyez = 6;
GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = 0;
int cont = 0;
string file_ford = "./testpicture1";
cv::Mat Trans = (cv::Mat_<double>(3, 3) << 1, 0, 0, 0, -1, win_he, 0, 0, 1);
void init(void) {

    scalex = 4508.0 / win_wideth;//修正一下
    scaley = 4096.0 / win_he;
    //need先设置投影矩阵
    //****后面再说

    //glClearColor(1.0, 1.0, 1.0, 1.0);//设置为黑色背景
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //设置视口
    //和窗口一致就好
   
}

void drawSquare(float l,float w)
{
    glBegin(GL_POLYGON);          //顶点指定需要按逆时针方向	
    glVertex3f(-1.0f*l/2, -1.0f*w/2,0.0f);      //左下点	
    glVertex3f(1.0f * l / 2, -1.0f * w / 2,0.0f);       //右下点	
    glVertex3f(1.0f * l / 2, 1.0f * w / 2,0.0f);        //右上点	
    glVertex3f(-1.0f * l / 2, 1.0f * w / 2,0.0f);       //左上点	
    glEnd();

}


void drawCircle(void)//是不是要改一改？
{
    //画圆
    //glClearColor(0, 0, 0, 0);
   // glColor4f(0, 0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glVertex3f(R * cos(2 * PI * i / n), R * sin(2 * PI * i / n),0);   //定义顶点
    }
    glEnd();

}

void drawCircle(float R,cv::Vec2f c)
{
    //画圆
    //glClearColor(0, 0, 0, 0);
    glColor4f(0, 0, 0, 0);//这里的颜色是不是要改变一下？
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glVertex3f(R * cos(2 * PI * i / n)+c[0], R * sin(2 * PI * i / n)+c[1], 0);   //定义顶点
    }
    glEnd();

}

//设置其他外圆--背景圆
void drawbgcircle()
{
    //准备数据
    
    //设两个6cm
    float r=2*R;
    cv::Vec2f c;
    c[0] = -1;
    c[1] = 0.7;
    drawCircle(r, c);
    c[0] = 1;
    c[1] = 0.7;
    drawCircle(r, c);

    //准备环形螺丝钉
    r = 0.018/2;
    float bigR = 1.3;//环形半径
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


//设置光源
void setlightsource()
{
    //尽可能多的考虑光照类型
    //阴天
    goballight();
    // 
    //晴天
    //远距离光
    //点光源
   //light_focus();
}

void drawbg()
{
    //清颜色和深度,以及得到所有参数的默认值
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
    //gluOrtho2D(-5.0, 5.0, -5.0, 5.0);  //设置显示的范围是X:-5.0~5.0, Y:-5.0~5.0	,好像和正交投影有关
    glLoadIdentity();
    //改为透视投影--需要内参
    gluPerspective(viewangle, win_wideth / win_he, 4, 25);//其实我们不知道这个宽高比
    glMatrixMode(GL_MODELVIEW);    //设置当前操作的矩阵为“模型视图矩阵”

    //playdg();
   // glClear(GL_COLOR_BUFFER_BIT);
   // glClear(GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//操作模型视图矩阵

    //设置视点
    gluLookAt(
        eyex,
        eyey,
        eyez,
        centerx,
        centery,
        centerz, 0, 1, 0);//脑袋朝上

    //glScalef(10.0, 10.8, 10.0);//先试试缩放，后面再去掉

    //glRotatef(0, 1, 0, 0);//旋转
  


    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(scalex, scaley, 1);//设置缩放

   // glColor4f(0.0, 0.0, 0.0, 0.0);//黑底
    set_drone_black();

   /* glPushMatrix();*/
    drawSquare(l,w);
    glDisable(GL_DEPTH_TEST);
   // glColor4f(1.0, 1.0, 1.0, 1.0);//白底
    set_drone_white();
    drawSquare(l - 2*R, w - 2*R);
    glEnable(GL_DEPTH_TEST);
    /*glPopMatrix();*/  //下矩形

 /*  glPushMatrix();
    glTranslatef(0.8f, 1.2f, 1.0f);
    glScalef(0.8, 0.4, 0.8);
    glColor3f(0.0, 1.0, 0.0);
    drawSquare();
    glPopMatrix();    //上矩形
*/
    //定义圆的平移矩阵
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

    set_drone_black();//设置材质
    for (int i = 0; i < 9; i++)
    {
        glPushMatrix();
        glTranslatef(T[i][0], T[i][1], T[i][2]);
        //glScalef(0.6, 0.6, 1.0);
       // glColor3f(0.0, 0.0, 0.0);//设为黑
        
        drawCircle();
        glPopMatrix();   //左圆
    }


    //多设置几个圆*********************
    set_screw();
    drawbgcircle();

    //**************************

    glFlush();
       //保存图片
    glutSwapBuffers();
    string s = file_ford + "/test" + to_string(cont) + ".bmp";
    SaveImage(s.c_str(), win_wideth, win_he);

    //***********************计算圆心的像素坐标
    GLdouble a[16];
    GLint c[4];
    GLdouble b[16];
    glGetDoublev(GL_PROJECTION_MATRIX, a);
    glGetDoublev(GL_MODELVIEW_MATRIX, b);
    glGetIntegerv(GL_VIEWPORT, c);

    //for (int i = 0; i < 16; i++)//投影矩阵
    //{
    //    if (i % 4 == 0)
    //    {
    //        outfile << endl;

    //    }
    //    outfile << a[i] << " ";
    //}
    for (int i = 0; i < 16; i++)//模型视图矩阵
    {
       
        outfile << b[i] << " ";
        if ((i + 1) % 4 == 0)
        {
            outfile << endl;

        }
    }
    //for (int i = 0; i < 4; i++)//视口
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


    outfile << "输出原始投影矩阵" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i%4==0)
        {
            outfile << endl;

        }
        outfile << a[i] << "\t";
    }
    outfile << "输出glm投影矩阵" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << pro[i/4][i%4] << "\t";
    }
    outfile << "输出原始模型矩阵" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << b[i] << "\t";
    }
    outfile << "输出glm模型矩阵" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << model[i / 4][i % 4] << "\t";
    }
    outfile << "输出原始shitu" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (i % 4 == 0)
        {
            outfile << endl;

        }
        outfile << c[i] << "\t";
    }
    outfile << "输出glm视图矩阵" << endl;
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
       //写入文件
       //outfile << propos[0] << "," << propos[1] << "," << propos[2] << endl;

    
#endif // DEBUG


    for (int i = 0; i < 9; i++)
    {   
        //******************试一试用另一种方法
        GLdouble winx, winy, winz, x = T[i][0], y = T[i][1], z = T[i][2];
        gluProject(x, y, z, b, a, c, &winx, &winy, &winz);
        cv::Mat t = (cv::Mat_<double>(3, 1) << winx , winy , 1);
        t = Trans * t;
        double t_x = t.at<double>(0, 0);
        double t_y = t.at<double>(1, 0);
        outfile << t_x << " " << t_y << " " << winz<<endl;

    }

    //关闭文件
    outfile.flush();
  
   

    //*****************************

/*
    glPushMatrix();
    glTranslatef(-1.0f, -0.8f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    drawCircle();
    glPopMatrix();   //左圆



    glPushMatrix();
    glTranslatef(1.0f, -0.8f, 0.0f);
    glScalef(0.6, 0.6, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    drawCircle();
    glPopMatrix();  //右圆
*/

 

}

void myidle()//定义每次循环,更改参数
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
    glutCreateWindow("渲染");
    init();
   
    //打开写入的txt************
    
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



