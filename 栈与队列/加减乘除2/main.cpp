#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
#define Max 100
using namespace std;
bool prev(char s1,char s2 ){                    //判断符号s1 与 s2 的优先级别的函数
    if(s1=='^'||s1=='*'||s1=='/')                 //如果栈顶符号为* ^ / 则不用考虑输入拿来比较的符号，直接返回真
        return true;
    else if((s1=='+'||s1=='-')&&(s2=='+'||s2=='-'))      //如果栈顶符号和拿来比较的符号为+或者-，也返回真
        return true;
        else
        return false;                                  //其他情况都返回假
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
void result(char ch,SeqStack<T> &s)                 //计算并将计算结果压入栈中
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
    SeqStack<char> x;                                           //符号栈
    SeqStack<double> y;                                       //数值栈
    char ch,c;
    double operand;
    x.Push('0');
    while(1)
    {
        cin.get(ch);
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')                                                   //若是+-*/则要与符号栈栈顶元素比较，决定是否运算
        {
            c=x.getTop();
            while(prev(c,ch))                              //符号比较返回真，则要计算,循环直到栈内能计算的符号全部计算
            {
                result(c,y);                                  //注意计算时使用的是符号栈中栈顶符号
                x.Pop();                                        //弹出刚刚计算过的符号c
                c=x.getTop();                                  //c保存当前符号栈栈顶的元素进行循环
            }
            x.Push(ch);                                     //计算结束压入刚刚输入的符号
        }
        else if(ch=='^'||ch=='(')                           //遇到符号^或者（直接压栈，不用考虑比较符号和计算
            x.Push(ch);
        else if(ch==')')                                   //遇到右括号，要对栈中元素进行循环计算，直到遇到左括号（
        {
            c=x.getTop();
            while(c!='(')                //此时的循环条件不是判断符号，遇到符号就要计算，因为括号里前面的元素，已经按优先级计算好
            {
                result(c,y);
                x.Pop();
                c=x.getTop();
            }
            x.Pop();                               //弹出（符号
        }
        else if(isdigit(ch))                  //是数字，放回输入流，重新输入数字，压栈
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
