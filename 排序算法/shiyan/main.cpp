#include <iostream>
#include <stdlib.h>
#include <time.h>
#define Max 100
using namespace std;

int main()
{
   int i,n,A[Max];
   cout<<"������Ҫ�������Ԫ�صĸ���: ";
   cin>>n;                          //�������Ԫ�ظ���
   srand( (unsigned)time( NULL ) );
   for(i=0;i<n;i++)
      A[i]=rand()%100;
    cout<<"������ɵ�����:"<<endl;
      for(i=0;i<n;i++)
        cout<<A[i]<<" ";
      cout<<endl;
   QuickSort(A,0,n-1);
   cout<<"�����Ľ��:"<<endl;
   for(i=0;i<n;i++)
    cout<<A[i]<<" ";
   cout<<endl;
    return 0;
}
