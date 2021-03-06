//快速排序（改进版）  元素较少时直接调用插入排序 稳定 O(nlog2 n)
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#define Max 20000
#define Cutoff 10      //设定选择进行快速排序、插入排序的临界值
using namespace std;
//直接插入排序  （当数据元素个数较少时调用）
void InsertSort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        if(A[i]<A[i-1])
        {
            temp=A[i];
            j=i-1;
            do
            {
                A[j+1]=A[j];
                j--;
            }while(j>=0&&temp<A[j]);
            A[j+1]=temp;
        }

    }
}
//交换两个数
void Swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
    return ;
}
//取pivot（基准、主元）函数（取头、中、尾的中位数）
int Median3(int A[],int left,int right)
{
    int mid=(left+right)/2;
    if(A[left]>A[mid])   Swap(A[left],A[mid]);
    if(A[left]>A[right]) Swap(A[left],A[right]);
    if(A[mid]>A[right])  Swap(A[mid],A[right]);
    /*    A[left]<=A[mid]<=A[right]   */
    //选取中位数A[mid]为pivot
    Swap(A[mid],A[right-1]);  //将pivot藏到倒数第二位（最后一位一定比pivot大）
    return A[right-1];        //返回pivot
}

//快速排序
void QuickSort(int A[],int left,int right)
{

    if((right-left)>Cutoff)
    {
        //划分左右子序列阶段，同时将pivot置于正确位置
        int pivot=Median3(A,left,right);   //取主元
        int i=left-1,j=right-1;              //j为主元索引
        //按照pivot大小，分到mid左右两边
        for(;;)
        {
          while(A[++i]<pivot) {}             //i到A[i]>=pivot的位置停下
          while(A[--j]>pivot) {}             //j到A[j]<=pivot的位置停下
          if(i<j)
            Swap(A[i],A[j]);
          else break;
        }
       //i最终停在pivot正确的位置
       Swap(A[i],A[right-1]);                //将pivot交换到正确的位置

       QuickSort(A,left,i-1);                //递归处理左子序列
       QuickSort(A,i+1,right);               //递归处理右子序列

    }
    else InsertSort(A+left,right-left+1);

}

//QuickSort标准接口
void QuickSort(int A[],int n)
{
    QuickSort(A,0,n-1);
}
int main()
{

   int i,n,A[Max];
    cout<<"请输入随机产生的初始序列长度: ";
    cin>>n;
    srand(unsigned(time(NULL)));
    cout<<"随机产生的序列为:"<<endl;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%10000;
        cout<<left<<setw(5)<<A[i]<<" ";

     }
    QuickSort(A,0,n-1);
    cout<<endl<<"按从小到大排序后的序列: "<<endl;
    for(i=0;i<n;i++)
        cout<<setw(6)<<A[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
