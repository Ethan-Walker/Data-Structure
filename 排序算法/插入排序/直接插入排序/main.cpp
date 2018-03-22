//直接插入排序 稳定 O(n^2)
//插入一个元素x，前面的数据已经排好序，x依次从末尾向开始比较，比其（设为y）小，用temp保存x的值，则将y的值赋给后面
//y前移一位，再重复上述过程，直到x>=y终止排序

#include <iostream>
#define Max 30
using namespace std;

void InsertSort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)            //从第1位开始插入（第0位不用排序），到第n-1位
    {
        if(A[i]<A[i-1])         //比较插入的元素、前面排好序的序列最后一位（比其小则执行交换操作，否则直接插入）
    {
        temp=A[i],j=i-1;        //temp保存插入的数据，j指向插入数据的前一位
        do
        {
            A[j+1]=A[j];
            j--;

        }while(j>=0&&temp<A[j]);
        A[j+1]=temp;
    }
    }
}
int main()
{
    int A[Max],n,i;
    cout<<"请输入初始数据的个数: ";
    cin>>n;
    cout<<endl<<"请输入初始数据: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    InsertSort(A,n);
    cout<<endl<<"排序后的数据:";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
