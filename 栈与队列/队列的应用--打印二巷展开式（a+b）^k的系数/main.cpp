#include <iostream>
using namespace std;
#define Max 100
class SeqQueue
{
public:
    SeqQueue();
    void EnQueue(int x);
    int DeQueue();
    int GetFront();
    int GetRear();
    bool IsEmpty();
    bool IsFull();
    int GetSize();
private:
    int A[Max];
    int rear;
    int front_;

};
int main()
{
    int k=1,x=0,y=0,n,i,j,a,b;
    SeqQueue s;
    s.EnQueue(k);
    s.EnQueue(k);
    cout<<"输入打印的杨辉三角行数"<<endl;
    cin>>n;
    cout<<"输出前"<<n<<"行杨辉三角"<<endl;
    for(i=1;i<=n;i++)
    {
        s.EnQueue(x);
        for(j=1;j<=i+2;j++)                                //第i行有i+2个数，包括添加的0
        {
            a=s.DeQueue();
            b=a+y;
            s.EnQueue(b);
            y=a;
            if(j!=i+2) cout<<y<<" ";                        //第i+2个数为0
        }
        cout<<endl;

    }
    return 0;
}
SeqQueue::SeqQueue()
{
    rear=front_=0;
}
void SeqQueue::EnQueue(int x)
{
    A[rear]=x;
    rear=(rear+1)%Max;

}
int SeqQueue::DeQueue()
{
    int x;
    x=A[front_];
    front_=(front_+1)%Max;
    return x;
}
int SeqQueue::GetFront()
{
    return A[front_];
}
int SeqQueue::GetRear()
{
    return A[rear-1];
}
bool SeqQueue::IsEmpty()
{
    if(front_==rear) return true;
    else return false;

}
bool SeqQueue::IsFull()
{
    if((rear+1)%Max==front_) return true;
    else return false;
}
int SeqQueue::GetSize()
{
    return (rear-front_+Max)%Max;
}


