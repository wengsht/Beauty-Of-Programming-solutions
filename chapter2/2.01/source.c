/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  原题目代码
 *
 *        Version:  1.0
 *        Created:  2012/09/17 20时41分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int Count(int v)
{
    int c = 0;
    while(v)
    {
        v &= v-1;
        c++;
    }
    return c;
}

int main ()
{
    int n;
    printf("input a num:");
    scanf("%d", &n);
    printf("res is %d\n", Count(n));

    return 0;
}			


