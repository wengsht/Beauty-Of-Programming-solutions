/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  队列中的最大值操作问题
 *                  此题一拿到觉得只能建个堆
 *
 *                  看了解法三还一时间没看懂。
 *                  比较巧妙，一直觉得不断求最大值只能像排序一样的复杂度。其实中间有一点不同的是排序相当于每次pop最大元素。而队列只pop头，这就和排序大不一样了，可以temp一下当前的max，然后后面的元素影响不到当前之前的元素的最大值。
 *                  要利用这种特性，得用栈而不能用队列，因为栈push第n+1个元素和pop操作过程中，都不会影响到前n个的最大值
 *
 *        Version:  1.0
 *        Created:  2012/10/14 13时22分29秒
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
using namespace std;

#define MX 10000

class Stack
{
public:
    Stack() : top(-1) {}
    bool push(int p)
    {
        if(top >= MX-1) return false;

        data[++top] = p;
        dp[top] = p;

        if(top > 0) dp[top] = max(dp[top-1], dp[top]);

        return true;
    }
    int pop()
    {
        if(top < 0) return -1;
        return data[top--];
    }
    int max_data()
    {
        if(top < 0) return -1;
        return dp[top];
    }
    void print()
    {
        for(int i = 0;i <= top;i++) printf("%d ", data[i]);
        printf("\n");
    }
    bool is_empty()
    {
        return top <= -1;
    }
private:
    int data[MX];
    /*
     *  dp[i]: the starting i numbers' max
     */
    int dp[MX];

    int top;
};
class Queue
{
public:
    Queue() {}

    bool push(int p) 
    {
        return sb.push(p);
    }
    int pop()
    {
        while(!sb.is_empty())
            sa.push(sb.pop());

        return sa.pop();
    }
    int max_data()
    {
        return max(sa.max_data(), sb.max_data());
    }
private:
    Stack sa, sb;
};
int main()
{
    Queue q;

    int g;

    cout<<"1 [int] for push; 2 for pop"<<endl;

    while(cin>>g)
    {
        if(g == 1)
        {
            cin>>g;

            q.push(g);
        }
        else q.pop();

        cout<<"max_value: "<<q.max_data()<<endl;

        cout<<"1 [int] for push; 2 for pop"<<endl;
    }


}
