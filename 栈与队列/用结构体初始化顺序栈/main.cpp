#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define MaxSize 20
typedef int ElemType;
struct SeqStack{
    ElemType data[MaxSize];
    int top;             //ջ��ָ��
};
bool Push(SeqStack *S,ElemType e)       //ѹջ
{
    if(S->top==MaxSize-1) {cout<<"ջ��"<<endl;return false;}
    S->top++;
    S->data[S->top]=e;
    return true;
}

//��ջ
bool Pop(SeqStack *S,ElemType *e)   //��ȡջ��Ԫ�ص�e��ͬʱ��ջ
{
    if(S->top==-1) return false;
    *e=S->data[S->top];
    S->top--;
    return true;
}

//����һ����ջ
void InitStack(SeqStack *S)
{
    S->top=-1;
    return ;
}
bool StackTraverse(SeqStack S)
{
    cout<<"����ջ�����ݣ�";
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
//�ж�ջ�Ƿ�Ϊ��ջ
bool IsEmpty(SeqStack S)
{
    if(S.top==-1){return true;}
    else return false;
}
//�ж�ջ�Ƿ�����
bool IsFull(SeqStack S)
{
    if(S.top==MaxSize) return true;
    else return false;
}

//��ջ�ÿ�
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
    cout<<"��������ջ��������Ŀ:";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++)
    Push(&S,rand()%100);
    StackTraverse(S);
    int e;
    Pop(&S,&e);
    cout<<"��ջ��Ԫ��Ϊ:"<<e<<endl;
    cout<<"��ʱջ��Ԫ�ظ���Ϊ:"<<S.top+1<<endl;
    ElemType x;
    GetTop(S,&x);
    cout<<"��õ�ջ��Ԫ��Ϊ:"<<x<<endl;
    return 0;
}
