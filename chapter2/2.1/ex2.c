/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  练习2   
 *
 *        Version:  1.0
 *        Created:  2012/09/17 20时41分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht 
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
int bit_same(int a, int b)
{
    return Count(a ^ b);
}

int main ()
{
    int l, r;
    printf("input a num:");
    scanf("%d", &l);
    printf("input another num:");
    scanf("%d", &r);
    printf("res is %d\n", bit_same(l, r));

    return 0;
}			


