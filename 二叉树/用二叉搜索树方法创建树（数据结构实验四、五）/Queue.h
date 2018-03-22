#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
//��ʽ���ж��弰���Ա������ʵ��

//�ýṹ�嶨����н��
template <class T>
struct Node
{
    T data;                                       //������
    Node *next;
    Node(T _data=NULL):data(_data),next(NULL){}   //���캯��
};
//�������
template <class T>
class Queue
{
private:
    Node<T> *front_,*rear;                        //���ף���β
public:
    Queue():front_(NULL),rear(NULL){}             //���캯��
    ~Queue(){makeEmpty();}                        //��������
    bool EnQueue(const T &x);                     //���
    T DeQueue();                                  //���Ӳ����ض���Ԫ��
    T getFront();                                 //���ض���Ԫ��
    T getRear();                                  //���ض�βԪ��
    int getSize();                                //���ض��г���
    bool IsEmpty();                               //�ж϶����Ƿ�Ϊ��
    void makeEmpty();                             //�ÿն���

};

//���
template <class T>
bool Queue<T>::EnQueue(const T &x)
{
   if(front_==NULL)
   {
       rear=front_=new Node<T>(x);                  //�ն��У��½����Ƕ�ͷ���Ƕ�β
       return true;

   }
   else
   {
    rear->next=new Node<T>(x);                      //�ǿն���ʱ������β׷���µĽ�㲢���¶�βָ��
    if(rear->next==NULL) return false;
    rear=rear->next;
   }
   return true;
}

//����
template <class T>
T Queue<T>::DeQueue()
{
    if(IsEmpty()) return false;
    else
    {
       T x;
       Node<T> *p=front_;                            //�ݴ��ͷ���
       x=front_->data;
       front_=front_->next;                          //��ͷ����
       delete p;                                     //�ͷ�ԭ��ͷ
       return x;                                     //����ԭ��ͷԪ��
    }
}

//���ض�ͷԪ��
template <class T>
T Queue<T>::getFront()
{
   return front_->data;
}

//���ض�βԪ��
template <class T>
T Queue<T>::getRear()
{
    return rear->data;
}

//���ض��г���
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

//�ж϶����Ƿ�Ϊ��
template <class T>
bool Queue<T>::IsEmpty()
{
    if(front_==NULL)
        return true;
    return false;
}

//�ÿն���
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
