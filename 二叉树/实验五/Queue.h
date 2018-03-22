#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
//链式队列定义及其成员函数的实现

//用结构体定义队列结点
template <class T>
struct Node
{
    T data;                                       //数据域
    Node *next;
    Node(T _data=NULL):data(_data),next(NULL){}   //构造函数
};
//定义队列
template <class T>
class Queue
{
private:
    Node<T> *front_,*rear;                        //队首，队尾
public:
    Queue():front_(NULL),rear(NULL){}             //构造函数
    ~Queue(){makeEmpty();}                        //析构函数
    bool EnQueue(const T &x);                     //入队
    T DeQueue();                                  //出队并返回队首元素
    T getFront();                                 //返回队首元素
    T getRear();                                  //返回队尾元素
    int getSize();                                //返回队列长度
    bool IsEmpty();                               //判断队列是否为空
    void makeEmpty();                             //置空队列

};

//入队
template <class T>
bool Queue<T>::EnQueue(const T &x)
{
   if(front_==NULL)
   {
       rear=front_=new Node<T>(x);                  //空队列，新结点既是队头又是队尾
       return true;

   }
   else
   {
    rear->next=new Node<T>(x);                      //非空队列时，在链尾追加新的结点并更新队尾指针
    if(rear->next==NULL) return false;
    rear=rear->next;
   }
   return true;
}

//出队
template <class T>
T Queue<T>::DeQueue()
{
    if(IsEmpty()) return false;
    else
    {
       T x;
       Node<T> *p=front_;                            //暂存队头结点
       x=front_->data;
       front_=front_->next;                          //队头后移
       delete p;                                     //释放原队头
       return x;                                     //返回原队头元素
    }
}

//返回队头元素
template <class T>
T Queue<T>::getFront()
{
   return front_->data;
}

//返回队尾元素
template <class T>
T Queue<T>::getRear()
{
    return rear->data;
}

//返回队列长度
template <class T>
int Queue<T>::getSize()
{
    if(front_==rear==NULL) return 0;
    if(front_==rear&&front_!=NULL) return 1;
    int n=2;
    Node<T> *current=front_;
    while(current->next!=rear)
    {
        n++;
    }
    return n;
}

//判断队列是否为空
template <class T>
bool Queue<T>::IsEmpty()
{
    if(front_==NULL)
        return true;
    return false;
}

//置空队列
template <class T>
void Queue<T>::makeEmpty()
{
    Node<T> *p;
    while(front_!=NULL)
    {
        p=front_;
        front_=front_->next;
        delete p;
    }
}

#endif // QUEUE_H_INCLUDED
