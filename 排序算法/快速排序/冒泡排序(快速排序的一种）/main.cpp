//ð������  �ȶ���O(n^2)
#include <iostream>
using namespace std;
//ð������ע����ѡ�����������
void BubbleSort(int A[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
       for(j=n-1;j>i;j--)
        if(A[j-1]>A[j])
       {
           t=A[j-1];
           A[j-1]=A[j];
           A[j]=t;
       }
    }

}

//�Ľ����ð������tag�����ĳ��ð���Ƿ���������ͽ�������û�з�������˵���Ѿ�����ã���ֹ����
void BubbleSort2(int A[],int n)
{
    int i,j,t,tag;
    for(i=0;i<n-1;i++)
    {
        tag=0;
        for(j=n-1;j>i;j--)
        {
            if(A[j-1]>A[j])
            {
                t=A[j-1];
                A[j-1]=A[j];
                A[j]=t;
                tag=1;
            }

         }
        if(tag==0) return ;                          //tag=0������������Ϊ0 �������������
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
    BubbleSort2(A,n);
    cout<<"���������飺";
    for(i=0;i<n;i++)
        cout<<A[i]<<"  ";
    return 0;
}
