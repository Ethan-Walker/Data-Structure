#include "MinHeap.h"
#include <iostream>
#include <iomanip>
using namespace std;
//���캯����ͨ����������鴴����
MinHeap::MinHeap(int A[],int n)
{
    currentSize=n;
    MaxHeapSize=(n>DefaultSize)?n:DefaultSize;
    heap=new int[MaxHeapSize];                   //�����Ѵ洢�ռ䣬����������ָ�����ָ��
    for(int i=0;i<n;i++)
        heap[i]=A[i];                            //���ƶ�����
    int position=(currentSize-2)/2;              //Ѱ�����һ����Ҷ�ӽڵ�
    while(position>=0)                            //�Ե������������γɶ�
    {
        siftDown(position,currentSize-1);        //�ֲ����ϵ����»�����
        position--;                              //��ǰ��һλ��������
    }

}
//siftDown: �ӽ��start��ʼ���������һ��Ԫ�أ�������Ϊֹ���������±Ƚϣ������Ů��ֵС�ڸ�����ֵ��
//          ��С��ֵ�ϸ����������²�Ƚϣ�������һ�����Ͼֲ�����Ϊ��С��
void MinHeap::siftDown(int start,int over)
{
    int i=start,j=2*i+1,t;                              //jΪi������Ů�±�
    while(j<=over)                                      //j����over������ѭ��
    {
        if(j<over&&heap[j+1]<heap[j]) j++; //���jû��over��˵��i������Ů��������Ů��С��jָ������Ůλ��,����jָ������Ů�н�С��λ��
        if(heap[i]<=heap[j])   break;                   //�������������������С��ֵ��С������������ѭ����ֹ
        else {
                t=heap[i];heap[i]=heap[j];heap[j]=t;   //���򽻻���������ֵ
                cout<<left<<"����"<<setw(3)<<t<<"��� : ";
                cout<<setw(3)<<t<<"��"<<setw(3)<<heap[i]<<"����,�ѱ�ɣ�";
                Traverse();
                i=j;j=2*i+1;                           //i��jλ�ã�j��j������Ů��
             }
    }

}

//�����㵽���еĶ��У�����siftUp����
bool MinHeap::Insert(const int& x)
{
    if(currentSize==MaxHeapSize) return false;        //����
    heap[currentSize]=x;                              //��������ĩβ����x
    currentSize++;                                   //�ѵĳ���+1
    siftUp(currentSize-1);                              //���뵱ǰҪ�����Ľ��λ��

    return true;
}
//siftUp: ��start�������±�Ϊ0 ��Ԫ��λ�ã��������ϱȽϣ���Ů��ֵС�ڸ�����ֵ
//        ������³��������ϵ���Ϊ��С�ѣ���ԭ�ȴ����õ���С�� ���µĽ�����Ϊ�µ���С�ѣ�
void MinHeap::siftUp(int start)
{
    int j=start,i=(j-1)/2,t;                            //j=2*i+1;����jΪ��/����Ůλ�ã�i=(j-1)/2 �õ���ʼ���Ǹ�����±�
    while(i>=0)
    {
        if(heap[i]<=heap[j])  break;                  //�����ֵС��������,����ѭ��
        else {
                t=heap[j];heap[j]=heap[i];heap[i]=t;  //������С���븸��㽻��
                cout<<left<<"����"<<setw(3)<<t<<"��� : ";
                cout<<setw(3)<<t<<"��"<<setw(3)<<heap[j]<<"����,�ѱ�ɣ�";
                Traverse();
                j=i;i=(j-1)/2;                        //j�Ƶ������i��λ�ã�i��i�ĸ����
             }
    }
}

//Removeɾ���Ѷ���С��Ԫ��,���������һ��Ԫ���Ƶ��Ѷ�������siftDown�������µ�������С��
bool MinHeap::RemoveMin(int &x)
{
    if(currentSize==0) return false;                  //�ѿ�
    x=heap[0];                                        //����Ѷ�Ԫ��
    heap[0]=heap[currentSize-1];                      //���������һ��Ԫ���Ƶ�ջ��
    currentSize--;                                    //�ѵĳ���-1
    siftDown(0,currentSize-1);                                      //ֻҪ��0λ�õ�������
    return true;
}
void MinHeap::Traverse()
{
    int i;
    for(i=0;i<currentSize;i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}
void MinHeap::HeapSort(int A[],int &n)
{
    int t,i,j;
    for(i=currentSize-1;i>=0;i--)                        //��С���������յõ����ǴӴ�С��˳��
    {
        t=heap[0];heap[0]=heap[i];heap[i]=t;
        siftDown(0,i-1);
    }
    for(i=currentSize-1,j=0;i>=0;j++,i--)
             A[j]=heap[i];
    n=currentSize;
    return ;
}





