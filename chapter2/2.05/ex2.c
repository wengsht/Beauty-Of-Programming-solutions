/*
 * =====================================================================================
 *
 *       Filename:  ex2.c
 *
 *    Description:  练习2 找出第k-m大的数字，保证0<k<=m<=n
 *                  当m == n时问题可以很容易转化为原问题，最直接的做法是分别找前k大数和前m大数，在取补集即可
 *                  更好的方法是利用部分快速排序，只需要跑两次，一次剔除前k-1个数，另一次剔除后面n-m个数就可以了，代码采用这种方法
 *                  还有一种方法是建一个m大小的最小堆，然后pop出前k-1个，剩下的就是k-m的数了,也比较好写
 *
 *        Version:  1.0
 *        Created:  2012/09/19 15时19分34秒
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
#include <string.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solution1
 *  Description:  部分快速排序, 调用将最大的k个数放在arr前k位 最坏情况O(n*ln(n)) 一般可以达到O(n)
 * =====================================================================================
 */

void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void solution1(int *arr, int k, int n)
{
    if(k <= 0 || k >= n || !arr) return ;
    int i = 0, p = 0;

    int j;
    for(j = 1;j < n;j++)
    {
        if(arr[j] >= arr[i]) swap(arr, ++p, j);
    }
    swap(arr, i, p);

    if(p+1 == k) return ;
    if(p+1 < k)
        solution1(arr+p+1, k-p-1, n-p-1);
    else
        solution1(arr, k, p);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_k_m
 *  Description:  找出第k大到第m大的数字，结果存于arr[res:res+m-k]中
 * =====================================================================================
 */
int find_k_m(int *arr, int k, int m, int n)
{
    solution1(arr, n-m, n);
    solution1(arr+n-m, m-k+1, m);

    return n-m;
}

void print_raw(int *arr, int n)
{
    int i;
    for(i = 0;i < n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void print(int *arr, int k, int m, int n)
{
    int i;
    for(i = 0;i < k;i++)
        printf("%d ", arr[i]);
    printf(" |  ");
    for(i = k;i < m;i++)
        printf("%d ", arr[i]);
    printf(" |  ");
    for(i = m;i < n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main (int argc, char *argv[])
{
    int test[100], tmp[100];
    srand(time(0));

    int i, res;
    
    for(i = 0; i < 100; i += 1)
        test[i] = rand() % 100;

    print_raw(test, 100);
    
    memcpy(tmp, test, sizeof(tmp));
    res = find_k_m(tmp, 1, 10, 100);
    print(tmp, res, res+10, 100);

    memcpy(tmp, test, sizeof(tmp));
    res = find_k_m(tmp, 30, 40, 100);
    print(tmp, res, res+11, 100);
    return 0;
}
