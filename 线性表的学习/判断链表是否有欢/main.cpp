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
    cout<<"��������Ҫ������������:";
    cin>>n;
    cout<<endl;
    cout<<"������������ÿ����㱣�������:";
    for(i=0;i<n;i++)
    {
        cin>>k;
     p=new Node;
     p->data=k;
     q->next=p;
     q=p;
    }
    p->next=head->next->next;
    cout<<endl<<"�������ɹ�"<<endl;
    return head;
}
//���ÿ���ָ�룬����������ָ�룬һ����һ����������л��Ļ������Ǳ�Ȼ����ĳ������
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
//����������ָ��p��q��p������ǰ�ߣ�qÿ�ζ���ͷ��ʼ�ߣ�����ÿ����㣬��P�ߵĲ����Ƿ��qһ����������ɲ�һ�����������˵���л�
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
