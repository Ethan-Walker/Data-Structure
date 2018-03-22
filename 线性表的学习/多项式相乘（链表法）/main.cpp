#include <iostream>
using namespace std;
struct Node{
    double coef;    //系数
    int exp;         // 指数
    Node *next;
};
Node* InitLink ()
{
    Node *head;
    head=new Node;
    head->next=NULL;
    return head;
}
void Mul(Node *head1,Node *head2,Node *head3)
{
    int Max,k,i;  //乘积多项式的最高阶
    Max=head1->next->exp+head2->next->exp;
    double *result=new double[Max+1];
    for(i=0;i<Max+1;i++) result[i]=0;
    Node *p=head1->next,*q;
    while(p)
    {
        q=head2->next;
        while(q)
        {
            k=p->exp+q->exp;
            result[k]=result[k]+p->coef*q->coef;
            q=q->next;
        }
     p=p->next;
    }
    for(i=0;i<=Max;i++)
        if(result[i]!=0)
    {
        p=new Node;
        p->exp=i;
        p->coef=result[i];
        p->next=head3->next;
        head3->next=p;
    }
    return ;
}
Node* Add(Node *head1,Node *head2,Node *head4);
void sort(Node *head);
void ShowLink(Node *head);


int main()
{
    Node *head1,*head2,*head3,*head4,*p,*q,*s;
    int m,n,i;
    p=head1=InitLink();
    q=head2=InitLink();
    head3=InitLink();
    head4=InitLink();
    cin>>m;
        for(i=0;i<m;i++)
        {
            s=new Node;
            cin>>s->coef>>s->exp;
            p->next=s;
            s->next=NULL;
            p=s;
        }
    cin>>n;
    for(i=0;i<n;i++)
    {
        s=new Node;
        cin>>s->coef>>s->exp;
        q->next=s;
        s->next=NULL;
        q=s;
    }
    sort(head1);
    sort(head2);
    Mul(head1,head2,head3);
    Add(head1,head2,head4);
    ShowLink(head3);
    ShowLink(head4);
    return 0;
}
void sort(Node *head)
{
    double x;
    int y;
    Node *p,*q;
    p=head->next;
    while(p->next)
    {
        q=p->next;
        while(q)
        {
            if(p->exp<q->exp)
            {
                x=p->coef;
                p->coef=q->coef;
                q->coef=x;
                y=p->exp;
                p->exp=q->exp;
                q->exp=y;

            }
           q=q->next;

        }
    p=p->next;
    }
     return ;
}
void ShowLink(Node *head)
{
    Node *p;
    p=head->next;
    if(p==NULL) {cout<<"0 0"<<endl;return ;}
    while(p)
    {
        if(p->coef!=0) {
        if(p->next!=NULL)
        cout<<p->coef<<" "<<p->exp<<" ";
        else cout<<p->coef<<" "<<p->exp;
        }
        p=p->next;
    }
    cout<<endl;
    return ;
}


Node* Add(Node *head1,Node *head2,Node *head4)
{
       Node *p,*q,*s,*x=head4;
       p=head1->next;
       q=head2->next;
       while(p&&q)
       {
           if(p->exp>q->exp)
           {
               s=p->next;
               x->next=p;
               x=p;
               x->next=NULL;
               p=s;
           }
           else if(p->exp==q->exp)
               {
                   if((p->coef+q->coef)!=0)
                   {
                       s=p->next;
                       p->coef+=q->coef;
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
        return head4;

}

