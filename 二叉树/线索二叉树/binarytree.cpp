#include "binarytree.h"
//寻找中序下第一个结点
Node* ThreadBTree::first(Node *current)
{
    Node *p=current;
    while(p->ltag==0) p=p->lchild;  //（p=1时说明左子树为空）最左下方的结点即为中序遍历时第一个结点,
    return p;
}
//寻找中序下最后一个结点
Node* ThreadBTree::last(Node *current)
{
    Node *p=current;
    while(p->rtag==0) p=p->rchild;   //（p=1时说明右子树为空）最右下方的结点即为中序遍历时最后一个结点
    return p;
}
//寻找某一结点的前驱
Node* ThreadBTree::prior(Node *current)
{
    Node *p=current;
    if(p->ltag==0) return last(p->lchild);   //如果ltag=0，即lchild中存放的是左子树不是前驱，寻找当前结点左子树中序遍历下的最后一个结点
    else return p->lchild;                   //否则ltag=1，即lchild中为前驱
}
//寻找某一节点的后继
Node* ThreadBTree::next(Node *current)
{
    Node *p=current;
    if(p->rtag==0) return first(p->rchild); //如果rtag=0，即rchild中存放的是右子树不是后继，寻找当前结点右子树中序遍历下的第一个结点
    else return p->rchild;                  //rtag=1，即rchild中存放的是后继
}

//遍历算法

//中序遍历，利用线索二叉树的特点，利用first、next函数遍历
void ThreadBTree::InOrder(Node *current)
{
    Node *p;
    for(p=first(root);p!=NULL;p=next(p))    //p得到线索二叉树中序遍历下的第一个结点，然后循环得到后继结点
                                            //这个过程中，只有当访问到中序遍历最后一个结点后，才会得到空指针,通过一条串联的线中序遍历
    {
        cout<<p->data<<" ";
    }
    cout<<endl;
}


//利用递归中序遍历对二叉树进行中序线索化
void ThreadBTree::CreateInThread()
{
    Node *pre=NULL;                          //pre总是指向遍历指针p的中序遍历下的前驱结点，即在中序遍历过程中刚刚访问过的点
    if(root!=NULL)                           //非空二叉树，线索化
    {
        CreateInThread(root,pre);            //中序遍历线索化二叉树，
        pre->rchild=NULL;                    //函数执行完后pre指向中序遍历的最后一个结点
        pre->rtag=1;                         //处理中序情况下最后一个结点
    }
}
void ThreadBTree::CreateInThread(Node *current,Node *&pre)
{
    if(current==NULL) return;
    CreateInThread(current->lchild,pre);     //递归，左子树线索化
    if(current->lchild==NULL)                //左子树为空，左链域保存的是前驱，建立当前结点的前驱线索
    {
        current->lchild=pre;
        current->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL)         //前驱结点的右子树为空，右链域保存的是后继，建立此前驱结点的后继线索
    {
       pre->rchild=current;
       pre->rtag=1;
    }
    pre=current;                             //前驱跟上，当前指针向前遍历
    CreateInThread(current->rchild,pre);     //递归，线索化右子树
}
void ThreadBTree::PreOrder(Node *subtree)
{
 if(subtree!=NULL)
 {
     cout<<subtree->data<<" ";
     PreOrder(subtree->lchild);
     PreOrder(subtree->rchild);
 }
}
void ThreadBTree::InOrder(Node *subtree)
{
 if(subtree!=NULL)
 {
     cout<<subtree->data<<" ";
     InOrder(subtree->lchild);
     InOrder(subtree->rchild);
 }
}
void ThreadBTree::PostOrder(Node *subtree)
{
 if(subtree!=NULL)
 {
     cout<<subtree->data<<" ";
     PostOrder(subtree->lchild);
     PostOrder(subtree->rchild);
 }
}






