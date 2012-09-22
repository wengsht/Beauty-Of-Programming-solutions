/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  练习1 三个数字
 *                  先排序，然后对每一个数字做一次O（n）的两数字和
 *
 *                  至于任意多个数字的。。现在想到的也只能是一直降维，当然每降一次就要*N的复杂度
 *                  如果是正数，那么搜索空间其实很小，只要O(SUM*d)次搜索，每次O（N）
 *                  （d个数字和为SUM）
 *
 *                  测试样例大小300， d取值1~150 
 *                  实测d=150耗时6s
 *
 *
 *                  代码默认数组只包含非负整数
 *
 *        Version:  1.0
 *        Created:  2012/09/22 10时57分40秒
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
#define NUM 300

void generator(int *arr, int n)
{
    srand(time(0));

    for(int i = 0;i < n;i++)
        arr[i] = rand() % n;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go
 *  Description:  在arr中找出d个数和为sum，结果标记于used[]中
 * =====================================================================================
 */
bool used[NUM];
bool nogood[NUM*NUM][NUM+1];
bool go(int arr[], int n, int sum, int d)
{
    if(d == 2)
    {
        if(nogood[sum][2] == true) return false;
        int l = 0, h = n-1;
        while(l < h)
        {
            if(used[l] || arr[l] + arr[h] < sum) { l++; continue; }
            if(used[h] || arr[l] + arr[h] > sum) { h--; continue; }

            break;
        }
        if(l < h)
        {
            used[l] = used[h] = true;

            return true;
        }
        nogood[sum][2] = true;
        return false;
    }

    for(int i = 0;i < n;i++)
    {
        if(used[i]) continue;

        if(sum - arr[i] >= 0 && nogood[sum-arr[i]][d-1] == false)
        {
            used[i] = true;

            if(go(arr, n, sum-arr[i], d-1)) return true;
            else nogood[sum][d] = true;

            used[i] = false;
        }
    }
    return false;
}
int main (int argc, char *argv[])
{
    int test[NUM], tmp[NUM];
    clock_t st, ed;
    double t;
    generator(test, NUM);
    for(int i = 0;i < NUM;i++)
        tmp[i] = test[i];
    int a;
    int d = rand() % NUM + 1;

    if(d > NUM/2) d = NUM/2;
    if(d <= 1) d = 2;

    int sum = 0;
    for(int i = 0;i < d;i++)
    {
        a = rand() % NUM;
        while(used[a]) a = rand() % NUM;
        used[a] = true;

        sum += test[a];
    }

    printf("一共%d个数，要找%d个数和为%d:\n", NUM, d, sum);

    st = clock();
    sort(test, test+NUM);

    memset(used, 0, sizeof(used));
    int test_sum = 0;
    if(go(test, NUM, sum, d))
    {
        printf("找出的%d个数分别是：", d);

        for(int i = 0;i < NUM;i++) 
            if(used[i])
            {
                test_sum += test[i];
                printf("%d ", test[i]);
            }
    }
    printf("\n");

    printf("和为：%d\n", test_sum);

    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;
    printf("耗时:%lfms\n", t);

    return 0;
}

