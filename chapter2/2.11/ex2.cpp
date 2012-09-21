/*
 * =====================================================================================
 *
 *       Filename:  ex2.cpp
 *
 *    Description:  寻找最远点对
 *                  很直接的感觉想到凸包，然后旋转卡壳求直径
 *
 *        Version:  1.0
 *        Created:  2012/09/21 19时45分01秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

#define NUM 10000

class Point
{
public:
    double x, y;
    friend int operator ==(Point a, Point b);
};

Point graham[NUM+1];

int operator ==(Point a, Point b)
{
    return a.x == b.x && a.y == b.y;
}

bool _cmpx(Point a, Point b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
bool _cmpy(Point a, Point b)
{
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
bool left(Point a, Point b, Point c)
{
    return (a.x - c.x)*(b.y - c.y) >= (b.x - c.x) * (a.y - c.y);
}
int convex(Point *points, int n, Point *res)
{
    sort(points, points+n, _cmpy);
    if(n <= 2)
    {
        for(int i = 0;i < n;i++) res[i] = points[i];

        return n;
    }

    int top = 1;
    for(int i = 0;i < 3;i++) res[i] = points[i];
    for(int i = 2;i < n;++i)
    {
        while(top && left(points[i], res[top], res[top-1]))
            top--;
        res[++top] = points[i];
    }

    int len = top;
    res[++top] = points[n-2];
    for(int i = n-3;i >= 0;i--)
    {
        while(top != len && left(points[i], res[top], res[top-1]))
            top--;
        res[++top] = points[i];
    }
    return top;
}
double det(double x1, double y1, double x2, double y2)
{
    return x1*y2 - x2*y1;
}
double xMult(Point a, Point b, Point c)
{
    return det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
}
double calcul(Point a, Point b)
{
    double xdis = a.x - b.x, ydis = a.y - b.y;
    return sqrt(xdis*xdis + ydis*ydis);
}
double RC(Point ch[], int n)
{
    int q = 1;
    double res = 0;
    ch[n] = ch[0];
    for(int p = 0;p < n;p++)
    {
        while(xMult(ch[p+1], ch[q+1], ch[p]) > xMult(ch[p+1], ch[q], ch[p]))
            q = (q+1)%n;

        res = max(res, max(calcul(ch[p], ch[q]), calcul(ch[p+1], ch[q+1])));
    }
    return res;
}

double find_longest(Point *points, int n)
{
    double res = 0;

    n = convex(points, n, graham);

    res = RC(graham, n);

    return res;
}

int main (int argc, char *argv[])
{
    double res = 0;
    Point test[NUM];
    srand(time(0));
    clock_t st, ed;
    double t;
    for(int i = 0;i < NUM;i++)
    {
        test[i].x = (rand() % 100000000) / 1000000.0;
        test[i].y = (rand() % 100000000) / 1000000.0;

        printf("(%lf, %lf) ", test[i].x, test[i].y);
    }
    printf("\n\n");

    st = clock();

    for(int i = 0;i < NUM;i++)
    {
        for(int j = i+1;j < NUM;j++)
        {
            double dis = calcul(test[i], test[j]);
            if(res < dis)
                res = dis;
        }
    }
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;
    printf("test n=%d\n", NUM);

    printf("朴素做法：最远距离: %lf time:%lfms\n", res, t);


    st = clock();
    res = find_longest(test, NUM);
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("凸包旋转卡壳解法：最远距离: %lf time:%lfms\n", res, t);

    return 0;
}

