#include <iostream>
using namespace std;
#define Max 1000
template <class T>
class SeqList{
public:

    bool Del(T x);          //ɾ��xԪ��
    bool Initial();
    bool Traverse();
private:
    T A[Max];
    int length;

};
template <class T>
bool SeqList<T>::Initial()
{
    int i,n;
    cout<<"�������ʼ��˳���ĳ���:"<<endl;
    cin>>length;
    cout<<"���������Ԫ��ֵ��"<<endl;
    for(i=0;i<length;i++)
        cin>>A[i];
    return true;

}
template <class T>
bool SeqList<T>::Del(T x)
{
    int i,j;
    for(i=0;i<length-1;i++)
    {
           if(A[i]==x) {
                for(j=i+1;j<length;j++)
                A[j-1]=A[j];
                length--;
                i--;
                }
    }
    if(x==A[length-1]) length--;
    return true;
}
template <class T>
bool SeqList<T>::Traverse()
{

    int i;
    for(i=0;i<length;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return true;
}
int main()
{
    int m;
    SeqList<int> s;
    s.Initial();
    cout<<"����˳�����Ԫ�أ�";
    s.Traverse();
    cout<<"�����������ֵ��"<<endl;
    cin>>m;
    s.Del(m);
    cout<<"ɾ����"<<m<<"��ͬԪ�غ��˳���Ϊ��";
    s.Traverse();
    return 0;
}
