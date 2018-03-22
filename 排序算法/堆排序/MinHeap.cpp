#include "MinHeap.h"
#include <iostream>
using namespace std;
//构造函数，通过传入的数组创建堆
MinHeap::MinHeap(int A[],int n)
{
    currentSize=n;
    MaxHeapSize=(n>DefaultSize)?n:DefaultSize;
    heap=new int[currentSize];                   //创建堆存储空间，并返回数组指针给堆指针
    for(int i=0;i<n;i++)
        heap[i]=A[i];                            //复制堆数组
    int position=(currentSize-2)/2;              //寻找最后一个非叶子节点
    while(position>=0)                            //自底向上逐步扩大形成堆
    {
        siftDown(position,currentSize-1);        //局部从上到下下滑调整
        position--;                              //向前移一位继续调整
    }


}
//siftDown: 从结点start开始到数组最后一个元素（包括）为止，自上向下比较，如果子女的值小于父结点的值，
//          则小的值上浮，继续向下层比较，这样将一个集合局部调整为最小堆
void MinHeap::siftDown(int start,int over)
{
    int i=start,j=2*i+1,t;                              //j为i的左子女下标
    while(j<=over)                                      //j超过over则跳出循环
    {
        if(j<over&&heap[j+1]<heap[j]) j++; //如果j没到over即说明i有右子女，若右子女较小，j指向右子女位置,最终j指向两子女中较小的位置
        if(heap[i]<=heap[j])   break;                   //如果父结点比左右子树最小的值还小，则不做调整，循环终止
        else {
                 t=heap[i];heap[i]=heap[j];heap[j]=t;   //否则交换两个结点的值
                 i=j;j=2*i+1;                           //i到j位置，j到j的左子女处
             }
    }

}

//插入结点到已有的堆中，利用siftUp函数
bool MinHeap::Insert(const int& x)
{
    if(currentSize==MaxHeapSize) return false;        //堆满
    heap[currentSize]=x;                              //将堆数组末尾插入x
    siftUp(currentSize);                              //传入当前要调整的结点位置
    currentSize++;                                   //堆的长度+1
    return true;
}
//siftUp: 从start到数组下标为0 的元素位置，自下向上比较，子女的值小于父结点的值
//        父结点下沉，将集合调整为最小堆（将原先创建好的最小堆 与新的结点调整为新的最小堆）
void MinHeap::siftUp(int start)
{
    int j=start,i=(j-1)/2,t;                            //j=2*i+1;无论j为左/右子女位置，i=(j-1)/2 得到的始终是父结点下标
    while(i>=0)
    {
        if(heap[i]<=heap[j])  break;                  //父结点值小，不调整,跳出循环
        else {
                t=heap[i];heap[i]=heap[j];heap[j]=t;  //插入结点小，与父结点交换
                j=i;i=(j-1)/2;                        //j移到父结点i的位置，i到i的父结点
             }
    }
}

//Remove删除堆顶最小的元素,将堆中最后一个元素移到堆顶，调用siftDown函数重新调整成最小堆
bool MinHeap::RemoveMin(int &x)
{
    if(currentSize==0) return false;                  //堆空
    x=heap[0];                                        //保存堆顶元素
    heap[0]=heap[currentSize-1];                      //将堆中最后一个元素移到栈顶
    currentSize--;                                    //堆的长度-1
    siftDown(0,currentSize-1);                                      //只要从0位置调整即可
    return true;
}
void MinHeap::Traverse()
{
    cout<<"遍历堆的结果:";
    int i;
    for(i=0;i<currentSize;i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}

//堆排序，用数组A保存从小到大的排序结果，n保存数组长度
void MinHeap::HeapSort(int A[],int &n)
{
    int t,i,j;
    for(i=currentSize-1;i>=0;i--)                        //堆里面最终得到的是从大到小的顺序
    {
        t=heap[0];heap[0]=heap[i];heap[i]=t;
        siftDown(0,i-1);
    }
    for(i=currentSize-1,j=0;i>=0;j++,i--)
             A[j]=heap[i];
    n=currentSize;
    return ;
}


