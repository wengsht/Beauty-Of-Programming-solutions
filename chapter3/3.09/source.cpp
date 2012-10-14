/*
 * =====================================================================================
 *
 *       Filename:  source.cpp
 *
 *    Description:  烦到不想编这种题。。直接拉很久以前在soj上做过的代码。
 *                  输入长度，前序，中序，输出宽度搜索次序
 *
 *                  实际上重建二叉树递归一下也很简单
 *
 *        Version:  1.0
 *        Created:  2012/10/14 15时09分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string a,b,c,d;
int n;
queue<string> q1,q2;
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        q1.push(a);
        q2.push(b);
        while(!q1.empty())
        {
            c = q1.front();
            d = q2.front();
            int l = c.length();
            q1.pop();
            q2.pop();
            if(l == 1) 
            {
                cout<<c[0];
                continue;
            }
            int p = d.find(c[0]);
            cout<<c[0];
            if(p == 0)
            {
                c.erase(0,1);
                d.erase(0,1);
                q1.push(c);
                q2.push(d);
            }
            else if(p == l - 1) 
            {
                c.erase(0,1);
                d.erase(p,1);
                q1.push(c);
                q2.push(d);
            }
            else
            {
                q1.push(c.substr(1,p));
                q1.push(c.substr(1+p,l-1-p));
                q2.push(d.substr(0,p));
                q2.push(d.substr(p+1,l-1-p));
            }
        }
        cout<<endl;
    }
    return 0;
}

                


                                 
