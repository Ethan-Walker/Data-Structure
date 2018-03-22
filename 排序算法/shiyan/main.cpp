#include <iostream>
#include <stdlib.h>
#include <time.h>
#define Max 100
using namespace std;

int main()
{
   int i,n,A[Max];
   cout<<"请输入要随机生成元素的个数: ";
   cin>>n;                          //随机生成元素个数
   srand( (unsigned)time( NULL ) );
   for(i=0;i<n;i++)
      A[i]=rand()%100;
    cout<<"随机生成的数据:"<<endl;
      for(i=0;i<n;i++)
        cout<<A[i]<<" ";
      cout<<endl;
   QuickSort(A,0,n-1);
   cout<<"排序后的结果:"<<endl;
   for(i=0;i<n;i++)
    cout<<A[i]<<" ";
   cout<<endl;
    return 0;
}
