//冒泡排序  稳定　O(n^2)
#include <iostream>
using namespace std;
//冒泡排序，注意与选择排序的区别
void BubbleSort(int A[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
       for(j=n-1;j>i;j--)
        if(A[j-1]>A[j])
       {
           t=A[j-1];
           A[j-1]=A[j];
           A[j]=t;
       }
    }

}

//改进后的冒泡排序，tag：标记某趟冒泡是否发生了逆序和交换，若没有发生，则说明已经排序好，终止排序
void BubbleSort2(int A[],int n)
{
    int i,j,t,tag;
    for(i=0;i<n-1;i++)
    {
        tag=0;
        for(j=n-1;j>i;j--)
        {
            if(A[j-1]>A[j])
            {
                t=A[j-1];
                A[j-1]=A[j];
                A[j]=t;
                tag=1;
            }

         }
        if(tag==0) return ;                          //tag=0，表明逆序数为0 ，即排序已完成
    }
}

int main()
{
    int A[600],i,n;
    cout<<"请输入数组中数据个数:";
    cin>>n;
    cout<<"请输入数组中数据:";
    for(i=0;i<n;i++)
        cin>>A[i];
    BubbleSort2(A,n);
    cout<<"排序后的数组：";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
    return 0;
}
