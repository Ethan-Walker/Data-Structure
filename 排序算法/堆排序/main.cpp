//��С�ѣ����ڲ������õ����ǴӴ�С��˳��
//���ѣ����ڲ������õ����Ǵ�С�����˳��
#include <iostream>
#include "MinHeap.h"
using namespace std;
#define Max 20
int main()
{
    int A[Max],i=0,n,m,k;
    cout<<"�������ʼ���ѵĳ��ȣ�";
    cin>>n;
    cout<<"������Ҫ�����Ķѵ����ݣ���f6/ctrl+Z����:";
    for(i=0;i<n;i++)
        cin>>A[i];
    MinHeap h(A,n);             //��ʼ������һ����
    h.Traverse();
    cout<<"������Ҫ����Ľ��:";
    cin>>m;
    h.Insert(m);
    cout<<"�������:";
    h.Traverse();
    h.RemoveMin(k);
    cout<<endl<<"ɾ����Ԫ��Ϊ�� "<<k<<endl;
    cout<<endl<<"ɾ������"<<endl;
    h.Traverse();
    h.HeapSort(A,n);
    cout<<endl<<"��������Ԫ�أ��Ӵ�С��: ";
    h.Traverse();
    cout<<endl<<"����С����˳��";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
