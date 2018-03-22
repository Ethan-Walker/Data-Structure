#include <iostream>
#include <stack>
#include <string>
using namespace std;
int isp(char ch)
{
    switch(ch)
    {
        case'#':return 0;
        case'(':return 1;
        case'*':
        case'/':
        case'%':
            return 5;
        case'+':
        case'-':
                return 3;
        case')':
            return 6;
    }
}
int icp(char ch)
{
    switch(ch)
    {
        case'#':return    0;
        case'(':return 6;
        case'*':
        case'/':
        case'%':
            return 4;
        case'+':
        case'-':
                return 2;
        case')':
            return 1;
    }
}
int main()
{
    stack<string> x;
    stack<char>   s;
    char ch1='#';
    double operand;
    s.push(ch1);
    cin.get(ch1);
    while(!s.empty()&&ch1!='#')
    {
        if(isdigit(ch1)) {cin.putback(ch1);cin>>operand;(cout<<operand<<" ";cin.get(ch1);}            //判断是否是数字，若是数字，则输出
        else {
            if(icp(ch1)>isp(s.top())) {s.push(ch1);cin.get(ch1);}    //如果栈外icp>栈内isp  ，压栈且读入下一个字符
            else if(icp(ch1)<isp(s.top())){cout<<s.top()<<" ";s.pop();}     //如果栈外icp<栈内isp，输出栈顶元素并退栈
            else if(icp(ch1)==isp(s.top())){                     //如果icp>isp，1--如果栈顶元素为“(”,则退栈，并读入下一个元素
                                                                //              2--如果栈顶元素不为“(”，仅仅退栈；
                if(s.top()=='(') cin.get(ch1);
                s.pop();
            }
        }


    }
    cout<<"循环结束"<<endl;
        //cout<<s.top()<<endl;
        cin.get();

    return 0;
}
