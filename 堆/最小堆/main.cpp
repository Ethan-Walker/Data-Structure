#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "MinHeap.h"
#define Max 50
using namespace std;

int main()
{
    int A[Max],i=0,n,m,k;
    cout<<"�������ʼ����С�ѵĳ��ȣ�";
    cin>>n;
    /*
    cout<<"������Ҫ�����Ķѵ����ݣ���f6/ctrl+Z����:";
    for(i=0;i<n;i++)
        cin>>A[i];
    */
    srand(unsigned(time(NULL)));
    cout<<"�������������: "<<endl;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%100;
        cout<<left<<setw(4)<<A[i]<<" ";
    }
    cout<<endl<<endl;
    MinHeap h(A,n);             //��ʼ������һ������
    cout<<"������С��: "<<endl;
    h.Traverse();


    cout<<endl<<"������Ҫ����Ľ��:";
    cin>>m;
    h.Insert(m);


    cout<<"ɾ����㣺"<<endl;
    h.RemoveMin(k);
    cout<<endl<<"ɾ����Ԫ��Ϊ�� "<<k<<endl;

    h.HeapSort(A,n);
    cout<<endl<<"���Ӵ�С�����: ";
    h.Traverse();
    return 0;

    return 0;
}
