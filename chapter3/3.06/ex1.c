/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  编程判断两个链表是否相交
 *                  练习1，链表可能有环
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
    struct Node *pn = p->next;
    free(p);

    if(pn) release(pn);

}
void print(struct Node *p)
{
    if(p == NULL) return ;
    printf("%d ", p->data);
    print(p->next);
}
int go(struct Node *p1, struct Node *p2)
{
    while(p1->next) p1 = p1->next;
    while(p2->next) p2 = p2->next;

    if(p1 == p2) return 1;

    return 0;
}
int main()
{
    struct Node *head1, *head2, *head3;

    generator_circle(&head1, 10, 5);
    head2 = head1;
    generator(&head3, 10);

    printf("list1 和 list2相交情况：%d\n", go(head1, head2));
    printf("list1 和 list3相交情况：%d\n", go(head1, head3));
    
    return 0;
}
