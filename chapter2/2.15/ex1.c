/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  子数组之和的最大值（二维）
 *                  首尾相连
 *
 *        Version:  1.0
 *        Created:  2012/10/08 12时50分19秒
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

#define max(a,b) (a>b?a:b)

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

    int max_left, max_right, sum_left, sum_right, l, r, res2;
    for(i = 0;i < n;i++)
    {
        for(j = i;j < n;j++)
        {
            max_left = max_right = -INF;
            sum_left = sum_right = 0;

            int tmp = 0;
            for(k = 0;k < m;k++)
            {
                if(tmp < 0) tmp = 0;

                tmp += sumj[j][k];
                sum_left += sumj[j][k];
                sum_right += sumj[j][n-k-1];

                if(i > 0) 
                {
                    tmp -= sumj[i-1][k];

                    sum_left -= sumj[i-1][k];
                    sum_right -= sumj[i-1][n-k-1];
                }
                if(sum_left > max_left) 
                {
                    max_left = sum_left;
                    l = k;
                }
                if(sum_right > max_right)
                {
                    max_right = sum_right;
                    r = n-k-1;
                }

                if(res < tmp) res = tmp;
            }
            if(l < r)
                res2 = max_left + max_right;
            else
            {
                tmp = sum_left = sum_right = 0;
                for(k = 0;k < r;k++) 
                {
                    sum_left += sumj[j][k];
                    if(i > 0) sum_left -= sumj[i-1][k];
                    
                    if(tmp < sum_left) tmp = sum_left;
                }
                res2 = max_right + tmp;

                tmp = 0;
                for(k = n-1;k > l;k--)
                {
                    sum_right += sumj[j][k];
                    if(i > 0) sum_right -= sumj[i-1][k];

                    if(tmp < sum_right) tmp = sum_right;
                }
                res2 = max(res2, max_left + tmp);
            }
            if(res < res2) res = res2;

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
