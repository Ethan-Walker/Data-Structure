#include <iostream>
#include "MaxHeap.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define Max 100
using namespace std;

int main()
{
    int A[Max],i=0,n,m,k;
    cout<<"�������ʼ�����ѵĳ��ȣ�";
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
    cout<<endl;
    MaxHeap h(A,n);             //��ʼ������һ������
    cout<<"��������: "<<endl;
    h.Traverse();


    cout<<endl<<"������Ҫ����Ľ��:";
    cin>>m;
    h.Insert(m);


    cout<<"ɾ����㣺"<<endl;
    k=h.RemoveMax();
    cout<<endl<<"ɾ����Ԫ��Ϊ�� "<<k<<endl;



    h.HeapSort();
    cout<<endl<<"����С��������: ";
    h.Traverse();
    return 0;
}
