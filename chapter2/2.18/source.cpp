/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  数组分割
 *                  书中仅给出求SUM值的算法，而并没有提及如何找出确切的组成元素。
 *                  参考2.12的习题，这个问题实际上很暴力。但是有了dp数组可能可以在递归的时候剪掉很多东西
 *
 *        Version:  1.0
 *        Created:  2012/10/09 14时44分53秒
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
#include <string.h>
#include <time.h>

#define NUM 10
#define MAXSUM NUM*100

#define min(a,b) (a<b?a:b)

void generator(int *arr, int n)
{
    srand(time(0));

    int i;
    for(i = 0;i < n;i++)
        arr[i] = rand() % 100;
}

int go(int *arr, int n, int sum)
{
    bool dp[NUM/2+1][MAXSUM];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;

    int i, j, k;
    for(i = 0;i < n;i++)
    {
        for(j = min(n/2, i); j > 0; j--)
        {
            for(k = 0;k <= sum/2;k++)
            {
                if(arr[i] <= k && dp[j-1][k-arr[i]])
                    dp[j][k] = true;
            }
        }
    }
    for(i = sum/2;i >= 0;i--)
        if(dp[n/2][i]) return i;

    return 0;
}
int main()
{
    int arr[NUM] = {1,5,7,8,9,6,3,11,20,17};

    //generator(arr, NUM);

    int sum = 0, i;
    for(i = 0;i < NUM;i++) sum += arr[i];

    int res = go(arr, NUM, sum);

    printf("sum:%d, (%d,%d)\n", sum, res, sum-res);
}
