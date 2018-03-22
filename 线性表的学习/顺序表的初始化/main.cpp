#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define ok 1
#define false 0
#define maxSize 100
typedef int Status;         //Status �Ǳ������ͣ���ֵ�Ǻ������״̬����ʾ�ɹ�ok����ʧ��error
typedef int ElemType;       //ElemType ���͸���ʵ���������
typedef struct{
    ElemType data[maxSize];
    int length;                 //��ǰ��ĳ���
}SeqList;
bool Insert(SeqList *L,int i,ElemType e )  //��L�е�i��λ��(data[i])�����µ�Ԫ��e��L�ĳ��ȼ�1
{
    int k;
    if(L->length==maxSize) return false;          //�������˳�
    if(i<0||i>L->length) return false;           //i��ֵ���������ش�����Ϣ
    if(i<=L->length)
    {
        for(k=L->length-1;k>=i;k--)         //��Ҫ����Ԫ��λ�ú����Ԫ��ȫ��������һλ
        L->data[k+1]=L->data[k];

    }
    L->data[i]=e;
    L->length++;                  //��ǰ��ĳ��ȼ�1
}
//��ʼ��˳���
Status initList(SeqList *L)
{
    L->length=10;
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++)
        L->data[i]=rand()%100;
    return ok;
}
//����˳���
void ListTraverse(SeqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        cout<<L.data[i]<<" ";
    cout<<endl;
    return ;
}
//�жϱ��Ƿ�Ϊ��
Status IsEmpty(SeqList L)
{
    if(L.length==0)
        return ok;
    else return false;
}
//�����ÿ�
Status MakeEmpty(SeqList *L)
{
    L->length=0;
    return ok;
}
//��λԪ��λ��
ElemType Locate(SeqList L,ElemType x)
{
    int k;
    for(k=0;k<L.length;k++)
        if(L.data[k]==x) return k;
    return false;
}
//����ĳһλ�õ�Ԫ��
ElemType Search(SeqList L,ElemType i)
{
    return L.data[i];
}
//ɾ��ĳһλ�õ�Ԫ��
bool Delete(SeqList *L,int i)   //ɾ����iλԪ��
{
    if(L->length==0) return false;
    if(i<0||i>=L->length) return false;
    if(i==L->length-1) {L->length--;return true;}
    else for(int k=i+1;k<L->length;k++)
        L->data[k-1]=L->data[k];
    L->length--;
    return true;

}
int main()
{
    int k;
    SeqList L;
    initList(&L);
    Status i;
    cout<<"��ʼ����L.length="<<L.length<<endl;
    cout<<"����˳����е�Ԫ�أ�";
    ListTraverse(L);
    cout<<"1.��Ԫ��19970301�����6λ֮ǰ.";
    Insert(&L,6,19970301);
    cout<<"��ʱ�õ���˳���Ϊ��";
    ListTraverse(L);
    cout<<"��ʱ˳���ĳ���Ϊ:"<<L.length<<endl<<endl;
    cout<<"2.��Ԫ��342623���뵽��ʮλ֮ǰ��";
    Insert(&L,10,342623);
    cout<<"��ʱ�õ���˳���Ϊ:";
    ListTraverse(L);
    cout<<"��ʱ˳���ĳ���Ϊ��"<<L.length<<endl;

    cout<<"��Ҫ�ҵڼ���Ԫ��?  :";
    cin>>k;
    cout<<"��Ҫ�ҵ�Ԫ��Ϊ��"<<Search(L,k)<<endl;
    cout<<"��Ҫ���ҵ�Ԫ�أ�";
    cin>>k;
    cout<<"��Ҫ�ҵ�Ԫ�ص�λ��Ϊ��"<<Locate(L,k)<<endl;

    cout<<"��Ҫɾ���ڼ���Ԫ�أ�";
    cin>>k;
    Delete(&L,k);
    cout<<"ɾ�����˳���Ϊ:";
    ListTraverse(L);



    cout<<"��ձ�\n";
    MakeEmpty(&L);
    return 0;
}
