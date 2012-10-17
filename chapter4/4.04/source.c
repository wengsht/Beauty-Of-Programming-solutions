/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  点是否在三角形内
 *
 *        Version:  1.0
 *        Created:  2012/10/17 14时22分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    double x, y;
} Point;
double product(Point a, Point b, Point c)
{
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}
int isIn(Point a, Point b, Point c, Point d)
{
    return ((product(b, c, d) >= 0 && product(c, a, d) >= 0 && product(a, b, d) >= 0) ? 1 : 0);
}
int main()
{
    Point a, b, c, d;
    // b a c要顺时针
    a.x = 1; a.y = 1;
    b.x = 0; b.y = 0;
    c.x = 1; c.y = 0;

    d.x = 0.5; d.y = 0;

    printf("<%lf, %lf> : %d\n", d.x, d.y, isIn(a,b,c,d));

    return 0;
}
