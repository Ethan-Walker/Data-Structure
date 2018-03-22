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

//��ʼ��������̬����
void staticLinkList::Initial()
{
    cout<<"���������������";
    int n;
    cin>>n;
    currentSize=n+1;
    if(currentSize>MaxSize-1);
        {
            MaxSize=currentSize+1;
            Vector=new Element[MaxSize+1];
        }
    cout<<"������ÿ����������Լ���۸�"<<endl;
    Vector[0].name=NULL;

    for(int i=1;i<currentSize;i++)
    {
        cin>>Vector[i].name>>Vector[i].price;   //����price��name
        Vector[i].link=i;                       //ÿ��Ԫ����ʼlinkΪi
    }
}

//�������򣬽�������Ԫ��link��price��С�����˳����������
void staticLinkList::InsertSort()
{
    Vector[0].price=M;
    Vector[0].link=1;
    Vector[1].link=0;                      // �γ�ֻ��һ��Ԫ�ص�ѭ������

    for(int i=2;i<currentSize;i++)
    {
        int p=Vector[0].link;
        int prev=0;                       //p��ǰ��
        while(Vector[p].price<=Vector[i].price)  //ѭ��������λ��
        {
            prev=p;
            p=Vector[p].link;
        }
        Vector[prev].link=i;
        Vector[i].link=p;                  //���i����prev��p֮��
    }
}

//���ź�˳��ľ�̬���������˳����һ�������
//�����������˳���Ԫ�ؽ�����������
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
        while(head<i&&head>0) head=Vector[head].link;//i�Ѵ����

    }

}

void staticLinkList::Print()
{
    cout<<left<<setw(6)<<"����"<<setw(6)<<"�۸�"<<setw(6)<<"link"<<endl;
    int p=Vector[0].link;
    while(p!=0)
    {
        cout<<Vector[p];
        p=Vector[p].link;
    }
}
void staticLinkList::Print1()
{
    cout<<left<<setw(6)<<"����"<<setw(6)<<"�۸�"<<setw(6)<<"link"<<endl;
    for(int i=1;i<currentSize;i++)
        cout<<Vector[i];
}

int main()
{
    staticLinkList sl;
    sl.Initial();
    sl.InsertSort();
    cout<<"ֻ������˳�������:"<<endl;
    sl.Print();
    sl.DeepSort();
    cout<<"��Ԫ�ؽ������������:"<<endl;
    sl.Print1();

    return 0;
}
