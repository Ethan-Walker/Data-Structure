//ϣ������  ���ȶ� ���Ӷ�δ֪��ȡ��������gap
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
        for(i=gap;i<n;i++)                     //�������н��洦��
        {
                if(A[i]<A[i-gap])              //��������Ԫ��A[i]����
                {
                    temp=A[i];                 //��������Ԫ��temp
                    j=i-gap;
                    //����˳��
                    do{
                        A[j+gap]=A[j];
                        j=j-gap;
                    }while(j>=0&&temp<A[j]);
                    A[j+gap]=temp;
                }

        }

    }while(gap>1);                           //gap=1ʱ��������ʵ����gap=1�Ѿ����������ˣ�

}
int main()
{
    int A[Max],n,i;
    cout<<"�������ʼ���ݵĸ���: ";
    cin>>n;
    cout<<endl<<"�������ʼ����: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    ShellSort(A,n);
    cout<<endl<<"����������:";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

}
