/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  求数组子数组之和的最大值
 *                  
 *                  迎来了一道相当简单的题目真开心。。
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go
 *  Description:  返回数组子数组之和的最大值
 * =====================================================================================
 */
int go(int *arr, int n)
{
    int res = arr[0], tmp = arr[0];

    int i;
    for(i = 1;i < n;i++)
    {
        if(tmp < 0) tmp = 0;
        tmp += arr[i];
        if(tmp > res) res = tmp;
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
    int res = go(test, NUM);
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("%d大小的数组子数组之和的最大值是： %d， 耗时：%lfms\n", NUM, res, t);

    return 0;
}
