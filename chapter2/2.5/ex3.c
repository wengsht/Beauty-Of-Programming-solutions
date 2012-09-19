/*
 * =====================================================================================
 *
 *       Filename:  ex3.c
 *
 *    Description:  练习3， 同样找前K个大数，但是数权值会不断更新，因此每更新一次前K大数集合也会跟着变动
 *                  想了好久没想出来。搜了一下网上都是一个版本，对整个数组建映射二分堆
 *                  这个方法感觉不是很靠谱，首先是空间问题，其次每一次查询都要pop出k个再塞进k个也很蛋疼(如果是只对k个建堆的话就不用pop)
 *
 *                  没法子。。写写当练
 *
 *        Version:  1.0
 *        Created:  2012/09/19 16时09分42秒
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

void print(int *arr, int n);

void swap(int *heap, int i, int j, int *mp, int *rv_mp)
{
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;

    if(rv_mp != NULL && mp != NULL)
    {
        tmp = rv_mp[i];
        rv_mp[i] = rv_mp[j];
        rv_mp[j] = tmp;

        mp[rv_mp[i]] = i;
        mp[rv_mp[j]] = j;
    }
}
void fix_up(int *heap, int p, int *mp, int *rv_mp)
{
    int q = p>>1;
    while(q >= 1 && heap[q] < heap[p])
    {
        swap(heap, p, q, mp, rv_mp);

        p = q;
        q >>= 1;
    }
}
void fix_down(int *heap, int p, int n, int *mp, int *rv_mp)
{
    int l, r;
    int q;
    while(1)
    {
        l = p<<1;
        r = l+1;

        q = p;

        if(l <= n && heap[l] > heap[p]) q = l;
        if(r <= n && heap[r] > heap[p] && heap[r] > heap[l]) q = r;

        if(p == q) break;

        swap(heap, p, q, mp, rv_mp);
        p = q;
    }
}
void build_heap(int *heap, int n, int *mp, int *rv_mp)
{
    int i;
    for(i = 1; i <= n; i++)
        mp[i] = rv_mp[i] = i;

    for(i = n/2; i >= 1; i--)
        fix_down(heap, i, n, mp, rv_mp);
}
int pop(int *heap, int n)
{
    if(n <= 0) return -1;

    int res = heap[1];
    heap[1] = heap[n];

    fix_down(heap, 1, n-1, NULL, NULL);

    return res;
}
void rand_change_fix_heap(int *heap, int p, int key, int n, int *mp, int *rv_mp)
{
    heap[mp[p]] = key;
    
    int q = mp[p] / 2;
    if(q >= 1 && heap[q] < key)
        fix_up(heap, mp[p], mp, rv_mp);
    else
        fix_down(heap, mp[p], n, mp, rv_mp);
}
int main (int argc, char *argv[])
{
    int n = 11, k = 5;
    int test[n], heap[n], mp[n], rv_mp[n];
    srand(time(0));

    int i;

    for(i = 1; i < n; i += 1)
        test[i] = heap[i] = rand() % 100;

    printf("原数据:\n");
    print(test+1, n-1);

    build_heap(heap, n-1, mp, rv_mp);

    for(i = 0; i < rand()%100; i++)
    {
        int index = rand()%(n-1)+1, r = rand()%100;
        int tmp = test[index];
        test[index] = r;

        rand_change_fix_heap(heap, index, r, n-1, mp, rv_mp);
        printf("change array[%d] from %d to %d\nnow the array is:", index, tmp, r);
        print(test+1, n-1);
    }

    printf("the max %d numbers is:", k);

    
    for(i = 0;i < k;i++)
        printf("%d ", pop(heap, --n));

    return 0;
}
void print(int *arr, int n)
{
    int i;
    for(i = 0;i < n;i++)
        printf("%d ", arr[i]);
    printf("\n");

}
