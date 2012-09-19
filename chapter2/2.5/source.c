/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  寻找最大的K个数
 *
 *        Version:  1.0
 *        Created:  2012/09/18 17时11分40秒
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

void print(int *arr, int m, int n);
void swap(int *arr, int i, int j);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solution1
 *  Description:  部分快速排序, 调用将最大的k个数放在arr前k位 最坏情况O(n*ln(n)) 一般可以达到O(n)
 * =====================================================================================
 */
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
 *         Name:  solution2
 *  Description:  二分查找第k大数,调用将最大的k个数放在arr前k位,O(ln(MAX-MIN)*n)
 * =====================================================================================
 */
void solution2(int *arr, int k, int n)
{
    if(k <= 0 || k >= n || !arr) return ;

    int mn = arr[0], mx = arr[0];
    int i, c1, c2, mid;
    for(i = 1;i < n; i += 1)
    {
        if(arr[i] > mx) mx = arr[i];
        if(arr[i] < mn) mn = arr[i];
    }

    while(mn <= mx)
    {
        mid = mn + ((mx-mn)>>1);

        c1 = 0;
        c2 = 1;
        for(i = 0; i < n; i += 1)
        {
            if(arr[i] >= mid)
            {
                c1 += 1;
                if(arr[i] > mid)
                    c2 += 1;
            }
        }
        if(c1 >= k && c2 <= k)
            break;

        if(c2 > k) mn = mid+1;
        else       mx = mid-1;
    }

    int p = 0;
    c2--;
    for(i = 0; i < n; i += 1)
        if(arr[i] > mid && c2-- || arr[i] == mid && k-p > c2) swap(arr, i, p++);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solution3
 *  Description:  最小优先队列方法，O(n*lnk)，结果存于res中，适用于k大小适中的情况
 * =====================================================================================
 */

void fix_delete(int *heap, int heap_size);
void fix_insert(int *heap, int heap_size);
void solution3(int *arr, int k, int n, int *heap)
{
    if(!arr) return ;
    if(k <= 0 || k >= n)
    {
        memcpy(heap, arr, n*sizeof(int));
        return ;
    }
    int heap_size = 0;
    int i;

    for(i = 0; i < n; i += 1)
    {
        if(heap_size < k)
        {
            heap[++heap_size] = arr[i];
            fix_insert(heap, heap_size);
        }
        else if(arr[i] > heap[1])
        {
            heap[1] = arr[i];
            fix_delete(heap, heap_size);
        }
    }
    swap(heap, 0, heap_size);
}

int main (int argc, char *argv[])
{
    int test[100], tmp[100];
    srand(time(0));

    int i;
    
    for(i = 0; i < 100; i += 1)
        test[i] = rand() % 100;

    printf("原数据:\n");
    print(test, 100, 100);

    memcpy(tmp, test, sizeof(tmp));
    solution1(tmp, 10, 100);
    printf("部分快速排序方法，处理后:\n");
    print(tmp, 10, 100);

    memcpy(tmp, test, sizeof(tmp));
    solution2(tmp, 10, 100);
    printf("二分查找第K大数方法，处理后:\n");
    print(tmp, 10, 100);
    
    solution3(test, 10, 100, tmp);
    printf("最小优先队列方法，处理后:\n");
    print(tmp, 10, 10);
    
    return 0;
}

void print(int *arr, int m, int n)
{
    int i;
    for(i = 0; i < m; i += 1)
        printf("%d ", arr[i]);
    printf(" |  ");
    for(i = m; i < n; i += 1)
        printf("%d ", arr[i]);

    printf("\n");
}

void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void fix_delete(int *heap, int heap_size)
{
    int l, r, t;
    int p = 1;
    while(p <= heap_size)
    {
        t = l = p<<1;
        r = l+1;

        if(l <= heap_size && heap[p] > heap[l] || r <= heap_size && heap[p] > heap[r])
        {
            if(r <= heap_size && heap[r] < heap[l]) t = r;

            swap(heap, p, t);

            p = t;
        }
        else break;
    }
}
void fix_insert(int *heap, int heap_size)
{
    int p = heap_size;
    int fa;
    while(p > 1)
    {
        fa = p>>1;
        if(heap[fa] > heap[p])
        {
            swap(heap, fa, p);

            p = fa;
        }
        else break;
    }
}
