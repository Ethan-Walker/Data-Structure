#include <iostream>
#include <stack>
using namespace std;
int main()
{
     stack<long> s;
     long n,sum=1,x,y,i;
     cout<<"������ʾ������";
     cin>>n;
     s.push(1);
     cout<<"��ʾ쳲�����ǰ"<<n<<"��:";
     cout<<"1 ";
     s.push(1);
     x=s.top();            //x����Ҫ������ջ��Ԫ��
     s.pop();                //����
     i=n;
     while(i-1)
     {
        y=s.top()+x;             //y����֮ǰ������ջ��Ԫ��x�����ڵ�ջ��Ԫ��֮�ͣ����õ��´�ѹջ��Ԫ��
        x=s.top();               //x�������ڵ�ջ��Ԫ��
        cout<<x<<" ";
        sum+=x;

        s.pop();              //����ջ��Ԫ��x
        s.push(y);            //��ǰ����֮��y��Ϊջ��Ԫ��ѹջ
        i--;
     }
     cout<<endl<<"ǰ"<<n<<"��ĺ�Ϊ��"<<sum<<endl;
     return 0;
}



