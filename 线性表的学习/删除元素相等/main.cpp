#include <iostream>
using namespace std;
#define Max 1000
template <class T>
class SeqList{
public:

    bool Del(T x);          //删除x元素
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
    cout<<"请输入初始化顺序表的长度:"<<endl;
    cin>>length;
    cout<<"请输入表中元素值："<<endl;
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
    cout<<"遍历顺序表中元素：";
    s.Traverse();
    cout<<"请输入给定的值："<<endl;
    cin>>m;
    s.Del(m);
    cout<<"删除与"<<m<<"相同元素后的顺序表为：";
    s.Traverse();
    return 0;
}
