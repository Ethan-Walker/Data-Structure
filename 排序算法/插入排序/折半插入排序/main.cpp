//����������  �ȶ� O(nlog2 n)
#include <iostream>
using namespace std;

void Traverse(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
//�۰��������
void BinaryInsertSort(int A[],int n)
{
    int i,j,left=0,right,temp,mid,k;
    for(i=1;i<n;i++)
    {
        temp=A[i];                      //Ҫ����Ԫ��
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
    cout<<"���������������ݸ���:";
    cin>>n;
    cout<<"����������������:";
    for(i=0;i<n;i++)
        cin>>A[i];
    BinaryInsertSort(A,n);
    cout<<endl<<"���������飺";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
        return 0;

}
