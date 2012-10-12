/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  字符串以为包含的问题
 *                  拼接后kmp即可
 *
 *        Version:  1.0
 *        Created:  2012/10/12 13时05分15秒
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

#define MX 10000
int fail[MX];

void get_fail(char *pattern, int len)
{
    fail[0] = -1;
    int i, k = -1;

    for(i = 1;i < len;i++)
    {
        while(k > -1 && pattern[k+1] != pattern[i]) k = fail[k];

        if(pattern[k+1] == pattern[i]) k++;

        fail[i] = k;
    }
}
int kmp(char *str, int len1, char *pattern, int len2)
{
    get_fail(pattern, len2);

    int end = len1-1+len2-1, i;
    if(end > 2*len1-1) end = 2*len1-1;

    int k = -1;
    for(i = 0;i <= end;i++)
    {
        char nxt = str[i%len1];

        while(k > -1 && pattern[k+1] != nxt) k = fail[k];

        if(pattern[k+1] == nxt) k++;

        if(k == len2-1)
            return i-len2+1;
    }
    return -1;
}
int main()
{
    char str[MX] = "AABCA", p[MX] = "AAA";

    int res = kmp(str,strlen(str), p, strlen(p));

    printf("匹配第一个开始位置：%d\n", res);

    return 0;
}
