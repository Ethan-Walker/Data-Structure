#include <iostream>
#include "MaxHeap.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define Max 100
using namespace std;

int main()
{
    int A[Max],i=0,n,m,k;
    cout<<"请输入初始化最大堆的长度：";
    cin>>n;
    /*
    cout<<"请输入要创建的堆的数据，以f6/ctrl+Z结束:";
    for(i=0;i<n;i++)
        cin>>A[i];
    */
    srand(unsigned(time(NULL)));
    cout<<"随机产生的序列: "<<endl;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%100;
        cout<<left<<setw(4)<<A[i]<<" ";
    }
    cout<<endl;
    MaxHeap h(A,n);             //初始化构造一个最大堆
    cout<<"遍历最大堆: "<<endl;
    h.Traverse();


    cout<<endl<<"请输入要插入的结点:";
    cin>>m;
    h.Insert(m);


    cout<<"删除结点："<<endl;
    k=h.RemoveMax();
    cout<<endl<<"删除的元素为： "<<k<<endl;



    h.HeapSort();
    cout<<endl<<"按从小到大排序: ";
    h.Traverse();
    return 0;
}
