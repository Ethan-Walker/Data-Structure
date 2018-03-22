#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
class LinkList{
private:
    Node *head;
    int Size(Node *a);
    int Max(Node *a);
    int Sum(Node *a);
    double Average(Node *a);
public:
    LinkList();
    void Create();
    int Size(){return Size(head->next);}
    int Max(){return Max(head->next);}
    int Sum(){return Sum(head->next);}
    int Average(){return Average(head->next);}

};
LinkList::LinkList()
{
    head=new Node;
    head->next=NULL;
}
void LinkList::Create()
{
    int n,i;
    cout<<"请输入创建链表的长度：";
    cin>>n;
    cout<<endl;
    cout<<"请输入链表中数据:";
    Node *p,*q;
    q=head;
    while(n--)
    {
        p=new Node;
        cin>>p->data;
        p->next=NULL;
        q->next=p;
        q=p;
    }
}
int LinkList::Size(Node *a)
{
    if(a==NULL) return 0;
    return 1+Size(a->next);
}

int LinkList::Max(Node *a)
{
    if(a==NULL) return -1000;
    return (a->data>=Max(a->next)?a->data:Max(a->next));
}
int LinkList::Sum(Node *a)
{
    if(a->next==NULL) return a->data;
    return a->data+Sum(a->next);
}
double LinkList::Average(Node *a)
{
    int t=Sum(a);
    int n=Size(a);
    return (t*1.0)/n;
}
int main()
{
    LinkList s;
    s.Create();
    cout<<"Size"<<s.Size()<<endl;
    cout<<"Max="<<s.Max()<<endl;
    cout<<"Average="<<s.Average()<<endl;
    return 0;
}
