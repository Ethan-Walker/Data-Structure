#include <iostream>
using namespace std;
#define MaxSize 50
typedef int ElemType;
struct SeqQueue{
    ElemType data[MaxSize];
    int front;
    int rear;
};
bool InitQueue(SeqQueue *Q)     // 初始化一个空队列
{
    Q->front=0;
    Q->rear=0;
    return true;
}
bool EnQueue(SeqQueue *Q,ElemType x)
{
    if((Q->rear+1)%MaxSize==Q->front)
     {
         cout<<"栈满"<<endl;
         return false;
     }
     Q->data[Q->rear]=x;
     Q->rear=(Q->rear+1)%MaxSize;
     return true;
}
bool DeQueue(SeqQueue *Q,ElemType *x)
{
    if(Q->rear==Q->front) {cout<<"栈空"<<endl;return false;}
    *x=Q->data[Q->front];
    Q->front=(Q->front+1)%MaxSize;
    return true;
}
bool QueueTranfer(SeqQueue *Q)
{
    int *x;
    if(Q->rear==Q->front) return false;
    while(Q->front!=Q->rear)
    {

        DeQueue(Q,x);
        cout<<*x<<" ";
    }
    cout<<"遍历结束."<<endl;
    return true;
}
int main()
{
    SeqQueue Q;
    InitQueue(&Q);
    int n,i,k;
    cout<<"输入你要创建的队列的长度:";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
    EnQueue(&Q,k);
    }
     int s;
     DeQueue(&Q,&s);
     //cout<<"s="<<s<<endl;
     EnQueue(&Q,12);
     QueueTranfer(&Q);
    return 0;
}
