/*
 * =====================================================================================
 *
 *       Filename:  ex2.c
 *
 *    Description:  练习1，求二进制1-n中出现1的次数
 *
 *        Version:  1.0
 *        Created:  2012/09/18 16时44分51秒
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
 *         Name:  f_binary
 *  Description:  返回1-n中出现1的个数，二进制
 * =====================================================================================
 */
int f_binary(int n)
{
    int l = 1, left, right;
    int res = 0;
    
    while(n / l != 0)
    {
        left = n / (l<<1) * l;
        
        res += left;

        if(n & l)
        {
            right = n % l;

            res += right+1;
        }
        l <<= 1;
    }

    return res;
}


int main (int argc, char *argv[])
{
    int n;
    scanf("%d", &n);

    int i;
    for(i = 1; i < 256; i += 1) 
        printf("%x %d\n", i, f_binary(i));

    printf("%x %d\n", n, f_binary(n));
    return 0;
}
