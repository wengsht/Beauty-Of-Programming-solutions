/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  测试代码
 *
 *        Version:  1.0
 *        Created:  2012/10/09 16时46分18秒
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

int main()
{
    int rg[30];
    unsigned long long i;
    const unsigned long long MAX = 0x7fffffffffffffff;
    printf("%lld\n", MAX);

    for(i = 0;i < 30;i++) rg[i] = i+2;

    for(i = 2123581660200;i < MAX;i++) 
    {
        int hit = 0;
        int hit1 = -1, hit2 = -1;
        int j;

        for(j = 0;j < 30 && hit <= 2;j++)
        {
            if(i % rg[j] != 0)
            {
                hit++;
                if(hit == 1)
                    hit1 = j;
                else if(hit == 2)
                    hit2 = j;
                else 
                    break;
            }
        }
        printf("%lld\n", i);
        if(hit == 2 && hit1 + 1 == hit2)
            break;
    }
    return 0;
}
