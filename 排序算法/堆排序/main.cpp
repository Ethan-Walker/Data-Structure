//最小堆，堆内部排序后得到的是从大到小的顺序
//最大堆，堆内部排序后得到的是从小到大的顺序
#include <iostream>
#include "MinHeap.h"
using namespace std;
#define Max 20
int main()
{
    int A[Max],i=0,n,m,k;
    cout<<"请输入初始化堆的长度：";
    cin>>n;
    cout<<"请输入要创建的堆的数据，以f6/ctrl+Z结束:";
    for(i=0;i<n;i++)
        cin>>A[i];
    MinHeap h(A,n);             //初始化构造一个堆
    h.Traverse();
    cout<<"请输入要插入的结点:";
    cin>>m;
    h.Insert(m);
    cout<<"插入结点后:";
    h.Traverse();
    h.RemoveMin(k);
    cout<<endl<<"删除的元素为： "<<k<<endl;
    cout<<endl<<"删除结点后："<<endl;
    h.Traverse();
    h.HeapSort(A,n);
    cout<<endl<<"排序后堆中元素（从大到小）: ";
    h.Traverse();
    cout<<endl<<"按从小到大顺序：";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
