#include <iostream>
using namespace std;
typedef int ElemType;
struct Node
{
    ElemType data;
    struct Node *next;
};
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
Node* BuilListloop(Node *head,int num)   //在第num个结点处建环，使得尾结点指向第num个结点
{
    Node *p=head->next,*q;
    int i;
    for(i=1;i<num;i++)
        p=p->next;
    q=p;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;
    return head;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
