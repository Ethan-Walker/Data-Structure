#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
//╤сап
template <class T>
struct QNode
{
    T data;
    QNode *next;
    QNode():next(NULL){}
    QNode(T _data):data(_data),next(NULL){}
};
template <class T>
class Queue
{
private:
    QNode<T> *front_,*rear;
public:
    Queue():front_(NULL),rear(NULL){}
    bool EnQueue(const T &x);
    bool DeQueue(T &x);
    T getFront();
    T getRear();
    int getSize();
    bool IsEmpty();

};

template <class T>
bool Queue<T>::EnQueue(const T &x)
{
   if(front_==NULL)
   {
       rear=front_=new QNode<T>(x);
       return true;

   }
   else{
    rear->next=new QNode<T>(x);
    if(rear->next==NULL) return false;
    rear=rear->next;

   }
   return true;
}

template <class T>
bool Queue<T>::DeQueue(T &x)
{
    if(IsEmpty()) return false;
    else
    {
       QNode<T> *p=front_;
       x=front_->data;
       front_=front_->next;
       delete p;
       return true;
    }
}

template <class T>
T Queue<T>::getFront()
{
   return front_->data;
}
template <class T>
T Queue<T>::getRear()
{
    return rear->data;
}
template <class T>
int Queue<T>::getSize()
{
    if(front_==NULL) return 0;
    if(front_==rear&&front_!=NULL) return 1;
    int n=2;
    QNode<T> *current=front_;
    while(current->next!=rear)
    {
        n++;
        current=current->next;
    }
    return n;
}
template <class T>
bool Queue<T>::IsEmpty()
{
    if(front_==NULL)
        return true;
    return false;
}


#endif // QUEUE_H_INCLUDED
