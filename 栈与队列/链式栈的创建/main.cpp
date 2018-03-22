#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class LinkedStack;                                          //������

template <class T>                                          //ȫ�ֵ�operator<<��>>������Ҫ���ඨ��ǰ����
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
    LinkedStack();                            //��ʼ��ջ������ͷ���Ϊtopջ��λ��
    ~LinkedStack(){makeEmpty();cout<<"��������ִ��"<<endl;}                        //�����������ÿ�ջ
    void Push(const T&x);
    T Pop();
    T getTop();
    bool IsEmpty()const{return (top->next==NULL)?true:false;}
    int getSize()const;
    void makeEmpty();
    friend istream& operator>> <>(istream &is,LinkedStack<T> &s);                  //ģ�庯������ԪҪ��ʽ������ģ���β�,
                                                                                   //���<>�ڿվ��ǰѵ�ǰ���ģ�������������.
    friend ostream& operator<< <>(ostream &os,LinkedStack<T> &s);                 //<>����ʡ��

private:
    Node<T> *top;                                         //ջ��ָ��
};
template <class T>
istream& operator>>(istream &is,LinkedStack<T> &s)
{
    int n,i,m;
    cout<<"����Ҫ������ջ��Ԫ�ظ���:";
    is>>n;
    cout<<endl;
    cout<<"����ջ��Ԫ��:";
    for(i=0;i<n;i++)
    {
        is>>m;
        s.Push(m);
    }
    return is;

}
template <class T>
ostream& operator<<(ostream &os,LinkedStack<T> &s)                    //����<<�����
{
    os<<"ջ��Ԫ�ظ���Ϊ��"<<s.getSize()<<endl;
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
    cout<<"���������ջ��";
    cout<<s;

    cout<<"��ʱջ��Ԫ��Ϊ:"<<s.getTop()<<endl<<endl;
    s.Push(s.getSize());
    cout<<"ѹ��ջ����ջ��:"<<endl;
    cout<<"��ʱջ��Ԫ��Ϊ:"<<s.getTop()<<endl;
    cout<<"������ջ���������ջ��Ԫ��"<<s.Pop();
    cout<<" "<<s.Pop()<<" ";
    cout<<s.Pop()<<endl;
    //����д��cout<<s.Pop<<" "<<s.Pop()<<" "<<s.Pop()<<endl;  �������˳��ǡ���෴
    //cout<<"������ڵ�ջ��"<<s;
    s.makeEmpty();
    cout<<"�ÿ�ջ��ջ�ĳ���:"<<s.getSize()<<endl;
    return 0;
}
template <class T>
LinkedStack<T>::LinkedStack()            //��ʼ��ջ
{
    cout<<"���캯��ִ��"<<endl;
    top=new Node<T>;                    //����ͷ��㣬���ظ�topָ��
    top->next=NULL;
}
template <class T>
void LinkedStack<T>::Push(const T&x)            //����Ԫ�أ�����ͷ���*top�뿪ʼ���֮��
{
    Node<T> *s;
    s=new Node<T>;
    s->data=x;
    s->next=top->next;
    top->next=s;
    return ;
}
template <class T>
T LinkedStack<T>::Pop()                         //��ջ���õ�ջ��Ԫ��
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
T LinkedStack<T>::getTop()                       //�õ�ջ��Ԫ��
{
    T x;
    assert(top->next!=NULL);
    x=top->next->data;
    return x;
}
template <class T>
int LinkedStack<T>::getSize()const                       //�õ���ʽջ�ĳ���
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





