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
    cout<<"正在创建新的顺序表 "<<endl;
    cout<<"请输入创建的顺序表的长度：";
    cin>>L.length;
    int i;
    cout<<endl<<"请输入顺序表内所有的数据:";
    for(i=0;i<L.length;i++)
        cin>>L.data[i];
    return ;
}
void DeleteSame(Seqlist &L)
{
    cout<<"正在删除顺序表中重复的元素..."<<endl;
    int i,j,k;
    for(i=0;i<L.length-1;i++)             //i遍历顺序表
    {
        for(j=i+1;j<L.length;j++)         //j遍历i之后的顺序表元素，并每次与i位进行比较
            if(L.data[i]==L.data[j])
        {
            for(k=j;k<L.length-1;k++)     //遇到重复元素，将该位后面的元素全部一次左移
                L.data[k]=L.data[k+1];
            L.length--;                   //删除元素后，顺序表长度减1
        }
    }
    return ;
}
void ShowSeqlist(Seqlist L)
{
    cout<<"显示顺序表：";
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
    cout<<"删除成功。"<<endl;
    ShowSeqlist(L);

    return 0;
}
