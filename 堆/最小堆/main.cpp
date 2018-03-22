#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "MinHeap.h"
#define Max 50
using namespace std;

int main()
{
    int A[Max],i=0,n,m,k;
    cout<<"请输入初始化最小堆的长度：";
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
    cout<<endl<<endl;
    MinHeap h(A,n);             //初始化构造一个最大堆
    cout<<"遍历最小堆: "<<endl;
    h.Traverse();


    cout<<endl<<"请输入要插入的结点:";
    cin>>m;
    h.Insert(m);


    cout<<"删除结点："<<endl;
    h.RemoveMin(k);
    cout<<endl<<"删除的元素为： "<<k<<endl;

    h.HeapSort(A,n);
    cout<<endl<<"按从大到小排序后: ";
    h.Traverse();
    return 0;

    return 0;
}
