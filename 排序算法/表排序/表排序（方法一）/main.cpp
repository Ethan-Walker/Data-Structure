//�������ȶ�
//������ÿ��Ԫ��Ϊһ�����ϵ�����
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
//��㶨��
struct Element
{
    int price;              //ÿ��Ԫ���е����ݼ���,���谴�ռ۸�����
    char name;
    int link;
    Element():link(0){}     //���캯��
    Element(int p,char na):price(p),name(na){} //���캯��
    friend ostream& operator<<(ostream &os,Element &x);

};
ostream& operator<<(ostream &os,Element &x)
{

    os<<left<<setw(6)<<x.name<<setw(6)<<x.price<<setw(6)<<x.link<<endl;
    return os;
}
//��̬������ඨ��
class staticLinkList
{
private:
    Element *Vector;                 //�洢������Ԫ�ص�����
    int MaxSize,currentSize;         //���Ԫ�ظ�������ǰԪ�ظ���
public:
    staticLinkList(int sz=DefaultSize):MaxSize(sz),currentSize(0)
    {Vector=new Element[sz];}     //���캯���������СΪsz��Ԫ�ؿռ�
    void Initial();
    void Sort();                     //�����ǽ���̬���������˳������Ԫ������˳��û�иı�
    void Print();
    void DeepSort();                 //�������ź���ľ�̬���������˳�򣬶�����Ԫ�ص�����˳���������

};

//��ʼ��������̬����
void staticLinkList::Initial()
{
    cout<<"���������������";
    int n;
    cin>>n;
    currentSize=n;
    if(currentSize>MaxSize);
        {
            MaxSize=currentSize;
            Vector=new Element[MaxSize];
        }
    cout<<"������ÿ����������Լ���۸�"<<endl;
    for(int i=0;i<currentSize;i++)
    {
        cin>>Vector[i].name>>Vector[i].price;   //����price��name
        Vector[i].link=i;                       //ÿ��Ԫ����ʼlinkΪi
    }
}

//�Գ�ʼ�����Ԫ�ذ�price��������
//�����ǵ�������˳�򣬲�û�е���Ԫ�ر����˳��
void staticLinkList::Sort()
{
    int j;
    for(int i=1;i<currentSize;i++)
    {
        j=i;
        if(Vector[Vector[j].link].price<Vector[Vector[j-1].link].price)   //ע��Ƚ�priceʱVector�ڲ�����ӦΪԪ���ڲ���linkֵ
        do
        {
            Swap(Vector[j].link,Vector[j-1].link);
            j--;
        }while(j>0&&Vector[Vector[j].link].price<Vector[Vector[j-1].link].price);

    }
}

//ԭ�����ź���ľ�̬�����е�����˳�������ɸ������Ļ����
//ϸ��:link[i]=iʱ��˵��Ԫ�ز����ƶ���ÿ���ƶ��󣬽�link[i]��Ϊi
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

             //��������ʼλ�ø��Ƹ���ʱԪ��
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

//��price��С˳�����Ԫ�أ���С����
//����ԭ����Ԫ��˳�򣬷��ʵ���Ԫ����linkָʾ��Ԫ��
void staticLinkList::Print()
{
    int i;
    cout<<left<<setw(6)<<"����"<<setw(6)<<"�۸�"<<setw(6)<<"����"<<endl;
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
    cout<<"����ǰ: "<<endl;
    sl.Print();
    sl.Sort();
    cout<<"ֻ�ı����Ӻ�������: "<<endl;
    sl.Print();
    sl.DeepSort();                         //�Ը�Ԫ�ؽ�����������
    cout<<"��Ԫ�ر���������: "<<endl;
    sl.Print();
    return 0;
}
