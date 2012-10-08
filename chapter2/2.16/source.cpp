/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  求数组中最长递增子序列
 *
 *        Version:  1.0
 *        Created:  2012/10/08 15时20分30秒
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


#define NUM 1000000
void generator(int *arr, int n)
{
    srand(time(0));

    int i;
    for(i = 0;i < n;i++)
        arr[i] = rand() % (20000) - 10000;
}

int find_index(int p, int *arr, int len)
{
    int l = 1;
    while(l <= len)
    {
        int mid = (l+len)/2;

        if(arr[mid] >= p) len = mid-1;
        else if(mid == len || arr[mid+1] >= p) return mid;
        else l = mid+1;
    }
    return 0;
}

int go(int *arr, int n)
{
    int leng_min[NUM], max_len = 0;
    int index;

    for(int i = 0;i < n;i++)
    {
        index = find_index(arr[i], leng_min, max_len);

        if(index == max_len)
        {
            max_len++;

            leng_min[max_len] = arr[i];
        }
        else leng_min[index+1] = arr[i];
    }
    return max_len;
}
int main (int argc, char *argv[])
{
    int arr[NUM];

    generator(arr, NUM);

    int res = go(arr, NUM);

    printf("最长递增子序列长度：%d\n", res);

    return 0;
}
