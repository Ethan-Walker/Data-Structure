//表排序，稳定
//适用于每个元素为一个集合的排序
#include <iostream>
#include <iomanip>
#define DefaultSize 100
using namespace std;
template <class T>
void Swap(T &data1,T &data2)
{
    T t;
    t=data1;
    data1=data2;
    data2=t;
}
//结点定义
struct Element
{
    int price;              //每个元素中的内容集合,假设按照价格排序
    char name;
    int link;
    Element():link(0){}     //构造函数
    Element(int p,char na):price(p),name(na){} //构造函数
    friend ostream& operator<<(ostream &os,Element &x);

};
ostream& operator<<(ostream &os,Element &x)
{

    os<<left<<setw(6)<<x.name<<setw(6)<<x.price<<setw(6)<<x.link<<endl;
    return os;
}
//静态链表的类定义
class staticLinkList
{
private:
    Element *Vector;                 //存储待排序元素的向量
    int MaxSize,currentSize;         //最大元素个数，当前元素个数
public:
    staticLinkList(int sz=DefaultSize):MaxSize(sz),currentSize(0)
    {Vector=new Element[sz];}     //构造函数，分配大小为sz的元素空间
    void Initial();
    void Sort();                     //仅仅是将静态链表的链接顺序排序，元素物理顺序并没有改变
    void Print();
    void DeepSort();                 //按照已排好序的静态链表的连接顺序，对所有元素的物理顺序进行排序

};

//初始化创建静态链表
void staticLinkList::Initial()
{
    cout<<"请输入书的总数：";
    int n;
    cin>>n;
    currentSize=n;
    if(currentSize>MaxSize);
        {
            MaxSize=currentSize;
            Vector=new Element[MaxSize];
        }
    cout<<"请输入每本书的名称以及其价格："<<endl;
    for(int i=0;i<currentSize;i++)
    {
        cin>>Vector[i].name>>Vector[i].price;   //输入price、name
        Vector[i].link=i;                       //每个元素起始link为i
    }
}

//对初始化后的元素按price插入排序
//仅仅是调整链接顺序，并没有调整元素本身的顺序
void staticLinkList::Sort()
{
    int j;
    for(int i=1;i<currentSize;i++)
    {
        j=i;
        if(Vector[Vector[j].link].price<Vector[Vector[j-1].link].price)   //注意比较price时Vector内部索引应为元素内部的link值
        do
        {
            Swap(Vector[j].link,Vector[j-1].link);
            j--;
        }while(j>0&&Vector[Vector[j].link].price<Vector[Vector[j-1].link].price);

    }
}

//原理：已排好序的静态链表中的链接顺序，有若干个独立的环组成
//细节:link[i]=i时，说明元素不用移动，每次移动后，将link[i]改为i
void staticLinkList::DeepSort()
{
     Element *temp;
     int i,p,q;
     temp=new Element;
     for(i=0;i<currentSize;i++)
     {
         if(Vector[i].link!=i)
         {
             p=i;
             q=Vector[p].link;

             //将环的起始位置复制给临时元素
             temp->name=Vector[p].name;
             temp->price=Vector[p].price;

             while(Vector[q].link!=q)
             {
                 Vector[p].name=Vector[q].name;
                 Vector[p].price=Vector[q].price;
                 Vector[p].link=p;
                 p=q;
                 q=Vector[q].link;
             }
             Vector[p].name=temp->name;
             Vector[p].price=temp->price;
             Vector[p].link=p;

         }
     }

}

//按price大小顺序输出元素（从小到大）
//沿着原来的元素顺序，访问的是元素中link指示的元素
void staticLinkList::Print()
{
    int i;
    cout<<left<<setw(6)<<"书名"<<setw(6)<<"价格"<<setw(6)<<"链接"<<endl;
    for(i=0;i<currentSize;i++)
        cout<<Vector[Vector[i].link];
    cout<<endl;
}

/*
a 21
b 15
c 13
d 16
e 22
f 17
*/
int main()
{
    staticLinkList sl;
    sl.Initial();
    cout<<"排序前: "<<endl;
    sl.Print();
    sl.Sort();
    cout<<"只改变链接后排序结果: "<<endl;
    sl.Print();
    sl.DeepSort();                         //对各元素进行物理排序
    cout<<"对元素本身排序结果: "<<endl;
    sl.Print();
    return 0;
}
