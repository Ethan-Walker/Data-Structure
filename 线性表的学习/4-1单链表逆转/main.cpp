#include <stdio.h>
#include <iostream>
#define MAX 1000
using namespace std;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode next;
} ;
typedef PtrToNode List;

List Read();
void  Print(List L){
    L=L->next;
   while(L->next!=NULL)
   {      e
      printf("%d ",L->Data);
       L=L->next;
   }
   printf("%d\n",L->Data);
   return ;
}

List Reverse(List L);

int main()
{
    List L1,L2;
    L1=Read();
    Print(L1);
    L2=Reverse(L1);

    Print(L2);

    return 0;
}
//头插法翻转原链表//List Reverse(List L);
//头插法创建新链表并将原链表中的值赋给新链表
//List Reverse(List L)
 List Reverse(List head)
 {
      List first,scend,third;
      first=head->next;      if(first==NULL) {cout<<"空链表"<<endl;return head;}
      scend=first->next;
      if(scend==NULL){cout<<"单节点不必反转"<<endl;return head;}
      while(scend)
      {
          third=scend->next;              //保存即将逆转结点scend的下一个结点地址
          scend->next=first;                //逆转scend的next指针,指向first
          first=scend;                      //将first scend 依次后移
          scend=third;
        }

        head->next->next=NULL;            //原来的开始结点现在为尾结点,next置空
        head->next=first;                  //first现在指向原来的尾结点,原来的尾结点现在是开始结点
        return head;

 }

List Read(){
    int n,i;
    int *p;
    p=new int[10];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&p[i]);
    List head,q,s;
    head=new Node;
    q=new Node;
    head->next=q;
    q->Data=p[0];
    for(i=1;i<n;i++)
    {
        s=new Node;
        s->Data=p[i];
        q->next=s;
        q=s;
    }
    q->next=NULL;
    return head;
}

/*List Reverse(List L){
    if(L==NULL) return NULL;
    List p,q,head;
    head=L;
    q=p=head->next;
    if(p==NULL) return head;
    head->next=NULL;             //head结点后为空
    while(p)
    {
       q=q->next;             //q结点为正操作结点p的后一个节点
       p->next=head->next;   //每次将p结点插到头结点和开始节点之间，同时head->next=NULL,即将NUll的值赋给p->next;
       head->next=p;          //再将头结点L指向p结点
       p=q;
    }
    return head;
}  */
/*List Reverse(List L)
{00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
    List head,p;
    head=new Node;        //创建新链表必须要新建一个结点
    head->next=NULL;       //链表置空
    //依次将L的第一个结点放到新链表的开始结点位置
    while(L->next)
    {
        p=head->next;            //保存head的后续结点
        head->next=L->next;      //将L的第一个结点放到新链表的开始结点位置
        L->next=L->next->next;    //从L中摘除该结点，使后面的结点成为L的开始结点
        head->next->next=p;       //head指向开始结点，再指向之前保存的后续结点
    }
    delete(L);              //释放原头结点，并返回新链表的头指针
    return head;
}*/
