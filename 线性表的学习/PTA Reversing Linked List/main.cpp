#include <iostream>
#include <cstring>
#define Max 100000
using namespace std;
struct Node{
    char address[6];
   long order;
    char address_[6];
    Node *next;
};
Node* InitLink();
long Size(Node *head);
Node* Transfer(Node *head,long circle,long length)
{
   long n,i,cnt;
   n=length/circle;
   Node *first,*second,*third,*p,*s;
   p=head;
   first=head->next;
   second=first->next;
   for(i=0;i<n;i++)
  {
       cnt=1;
       while(cnt<circle)
    {
       third=second->next;
      // strcpy(third->address_,second->address)
       second->next=first;
       first=second;
       second=third;
       cnt++;

   }    if(i==n-1) {
        p->next->next=second;
        p->next=first;
        break;
    }

        s=p->next;
        p->next->next=second;
        p->next=first;
        p=s;
        first=second;
       second=second->next;  }
  return head;


}
void ChangeAddress_(Node *head)
{
     Node *p=head->next,*q=head->next;
     while(q->next)
     {    q=q->next;
     strcpy(p->address_,q->address);
          p=p->next;
     }

    strcpy(p->address_,"-1");
    return ;
}
void ShowLink(Node *head);
int main()
{
    Node *p[Max];
    Node *head,*q;
    head=InitLink();
  q=head;

    long amount,circle,i,length;

    char addr[6];
    cin>>addr>>amount>>circle;
    strcpy(q->address_,addr);
    for(i=0;i<amount;i++)

        {
            p[i]=new Node;
            cin>>p[i]->address>>p[i]->order>>p[i]->address_;
        }
    for(i=0;i<amount;)
    {
       if(strcmp(q->address_,p[i]->address)==0)
        { q->next=p[i];
          p[i]->next=NULL;
          q=p[i];
        i=0;
        }
        else i++;
        if(strcmp(q->address_,"-1")==0) break;
    }
    //cout<<"显示创建的链表："<<endl;
   // ShowLink(head);
    length=Size(head);
    head=Transfer(head,circle,length);
    ChangeAddress_(head) ;
   // cout<<"翻转之后的链表："<<endl;
    ShowLink(head);

    return 0;
}

Node* InitLink()
{
    Node *head;
    head=new Node;
    head->next=NULL;
    return head;
}
long Size(Node *head)
{
   long n=0;
  Node *p;
  p=head->next;
  while(p)
  {
      n++;
      p=p->next;
  }
  return n;
}
void ShowLink(Node *head)
{
    Node *p;
    p=head->next;
    while(p)
    {
       cout<<p->address<<" "<<p->order<<" "<<p->address_<<endl;
       p=p->next;
    }
    return ;
}
