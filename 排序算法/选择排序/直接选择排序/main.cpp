//ѡ������  O(n^2)  ���ȶ�

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
    cout<<"���������������ݸ���:";
    cin>>n;
    cout<<"����������������:";
    for(i=0;i<n;i++)
        cin>>A[i];
    SelectSort(A,n);
    cout<<"���������飺";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
        return 0;
}
