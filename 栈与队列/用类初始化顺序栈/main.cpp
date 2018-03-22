#include <iostream>
using namespace std;
#define Max 100
template <class T>
class SeqStack{
public:
    SeqStack():top(-1){}
    ~SeqStack(){MakeEmpty();}
    bool Push(T x);
    bool IsEmpty();
    bool Pop(T &x);
    bool MakeEmpty();
    bool GetTop(T &x);
    bool Size(int &n);
    bool IsFull();
private:
    T data[Max];
    int top;
};
int main()
{
    SeqStack<int> s;
    int operand,top,length;
    while(cin>>operand)
    {
        s.Push(operand);
    }
    s.GetTop(top);
    cout<<"top="<<top<<endl;
    s.Pop(top);
    s.Size(length);
    s.Push(length);
    cout<<"此时的栈长为:"<<length<<endl;
    s.Pop(top);
    cout<<"top:"<<top<<endl;
    s.MakeEmpty();
    if(s.IsEmpty()) cout<<"栈置空成功"<<endl;
    return 0;
}
template <class T>
bool SeqStack<T>::Push(T x)
{
    if(top==Max-1) {cout<<"栈满"<<endl;return false;}
    top++;
    data[top]=x;
    return true;
}
template <class T>
bool SeqStack<T>::Pop(T &x)
{
    if(IsEmpty()) {cout<<"栈空"<<endl;return false;}
    x=data[top];
    top--;
    return true;
}
template <class T>
bool SeqStack<T>::GetTop(T &z)
{
    if(IsEmpty()) {cout<<"栈空"<<endl;return false;}
    z=data[top];
    return true;

}
template <class T>
bool SeqStack<T>::IsEmpty()
{
    if(top==-1)
        return true;
    return false;
}
template <class T>
bool SeqStack<T>::IsFull()
{
    if(top==Max-1) return true;
    return false;
}
template <class T>
bool SeqStack<T>::MakeEmpty()
{
    top==-1;
    return false;
}
template <class T>
bool SeqStack<T>::Size(int &n)
{
    n=0;
    if(top==-1) {n=0;return true;}
    while(top+1)
    {
        n++;
        top--;
    }
    return true;
}
