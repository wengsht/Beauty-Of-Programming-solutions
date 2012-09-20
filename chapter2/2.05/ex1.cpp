/*
 * =====================================================================================
 *
 *       Filename:  ex1.cpp
 *
 *    Description:  练习1 寻找最大的K个不同的浮点数
 *                  由于是浮点数所以姑且不考虑计数排序之类的方法，题目要求找不不同的数，所以不能直接套用
 *                  想到的是利用平衡二叉数 cache一下树中最小值可以像堆一样快速判断是否需要更新树，更新过程中遇到相同key则放弃更新即可
 *
 *        Version:  1.0
 *        Created:  2012/09/19 10时13分58秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define MX 100000
int mx_index, root;
int size;
typedef struct 
{
   int l, r, rand_fix;
   double key;
} Treap;

Treap node[MX];
double cache_mn;

//left  rotate
void l_rot(int &index)
{
   int y = node[index].r;
   node[index].r = node[y].l;
   node[y].l = index;
   index = y;
}
//right rotate
void r_rot(int &index)
{
   int y = node[index].l;
   node[index].l = node[y].r;
   node[y].r = index;
   index = y;
}
bool insert(int &index, double nkey)
{
    bool ok;
   if(index == -1)
   {
       index = ++mx_index;
       node[index].l = node[index].r = -1;
       node[index].rand_fix = rand();
       node[index].key = nkey;
       return true;
   }
   if(nkey == node[index].key)
       return false;
   else if(nkey < node[index].key)
   {
       ok = insert(node[index].l, nkey);
       if(node[node[index].l].rand_fix > node[index].rand_fix)
           r_rot(index);
   }
   else
   {
       ok = insert(node[index].r, nkey);
       if(node[node[index].r].rand_fix > node[index].rand_fix)
           l_rot(index);
   }
   return ok;
}
bool remove(int &index, double nkey)
{
   if(index == -1) return false;
   if(nkey < node[index].key)
       return remove(node[index].l, nkey);
   else if(nkey > node[index].key)
       return remove(node[index].r, nkey);
   if(node[index].l == -1 && node[index].r == -1)
       index = -1;
   else if(node[index].l == -1)
       index = node[index].r;
   else if(node[index].r == -1)
       index = node[index].l;
   else
   {
       if(node[node[index].l].rand_fix < node[node[index].r].rand_fix)
       {
           l_rot(index);
           remove(node[index].l, nkey);
       }
       else
       {
           r_rot(index);
           remove(node[index].r, nkey);
       }
   }
   return true;
}
       
void init()
{
   size = 0;
   mx_index = root = -1;
   srand(time(0));
}
void print(int index)
{
   if(index == -1) return ;
   if(node[index].l != -1) print(node[index].l);
   printf("%lf ", node[index].key);
   if(node[index].r != -1) print(node[index].r);
}
void print(double *arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%lf ", arr[i]);

    printf("\n");
}

double find_new_mn(int index)
{
    return (node[index].l == -1 ? node[index].key : find_new_mn(node[index].l));
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_diff_k
 *  Description:  找arr最大的k个不同的浮点数， 结果存于全局的Treap树node中
 * =====================================================================================
 */
void find_diff_k(double *arr, int k, int n)
{
    if(k <= 0 || k >= n) return ;
    init();

    insert(root, arr[0]);
    cache_mn = arr[0];
    size++;

    int i;
    for(i = 1; i < n; i++)
    {
        if(size < k && insert(root, arr[i])) 
        {
            size++;
            if(cache_mn > arr[i]) cache_mn = arr[i];
        }
        else if(cache_mn < arr[i] && insert(root, arr[i]))
        {
            remove(root, cache_mn);
            cache_mn = find_new_mn(root);
        }
    }

}
int main (int argc, char *argv[])
{
    double test[200];
    int i;

    for ( i = 0; i < 200; i += 2 ) 
    {
        test[i] = rand() % 1000000 / 10000.0;
        test[i+1] = test[i];
    }

    find_diff_k(test, 10, 200);

    print(test, 200);
    print(root);

    return 0;
}
