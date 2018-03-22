#include <iostream>
#include <stack>
using namespace std;
int main()
{
     stack<long> s;
     long n,sum=1,x,y,i;
     cout<<"输入显示个数：";
     cin>>n;
     s.push(1);
     cout<<"显示斐波拉契前"<<n<<"项:";
     cout<<"1 ";
     s.push(1);
     x=s.top();            //x保存要弹出的栈顶元素
     s.pop();                //弹出
     i=n;
     while(i-1)
     {
        y=s.top()+x;             //y保存之前弹出的栈顶元素x与现在的栈顶元素之和，即得到下次压栈的元素
        x=s.top();               //x保存现在的栈顶元素
        cout<<x<<" ";
        sum+=x;

        s.pop();              //弹出栈顶元素x
        s.push(y);            //将前两项之和y作为栈顶元素压栈
        i--;
     }
     cout<<endl<<"前"<<n<<"项的和为："<<sum<<endl;
     return 0;
}



