#include <iostream>
using namespace std;
typedef int ElemType;
#define MaxSize 20
struct Seqlist{
    ElemType data[MaxSize];
    int length;
};
void initial(Seqlist &L)
{
    cout<<"���ڴ����µ�˳��� "<<endl;
    cout<<"�����봴����˳���ĳ��ȣ�";
    cin>>L.length;
    int i;
    cout<<endl<<"������˳��������е�����:";
    for(i=0;i<L.length;i++)
        cin>>L.data[i];
    return ;
}
void DeleteSame(Seqlist &L)
{
    cout<<"����ɾ��˳������ظ���Ԫ��..."<<endl;
    int i,j,k;
    for(i=0;i<L.length-1;i++)             //i����˳���
    {
        for(j=i+1;j<L.length;j++)         //j����i֮���˳���Ԫ�أ���ÿ����iλ���бȽ�
            if(L.data[i]==L.data[j])
        {
            for(k=j;k<L.length-1;k++)     //�����ظ�Ԫ�أ�����λ�����Ԫ��ȫ��һ������
                L.data[k]=L.data[k+1];
            L.length--;                   //ɾ��Ԫ�غ�˳����ȼ�1
        }
    }
    return ;
}
void ShowSeqlist(Seqlist L)
{
    cout<<"��ʾ˳���";
    int i;
    for(i=0;i<L.length;i++)
        cout<<L.data[i]<<" ";
    cout<<endl;
}
int main()
{
    Seqlist L;
    initial(L);
    ShowSeqlist(L);
    DeleteSame(L);
    cout<<"ɾ���ɹ���"<<endl;
    ShowSeqlist(L);

    return 0;
}
