/*
 * =====================================================================================
 *
 *       Filename:  ex2.c
 *
 *    Description:  瓷砖覆盖地板
 *                  用1*2覆盖8*8的方案数
 *
 *        Version:  1.0
 *        Created:  2012/10/15 20时12分25秒
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

#define  MX 0x100

int dp[7][MX];
int tmp[MX][MX];  //tmp[i][j] i类型锯齿是否可以产生j类型锯齿

/*
 *  good(i) i的8位二进制数上没有连续的奇数个0
 */
int good(int p)
{
    int l = 0, r = 8;
    while(p)
    {
        if(p%2)
        {
            if(l % 2) return 0;
            l = 0;
        }
        else l++;

        p >>= 1;
        r--;
    }
    return (r+1)%2;
}
int main()
{
    int i, j, k, res = 0;

    //dp[0][i]的结果和good(i)一样，算是个不费空间换时间的糖果,其实用交替数组dp[2][MX]就够了。。
    for(i = 0;i < MX;i++) dp[0][i] = good(i);

    //迭代一下，dp[i][j]表示从锯齿k到锯齿j的方案数之和，可以转化的条件是k和j不重合并且k|j剩下的那些空方块可以被横瓷砖覆盖
    for(i = 1; i < 7;i++)
        for(j = 0;j < MX;j++)
            for(k = 0;k < MX;k++)
                if((k & j) == 0 && dp[0][(k | j)]) dp[i][j] += dp[i-1][k];

    for(i = 0;i < MX;i++)
        if(dp[0][i]) res += dp[6][i];

    printf("%d\n", res);

    return 0;
}
