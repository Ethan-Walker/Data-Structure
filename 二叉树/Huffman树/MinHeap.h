#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED
//×îÐ¡¶Ñ
#include "Node.h"
#define DefaultSize 50
template <class T>
class MinHeap
{
private:
    T *heap;
    int currentSize;
    void SiftUp(int start);
    void SiftDown(int start,int over);
public:
    MinHeap():currentSize(0){ heap=new T[DefaultSize];}
    ~MinHeap(){currentSize=0;}
    bool Insert(const T &x);
    bool RemoveMin(T &x);
    bool IsEmpty(){return (currentSize==0)?true:false;}
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
    int j=start,i=(j-1)/2;
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
bool MinHeap<T>::RemoveMin(T &x)
{
    if(!IsEmpty())
    {
        x=heap[0];
        heap[0]=heap[currentSize-1];
        currentSize--;
        SiftDown(0,currentSize-1);
        return true;
    }
    else return false;
}

#endif // MINHEAP_H_INCLUDED
