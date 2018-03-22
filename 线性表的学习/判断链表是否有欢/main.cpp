#include <iostream>
using namespace std;
typedef int ElemType;
struct Node{
    ElemType data;
    Node *next;
};
Node* Create()
{
    Node *head,*p,*q;
    head=new Node;
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
    p->next=head->next->next;
    cout<<endl<<"链表创建成功"<<endl;
    return head;
}
//利用快慢指针，设两个工作指针，一个快一个慢，如果有环的话，它们必然会在某点相遇
bool JudgeCircle(Node *head)
{
    Node *p,*q;
    p=q=head;
    while(p->next!=NULL&&q->next!=NULL)
    {
        p=p->next;
        if(q->next!=NULL)
        q=q->next->next;
        if(p==q) return 1;
    }
    return 0;
}
//设两个工作指针p，q，p总是向前走，q每次都从头开始走，对于每个结点，看P走的步数是否和q一样。如果狐仙不一样的情况，则说明有环
bool JudgeCircle(Node *head)
{
    Node *p,*q;
    p=q=head;
    int step1=0,step2=0;
    while(p->next!=NULL)
    {
     q=head;
     step2=0;
     step1++;
     while(q)
     {
         step2++;
         if(q==p)
            if(step1==step2) break;
            else if(step1!=step2) return 1;
         q=q->next;
     }
     p=p->next;
    }
    return 0;
}
int main()
{
    int i;
    Node *head;
    head=Create();
    i=JudgeCircle(head);
    cout<<i<<endl;
    return 0;
}
