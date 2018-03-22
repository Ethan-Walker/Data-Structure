#include <iostream>
#include <stack>
#include <queue>
#include "AVL.h"
#define Max 100
using namespace std;
void AVLTree::Initial()
{
    int n,i,A[Max];
    cout<<"输入初始化创建的AVL树的结点总数: ";
    cin>>n;
    cout<<"请输入初始各节点数据： "<<endl;
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
//左单旋，右子树比左子树高
/*
   *
 *   */
void AVLTree::RotateL(AVLNode *&ptr)
{
    AVLNode *subL=ptr;               //旋转子树的根结点
    ptr=subL->rchild;                //ptr指向旋转轴结点
    subL->rchild=ptr->lchild;
    ptr->lchild=subL;
    ptr->bf=subL->bf=0;
}
//右单旋，左子树比右子树高
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
//先左旋，后右旋
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
//先右旋后左旋
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

//插入结点
bool AVLTree::Insert(int x,AVLNode *&ptr)
{
    AVLNode *p=ptr,*pr=NULL,*q;
    int d;
    stack<AVLNode*> st;
    while(p!=NULL)                       //寻找插入位置
    {
        if(x==ptr->data) return false;
        pr=p;st.push(pr);                //用栈记忆查找路径
        if(x<p->data) p=p->lchild;
        else p=p->rchild;
    }
    p=new AVLNode(x);
    if(p==NULL) {cout<<"存储空间不足"<<endl;return false;}
    if(pr==NULL) {ptr=p;return true;}    //空树，新结点成为根结点
    if(x<pr->data) pr->lchild=p;         //新结点插入
    else pr->rchild=p;
    while(st.empty())
    {
        pr=st.top();
        st.pop();                        //从栈中退出父结点
        if(p==pr->lchild) pr->bf--;        //调整父结点的平衡因子
        else pr->bf++;

        if(pr->bf==0) break;             //第一种情况，平衡退出
        if(pr->bf==-1||pr->bf==1)        //第二种情况
            p=pr;                        //p指向父结点，往前循环，观察是否有非平衡结点
        else                             //第三种情况，pr->bf==+-2
          {
              d=(pr->bf<0)?-1:1;        //区别单双旋转的标志
              if(p->bf==d)              //同号，单旋转
              {
                  if(d==-1) RotateR(pr);//同负，右旋转
                  else RotateL(pr);     //同正，左旋转

              }
              else                       //异号，双旋转
              {
                  if(d==-1) RotateLR(pr);// -+ 先左后右旋转
                  else RotateRL(pr);     // +- 先右后左旋转

              }
              break;                     //不再向上调整
          }
    }
    if(st.empty())  ptr=pr;             //调整到树的根结点
    else                                //中间重新连接
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
//按层遍历
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


