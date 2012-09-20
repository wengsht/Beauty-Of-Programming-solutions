/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  不要被阶乘吓到， 课本原题
 *
 *        Version:  1.0
 *        Created:  2012/09/18 09时38分14秒
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

#define pi 3.141592658
#define e  2.71828183

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Count0
 *  Description:  阶乘十进制尾0个数，
 * =====================================================================================
 */
int Count0(int n)
{
    int res = 0;
    
    while(n)
    {
        res += n / 5;
        
        n /= 5;
    }
    return res;
}

int Last1(int n)
{
    int res = 0;
    
    while(n)
    {
        res += n / 2;
        
        n /= 2;
    }
    return res+1;
}

int main (int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    printf("十进制尾0个数:%d\n", Count0(n));
    printf("二进制最低位1位置(最末位为1):%d\n", Last1(n));
    return 0;
}
