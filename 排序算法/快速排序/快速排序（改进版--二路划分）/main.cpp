//�������򣨸Ľ��棩  Ԫ�ؽ���ʱֱ�ӵ��ò������� �ȶ� O(nlog2 n)
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#define Max 20000
#define Cutoff 10      //�趨ѡ����п������򡢲���������ٽ�ֵ
using namespace std;
//ֱ�Ӳ�������  ��������Ԫ�ظ�������ʱ���ã�
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
//����������
void Swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
    return ;
}
//ȡpivot����׼����Ԫ��������ȡͷ���С�β����λ����
int Median3(int A[],int left,int right)
{
    int mid=(left+right)/2;
    if(A[left]>A[mid])   Swap(A[left],A[mid]);
    if(A[left]>A[right]) Swap(A[left],A[right]);
    if(A[mid]>A[right])  Swap(A[mid],A[right]);
    /*    A[left]<=A[mid]<=A[right]   */
    //ѡȡ��λ��A[mid]Ϊpivot
    Swap(A[mid],A[right-1]);  //��pivot�ص������ڶ�λ�����һλһ����pivot��
    return A[right-1];        //����pivot
}

//��������
void QuickSort(int A[],int left,int right)
{

    if((right-left)>Cutoff)
    {
        //�������������н׶Σ�ͬʱ��pivot������ȷλ��
        int pivot=Median3(A,left,right);   //ȡ��Ԫ
        int i=left-1,j=right-1;              //jΪ��Ԫ����
        //����pivot��С���ֵ�mid��������
        for(;;)
        {
          while(A[++i]<pivot) {}             //i��A[i]>=pivot��λ��ͣ��
          while(A[--j]>pivot) {}             //j��A[j]<=pivot��λ��ͣ��
          if(i<j)
            Swap(A[i],A[j]);
          else break;
        }
       //i����ͣ��pivot��ȷ��λ��
       Swap(A[i],A[right-1]);                //��pivot��������ȷ��λ��

       QuickSort(A,left,i-1);                //�ݹ鴦����������
       QuickSort(A,i+1,right);               //�ݹ鴦����������

    }
    else InsertSort(A+left,right-left+1);

}

//QuickSort��׼�ӿ�
void QuickSort(int A[],int n)
{
    QuickSort(A,0,n-1);
}
int main()
{

   int i,n,A[Max];
    cout<<"��������������ĳ�ʼ���г���: ";
    cin>>n;
    srand(unsigned(time(NULL)));
    cout<<"�������������Ϊ:"<<endl;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%10000;
        cout<<left<<setw(5)<<A[i]<<" ";

     }
    QuickSort(A,0,n-1);
    cout<<endl<<"����С��������������: "<<endl;
    for(i=0;i<n;i++)
        cout<<setw(6)<<A[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
