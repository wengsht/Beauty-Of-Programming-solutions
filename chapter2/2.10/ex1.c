/*
 * =====================================================================================
 *
 *       Filename:  ex1.c
 *
 *    Description:  练习1 找第二大数，线性一般方法最坏需要比较2*N次
 *                  如果把数组分成两堆，分别找最大值，在在这两个数中找第二大的
 *                  只需N次
 *
 *        Version:  1.0
 *        Created:  2012/09/20 18时46分57秒
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
#include <time.h>

int main (int argc, char *argv[])
{
    int n = 100, i;
    int arr[1000];
    srand(time(0));
    for(i = 0;i < n;i++) 
    {
        arr[i] = rand() % n;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int mx1 = arr[0], mx2 = arr[1];
    for(i = 2;i < n;i += 2)
        if(arr[i] > mx1) mx1 = arr[i];
    for(i = 3;i < n;i += 2)
        if(arr[i] > mx2) mx2 = arr[i];
    if(mx1 < mx2) printf("%d ", mx1);
    else          printf("%d ", mx2);
    printf("is the 2nd max number\n");

    return 0;
}
