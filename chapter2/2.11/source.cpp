/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  寻找最近点对
 *                  算法导论有经典解，此处就直接实现了
 *
 *        Version:  1.0
 *        Created:  2012/09/21 14时19分01秒
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

#define INF 99999999.00
#define NUM 10000
int zone[NUM];

class Point
{
public:
    double x, y;
    friend int operator ==(Point a, Point b);
};

Point y_sorted_left[NUM], y_sorted_right[NUM], tmp[NUM];

int operator ==(Point a, Point b)
{
    return a.x == b.x && a.y == b.y;
}

typedef struct
{
    Point a, b;

    double dis;
} TwoPoint;

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

double calcul(Point a, Point b)
{
    double xdis = a.x - b.x, ydis = a.y - b.y;
    return sqrt(xdis*xdis + ydis*ydis);
}
void merge(Point *arr, int mid, int n)
{
    int p = 0, q = mid+1;
    for(int i = 0;i < n;i++)
    {
        if(p > mid) tmp[i] = arr[q++];
        else if(q >= n) tmp[i] = arr[p++];
        else if(arr[p].y < arr[q].y) tmp[i] = arr[p++];
        else tmp[i] = arr[q++];
    }
    memcpy(arr, tmp, n*sizeof(Point));
}

TwoPoint go(Point x_sorted[], Point y_sorted[], int n)
{
    TwoPoint res, res_left, res_right;
    res.dis = INF;
    double dis;
    if(n <= 3)
    {
        for(int i = 0;i < n-1;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                dis = calcul(x_sorted[i], x_sorted[j]);

                if(dis < res.dis)
                {
                    res.dis = dis;

                    res.a = x_sorted[i];
                    res.b = x_sorted[j];
                }
            }
        }
        return res;
    }
    
    int mid = (n-1) >> 1;

    /* 计数器表示与mid一样而且又在left中的点个数 */
    int Count_equal_left = 1;
    for(int i = mid-1;i >= 0;i--)
    {
        if(x_sorted[i] == x_sorted[mid]) Count_equal_left++;

        else break;
    }

    for(int i = 0, left_n = 0, right_n = 0;i < n;i++)
    {
        if(y_sorted[i].x < x_sorted[mid].x || y_sorted[i].x == x_sorted[mid].x && y_sorted[i].y < x_sorted[mid].y)
            y_sorted_left[left_n++] = y_sorted[i];
        else if(y_sorted[i] == x_sorted[mid] && Count_equal_left-- > 0)
            y_sorted_left[left_n++] = y_sorted[i];
        else
            y_sorted_right[right_n++] = y_sorted[i];
    }

    memcpy(y_sorted, y_sorted_left, (mid+1)*sizeof(Point));
    memcpy(y_sorted+mid+1, y_sorted_right, (n-mid-1)*sizeof(Point));
//    delete [] y_sorted_left;
//    delete [] y_sorted_right;
    res_left = go(x_sorted, y_sorted, mid+1);
    res_right = go(x_sorted+mid+1, y_sorted+mid+1, n-mid-1);

    merge(y_sorted, mid, n);

    if(res_left.dis < res_right.dis) res = res_left;
    else                             res = res_right;

//    int * zone = new int[n];
    int m = 0;
    double left = x_sorted[mid].x - res.dis, right = x_sorted[mid].x + res.dis;

    for(int i = 0;i < n;i++)
    {
        if(y_sorted[i].x >= left && y_sorted[i].x <= right)
            zone[m++] = i;
    }
    for(int i = 0;i < m;i++)
    {
        int c = 0;
        for(int j = i+1;j < m;j++)
        {
            dis = calcul(y_sorted[zone[i]], y_sorted[zone[j]]);
            if(res.dis > dis)
            {
                res.dis = dis;
                res.a = y_sorted[zone[i]];
                res.b = y_sorted[zone[j]];
            }
            if(++c >= 7) break;
        }
    }
//    delete [] zone;
    return res;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_nearest_point
 *  Description:  传参点阵和个数，返回两个点，及距离，其距离最小
 * =====================================================================================
 */
TwoPoint find_nearest_point(Point points[], int n)
{
    TwoPoint res;
    Point *x_sorted, *y_sorted;
    x_sorted = points;

    y_sorted = new Point[n];

    memcpy(y_sorted, points, sizeof(Point) * n);
    sort(x_sorted, x_sorted+n, _cmpx);
    sort(y_sorted, y_sorted+n, _cmpy);

    res = go(x_sorted, y_sorted, n);

    delete [] y_sorted;

    return res;
}

int main (int argc, char *argv[])
{
    TwoPoint res;
    res.dis = INF;
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
            if(res.dis > dis)
            {
                res.dis = dis;
                res.a = test[i];
                res.b = test[j];
            }
        }
    }
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;
    printf("test n=%d\n", NUM);

    printf("朴素做法：(%lf,%lf) and (%lf, %lf) is nearest: %lf time:%lfms\n", res.a.x, res.a.y, res.b.x, res.b.y, res.dis, t);


    st = clock();
    res = find_nearest_point(test, NUM);
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("分治解法：(%lf,%lf) and (%lf, %lf) is nearest: %lf time:%lfms\n", res.a.x, res.a.y, res.b.x, res.b.y, res.dis, t);

    return 0;
}

