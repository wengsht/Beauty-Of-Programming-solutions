/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  金刚坐飞机问题
 *                  问题2 dp
 *
 *        Version:  1.0
 *        Created:  2012/10/15 17时18分05秒
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

#define MX 1000
double dp[MX][MX];

int main()
{
    dp[1][1] = 1;

    int p, n;
    int l, i, j;

    scanf("%d %d", &p, &n);

    for(l = 2;l <= n;l++)
    {
        dp[1][l] = 1.0/l;
        for(i = 2;i <= l;i++)
        {
            dp[i][l] = (double)(l-i+1)/l;

            for(j = 1;j <= i-2;j++)
                dp[i][l] += 1.0/l*dp[i-j][l-j];
        }
    }
    printf("dp 结果：%.6lf\n", dp[p][n]);
    printf("公式结果:%.6lf\n", (double)(n-p+1)/(n-p+2));

    return 0;
}
