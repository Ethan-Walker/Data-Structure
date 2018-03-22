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
Node* DeleteSame(Node *L)
{
    cout<<"现在进行删除链表中的重复元素..."<<endl;
    Node *p,*q,*r;
    p=L->next;
    while(p)             //p用于遍历链表
    {
        q=p;
        while(q->next)         //q遍历p后面的结点，并与p数值比较
                    {
            if(q->next->data==p->data)   //当q的后一结点与p相等时
            {
                r=q->next;          //r保存需要删掉的结点
                q->next=r->next;     //需要删除的结点前后结点相连接
                delete r;           //删除保存的结点
            }
            else q=q->next;
        }
        p=p->next;                 //q再往后遍历，观察是否还有重复元素
    }
    return L;

}
void ShowLink(Node *L)
{
    cout<<"显示链表中所有结点的数据：";
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
   cout<<"删除成功。"<<endl;
   ShowLink(L);
    return 0;
}
