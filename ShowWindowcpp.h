#ifndef _ShowWindowcpp_H_
#define _ShowWindowcpp_H_
 
#define SideLenth 0.02 //Õý·½ÐÎ±ß³¤ 0.02
 
#include <GL/glut.h>
#include "func.h"
#include "WordLevenShtein.h"
 
void changeSize(int w, int h);
void ShowRectangle(int i,int j,double Radio);
void DrowBackground(void);
void myDisplay(void);
 
 
#endif
