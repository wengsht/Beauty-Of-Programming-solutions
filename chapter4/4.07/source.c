/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  蚂蚁爬杆
 *                  算是个比较简单的问题
 *
 *        Version:  1.0
 *        Created:  2012/10/17 18时18分55秒
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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int main()
{
    int n, l;
    int position[MX];

    printf("input the number of the ants:");
    scanf("%d", &n);
    printf("input the length:");
    scanf("%d", &l);
    printf("input the positions of all the ants:");

    int i;
    for(i = 0;i < n;i++)
    {
        scanf("%d", position+i);
        if(position[i] < 0 || position[i] > l) 
        {
            printf("position must between [0,l]!\n");

            i--;
        }
    }
    int mx = max(l-position[0], position[n-1]);
    int mn = 0;
    for(i = 0;i < n;i++)
    {
        int tmp = min(l-position[i], position[i]);

        if(tmp > mn) mn = tmp;
    }
    printf("min: %d; max: %d\n", mn, mx);

    return 0;
}
