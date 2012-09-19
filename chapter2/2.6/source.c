/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  精确表达浮点数， 给出一个有限小数或者无限循环小数，输出分数形式
 *                  很容易看出循环节部分的转换实际上是一个等比无穷级数求和，公式直接就出来了
 *
 *        Version:  1.0
 *        Created:  2012/09/19 19时49分51秒
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

typedef struct
{
    long long rator, nator;
} Frac;

long long f[18];  /*  f[i] = 10^i */
int get_size(long long p)
{
    int res = 0;
    while(p)
    {
        res++;
        p /= 10;
    }
    return (res == 0 ? 1 : res);
     
}
long long gcd(long long a, long long b)
{
    return (b == 0 ? a : gcd(b, a%b));
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solution
 *  Description:  输入小数dec(cycle), cycle为循环部分 返回分数 = dec + cycle(cycle~)/10^k
 * =====================================================================================
 */
Frac solution(double dec, long long cycle, int k)
{
    Frac res;
    if(cycle == 0)
    {
        res.rator = dec * f[k];
        res.nator = f[k];
    }
    else
    {
        int m = get_size(cycle);

        res.rator = (cycle*f[m] + dec * f[k] * (f[m] - 1));
        res.nator = f[k] * (f[m] - 1);
    }

    long long gcd_rn = gcd(res.rator, res.nator);
    res.rator /= gcd_rn;
    res.nator /= gcd_rn;

    return res;
}

void print(Frac out)
{
    printf("%lld/%lld\n", out.rator, out.nator);
}


int main (int argc, char *argv[])
{
    int i;
    f[0] = 1;
    for(i = 1;i < 18;i++)
        f[i] = f[i-1] * 10;

    printf("0.333375: ");
    print(solution(0.333375, 0, 7));

    printf("0.(3): ");
    print(solution(0, 3, 1));

    printf("0.33(333): ");
    print(solution(0.33, 333, 5));

    printf("0.285714(285714): ");
    print(solution(0.285714, 285714, 12));
    return 0;
}
