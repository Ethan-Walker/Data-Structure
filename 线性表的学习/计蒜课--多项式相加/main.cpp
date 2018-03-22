#include <iostream>
using namespace std;
struct Node{
    double xishu;
    int zhishu;
    Node *next;
};
Node* InitLink()
{
    Node *head;
    head=new Node;
    head->next=NULL;
    return head;
}
Node* Add(Node *head1,Node *head2,Node *head3)
{
       Node *p,*q,*s,*x=head3;
       p=head1->next;
       q=head2->next;
       while(p&&q)
       {
           if(p->zhishu>q->zhishu)
           {
               s=p->next;
               x->next=p;
               x=p;
               x->next=NULL;
               p=s;
           }
           else if(p->zhishu==q->zhishu)
               {
                   if((p->xishu+q->xishu)!=0)
                   {
                       s=p->next;
                       p->xishu+=q->xishu;
                       x->next=p;
                       x=p;
                       x->next=NULL;
                       p=s;
                       q=q->next;
                   }
                   else {
                         p=p->next;
                         q=q->next;
                        }
               }
               else {
                     s=q->next;
                     x->next=q;

                     x=q;
                     x->next=NULL;
                     q=s;
               }

       }

        if(q){x->next=q;}
        if(p){x->next=p;}
        return head3;

}

void ShowLink(Node *head)
{
    Node *p;
    p=head->next;
    while(p)
    {
        if(p->xishu!=0)
        cout<<p->xishu<<" "<<p->zhishu<<endl;
        p=p->next;
    }
    return;
}
void  sort(Node *head);
int main()
{

    Node *head1,*p,*head2,*q;
    Node *head3;
    head3=InitLink();
    p=head1=InitLink();
    q=head2=InitLink();
    Node *A[10000],*B[10000];
    int m,n,i;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        A[i]=new Node;
        cin>>A[i]->xishu>>A[i]->zhishu;
        A[i]->next=p->next;
        p->next=A[i];
    }
    for(i=0;i<n;i++)
    {
        B[i]=new Node;
        cin>>B[i]->xishu>>B[i]->zhishu;
        B[i]->next=q->next;
        q->next=B[i];
    }

    sort(head1);
    sort(head2);
    head3=Add(head1,head2,head3);
    cout<<"显示计算后的多项式链表："<<endl;
    ShowLink(head3);

    return 0;
}




void  sort(Node *head) //将链表中结点按指数从大到小的顺序排列
{
   int x;
   double y;
   Node *p=head->next,*q;
   while(p->next!=NULL)
   {
       q=p->next;
       while(q!=NULL)
       {
           if(p->zhishu<q->zhishu) {
            x=p->zhishu;
            p->zhishu=q->zhishu;
            q->zhishu=x;
            y=p->xishu;
            p->xishu=q->xishu;
            q->xishu=y;
           }
           else if(p->zhishu==q->zhishu)
           {
               p->xishu+=q->xishu;

           }
           q=q->next;
       }
       p=p->next;
   }
   return;
}
