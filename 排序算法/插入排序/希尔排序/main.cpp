//希尔排序  不稳定 复杂度未知，取决于增量gap
#include <iostream>
#define Max 100
using namespace std;

void ShellSort(int A[],int n)
{
    int gap=n;
    int i,j,temp;

    do
    {
        gap=gap/3+1;
        for(i=gap;i<n;i++)                     //各子序列交替处理
        {
                if(A[i]<A[i-gap])              //如果插入的元素A[i]逆序
                {
                    temp=A[i];                 //保存插入的元素temp
                    j=i-gap;
                    //调整顺序
                    do{
                        A[j+gap]=A[j];
                        j=j-gap;
                    }while(j>=0&&temp<A[j]);
                    A[j+gap]=temp;
                }

        }

    }while(gap>1);                           //gap=1时跳出（但实际上gap=1已经进行排序了）

}
int main()
{
    int A[Max],n,i;
    cout<<"请输入初始数据的个数: ";
    cin>>n;
    cout<<endl<<"请输入初始数据: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    ShellSort(A,n);
    cout<<endl<<"排序后的数据:";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

}
