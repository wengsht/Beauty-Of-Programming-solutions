/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  寻找发帖“水王”
 *
 *        Version:  1.0
 *        Created:  2012/09/18 14时50分24秒
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_water
 *  Description:  返回数组arr中出现超过一半的数字
 * =====================================================================================
 */
int find_water(int *arr, int n)
{
    if(n <= 0) return -1;
    int res, cnt = 0;
    
    int i;
    for (i = 0; i < n; i += 1) 
    {
        if(!cnt)
        {
            res = arr[i];

            cnt++;
        }
        else
            cnt += (res == arr[i] ? 1:-1);
    }
    return res;
}
int main (int argc, char *argv[])
{
    int test[] = {1, 1, 3, 4, 5, 6, 1, 1, 1, 1, 3, 3, 1, 3, 1, 3};

    printf("%d\n", find_water(test, 16));
    return 0;
}
