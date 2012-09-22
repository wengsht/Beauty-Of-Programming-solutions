/*
 * =====================================================================================
 *
 *       Filename:  ex1.c
 *
 *    Description:  练习1 环形
 *
 *        Version:  1.0
 *        Created:  2012/09/22 15时07分24秒
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
#define max(a,b) (a>b?a:b)

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
 *  Description:  返回环形数组子数组之和的最大值
 * =====================================================================================
 */
int go(int *arr, int n)
{
    int res = arr[0], tmp = arr[0];
    int sum_left = arr[0], sum_right = arr[n-1];
    int max_left = arr[0], max_right = arr[n-1];
    int j = 0, k = n-1;

    int i;
    for(i = 1;i < n;i++)
    {
        sum_left += arr[0];
        sum_right += arr[n-i-1];
        if(sum_left < max_left)
        {
            max_left = sum_left;

            j = i;
        }
        if(sum_right < max_right)
        {
            max_right = sum_right;

            k = n-i-1;
        }
        if(tmp < 0) tmp = 0;
        tmp += arr[i];
        if(tmp > res) res = tmp;
    }

    int res2;
    if(j < k)
        res2 = max_left + max_right;
    else
    {
        int sub_max = 0, sub_sum = 0;

        for(i = 0;i < k;i++)
        {
            sub_sum += arr[i];

            if(sub_max < sub_sum) sub_max = sub_sum;
        }
        res2 = sub_max + max_right;

        sub_max = sub_sum = 0;
        for(i = n-1;i > j;i--)
        {
            sub_sum += arr[i];

            if(sub_max < sub_sum) sub_max = sub_sum;
        }
        res2 = max(res2, sub_max + max_left);
    }
    return max(res2, res);
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

    printf("%d大小的环形数组子数组之和的最大值是： %d， 耗时：%lfms\n", NUM, res, t);

    return 0;
}
