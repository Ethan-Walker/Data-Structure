#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MaxSize 50
struct SeqStack{
    double data[MaxSize];
    int top;
};
bool InitStack(SeqStack *S)
{
    S->top=-1;
    return true;
}
bool Push(SeqStack *S,double x)
{
    S->top++;
    S->data[S->top]=x;
    return true;
}
bool Pop(SeqStack *S,double &s)
{
    s=S->data[S->top];
    S->top--;
    return true;
}

void DoOperator(SeqStack *S,char ch)
{
    double left,right,value;
    Pop(S,right);
    Pop(S,left);
    switch(ch)
    {
        case '+':value=left+right;Push(S,value);break;
        case '-':value=left-right;Push(S,value);break;
        case '*':value=left*right;Push(S,value);break;
        case '/':
            if(right==0) cout<<"错误"<<endl;
               else value=left/right;Push(S,value);break;
    }
    return ;
}
int main()
{
    SeqStack S;
    InitStack(&S);
    double operand,result;
    char ch;
    while(cin>>ch) {
        if(isdigit(ch))
        {cin.putback(ch);                //是操作数则将字符放回输入流(可能要输入的是12,2.5等等大于10或者非整数，用double变量保存
        cin>>operand;                     //重新读取操作数
        Push(&S,operand);                   //操作数压栈
        }
        else DoOperator(&S,ch);
    }
    Pop(&S,result);
    cout<<result<<endl;
    return 0;
}
