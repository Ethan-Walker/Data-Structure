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
    p->next=NULL;
    cout<<endl<<"�������ɹ�"<<endl;
    return head;
}
Node* BuilListloop(Node *head,int num)   //�ڵ�num����㴦������ʹ��β���ָ���num�����
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
