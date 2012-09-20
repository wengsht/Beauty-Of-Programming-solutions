/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  练习1
 *                  三维本质上没什么区别
 *                  [Fn, Fn-1, Fn-2] = [Fn-1, Fn-2, Fn-3]A
 *                  其中A为|1 1 0|
 *                         |1 0 1|
 *                         |1 0 0| 
 *
 *        Version:  1.0
 *        Created:  2012/09/20 16时23分40秒
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
    int s[3][3];
    Matrix operator *(Matrix b)
    {
       Matrix c;
       memset(&c, 0, sizeof(c));

       for(int k = 0;k < 3;k++)
       {
           for(int i = 0;i < 3;i++)
           {
               if(s[i][k] == 0) continue;

               for(int j = 0;j < 3;j++)
                   c.s[i][j] = (c.s[i][j] + s[i][k]*b.s[k][j])% modq;
           }
       }
       return c;
    }
};
Matrix quick_pow(long long c)
{
    Matrix result, tmp;
    tmp.s[0][0] = 1; tmp.s[0][1] = 1; tmp.s[0][2] = 0;
    tmp.s[1][0] = 1; tmp.s[1][1] = 0; tmp.s[1][2] = 1;
    tmp.s[2][0] = 1; tmp.s[2][1] = 0; tmp.s[2][2] = 0;

    memset(&result, 0, sizeof(result));
    for(int i = 0;i < 3;i++)
            result.s[i][i] = 1;
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
    long long n;
    while(scanf("%lld", &n) && n != -1)
    {
       if(!n) printf("1\n");
       else if(n < 3) printf("2\n");
       else
       {
           Matrix cc = quick_pow(n-2);

           int res = 0;
           res = (2*cc.s[0][0] + 2*cc.s[1][0] + cc.s[2][0]) % modq;
           printf("%d\n", res);
       }
    }
}
