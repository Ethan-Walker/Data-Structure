//ֱ�Ӳ������� �ȶ� O(n^2)
//����һ��Ԫ��x��ǰ��������Ѿ��ź���x���δ�ĩβ��ʼ�Ƚϣ����䣨��Ϊy��С����temp����x��ֵ����y��ֵ��������
//yǰ��һλ�����ظ��������̣�ֱ��x>=y��ֹ����

#include <iostream>
#define Max 30
using namespace std;

void InsertSort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)            //�ӵ�1λ��ʼ���루��0λ�������򣩣�����n-1λ
    {
        if(A[i]<A[i-1])         //�Ƚϲ����Ԫ�ء�ǰ���ź�����������һλ������С��ִ�н�������������ֱ�Ӳ��룩
    {
        temp=A[i],j=i-1;        //temp�����������ݣ�jָ��������ݵ�ǰһλ
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
    cout<<"�������ʼ���ݵĸ���: ";
    cin>>n;
    cout<<endl<<"�������ʼ����: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    InsertSort(A,n);
    cout<<endl<<"����������:";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
