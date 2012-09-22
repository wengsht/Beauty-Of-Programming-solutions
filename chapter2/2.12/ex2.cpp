/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  快速寻找满足条件的两个数 练习2，接近而非等于
 *
 *                  其实稍微改一下排序+线性搜索就可以了
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
#define INF 999999999

void generator(int *arr, int n)
{
    srand(time(0));

    for(int i = 0;i < n;i++)
        arr[i] = rand() % n;
}

int main (int argc, char *argv[])
{
    int test[NUM];
    clock_t st, ed;
    double t;
    generator(test, NUM);

    int sum = 2*NUM/3+rand() % (NUM*3/2);
    st = clock();
    sort(test, test+NUM);

    int i = 0, index = NUM-1;
    int resa, resb, mn = INF;
    while(i < index)
    {
        int test_sum = test[i] + test[index];
        if(abs(sum-test_sum) < mn)
        {
            mn = abs(sum-test_sum);
            resa = i;
            resb = index;
        }
        if(test_sum == sum) 
        {
            break;
        }
        if(test_sum <  sum) 
            i++;
        else
            index--;
    }

    ed = clock();
    t = (ed-st)/(double)CLOCKS_PER_SEC * 1000.0;

    printf("排序+线性查找：最小间距(%d+%d,%d) = %d  耗时：%lfms\n", test[i], test[index], sum, mn, t);

    return 0;
}

