#include "func.h"
int GetMaxValue(int a, int b)
{
    return a > b ? a : b;
}
 
int GetMinValue(int a, int b, int c)
{
    int min = a > b ? b : a;
    min = min > c ? c : min;
    return min;
}
 
int IsNotSame(char a, char b)
{
    return a == b ? 0 : 1;
}
