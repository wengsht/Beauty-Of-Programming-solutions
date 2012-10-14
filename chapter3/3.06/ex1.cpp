/*
 * =====================================================================================
 *
 *       Filename:  ex1.cpp
 *
 *    Description:  编程判断两个链表是否相交
 *                  练习1，链表可能有环
 *                  遍历节点并hash，找出最后一个节点或者环的开始节点即可
 *
 *        Version:  1.0
 *        Created:  2012/10/13 15时32分22秒
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
#include <vector>
#include <iostream>

using namespace std;

#define MOD 13917
struct Node
{
    struct Node *next;
    int data;
};

void generator(struct Node ** head, int n)
{
    *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = *head;

    int i;
    for(i = 1;i < n;i++)
    {
        p->next = (struct Node*)malloc(sizeof(struct Node));

        p = p->next;
    }
    p->next = NULL;
}
void generator_circle(struct Node ** head, int n, int k)
{
    *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = *head, *last_nxt;

    int i;
    for(i = 1;i < n;i++)
    {
        p->next = (struct Node*)malloc(sizeof(struct Node));

        p = p->next;
        if(i == k) last_nxt = p;
    }
    p->next = NULL;
    p->next = last_nxt;
}
void release(struct Node *p)
{
    struct Node *pn = p->next;
    free(p);

    if(pn) release(pn);

}
int go(struct Node *p1, struct Node *p2)
{
    vector<struct Node *> ptrs[MOD];

    unsigned long hash;
    bool had;
    hash = (unsigned long)p1 % MOD;
    ptrs[hash].push_back(p1);
    while(p1->next) 
    {
        p1 = p1->next;

        hash = (unsigned long)p1 % MOD;

        had = false;
        for(int i = 0;i < ptrs[hash].size();i++) 
        {
            if(p1 == ptrs[hash][i]) had = true;
        }
        if(had) break;
        ptrs[hash].push_back(p1);
    }
    for(int i = 0;i < MOD;i++) ptrs[i].clear();

    hash = (unsigned long)p2 % MOD;
    ptrs[hash].push_back(p2);
    while(p2->next) 
    {
        p2 = p2->next;

        hash = (unsigned long)p2 % MOD;

        had = false;
        for(int i = 0;i < ptrs[hash].size();i++) 
        {
            if(p2 == ptrs[hash][i]) had = true;
        }
        if(had) break;
        ptrs[hash].push_back(p2);
    }
    if(p1 == p2) return 1;

    return 0;
}
int main()
{
    struct Node *head1, *head2, *head3;

    generator_circle(&head1, 10, 5);
    head2 = head1;
    head2 = head2->next;
    generator(&head3, 10);

    printf("list1 和 list2相交情况：%d\n", go(head1, head2));
    printf("list1 和 list3相交情况：%d\n", go(head1, head3));
    
    return 0;
}
