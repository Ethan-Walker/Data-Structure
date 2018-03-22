#include <iostream>
#define DefaultSize 20
using namespace std;

struct Node
{
    int data;
    Node *lchild,*rchild,*parent;
    Node(int _data=0):data(_data),lchild(NULL),rchild(NULL),parent(NULL){}
    bool operator<(Node &N){return data<N.data;}
    bool operator<=(Node &N){return data<=N.data;}
    bool operator>(Node &N){return data>N.data;}
    bool operator>=(Node &N){return data>=N.data;}

};
template <class T>
class MinHeap
{
private:
    T *heap;
    int currentSize;
    void SiftUp(int start);
    void SiftDown(int start,int over);
public:
    MinHeap():currentSize(0){heap=new T[DefaultSize];}
    ~MinHeap(){currentSize=0;}
    bool Insert(const T &x);
    T RemoveMin();
    bool IsEmpty(){return (currentSize==0)?true:false;}
    void Traverse();
};
template <class T>
bool MinHeap<T>::Insert(const T &x)
{
     heap[currentSize]=x;
     SiftUp(currentSize);
     currentSize++;
     return true;
}
template <class T>
void MinHeap<T>::SiftUp(int start)
{
    int j=start;
    int i=(j-1)/2;
    T t;
    while(i>=0)
    {
        if(heap[j]>=heap[i])  break;
        else
        {
            t=heap[j];
            heap[j]=heap[i];
            heap[i]=t;
            j=i;i=(j-1)/2;
        }

    }
}
template <class T>
void MinHeap<T>::SiftDown(int start,int over)
{
    T t;
    int i=start,j=2*i+1;
    while(j<=over)
    {
        if(j<over&&heap[j+1]<heap[j]) j++;
        if(heap[j]>=heap[i]) break;
        else
        {
            t=heap[j];
            heap[j]=heap[i];
            heap[i]=t;
            i=j;j=2*i+1;
        }

    }
}
template <class T>
T MinHeap<T>::RemoveMin()
{
    if(!IsEmpty())
    {
        T x=heap[0];
        heap[0]=heap[currentSize-1];
        currentSize--;
        SiftDown(0,currentSize-1);
        return x;

    }
}

template <class T>
void MinHeap<T>::Traverse()
{
    cout<<"遍历最小堆 ： ";
    for(int i=0;i<currentSize;i++)
        cout<<heap[i]<<" ";
}

int main()
{
    MinHeap<int> mh;
   int A[10],i,n;
   cin>>n;
   for(i=0;i<n;i++)
   {

    cin>>A[i];
    mh.Insert(A[i]);
   }
   mh.Traverse();

    return 0;
}
