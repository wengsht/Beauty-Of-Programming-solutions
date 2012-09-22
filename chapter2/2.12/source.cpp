/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  快速寻找满足条件的两个数
 *
 *        Version:  1.0
 *        Created:  2012/09/22 09时57分40秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
#define NUM 1000000

bool has(int *arr, int l, int h, int p)
{
    while(l <= h)
    {
        int mid = (l+h)>>1;

        if(arr[mid] == p) return true;
        if(arr[mid] >  p) h = mid-1;
        else              l = mid+1;
    }
    return false;
}

void generator(int *arr, int n)
{
    srand(time(0));

    for(int i = 0;i < n;i++)
        arr[i] = rand() % n;
}

int main (int argc, char *argv[])
{
    int test[NUM], tmp[NUM];
    clock_t st, ed;
    double t;
    generator(test, NUM);
    for(int i = 0;i < NUM;i++)
        tmp[i] = test[i];
    int a, b;
    a = rand()%NUM;
    b = a;
    while(b == a)
        b = rand()%NUM;
    int sum = test[a] + test[b];

    st = clock();
    sort(test, test+NUM);

    int i, index, tofind;
    for(i = 0;i < NUM;i++)
    {
        tofind = sum - test[i];

        if(has(test, i+1, NUM, tofind))
            break;
    }
    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("排序+二分查找：%d+%d=%d  耗时：%lfms\n", test[i], tofind, sum, t);

    st = clock();
    sort(tmp, tmp+NUM);

    i = 0, index = NUM-1;
    while(i < index)
    {
        if(tmp[i] + tmp[index] == sum) break;
        if(tmp[i] + tmp[index] <  sum) i++;
        else                           index--;
    }

    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("排序+线性查找：%d+%d=%d  耗时：%lfms\n", test[i], test[index], sum, t);

    return 0;
}

