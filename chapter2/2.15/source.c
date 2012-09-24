/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  子数组之和的最大值（二维）
 *                  貌似经典DP
 *
 *        Version:  1.0
 *        Created:  2012/09/22 15时50分19秒
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

#define MAX 100
#define INF 1000000000

void generator(int mat[][MAX], int n, int m)
{
    int i, j;
    srand(time(0));
    for(i = 0;i < n;i++)
        for(j = 0;j < m;j++)
            mat[i][j] = rand() % 200 - 100;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go
 *  Description:  返回最大子数组的和
 * =====================================================================================
 */
int go(int mat[][MAX], int n, int m)
{
    int sumj[MAX][MAX], i, j, k;

    int res = -INF;
    memset(sumj, 0, sizeof(sumj));

    for(j = 0;j < m;j++)
        sumj[0][j] = mat[0][j];
    for(i = 1;i < n;i++)
        for(j = 0;j < m;j++)
            sumj[i][j] = sumj[i-1][j] + mat[i][j];

    for(i = 0;i < n;i++)
    {
        for(j = i;j < n;j++)
        {
            int tmp = 0;
            for(k = 0;k < m;k++)
            {
                if(tmp < 0) tmp = 0;

                tmp += sumj[j][k];
                if(i > 0) tmp -= sumj[i-1][k];

                if(res < tmp) res = tmp;
            }
        }
    }

    return res;
}
int main (int argc, char *argv[])
{
    int mat[MAX][MAX];
    generator(mat, MAX, MAX);

    int res = go(mat, MAX, MAX);

    printf("%d*%d矩阵，最大子矩阵和为：%d\n", MAX, MAX, res);
    return 0;
}
