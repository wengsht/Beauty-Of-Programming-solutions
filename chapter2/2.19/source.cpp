/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  区间重合判断
 *                  此题一看就想到线段树。
 *                  解法二直接排序其实更加省时省力。现在大脑都懒得想了
 *
 *        Version:  1.0
 *        Created:  2012/10/09 15时30分42秒
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
#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

typedef struct
{
    int l, r;
} Edge;

#define NUM 10

void generator(Edge *edges, int n)
{
    srand(time(0));

    for(int i = 0;i < n;i++)
    {
        edges[i].l = rand() % 10000;
        edges[i].r = rand() % 10000;

        if(edges[i].l > edges[i].r) swap(edges[i].l, edges[i].r);
    }
}

bool _cmp(Edge a, Edge b)
{
    return a.l < b.l;
}

int find_index(Edge *edges, int n, int l)
{
    int low = 0, hig = n-1;

    while(low <= hig)
    {
        int mid = (low+hig) / 2;

        if(edges[mid].l > l) hig = mid-1;
        else if(mid == n-1 || edges[mid+1].l > l) return mid;
        else low = mid+1;
    }
    return -1;
}
bool go(Edge *edges, int n, Edge target)
{
    sort(edges, edges+n, _cmp);

    int p = 0;

    for(int i = 0;i < n;)
    {
        edges[p].l =  edges[i].l;
        int r = edges[i].r;

        int j;
        for(j = i+1;j < n;j++)
        {
            if(r >= edges[j].l)
                r = max(r, edges[j].r);
            else break;
        }
        i = j;
        edges[p++].r = r;
    }
    int index = find_index(edges, p, target.l);

    if(index == -1 || edges[index].r < target.r) return false;

    return true;
}

int main()
{
    Edge test[NUM], target;

    generator(test, NUM);
    target.l = rand() % 10000;
    target.r = rand() % 10000;
    if(target.l > target.r) swap(target.l, target.r);

    bool res = go(test, NUM, target);
    
    printf("目标区间包含于无序区间组中？%d", res);

    return 0;



}

