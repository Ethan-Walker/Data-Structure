#include <iostream>
#include <iomanip>
#define M 0x7ffffff
#define DefaultSize 100
using namespace std;

template <class T>
void Swap(T &a,T &b)
{
    T t;
    t=a;
    a=b;
    b=t;
    return ;
}
struct Element
{
    char name;
    int price;
    int link;
    Element(char na='\0',int pr=0):name(na),price(pr),link(0){}
    friend ostream& operator<<(ostream &os,Element &x);
};
ostream& operator<<(ostream &os,Element &x)
{
    os<<left<<setw(6)<<x.name<<setw(6)<<x.price<<setw(6)<<x.link<<endl;
    return os;
}

class staticLinkList
{
private:
    Element *Vector;
    int MaxSize,currentSize;
public:
    staticLinkList(int sz=DefaultSize):MaxSize(sz),currentSize(0)
    {
        Vector=new Element[sz];
    }
    ~staticLinkList(){delete []Vector;}
    void Initial();
    void InsertSort();
    void Print();
    void Print1();
    void DeepSort();
};

//初始化创建静态链表
void staticLinkList::Initial()
{
    cout<<"请输入书的总数：";
    int n;
    cin>>n;
    currentSize=n+1;
    if(currentSize>MaxSize-1);
        {
            MaxSize=currentSize+1;
            Vector=new Element[MaxSize+1];
        }
    cout<<"请输入每本书的名称以及其价格："<<endl;
    Vector[0].name=NULL;

    for(int i=1;i<currentSize;i++)
    {
        cin>>Vector[i].name>>Vector[i].price;   //输入price、name
        Vector[i].link=i;                       //每个元素起始link为i
    }
}

//插入排序，仅仅将各元素link域按price从小到大的顺序链接起来
void staticLinkList::InsertSort()
{
    Vector[0].price=M;
    Vector[0].link=1;
    Vector[1].link=0;                      // 形成只有一个元素的循环链表

    for(int i=2;i<currentSize;i++)
    {
        int p=Vector[0].link;
        int prev=0;                       //p的前驱
        while(Vector[p].price<=Vector[i].price)  //循环找链入位置
        {
            prev=p;
            p=Vector[p].link;
        }
        Vector[prev].link=i;
        Vector[i].link=p;                  //结点i链入prev和p之间
    }
}

//已排好顺序的静态链表的链接顺序，由一个环组成
//按照这个环的顺序对元素进行物理排序
void staticLinkList::DeepSort()
{
    int i=1;
    int head=Vector[0].link;
    Element temp;
    while(head!=0)
    {
        temp=Vector[head];
        Vector[head]=Vector[i];
        Vector[i]=temp;
        Vector[i].link=head;
        head=temp.link;
        i++;
        while(head<i&&head>0) head=Vector[head].link;//i已处理过

    }

}

void staticLinkList::Print()
{
    cout<<left<<setw(6)<<"书名"<<setw(6)<<"价格"<<setw(6)<<"link"<<endl;
    int p=Vector[0].link;
    while(p!=0)
    {
        cout<<Vector[p];
        p=Vector[p].link;
    }
}
void staticLinkList::Print1()
{
    cout<<left<<setw(6)<<"书名"<<setw(6)<<"价格"<<setw(6)<<"link"<<endl;
    for(int i=1;i<currentSize;i++)
        cout<<Vector[i];
}

int main()
{
    staticLinkList sl;
    sl.Initial();
    sl.InsertSort();
    cout<<"只对链接顺序排序后:"<<endl;
    sl.Print();
    sl.DeepSort();
    cout<<"对元素进行物理排序后:"<<endl;
    sl.Print1();

    return 0;
}
