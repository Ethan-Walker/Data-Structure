#include <iostream>
using namespace std;
#define MaxSize 100
typedef int ElemType;
struct Node{
    ElemType data;
    Node *next;
};
Node* Create()
{
    int n,i;
    cout<<"创建单链表:"<<endl;
    cout<<"请输入你要创建链表的长度:";
    cin>>n;
    cout<<endl;
    int A[MaxSize];
    cout<<"请输入你要创建的链表数据:";
    for(i=0;i<n;i++)
        cin>>A[i];
    cout<<endl;
    Node *head,*p,*q;
    head=new Node;
    head->next=NULL;
    p=head;
    for(i=0;i<n;i++)
    {

        q=new Node;
        q->data=A[i];
        p->next=q;
        p=q;
    }
    q->next=NULL;
    return head;
}
void Showlink(Node *head)
{
    cout<<"显示链表中的数据：";
    Node *p=head;
    p=p->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return ;
}
ElemType Findlastth(Node *head,int i)          //找寻链表中倒数第N个数
{
    int k=i;
    Node *p,*q;
    p=q=head->next;
    while(k>1)
    {
        q=q->next;
        k--;
    }
    if(q->next==NULL) return p->data;

    while(q->next)
    {
        p=p->next;
        q=q->next;
    }
    return p->data;
}
int main()
{
    int i;
    Node *head;
    head=Create();
    Showlink(head);
    cout<<"请输入您要找的链表倒数第几个数:";
    cin>>i;
    cout<<"您要找的数为："<<Findlastth(head,i)<<endl;
    return 0;
}
