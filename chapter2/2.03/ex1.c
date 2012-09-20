/*
 * =====================================================================================
 *
 *       Filename:  ex1.c
 *
 *    Description:  练习1, 寻找三个发帖超过1/4的水王,方法和例题一样，每次减去4个不同ID即可
 *
 *        Version:  1.0
 *        Created:  2012/09/18 14时57分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int num[3];
    int count[3];
} TribleWater;

int checkin(TribleWater *res, int k)
{
    int i;
    for(i = 0; i < 3; i++)
    {
        if(res->num[i] == k)
        {
            res->count[i]++;
            return 1;
        }
    }
    for(i = 0; i < 3; i++)
    {
        if(res->count[i] == 0)
        {
            res->num[i] = k;
            res->count[i] = 1;
            return 1;
        }
    }
    return 0;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_waters
 *  Description:  返回出现超过1/4的三个数字
 * =====================================================================================
 */
TribleWater find_waters(int arr[], int n)
{
    TribleWater res;
    memset(&res, 0, sizeof(res));

    if(n < 3) return res;

    int i;
    for(i = 0;i < n;i++)
    {
        if(!checkin(&res, arr[i]))
        {
            res.count[0]--;
            res.count[1]--;
            res.count[2]--;
        }
    }

    return res;
}

int main (int argc, char *argv[])
{
    int test[159], i;
    for(i = 0; i < 120;i+=3)
    {
        test[i] = 1;
        test[i+1] = 2;
        test[i+2] = 3;
    }
    for(i = 120;i < 160;i++)
        test[i] = i;

    TribleWater res = find_waters(test, 159);

    printf("%d %d %d are waters\n", res.num[0], res.num[1], res.num[2]);
    return 0;
}
