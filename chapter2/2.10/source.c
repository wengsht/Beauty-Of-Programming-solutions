/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  寻找数组中的最大值和最小值
 *
 *        Version:  1.0
 *        Created:  2012/09/20 16时54分16秒
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

typedef struct 
{
    int mini, maxi;
} Pair;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solution1
 *  Description:  3/2n次比较，返回最大和最小值到res中
 * =====================================================================================
 */
Pair solution1(int *arr, int n)
{
    Pair res;
    int min_index = 0, max_index = 1;
    int st = 1, i;
    if(n % 2 == 1)
        res.mini = res.maxi = arr[0];
    else
    {
        st = 2;
        if(arr[0] > arr[1])
        {
            min_index = 1;
            max_index = 0;
        }
        res.mini = arr[min_index];
        res.maxi = arr[max_index];
        
    }
    for(i = st;i < n;i+=2)
    {
        min_index = i;
        max_index = i+1;
        if(arr[i] > arr[i+1])
        {
            min_index = i+1;
            max_index = i;
        }

        if(arr[min_index] < res.mini) res.mini = arr[min_index];
        if(arr[max_index] > res.maxi) res.maxi = arr[max_index];
        
    }
    return res;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solution2
 *  Description:  二分 ln(n)*2
 * =====================================================================================
 */
Pair solution2(int *arr, int n)
{
    Pair res;
    if(n == 1)
    {
        res.mini = res.maxi = arr[0];
        return res;
    }
    if(n == 2)
    {
        if(arr[0] < arr[1])
        {
            res.mini = arr[0];
            res.maxi = arr[1];
        }
        else
        {
            res.mini = arr[1];
            res.maxi = arr[0];
        }
        return res;
    }

    Pair left, right;
    int mid = (n-1) / 2;

    left = solution2(arr, mid+1);
    right = solution2(arr+mid+1, n-mid-1);

    if(left.mini < right.mini) res.mini = left.mini;
    else                       res.mini = right.mini;

    if(left.maxi > right.maxi) res.maxi = left.maxi;
    else                       res.maxi = right.maxi;

    return res;
}


int main (int argc, char *argv[])
{
    int n = 100, i;
    int test[1000];
    srand(time(0));
    for(i = 0;i < n;i++) 
    {
        test[i] = rand() % n;
        printf("%d ", test[i]);
    }
    printf("\n");

    Pair ant = solution1(test, n);
    printf("[solution1] max: %d, min: %d\n", ant.maxi, ant.mini);

    ant = solution2(test, n);
    printf("[solution1] max: %d, min: %d\n", ant.maxi, ant.mini);
    return 0;
}
