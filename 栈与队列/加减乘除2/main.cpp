#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
#define Max 100
using namespace std;
bool prev(char s1,char s2 ){                    //�жϷ���s1 �� s2 �����ȼ���ĺ���
    if(s1=='^'||s1=='*'||s1=='/')                 //���ջ������Ϊ* ^ / ���ÿ������������Ƚϵķ��ţ�ֱ�ӷ�����
        return true;
    else if((s1=='+'||s1=='-')&&(s2=='+'||s2=='-'))      //���ջ�����ź������Ƚϵķ���Ϊ+����-��Ҳ������
        return true;
        else
        return false;                                  //������������ؼ�
    }

template <class T>
class SeqStack
{
public:
    SeqStack():top(-1){}
    ~SeqStack(){top=-1;}
    T Pop();
    T getTop();
    void Push(T x);
    bool IsEmpty();
    bool IsFull();
private:
    T A[Max];
    int top;
};
template <class T>
void result(char ch,SeqStack<T> &s)                 //���㲢��������ѹ��ջ��
{
    T x,y,result;
    x=s.Pop();
    y=s.Pop();
    switch(ch)
    {
        case '+':result=y+x;break;
        case '-':result=y-x;break;
        case '*':result=y*x;break;
        case '/':result=y/x;break;
        case '^':result=pow(y,x);break;
    }
    s.Push(result);
    return ;
}
int main()
{
    SeqStack<char> x;                                           //����ջ
    SeqStack<double> y;                                       //��ֵջ
    char ch,c;
    double operand;
    x.Push('0');
    while(1)
    {
        cin.get(ch);
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')                                                   //����+-*/��Ҫ�����ջջ��Ԫ�رȽϣ������Ƿ�����
        {
            c=x.getTop();
            while(prev(c,ch))                              //���űȽϷ����棬��Ҫ����,ѭ��ֱ��ջ���ܼ���ķ���ȫ������
            {
                result(c,y);                                  //ע�����ʱʹ�õ��Ƿ���ջ��ջ������
                x.Pop();                                        //�����ոռ�����ķ���c
                c=x.getTop();                                  //c���浱ǰ����ջջ����Ԫ�ؽ���ѭ��
            }
            x.Push(ch);                                     //�������ѹ��ո�����ķ���
        }
        else if(ch=='^'||ch=='(')                           //��������^���ߣ�ֱ��ѹջ�����ÿ��ǱȽϷ��źͼ���
            x.Push(ch);
        else if(ch==')')                                   //���������ţ�Ҫ��ջ��Ԫ�ؽ���ѭ�����㣬ֱ�����������ţ�
        {
            c=x.getTop();
            while(c!='(')                //��ʱ��ѭ�����������жϷ��ţ��������ž�Ҫ���㣬��Ϊ������ǰ���Ԫ�أ��Ѿ������ȼ������
            {
                result(c,y);
                x.Pop();
                c=x.getTop();
            }
            x.Pop();                               //����������
        }
        else if(isdigit(ch))                  //�����֣��Ż��������������������֣�ѹջ
        {
            cin.putback(ch);
            cin>>operand;
            y.Push(operand);

        }
        else if(ch=='\n')
        {
            c=x.getTop();
            while(c!='0')
            {
                result(c,y);
                x.Pop();
                c=x.getTop();
            }
            cout<<y.Pop()<<endl;break;
        }
    }

    return 0;
}
template <class T>
T SeqStack<T>::Pop()
{
    assert(top!=-1);
    T x;
    x=A[top];
    top--;
    return x;
}
template <class T>
void SeqStack<T>::Push(T x)
{
    assert(top!=Max-1);
    top++;
    A[top]=x;
    return ;
}
template <class T>
T SeqStack<T>::getTop()
{
    assert(top!=-1);
    return A[top];
}
template <class T>
bool SeqStack<T>::IsEmpty()
{
    if(top==-1) return true;
    else return false ;
}
template <class T>
bool SeqStack<T>::IsFull()
{
    if(top==Max-1)return true;
    else return false;
}
