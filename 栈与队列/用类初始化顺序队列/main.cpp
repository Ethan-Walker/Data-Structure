#include <iostream>
#define Max 100
using namespace std;
template <class T>
class SeqQueue{
public:
    SeqQueue(){MakeEmpty();}
    void MakeEmpty();
    bool EnQueue(T x);
    bool DeQueue(T &x);
    T getFront();
    bool IsEmpty();
    bool IsFull();
    int getSize();
    T getRear();
private:
    T data[Max];
    int front_;
    int rear;
};

int main()
{
    SeqQueue<int> s;
    int n,length,rear,front;
    while(cin>>n)
    {
        s.EnQueue(n);
    }
    length=s.getSize();
    s.DeQueue(front);
    cout<<"ɾ����Ԫ��Ϊ:"<<front<<endl;
    cout<<"����Ԫ��Ϊ:"<<s.getFront()<<endl;
    cout<<"��βԪ��Ϊ:"<<s.getRear()<<endl;
    length=s.getSize();
    cout<<"��ʱ���еĳ���Ϊ:"<<length<<endl;
    s.EnQueue(length);
    cout<<"��ʱ��βԪ��Ϊ:"<<s.getRear()<<endl;
    s.MakeEmpty();
    if(s.IsEmpty()) cout<<"ջ�ɹ��ÿ�"<<endl;
    return 0;
}
template <class T>
void SeqQueue<T>::MakeEmpty()
{
    front_=rear=0;
    return;
}
template <class T>
bool SeqQueue<T>::EnQueue(T x)
{
    if(IsFull()) return false;
    data[rear]=x;
    rear=(rear+1)%Max;
    return true;
}
template <class T>
bool SeqQueue<T>::DeQueue(T &x)               // ע�����ɾ��Ԫ��ʱfront�±�ҲҪ+1
{
    if(IsEmpty()) return false;
    x=data[front_];
    front_=(front_+1)%Max;
    return true;
}
template <class T>
T SeqQueue<T>::getFront()
{

    return data[front_];
}
template <class T>
T SeqQueue<T>::getRear()
{
    return data[rear-1];
}
template <class T>
int SeqQueue<T>::getSize()
{
    int n;
    n=(rear-front_+Max)%Max;             //ע��õ����г��ȹ�ʽ��rear-front+Max��%Max
    return n;
}
template <class T>
bool SeqQueue<T>::IsEmpty()
{
    if(rear==front_) return true;
    return false;

}
template <class T>
bool SeqQueue<T>::IsFull()
{
    if((rear+1)%Max==front_) return true;         //ע��ջ����������ջ�յ��������
    return false;
}




