#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef int ElemType;
struct Node
{
    ElemType data;
    struct Node *next;
};
typedef Node LinkList;
Node* Create()
{
    Node *head,*p,*q;
    head=new Node;
    head->next=NULL;
    q=head;
    int n,i;
    double k;
    cout<<"请输入您要创建的链表长度:";
    cin>>n;
    cout<<endl;
    cout<<"请输入链表中每个结点保存的数据:";
    for(i=0;i<n;i++)
    {
        cin>>k;
     p=new Node;
     p->data=k;
     q->next=p;
     q=p;
    }
    p->next=NULL;
    cout<<endl<<"链表创建成功"<<endl;
    return head;
}
bool Insert(LinkList *L,ElemType x,int i)
{
    LinkList *p,*q=L,*s;
    int k;
    for(k=0;k<i;k++)
    {
        p=q;
        q=q->next;
        if(q==NULL) return false;
    }
    s=new Node;
    s->data=x;
    s->next=q;
    p->next=s;

    return true;

}
void ShowLink(LinkList *L)
{
    Node *head,*p;
    head=L;
    p=head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return ;
}
int SearchMid(LinkList *L)
 {
    LinkList *p,*q;
    p=q=L;
    while(q->next!=NULL)
    {
        if(q->next->next!=NULL)
        {
            q=q->next->next;
            p=p->next;
        }
        else {q=q->next;
            p=p->next;
            }

    }
    return p->data;


}
int main()
{
    int k;
    LinkList *L;
    L=Create();
    cout<<"显示创建的链表：";
    ShowLink(L);
    k=SearchMid(L);
    cout<<"链表中间结点保存的数据为："<<k<<endl;

    return 0;
}
