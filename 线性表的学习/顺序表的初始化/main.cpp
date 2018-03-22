#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define ok 1
#define false 0
#define maxSize 100
typedef int Status;         //Status 是变量类型，其值是函数结果状态，表示成功ok或者失败error
typedef int ElemType;       //ElemType 类型根据实际情况而定
typedef struct{
    ElemType data[maxSize];
    int length;                 //当前表的长度
}SeqList;
bool Insert(SeqList *L,int i,ElemType e )  //在L中第i个位置(data[i])插入新的元素e，L的长度加1
{
    int k;
    if(L->length==maxSize) return false;          //表满则退出
    if(i<0||i>L->length) return false;           //i的值不合理，返回错误信息
    if(i<=L->length)
    {
        for(k=L->length-1;k>=i;k--)         //将要插入元素位置后面的元素全部往后移一位
        L->data[k+1]=L->data[k];

    }
    L->data[i]=e;
    L->length++;                  //当前表的长度加1
}
//初始化顺序表
Status initList(SeqList *L)
{
    L->length=10;
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++)
        L->data[i]=rand()%100;
    return ok;
}
//遍历顺序表
void ListTraverse(SeqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        cout<<L.data[i]<<" ";
    cout<<endl;
    return ;
}
//判断表是否为空
Status IsEmpty(SeqList L)
{
    if(L.length==0)
        return ok;
    else return false;
}
//将表置空
Status MakeEmpty(SeqList *L)
{
    L->length=0;
    return ok;
}
//定位元素位置
ElemType Locate(SeqList L,ElemType x)
{
    int k;
    for(k=0;k<L.length;k++)
        if(L.data[k]==x) return k;
    return false;
}
//查找某一位置的元素
ElemType Search(SeqList L,ElemType i)
{
    return L.data[i];
}
//删除某一位置的元素
bool Delete(SeqList *L,int i)   //删除第i位元素
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
    cout<<"初始化后L.length="<<L.length<<endl;
    cout<<"遍历顺序表中的元素：";
    ListTraverse(L);
    cout<<"1.将元素19970301插入第6位之前.";
    Insert(&L,6,19970301);
    cout<<"此时得到的顺序表为：";
    ListTraverse(L);
    cout<<"此时顺序表的长度为:"<<L.length<<endl<<endl;
    cout<<"2.将元素342623插入到第十位之前。";
    Insert(&L,10,342623);
    cout<<"此时得到的顺序表为:";
    ListTraverse(L);
    cout<<"此时顺序表的长度为："<<L.length<<endl;

    cout<<"您要找第几号元素?  :";
    cin>>k;
    cout<<"您要找的元素为："<<Search(L,k)<<endl;
    cout<<"您要查找的元素：";
    cin>>k;
    cout<<"您要找的元素的位置为："<<Locate(L,k)<<endl;

    cout<<"您要删除第几号元素：";
    cin>>k;
    Delete(&L,k);
    cout<<"删除后的顺序表为:";
    ListTraverse(L);



    cout<<"清空表：\n";
    MakeEmpty(&L);
    return 0;
}
