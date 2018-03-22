//链队列 不用考虑循环队列，满队列
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
struct Node{
    T data;
    Node *next;
};
template <class T>
class LinkedQueue;

template <class T>
istream&operator>>(istream&is,LinkedQueue<T> &s);

template <class T>
ostream&operator<<(ostream&os,LinkedQueue<T> &s);

template <class T>
class LinkedQueue
{
public:
    LinkedQueue();
    ~LinkedQueue(){front_=rear=0;}
    T getFront();
    T getRear();
    void EnQueue(T x);
    void DeQueue();
    bool IsEmpty();
    int getSize();
    friend istream&operator>> <>(istream&is,LinkedQueue<T> &s);
    friend ostream&operator<< <>(ostream&os,LinkedQueue<T> &s);
private:
    Node<T> *front_,*rear;
};
template <class T>
istream&operator>>(istream&is,LinkedQueue<T> &s)
{
    int n,i;
    T m;
    cout<<"请输入创建的队列的长度：";
    is>>n;
    cout<<endl<<"请输入创建的队列的元素：";
    for(i=0;i<n;i++)
    {is>>m;s.EnQueue(m);}
    cout<<endl;
    return is;
}
template <class T>
ostream&operator<<(ostream&os,LinkedQueue<T> &s)
{
    Node<T> *p=s.front_->next;
    os<<"队列中元素个数为:"<<s.getSize()<<endl;
    os<<"遍历队列中元素：";
    while(p)
    {
        os<<p->data<<" ";
        p=p->next;
    }
    os<<endl;
    return os;
}
int main()
{
    LinkedQueue<int> s;
    cin>>s;
    cout<<s;
    s.EnQueue(s.getSize());
    cout<<s;
    return 0;
}
template <class T>
LinkedQueue<T>::LinkedQueue()
{
    front_=new Node<T>;
    front_->next=NULL;
    rear=front_;
}
template <class T>
T LinkedQueue<T>::getFront()
{
    assert(front_==rear);
    return front_->next->data;
}
template <class T>
T LinkedQueue<T>::getRear()
{
    assert(front_==rear);
    return rear->data;
}
template <class T>
void LinkedQueue<T>::EnQueue(T x)
{
    Node<T> *p;
    p=new Node<T>;
    p->data=x;
    rear->next=p;
    p->next=NULL;
    rear=p;
}
template <class T>
void LinkedQueue<T>::DeQueue()
{
    Node<T> *p;
    p=front_->next;
    front_->next=p->next;
    delete p;
}
template <class T>
bool LinkedQueue<T>::IsEmpty()
{
    if(front_==rear) return true;
    else return false;
}
template <class T>
int LinkedQueue<T>::getSize()
{
    int n=0;
    Node<T> *p=front_->next;
    while(p)
    {
        n++;
        p=p->next;
    }
    return n;
}

