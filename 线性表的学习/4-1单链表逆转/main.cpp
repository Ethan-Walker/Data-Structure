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
//ͷ�巨��תԭ����//List Reverse(List L);
//ͷ�巨������������ԭ�����е�ֵ����������
//List Reverse(List L)
 List Reverse(List head)
 {
      List first,scend,third;
      first=head->next;      if(first==NULL) {cout<<"������"<<endl;return head;}
      scend=first->next;
      if(scend==NULL){cout<<"���ڵ㲻�ط�ת"<<endl;return head;}
      while(scend)
      {
          third=scend->next;              //���漴����ת���scend����һ������ַ
          scend->next=first;                //��תscend��nextָ��,ָ��first
          first=scend;                      //��first scend ���κ���
          scend=third;
        }

        head->next->next=NULL;            //ԭ���Ŀ�ʼ�������Ϊβ���,next�ÿ�
        head->next=first;                  //first����ָ��ԭ����β���,ԭ����β��������ǿ�ʼ���
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
    head->next=NULL;             //head����Ϊ��
    while(p)
    {
       q=q->next;             //q���Ϊ���������p�ĺ�һ���ڵ�
       p->next=head->next;   //ÿ�ν�p���嵽ͷ���Ϳ�ʼ�ڵ�֮�䣬ͬʱhead->next=NULL,����NUll��ֵ����p->next;
       head->next=p;          //�ٽ�ͷ���Lָ��p���
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
    head=new Node;        //�������������Ҫ�½�һ�����
    head->next=NULL;       //�����ÿ�
    //���ν�L�ĵ�һ�����ŵ�������Ŀ�ʼ���λ��
    while(L->next)
    {
        p=head->next;            //����head�ĺ������
        head->next=L->next;      //��L�ĵ�һ�����ŵ�������Ŀ�ʼ���λ��
        L->next=L->next->next;    //��L��ժ���ý�㣬ʹ����Ľ���ΪL�Ŀ�ʼ���
        head->next->next=p;       //headָ��ʼ��㣬��ָ��֮ǰ����ĺ������
    }
    delete(L);              //�ͷ�ԭͷ��㣬�������������ͷָ��
    return head;
}*/
