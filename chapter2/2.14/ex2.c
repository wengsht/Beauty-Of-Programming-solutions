/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  求数组子数组之和的最大值 练习2 记录子数组位置
 *                  只需要记录tmp(书中为nStart)的开始位置就可以了
 *                  
 *        Version:  1.0
 *        Created:  2012/09/22 14时55分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define NUM 1000000

void generator(int *arr, int n)
{
    srand(time(0));

    int i;
    for(i = 0;i < n;i++)
        arr[i] = rand() % (200) - 100;
}

typedef struct
{
    int l, r, sum;
} Trible;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go
 *  Description:  返回数组子数组之和的最大值,以及相应子数组位置
 * =====================================================================================
 */
Trible go(int *arr, int n)
{
    Trible res;
    res.sum = arr[0];
    res.l = res.r = 0;
    int tmp = arr[0];

    int i, j = 0;
    for(i = 1;i < n;i++)
    {
        if(tmp < 0) 
        {
            tmp = 0;

            j = i;
        }
        tmp += arr[i];
        if(tmp > res.sum) 
        {
            res.sum = tmp;
            res.l = j;
            res.r = i;
        }
    }

    return res;
}

int main (int argc, char *argv[])
{
    int test[NUM];
    clock_t st, ed;
    double t;
    generator(test, NUM);

    st = clock();
    Trible res = go(test, NUM);
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("%d大小的数组子数组[%d,%d]之和的最大值是： %d， 耗时：%lfms\n", NUM,res.l,res.r, res.sum, t);

    return 0;
}
