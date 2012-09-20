/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  找符合条件的整数
 *
 *        Version:  1.0
 *        Created:  2012/09/20 13时42分04秒
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
#include <iostream>
#include <vector>
using namespace std;

#define MX 100001
vector <int> BigInt[MX];

void init(int N)
{
    for(int i = 0;i < N;i++) BigInt[i].clear();
}
void print(vector<int> out)
{
    int siz = out.size();
    if(siz == 0) return ;

    printf("1");
    int i = out.size() - 1;
    for(i-- ; i >= 0; i--)
    {
        for(int j = out[i]+1; j < out[i+1]; j++) printf("0");
        printf("1");
    }
    for(int j = 0;j < out[0];j++) printf("0");
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go
 *  Description:  找出N*M，使得M最小，而N*M只包含1或0，结果存于BigInt[0]中
 * =====================================================================================
 */
void go(int N)
{
    for(int i  = 0, j = 1%N; ;i++, j = (j*10)%N)
    {
        if(BigInt[j].size() == 0)
        {
            BigInt[j].push_back(i);
        }
        for(int k = 1;k < N;k++)
        {
            if(BigInt[k].size() > 0 && BigInt[(k+j)%N].size() == 0 && i > BigInt[k][BigInt[k].size()-1])
            {
                BigInt[(k+j)%N] = BigInt[k];
                BigInt[(k+j)%N].push_back(i);
            }
        }

        if(BigInt[0].size() > 0) return ;
    }
    return ;
}
int main (int argc, char *argv[])
{
    int N;
    scanf("%d", &N);
    while(N <= 0 || N > MX) 
    {
        printf("N must be between (1, 100000)\n");
        scanf("%d", &N);
    }
    init(N);

    go(N);

    printf("for %d, N*M is ", N);
    print(BigInt[0]);
    printf("\n");

    return 0;
}
