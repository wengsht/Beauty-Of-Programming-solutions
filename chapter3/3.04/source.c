/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  从无头单链表中删除节点
 *
 *        Version:  1.0
 *        Created:  2012/10/12 19时10分42秒
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
} *head;

void generator()
{
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    head->data = 0;

    int i;
    for(i = 1;i < 10;i++)
    {
        p->next = (struct Node*)malloc(sizeof(struct Node));

        p->next->data = i;
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
    printf("%d ", p->data);
    print(p->next);
}
void rme(struct Node *p)
{
    if(p->next == NULL || p == NULL) return ;

    p->data = p->next->data;

    struct Node * nxt = p->next;

    p->next = nxt->next;

    free(nxt);
}
int main()
{
    generator();

    printf("原链表:");
    print(head);
    printf("\n");

    struct Node *p = head->next->next->next->next;

    printf("手头有%d的指针\n", p->data);

    rme(p);

    printf("删除它后，链表状态:");
    print(head);
    printf("\n");

    release(head);

    return 0;
}
