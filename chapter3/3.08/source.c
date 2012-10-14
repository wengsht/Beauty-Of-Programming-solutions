/*
 * =====================================================================================
 *
 *       Filename:  source.c
 *
 *    Description:  求二叉树中节点的最大距离
 *
 *                  乍一看去以为是LCA.然后发现以为是多叉树的dp，然后看见只有二叉。直接dfs一次就出来了。
 *
 *        Version:  1.0
 *        Created:  2012/10/14 14时30分15秒
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

#define max(a,b) (a>b?a:b)
int res = 0;

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
 *  返回以head为一端的最长链
 *  同时更新结果于res中
 */
int dfs(struct Node *head)
{
    int lm = -1, rm = -1;
    if(head->left) lm = dfs(head->left);
    if(head->right) rm = dfs(head->right);

    if(lm+rm+2 > res) res = lm+rm+2;

    return max(lm+1, rm+1);
}

int main()
{
    generator();

    dfs(head);
    printf("%d\n", res);

    release(head);

    return 0;
}
