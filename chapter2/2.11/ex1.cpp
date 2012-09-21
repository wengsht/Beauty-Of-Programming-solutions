/*
 * =====================================================================================
 *
 *       Filename:  ex1.c
 *
 *    Description:  练习1，找整数数组相邻两数最大差值。
 *                  经典题目，遇到过。
 *
 *        Version:  1.0
 *        Created:  2012/09/21 18时41分05秒
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
#include <time.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define NUM 2000000


/*  桶存储最大值和最小值，已经是否为空 */
typedef struct 
{
    int mini, maxi;
    int full;
} Pair;

Pair barrel[NUM];

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solution1
 *  Description:  3/2n次比较，返回最大和最小值到res中
 * =====================================================================================
 */
Pair solution1(int *arr, int n)
{
    Pair res;
    int min_index = 0, max_index = 1;
    int st = 1, i;
    if(n % 2 == 1)
        res.mini = res.maxi = arr[0];
    else
    {
        st = 2;
        if(arr[0] > arr[1])
        {
            min_index = 1;
            max_index = 0;
        }
        res.mini = arr[min_index];
        res.maxi = arr[max_index];
        
    }
    for(i = st;i < n;i+=2)
    {
        min_index = i;
        max_index = i+1;
        if(arr[i] > arr[i+1])
        {
            min_index = i+1;
            max_index = i;
        }

        if(arr[min_index] < res.mini) res.mini = arr[min_index];
        if(arr[max_index] > res.maxi) res.maxi = arr[max_index];
        
    }
    return res;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go
 *  Description:  返回相邻数的最大差值
 * =====================================================================================
 */
int go(int *arr, int n)
{
    memset(barrel, 0, sizeof(Pair)*n);
    Pair tmp = solution1(arr, n);

    double ds = (double)(tmp.maxi - tmp.mini) / (n-1);
    int index, i;
    int res = 0;

    for(i = 0;i < n;i++)
    {
        index = floor((arr[i]-tmp.mini) / ds);

        if(!barrel[index].full)
        {
            barrel[index].full = 1;
            barrel[index].mini = barrel[index].maxi = arr[i];
        }
        else
        {
            if(barrel[index].mini > arr[i]) barrel[index].mini = arr[i];
            if(barrel[index].maxi < arr[i]) barrel[index].maxi = arr[i];
        }
    }

    for(i = 0;i < n;i++)
        if(barrel[i].full) break;

    int j = i;
    for(i++;i < n;i++)
    {
        if(barrel[i].full)
        {
            int new_dis = barrel[i].mini - barrel[j].maxi;
            if(res < new_dis) res = new_dis;
            j = i;
        }
    }

    return res;
}
int main (int argc, char *argv[])
{
    int test[NUM];
    int res, i;
    clock_t st, ed;
    double t;
    srand(time(0));
    for(i = 0;i < NUM;i++) 
    {
        test[i] = rand() % NUM;
//        printf("%d ", test[i]);
    }
    printf("\n");

    st = clock();
    res = go(test, NUM);
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("测试样例大小：%d\n", NUM);
    printf("桶解法：最大差值为%d, 耗时%lfms\n", res, t);

    st = clock();
    sort(test, test+NUM);

    res = 0;
    for(int i = 0;i < NUM-1;i++)
    {
        int new_dis = test[i+1] - test[i];
        if(res < new_dis) res = new_dis;
    }
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("sort排序：最大差值为%d, 耗时%lfms\n", res, t);
    
    return 0;
}
