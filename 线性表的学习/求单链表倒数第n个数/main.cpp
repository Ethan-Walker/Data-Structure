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
    cout<<"����������:"<<endl;
    cout<<"��������Ҫ��������ĳ���:";
    cin>>n;
    cout<<endl;
    int A[MaxSize];
    cout<<"��������Ҫ��������������:";
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
    cout<<"��ʾ�����е����ݣ�";
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
ElemType Findlastth(Node *head,int i)          //��Ѱ�����е�����N����
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
    cout<<"��������Ҫ�ҵ��������ڼ�����:";
    cin>>i;
    cout<<"��Ҫ�ҵ���Ϊ��"<<Findlastth(head,i)<<endl;
    return 0;
}
