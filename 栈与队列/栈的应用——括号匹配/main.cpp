#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
     stack<char> s;
     char A[100]={'\0'};
     gets(A);
     int i;
     for(i=0;i<strlen(A);i++){
        if(A[i]=='(') s.push(A[i]);        //��������ѹջ
        else if((A[i]==')'&&
        {
            if(!s.empty())                  //��������ջ�зǿ�����ջ
            s.pop();
        else {s.push(A[i]);break;}          //��������ջ��Ϊ�գ���˵����ƥ�䣬����������ѹ��ջ�У�ʹ��ǿ��Ա���������ƥ��
        }

     }
     if(!s.empty()) cout<<"��ƥ��"<<endl;
     else cout<<"��ȷƥ��"<<endl;
     return 0;
}
