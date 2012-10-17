/*
 * =====================================================================================
 *
 *       Filename:  ex1.c
 *
 *    Description:  蚂蚁爬杆
 *                  第i只蚂蚁什么时候爬出去
 *
 *        Version:  1.0
 *        Created:  2012/10/17 20时12分47秒
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

#define L 0
#define R 1
#define MX 100000
typedef struct
{
    int p;
    int to;
} Ant;

int main()
{
    freopen("1.txt", "r", stdin);
    int n, l;
    Ant ants[MX];
    printf("input the number of the ants:");
    scanf("%d", &n);
    printf("input the length:");
    scanf("%d", &l);
    printf("input the positions and the direction of all the ants:(0 for toLeft, for toRight)\n");

    int i;
    for(i = 0;i < n;i++)
    {
        scanf("%d %d", &ants[i].p, &ants[i].to);
        if(ants[i].p < 0 || ants[i].p > l) 
        {
            printf("position must between [0,l]!\n");

            i--;
            continue;
        }
        if(ants[i].to == 0) ants[i].to = -1;
        else ants[i].to = 1;
    }
    int res = -1;
    int a[2], now = 0;

    printf("input the index of your ant i:\n");
    scanf("%d", &i);
    i--;
    a[0] = a[1] = i;
    int nowto = ants[i].to;
    int done = 0;
    while(!done)
    {
        while(1)
        {
            a[now] += nowto;

            if(a[now] > l || a[now] < 0)
            {
                done = 1;
                break;
            }
            if(ants[a[now]].p != nowto)
            {
                res = a[now];
                nowto = -nowto;
                now ^= 1;
                break;
            }
        }
    }
    
    if(ants[res].to == -1)
        printf("time: %d\n", ants[res].p);
    else
        printf("time: %d\n", l-ants[res].p);


    return 0;
}
