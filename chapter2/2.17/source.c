/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  数组循环移位
 *
 *        Version:  1.0
 *        Created:  2012/10/08 16时31分08秒
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

#define NUM  10
int arr[NUM] = {1,2,3,4,5,6,7,8,9,10};

inline void swap(int *arr, int l, int r)
{
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}
void reverse(int *arr, int l, int r)
{
    while(l < r)
    {
        swap(arr, l, r);
        l++;
        r--;
    }
}
void right_shift(int *arr, int n, int k)
{
    k = (k%n + n) % n;

    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
}
void print(int *arr, int n)
{
    int i;
    for(i = 0;i < n;i++) printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int k;
    printf("原数组：");
    print(arr, NUM);

    printf("输入右移位数: ");
    while(scanf("%d", &k))
    {
        right_shift(arr, NUM, k);

        printf("数组现状：");
        print(arr, NUM);

        printf("输入右移位数: ");
    }
    return 0;
}
