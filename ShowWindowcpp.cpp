#include "ShowWindowcpp.h"
 
extern double result[100][100];
extern int ArrayLenth;
 
void changeSize(int w, int h)
{
    return;
}
 
/*绘制第i行j列的方块 Radio为求得的相似度*/
void ShowRectangle(int i,int j,double Radio)
{
    double pointx = 0.0, pointy=0.0;
      
    pointx = ((double)(i))/50 - 1.0;
    pointy = 1.0 - ((double)(j))/50;
     
    Radio = 1-Radio;//以黑色作为最相近的颜色
 
    glBegin(GL_POLYGON);  
    //cout<<i<<"------>"<<j<<"----->"<<Radio<<endl;
    glColor3f(Radio, Radio, Radio);    //颜色 
 
    glVertex2f(pointx,pointy);   
    glVertex2f(pointx,pointy- SideLenth);   
    glVertex2f(pointx + SideLenth,pointy - SideLenth);   
    glVertex2f(pointx + SideLenth,pointy);  
     
    glEnd();  
     
    //绘制正方形的边线，防止2个同色图形紧挨而显示不出来
    glBegin(GL_LINES) ;//上方
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(pointx,pointy); 
    glVertex2f(pointx + SideLenth,pointy);
    glEnd();
     
    glBegin(GL_LINES) ;//下方
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(pointx ,pointy - SideLenth); 
    glVertex2f(pointx + SideLenth,pointy - SideLenth);
    glEnd();
 
    glBegin(GL_LINES) ;//左方
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(pointx,pointy); 
    glVertex2f(pointx,pointy - SideLenth); 
    glEnd();
 
    glBegin(GL_LINES) ;//右方
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(pointx + SideLenth,pointy); 
    glVertex2f(pointx + SideLenth,pointy - SideLenth); 
    glEnd();
 
    glFlush();
    return ;
}
 
/*绘制灰色背景*/
void DrowBackground(void)
{
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-1,-1);
    glVertex2f(-1,1);
    glVertex2f(1,1); 
    glVertex2f(1,-1); 
    glEnd(); 
}
 
void myDisplay(void)
{
    int i=0,j=0;
     
    glClearColor(0.3,0.3,0.3,1); 
    DrowBackground();
     
    for (i=0;i<ArrayLenth;i++)
        for (j=0;j<ArrayLenth;j++)       
            ShowRectangle(i,j,result[j][i]);
 
    return ;
}
