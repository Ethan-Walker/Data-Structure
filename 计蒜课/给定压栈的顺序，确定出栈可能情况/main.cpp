//����ѹջ˳����1 2 3 4 5 6 7 8 ..n��ȷ�����п��ܳ�ջ�ĵõ��Ľ��
//ͬʱ�������������n
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
//�ݹ鷨ֻ���������������
int getPermuStack(int n, int m)
{
     if(n == 0)//�ݹ�߽�
     return 1;
     if(m == 0)//(n,0)����Ĵ���
     return getPermuStack(n-1, 1);
     return getPermuStack(n, m-1) + getPermuStack(n-1, m+1);
}
//Catalan��ʽ�� ���ֻ���㵽n=10
long long jiecheng(long long n)
{
    if(n==1) return 1;
    else return n*jiecheng(n-1);
}
long long catalan(long long n)
{
    return (jiecheng(2*n)/jiecheng(n+1)/jiecheng(n));
}
//�����㷨������������п���ѹջ����ȫѹ�����԰�����˳��ѹջ���������Ҳ�����Ӧ�ĳ�ջ���������
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
      cout<<"������1~n��n����:";
      while(cin>>n)
      {
        res=0;
        clear(in);
        clear(out);
        clear(s);
        for(i=n;i>=1;i--)
              in.push(i);
        dostack(in,s,out);
        cout<<"��Ӧ�ĳ�ջ�������="<<res<<endl;

      }
      cout<<"1~n���ν�ջʱ��ʹ�õݹ麯�����е��������:"<<endl;
      for(i=1;i<15;i++)
         cout<<"n="<<i<<"  "<<getPermuStack(i,0)<<endl;

      cout<<endl<<"1~n���ν�ջʱ��ʹ��Catalan��ʽ���е��������:"<<endl;
      for(i=1;i<15;i++)
         cout<<"n="<<i<<"  "<<catalan(i)<<endl;


      return 0;
}
