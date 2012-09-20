/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  矩阵分治求斐波那契第n项（模10000）
 *
 *        Version:  1.0
 *        Created:  2012/09/20 15时02分04秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define modq 10000
struct Matrix
{
    int s[2][2];
    Matrix operator *(Matrix b)
    {
       Matrix c;
       c.s[0][0] = s[0][0]*b.s[0][0] + s[0][1] * b.s[1][0];
       c.s[0][0] %= 10000;
       c.s[0][1] = s[0][0]*b.s[0][1] + s[0][1] * b.s[1][1];
       c.s[0][1] %= 10000;
       c.s[1][0] = s[1][0]*b.s[0][0] + s[1][1] * b.s[1][0];
       c.s[1][0] %= 10000;
       c.s[1][1] = s[1][0]*b.s[0][1] + s[1][1] * b.s[1][1];
       c.s[1][1] %= 10000;
       return c;
    }
};
Matrix quick_pow(int c)
{
    Matrix result, tmp;
    tmp.s[0][0] = 1; tmp.s[0][1] = 1; tmp.s[1][0] = 1; tmp.s[1][1] = 0;
    result.s[0][0] = 1; result.s[0][1] = 0; result.s[1][0] = 0; result.s[1][1] = 1;
    while(c)
    {
       if(c & 0x1) result = result * tmp;

       c>>=1;
       tmp = tmp*tmp;
    }
    return result;
}

int main()
{
    int n;
    while(scanf("%d", &n) && n != -1)
    {
       if(!n) printf("0\n");
       else if(n < 3) printf("1\n");
       else
       {
           Matrix cc = quick_pow(n-2);
           printf("%d\n", cc.s[0][0]+cc.s[1][0]);
       }
    }
}
