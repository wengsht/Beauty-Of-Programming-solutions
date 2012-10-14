/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  分层遍历二叉树
 *                  宽搜
 *                  上下位置颠倒
 *
 *        Version:  1.0
 *        Created:  2012/10/14 16时30分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stack>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

#define MX 10000
struct Node 
{
    struct Node *left, *right;

    int data;
} *head;

void insert(int p)
{
    struct Node *tmp = head, *tmp2;
    int lr = -1;
    while(tmp != NULL)
    {
        if(tmp->data > p) 
        {
            tmp2 = tmp;

            lr = 0;
            tmp = tmp->left;
        }
        else          
        {
            tmp2 = tmp;

            lr = 1;
            tmp = tmp->right;
        }
    }
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = p;

    if(lr == -1) head = tmp;
    else if(lr == 0) tmp2->left = tmp;
    else tmp2->right = tmp;
}
void generator()
{
    /*
     *                 3
     *                / \
     *               1   4
     *                \ / \
     *                2 3 9
     *                   /
     *                  8
     *                 /
     *                7
     *                maxlen : 6
     *
     */
    insert(3);
    insert(4);
    insert(1);
    insert(9);
    insert(8);
    insert(3);
    insert(2);
    insert(7);
}
void release(struct Node * p)
{
    if(p->left) release(p->left);
    if(p->right) release(p->right);

    free(p);

}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  go
 *  Description:  输出数各层次的值
 * =====================================================================================
 */
void go()
{
    queue<struct Node *> q;
    stack<int> q2;
    int each[MX];
    memset(each, 0, sizeof(each));

    struct Node *tmp;
    q.push(head);
    q2.push(head->data);
    each[0] = 1;
    int now = 0, count = 0;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        
        if(tmp->left != NULL && ++each[now+1])
        {
            q.push(tmp->left);
            q2.push(tmp->left->data);
        }
        if(tmp->right != NULL && ++each[now+1])
        {
            q.push(tmp->right);
            q2.push(tmp->right->data);
        }

        count++;
        if(count == each[now])
        {
            now++;
            count = 0;
        }
    }
    for(int i = now-1;i >= 0;i--)
    {
        for(int j = each[i];j > 0;j--)
        {
            int tmp = q2.top();
            q2.pop();
            cout<<tmp<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    generator();

    go();

    release(head);

    return 0;
}
