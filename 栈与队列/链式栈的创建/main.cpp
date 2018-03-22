#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class LinkedStack;                                          //类声明

template <class T>                                          //全局的operator<<、>>函数都要在类定义前声明
istream& operator>>(istream &is,LinkedStack<T> &s);
template <class T>
ostream& operator<<(ostream &os,LinkedStack<T> &s);

template <class T>
struct Node{
    T data;
    Node<T> *next;
};
template <class T>
class LinkedStack
{
public:
    LinkedStack();                            //初始化栈，链表头结点为top栈顶位置
    ~LinkedStack(){makeEmpty();cout<<"析构函数执行"<<endl;}                        //析构函数，置空栈
    void Push(const T&x);
    T Pop();
    T getTop();
    bool IsEmpty()const{return (top->next==NULL)?true:false;}
    int getSize()const;
    void makeEmpty();
    friend istream& operator>> <>(istream &is,LinkedStack<T> &s);                  //模板函数做友元要显式的声明模板形参,
                                                                                   //如果<>内空就是把当前类的模板参数传进来用.
    friend ostream& operator<< <>(ostream &os,LinkedStack<T> &s);                 //<>不能省略

private:
    Node<T> *top;                                         //栈顶指针
};
template <class T>
istream& operator>>(istream &is,LinkedStack<T> &s)
{
    int n,i,m;
    cout<<"输入要创建的栈的元素个数:";
    is>>n;
    cout<<endl;
    cout<<"输入栈中元素:";
    for(i=0;i<n;i++)
    {
        is>>m;
        s.Push(m);
    }
    return is;

}
template <class T>
ostream& operator<<(ostream &os,LinkedStack<T> &s)                    //重载<<运算符
{
    os<<"栈中元素个数为："<<s.getSize()<<endl;
    Node<T> *p=s.top->next;
    int i=0;
    while(p)
    {os<<++i<<":"<<p->data<<endl;
    p=p->next;
    }
    return os;
}


int main()
{
    LinkedStack<int> s;
    cin>>s;
    cout<<"输出创建的栈：";
    cout<<s;

    cout<<"此时栈顶元素为:"<<s.getTop()<<endl<<endl;
    s.Push(s.getSize());
    cout<<"压入栈长到栈中:"<<endl;
    cout<<"此时栈顶元素为:"<<s.getTop()<<endl;
    cout<<"出三次栈并依次输出栈顶元素"<<s.Pop();
    cout<<" "<<s.Pop()<<" ";
    cout<<s.Pop()<<endl;
    //不能写成cout<<s.Pop<<" "<<s.Pop()<<" "<<s.Pop()<<endl;  否则输出顺序恰好相反
    //cout<<"输出现在的栈："<<s;
    s.makeEmpty();
    cout<<"置空栈后栈的长度:"<<s.getSize()<<endl;
    return 0;
}
template <class T>
LinkedStack<T>::LinkedStack()            //初始化栈
{
    cout<<"构造函数执行"<<endl;
    top=new Node<T>;                    //创建头结点，返回给top指针
    top->next=NULL;
}
template <class T>
void LinkedStack<T>::Push(const T&x)            //插入元素，插在头结点*top与开始结点之间
{
    Node<T> *s;
    s=new Node<T>;
    s->data=x;
    s->next=top->next;
    top->next=s;
    return ;
}
template <class T>
T LinkedStack<T>::Pop()                         //退栈并得到栈顶元素
{
    T x;
    assert(top->next!=NULL);
    Node<T> *p;
    p=top->next;
    top->next=p->next;
    x=p->data;
    delete p;
    return x;
}
template <class T>
T LinkedStack<T>::getTop()                       //得到栈顶元素
{
    T x;
    assert(top->next!=NULL);
    x=top->next->data;
    return x;
}
template <class T>
int LinkedStack<T>::getSize()const                       //得到链式栈的长度
{
    int n=0;
    if(top->next==NULL) return 0;
    Node<T> *p=top->next;
    while(p)
    {
        n++;
        p=p->next;
    }
    return n;
}

template <class T>
void LinkedStack<T>::makeEmpty()
{
    if(top->next==NULL) return ;
    Node<T> *p=top->next,*q=p->next;
    while(1)
    {
        delete p;
        p=q;
        if(p==NULL) break;
        q=q->next;
    }
    top->next=NULL;
    return ;
}





