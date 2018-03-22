#include <iostream>
#include <stack>
#include <queue>
#include "AVL.h"
#define Max 100
using namespace std;
void AVLTree::Initial()
{
    int n,i,A[Max];
    cout<<"�����ʼ��������AVL���Ľ������: ";
    cin>>n;
    cout<<"�������ʼ���ڵ����ݣ� "<<endl;
    for(int i=0;i<n;i++)
        {
            cin>>A[i];
            Insert(A[i]);
        }

}

AVLNode* AVLTree::Search(int x,AVLNode *ptr)
{
    if(ptr==NULL) return NULL;
    if(x==ptr->data) return ptr;
    else if(x>ptr->data)
        return Search(x,ptr->rchild);
    else if(x<ptr->data)
        return Search(x,ptr->lchild);
}
//����������������������
/*
   *
 *   */
void AVLTree::RotateL(AVLNode *&ptr)
{
    AVLNode *subL=ptr;               //��ת�����ĸ����
    ptr=subL->rchild;                //ptrָ����ת����
    subL->rchild=ptr->lchild;
    ptr->lchild=subL;
    ptr->bf=subL->bf=0;
}
//�ҵ���������������������
/*      *
      *
    *   *
*/
void AVLTree::RotateR(AVLNode *&ptr)
{
    AVLNode *subR=ptr;
    ptr=subR->lchild;
    subR->lchild=ptr->rchild;
    ptr->rchild=subR;
    subR->bf=ptr->bf=0;
}
//��������������
/*
    *
  *
    *
*/
void AVLTree::RotateLR(AVLNode *&ptr)
{
    AVLNode *subR=ptr,*subL=ptr->lchild;
    ptr=subL->rchild;
    subL->rchild=ptr->lchild;
    ptr->lchild=subL;
    if(ptr->bf<=0) subL->bf=0;
    else subL->bf=-1;
    subR->lchild=ptr->rchild;
    ptr->rchild=subR;
    if(ptr->bf==-1) subR->bf=1;
    else subR->bf=0;
    ptr->bf=0;
}
//������������
/*
     *
        *
     *
*/
void AVLTree::RotateRL(AVLNode *&ptr)
{
    AVLNode *subL=ptr,*subR=ptr->lchild;
    ptr=subR->lchild;
    subR->lchild=ptr->rchild;
    ptr->rchild=subR;
    if(ptr->bf>=0) subR->bf=0;
    else subR->bf=1;
    subL->rchild=ptr->lchild;
    ptr->lchild=subL;
    if(ptr->bf==1) subL->bf=-1;
    else subL->bf=0;
    ptr->bf=0;
}

//������
bool AVLTree::Insert(int x,AVLNode *&ptr)
{
    AVLNode *p=ptr,*pr=NULL,*q;
    int d;
    stack<AVLNode*> st;
    while(p!=NULL)                       //Ѱ�Ҳ���λ��
    {
        if(x==ptr->data) return false;
        pr=p;st.push(pr);                //��ջ�������·��
        if(x<p->data) p=p->lchild;
        else p=p->rchild;
    }
    p=new AVLNode(x);
    if(p==NULL) {cout<<"�洢�ռ䲻��"<<endl;return false;}
    if(pr==NULL) {ptr=p;return true;}    //�������½���Ϊ�����
    if(x<pr->data) pr->lchild=p;         //�½�����
    else pr->rchild=p;
    while(st.empty())
    {
        pr=st.top();
        st.pop();                        //��ջ���˳������
        if(p==pr->lchild) pr->bf--;        //����������ƽ������
        else pr->bf++;

        if(pr->bf==0) break;             //��һ�������ƽ���˳�
        if(pr->bf==-1||pr->bf==1)        //�ڶ������
            p=pr;                        //pָ�򸸽�㣬��ǰѭ�����۲��Ƿ��з�ƽ����
        else                             //�����������pr->bf==+-2
          {
              d=(pr->bf<0)?-1:1;        //����˫��ת�ı�־
              if(p->bf==d)              //ͬ�ţ�����ת
              {
                  if(d==-1) RotateR(pr);//ͬ��������ת
                  else RotateL(pr);     //ͬ��������ת

              }
              else                       //��ţ�˫��ת
              {
                  if(d==-1) RotateLR(pr);// -+ ���������ת
                  else RotateRL(pr);     // +- ���Һ�����ת

              }
              break;                     //�������ϵ���
          }
    }
    if(st.empty())  ptr=pr;             //���������ĸ����
    else                                //�м���������
    {
        q=st.top();
        if(q->data>pr->data)  q->lchild=pr;
        else q->rchild=pr;
    }
    return true;
}
void AVLTree::InOrder(AVLNode *subtree)
{
    if(subtree!=NULL)
    {
        InOrder(subtree->lchild);
        cout<<subtree->data<<" ";
        InOrder(subtree->rchild);
    }
}
//�������
void AVLTree::LevelOrder(AVLNode *subtree)
{
    queue<AVLNode*> q;
    AVLNode *temp;
    q.push(subtree);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->lchild!=NULL) q.push(temp->lchild);
        if(temp->rchild!=NULL) q.push(temp->rchild);
    }
}


