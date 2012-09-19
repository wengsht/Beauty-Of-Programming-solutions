/*
 * =====================================================================================
 *
 *       Filename:  lab1.c
 *
 *    Description:  练习1
 *
 *        Version:  1.0
 *        Created:  2012/09/18 14时30分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int is_pow(int n)
{
    return n > 0 && (n & (n-1)) == 0;
}
int main()
{
    int n;
    scanf("%d", &n);

    printf("%d is%spower number\n", n, (is_pow(n)? " ":" not ") );
}
