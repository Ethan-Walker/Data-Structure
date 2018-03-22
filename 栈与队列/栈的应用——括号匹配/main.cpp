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
        if(A[i]=='(') s.push(A[i]);        //左括号则压栈
        else if((A[i]==')'&&
        {
            if(!s.empty())                  //右括号且栈中非空则退栈
            s.pop();
        else {s.push(A[i]);break;}          //右括号且栈中为空，则说明不匹配，将该右括号压入栈中，使其非空以便后面输出不匹配
        }

     }
     if(!s.empty()) cout<<"不匹配"<<endl;
     else cout<<"正确匹配"<<endl;
     return 0;
}
