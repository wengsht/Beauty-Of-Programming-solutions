/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  分层遍历二叉树
 *                  宽搜
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
#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

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
    queue<struct Node *> q[2];
    struct Node *tmp;
    int now = 0;
    q[now].push(head);
    while(!q[now].empty())
    {
        tmp = q[now].front();
        q[now].pop();
        
        printf("%d ", tmp->data);
        if(tmp->left != NULL)
            q[now^1].push(tmp->left);
        if(tmp->right != NULL)
            q[now^1].push(tmp->right);

        if(q[now].empty())
        {
            printf("\n");

            now ^= 1;
        }
    }
}
int main()
{
    generator();

    go();

    release(head);

    return 0;
}
