/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  计算字符串的相似度
 *
 *        Version:  1.0
 *        Created:  2012/10/12 18时56分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MX 10000
#define min(a,b) (a<b?a:b)
int dp[MX][MX];

int go(char *str1, int i, int len1, char *str2, int j, int len2)
{
    if(i >= len1)
        return len2 - j;
    if(j >= len2)
        return len1 - i;

    if(dp[i][j] != -1) return dp[i][j];

    int t1 = go(str1, i+1, len1, str2, j+1, len2);

    if(str1[i] == str2[j]) 
    {
        dp[i][j] = t1;

        return t1;
    }

    int t2 = go(str1, i, len1, str2, j+1, len2);
    int t3 = go(str1, i+1, len1, str2, j, len2);

    dp[i][j] = min(min(t1,t2),t3) + 1;
    return dp[i][j];
}

int main()
{
    char str1[] = "abcdefg", str2[] = "abbcdef";
    int len1 = strlen(str1), len2 = strlen(str2);

    memset(dp, -1, sizeof(dp));

    printf("距离：%d\n", go(str1, 0, len1, str2, 0, len2));

    return 0;
}
