#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define MaxSize 20
typedef int ElemType;
struct SeqStack{
    ElemType data[MaxSize];
    int top;             //栈顶指针
};
bool Push(SeqStack *S,ElemType e)       //压栈
{
    if(S->top==MaxSize-1) {cout<<"栈满"<<endl;return false;}
    S->top++;
    S->data[S->top]=e;
    return true;
}

//出栈
bool Pop(SeqStack *S,ElemType *e)   //获取栈顶元素到e，同时出栈
{
    if(S->top==-1) return false;
    *e=S->data[S->top];
    S->top--;
    return true;
}

//构造一个空栈
void InitStack(SeqStack *S)
{
    S->top=-1;
    return ;
}
bool StackTraverse(SeqStack S)
{
    cout<<"遍历栈中数据：";
    int i;
    for(i=0;i<=S.top;i++)
        cout<<S.data[i]<<" ";
    cout<<endl;
    return true;
}
bool GetTop(SeqStack S,ElemType *x)
{
    if(S.top==-1) return false;
    *x=S.data[S.top];
    return true;
}
//判断栈是否为空栈
bool IsEmpty(SeqStack S)
{
    if(S.top==-1){return true;}
    else return false;
}
//判断栈是否已满
bool IsFull(SeqStack S)
{
    if(S.top==MaxSize) return true;
    else return false;
}

//将栈置空
bool MakeEmpty(SeqStack *S)
{
    S->top==-1;
    return true;
}
int main()
{
    SeqStack S;
    InitStack(&S);
    srand((unsigned)time(NULL));
    int n;
    cout<<"请输入入栈的数据数目:";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++)
    Push(&S,rand()%100);
    StackTraverse(S);
    int e;
    Pop(&S,&e);
    cout<<"出栈的元素为:"<<e<<endl;
    cout<<"此时栈中元素个数为:"<<S.top+1<<endl;
    ElemType x;
    GetTop(S,&x);
    cout<<"获得的栈顶元素为:"<<x<<endl;
    return 0;
}
