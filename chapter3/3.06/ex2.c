/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  编程判断两个链表是否相交
 *                  
 *                  找出第一个相交节点。
 *
 *                  记录长度 对齐处理
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
void release(struct Node *p)
{
    if(p->next) release(p->next);

    free(p);
}
void print(struct Node *p)
{
    if(p == NULL) return ;
    printf("%p ", p);
    print(p->next);
}
struct Node * go(struct Node *p1, struct Node *p2)
{
    struct Node *tmp1 = p1, *tmp2 = p2;
    int len1 = 1, len2 = 1;
    while(p1->next && len1++) p1 = p1->next;
    while(p2->next && len2++) p2 = p2->next;

    if(p1 != p2) return NULL;

    while(len1 > len2 && len1--) tmp1 = tmp1->next;
    while(len2 > len1 && len2--) tmp2 = tmp2->next;

    while(tmp1 != tmp2)
    {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return tmp1;
}
int main()
{
    struct Node *head1, *head2, *head3;

    generator(&head1, 10);
    head2 = head1->next;
    printf("list1地址: ");
    print(head1);
    printf("\n");
    printf("list2地址: ");
    print(head2);
    printf("\n");
    generator(&head3, 10);
    printf("list3地址: ");
    print(head3);
    printf("\n");

    printf("list1 和 list2第一个相交节点：%p\n", go(head1, head2));
    printf("list1 和 list3第一个相交节点：%p\n", go(head1, head3));
    
    return 0;
}
