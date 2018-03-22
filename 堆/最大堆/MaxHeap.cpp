#include <iostream>
#include <iomanip>
#include "MaxHeap.h"
using namespace std;
MaxHeap::MaxHeap(int A[],int n)
{
    currentSize=n;
    MaxSize=(n>DefaultSize)?n:DefaultSize;
    heap=new int[MaxSize];
    for(int i=0;i<n;i++)
        heap[i]=A[i];
    int position=(currentSize-2)/2;
    while(position>=0)
    {
        SiftDown(position,currentSize-1);
        position--;
    }
}
void MaxHeap::SiftDown(int start,int over)
{
    int t;
    int i=start,j=2*i+1;
    while(j<=over)
    {
        if(j<over&&heap[j+1]>heap[j]) j++;
        if(heap[i]>=heap[j]) break;
        else
        {
            t=heap[i],heap[i]=heap[j];heap[j]=t;
            cout<<left<<"调整"<<setw(3)<<t<<"结点 : ";
            cout<<setw(3)<<t<<"与"<<setw(3)<<heap[i]<<"交换,堆变成：";
            Traverse();
            i=j;j=2*i+1;
        }
    }
}
void MaxHeap::SiftUp(int start)
{
    int j=start,i=(j-1)/2;
    int t;
    while(i>=0)
    {
        if(heap[j]>heap[i])
        {
            t=heap[j];heap[j]=heap[i];heap[i]=t;
            cout<<left<<"调整"<<setw(3)<<t<<"结点 : ";
            cout<<setw(3)<<t<<"与"<<setw(3)<<heap[j]<<"交换,堆变成：";
            Traverse();
            j=i;
            i=(j-1)/2;
        }
        else break;
    }
}

//删除并返回
int MaxHeap::RemoveMax()
{
    int x;
    x=heap[0];
    heap[0]=heap[currentSize-1];
    currentSize--;
    SiftDown(0,currentSize-1);

    return x;
}
void MaxHeap::Insert(const int x)
{
    if(currentSize==MaxSize) {cout<<"堆满"<<endl;return ;}
    heap[currentSize]=x;
    currentSize++;
    SiftUp(currentSize-1);

    return ;
}

void MaxHeap::Traverse()
{
    for(int i=0;i<currentSize;i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}

//堆变成从小到大的序列
void MaxHeap::HeapSort()
{
    int i,t;
    for(i=currentSize-1;i>=0;i--)
    {
        t=heap[0];heap[0]=heap[i];heap[i]=t;
        SiftDown(0,i-1);
    }
}











