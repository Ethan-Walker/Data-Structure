//这般插入排序  稳定 O(nlog2 n)
#include <iostream>
using namespace std;

void Traverse(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
//折半插入排序
void BinaryInsertSort(int A[],int n)
{
    int i,j,left=0,right,temp,mid,k;
    for(i=1;i<n;i++)
    {
        temp=A[i];                      //要插入元素
        left=0;
        right=i-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(temp<A[mid]) right=mid-1;
            else left=mid+1;

        }
        for(k=i-1;k>=left;k--)
            {
                A[k+1]=A[k];

            }
        A[left]=temp;

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
    BinaryInsertSort(A,n);
    cout<<endl<<"排序后的数组：";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
        return 0;

}
