//选择排序  O(n^2)  不稳定

#include <iostream>
using namespace std;
void SelectSort(int A[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=i;j<n;j++)
         if(A[i]>A[j])
         {
             t=A[i];
             A[i]=A[j];
             A[j]=t;
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
    SelectSort(A,n);
    cout<<"排序后的数组：";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
        return 0;
}
