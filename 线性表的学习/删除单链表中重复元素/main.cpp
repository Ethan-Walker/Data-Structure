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
Node* DeleteSame(Node *L)
{
    cout<<"���ڽ���ɾ�������е��ظ�Ԫ��..."<<endl;
    Node *p,*q,*r;
    p=L->next;
    while(p)             //p���ڱ�������
    {
        q=p;
        while(q->next)         //q����p����Ľ�㣬����p��ֵ�Ƚ�
                    {
            if(q->next->data==p->data)   //��q�ĺ�һ�����p���ʱ
            {
                r=q->next;          //r������Ҫɾ���Ľ��
                q->next=r->next;     //��Ҫɾ���Ľ��ǰ����������
                delete r;           //ɾ������Ľ��
            }
            else q=q->next;
        }
        p=p->next;                 //q������������۲��Ƿ����ظ�Ԫ��
    }
    return L;

}
void ShowLink(Node *L)
{
    cout<<"��ʾ���������н������ݣ�";
    Node *p;
    p=L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
   Node *L;
   L=Create();
   ShowLink(L);
   DeleteSame(L);
   cout<<"ɾ���ɹ���"<<endl;
   ShowLink(L);
    return 0;
}
