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
        if(isdigit(ch1)) {cin.putback(ch1);cin>>operand;(cout<<operand<<" ";cin.get(ch1);}            //�ж��Ƿ������֣��������֣������
        else {
            if(icp(ch1)>isp(s.top())) {s.push(ch1);cin.get(ch1);}    //���ջ��icp>ջ��isp  ��ѹջ�Ҷ�����һ���ַ�
            else if(icp(ch1)<isp(s.top())){cout<<s.top()<<" ";s.pop();}     //���ջ��icp<ջ��isp�����ջ��Ԫ�ز���ջ
            else if(icp(ch1)==isp(s.top())){                     //���icp>isp��1--���ջ��Ԫ��Ϊ��(��,����ջ����������һ��Ԫ��
                                                                //              2--���ջ��Ԫ�ز�Ϊ��(����������ջ��
                if(s.top()=='(') cin.get(ch1);
                s.pop();
            }
        }


    }
    cout<<"ѭ������"<<endl;
        //cout<<s.top()<<endl;
        cin.get();

    return 0;
}
