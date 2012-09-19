/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  1的数目
 *
 *        Version:  1.0
 *        Created:  2012/09/18 15时20分12秒
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
 *         Name:  f
 *  Description:  返回1到n这些整数出现1的次数,O(len(n)),思路是对于特定位置，找比它高和比它矮的位置的组合数
 * =====================================================================================
 */
long long f(long long n)
{
    long long res = 0;
    long long l = 1, right = 0;
    long long dv, md;
    while(n)
    {
        dv = n / 10;
        md = n % 10;
        if(md <= 1)
        {
            res += dv * l;
            if(md == 1)
                res += (right + 1);
        }
        else
            res += (dv+1)*l;

        right = right + md*l;
        l *= 10;
        n /= 10;
    }

    return res;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  max_fn
 *  Description:  f(n) = n 的最大整数
 * =====================================================================================
 */
long long max_fn()
{
    long long mx = 100000000000;
    
    for (; mx >= 0; mx -= 1) 
    {
        if(f(mx) == mx) return mx;
    }
    return 0;
}


int main (int argc, char *argv[])
{
    int n;
    scanf("%d", &n);

    int i;
    for ( i = 1; i < 199; i += 1 ) {
        printf("%d %lld\n",i ,f(i));
    }
    printf("\n1-%d has %lld 1s\n", n, f(n));

    printf("max n that f(n) = n is: %lld\n", max_fn());
    return 0;
}
