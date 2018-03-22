//输入压栈顺序如1 2 3 4 5 6 7 8 ..n，确定所有可能出栈的得到的结果
//同时计算情况的总数n
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
//递归法只计算所有情况总数
int getPermuStack(int n, int m)
{
     if(n == 0)//递归边界
     return 1;
     if(m == 0)//(n,0)问题的处理
     return getPermuStack(n-1, 1);
     return getPermuStack(n, m-1) + getPermuStack(n-1, m+1);
}
//Catalan公式法 最多只能算到n=10
long long jiecheng(long long n)
{
    if(n==1) return 1;
    else return n*jiecheng(n-1);
}
long long catalan(long long n)
{
    return (jiecheng(2*n)/jiecheng(n+1)/jiecheng(n));
}
//下面算法函数既输出所有可能压栈（不全压，但仍按给定顺序压栈）的情况，也输出对应的出栈情况及总数
int n,i,j;
int res;
stack <int> s;
queue <int> in,out;
void clear(stack <int> &s)
{
    while(!s.empty())
    s.pop();
}
void clear(queue <int> &s)
{
    while(!s.empty())
    s.pop();
}
void print(queue <int> i)
{
    while(!i.empty())
   {
    cout<<i.front();
    i.pop();
   }
    cout<<endl;
}
void dostack(queue <int> in,stack <int> s,queue <int> out)
{
    if(in.empty())
     {
        if(s.empty())
       {
          res++;
          print(out);
       }
       else
       {
          out.push(s.top());
          s.pop();
          dostack(in,s,out);
       }
    }
    else
    {
       if(!s.empty())
        {
         stack <int> ts;
         queue <int> tin,tout;
         tin=in;
         ts=s;
         tout=out;
         tout.push(ts.top());
         ts.pop();
         dostack(tin,ts,tout);
        }
         s.push(in.front());
         in.pop();
         dostack(in,s,out);
    }
}
int main()
{
      cout<<"请输入1~n共n个数:";
      while(cin>>n)
      {
        res=0;
        clear(in);
        clear(out);
        clear(s);
        for(i=n;i>=1;i--)
              in.push(i);
        dostack(in,s,out);
        cout<<"对应的出栈情况总数="<<res<<endl;

      }
      cout<<"1~n依次进栈时，使用递归函数所有的情况总数:"<<endl;
      for(i=1;i<15;i++)
         cout<<"n="<<i<<"  "<<getPermuStack(i,0)<<endl;

      cout<<endl<<"1~n依次进栈时，使用Catalan公式所有的情况总数:"<<endl;
      for(i=1;i<15;i++)
         cout<<"n="<<i<<"  "<<catalan(i)<<endl;


      return 0;
}
