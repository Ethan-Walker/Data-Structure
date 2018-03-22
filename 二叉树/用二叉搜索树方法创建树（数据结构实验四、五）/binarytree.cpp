//二叉树成员函数实现
#include "binarytree.h"
#include "Queue.h"
#include<iostream>
using namespace std;

//运算符重载
istream& operator>>(istream &is,BinaryTree &BT)
{
    BT.Create(is);
    return is;
}

//初始化创建二叉树
void BinaryTree::Create(istream &is)
{
    char ch;
    int n,i;
    cout<<"请输入各个结点的数据,注意各字符间以空格分开，以回车结束: ";
        while(is>>ch)
        Insert(ch,BiTree);

    cout<<"创建二叉树成功."<<endl;
}

//插入结点
//插入策略：要插入的结点大于根结点则插入到右子树，小于根结点则插入左子树
//          如果相应子树为空，则将该结点插入
//          如果不为空，则将该结点与子树根结点比较，重复上述步骤
bool BinaryTree::Insert(char ch,BiTNode *&subtree)
{
    if(subtree==NULL)                       //空树
    {
        subtree=new BiTNode(ch);            //插入到根结点
        return true;
    }
    else if(ch<subtree->data)               //待插结点小于根结点
    {
        Insert(ch,subtree->lchild);         //插入到左子树
    }
    else if(ch>subtree->data)               //待插接点大于根结点
    {
        Insert(ch,subtree->rchild);         //插入到右子树
    }
    else return false;                      //ch已在树中，不再插入
}

//删除结点
//删除策略：在已有的二叉树中查找到给定的结点
//          1.如果右子树为空，用左子女填补到该结点位置
//          2.如果左子树为空，用右子女填补到该结点位置
//          3.如果左右子树都为空，在右子树找中序第一个子女填补到该位置
bool BinaryTree::Remove(char ch,BiTNode *&subtree)
{
    BiTNode *current;
    if(subtree!=NULL)
    {
        if(ch<subtree->data)        Remove(ch,subtree->lchild);        //在左子树中执行删除
        else if(ch>subtree->data)   Remove(ch,subtree->rchild);        //在右子树中执行删除
        else if(subtree->lchild!=NULL&&subtree->rchild!=NULL)          //左右子树都为空
        {
            current=subtree->rchild;
            while(current->lchild!=NULL) current=current->lchild;      //寻找右子树中序下第一个结点
            subtree->data=current->data;                               //将找到的结点数据代替根结点数据
            Remove(subtree->data,subtree->rchild);                     //删除多余的重复结点
        }
        else
        {
            current=subtree;
            if(subtree->lchild==NULL) subtree=subtree->rchild;          //左子树为空，右子女填补
                else                  subtree=subtree->lchild;          //右子树为空，左子女填补
            delete current;
            return true;
        }
    }
}

//前序遍历
void BinaryTree::PreOrder(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);
    }
}
//中序遍历
void BinaryTree::InOrder(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        InOrder(subtree->lchild);
        cout<<subtree->data<<" ";
        InOrder(subtree->rchild);
    }
}
//后序遍历
void BinaryTree::PostOrder(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        PostOrder(subtree->lchild);
        PostOrder(subtree->rchild);
        cout<<subtree->data<<" ";
    }
}
//用队列实现按层遍历
void BinaryTree::LevelOrder(BiTNode *subtree)
{
    Queue<BiTNode*> q;
    BiTNode *p=subtree;
    q.EnQueue(p);

    while(!q.IsEmpty())
    {
        p=q.DeQueue();                                                //出队
        cout<<p->data<<" ";
        if(p->lchild!=NULL) q.EnQueue(p->lchild);                     //左子女不为空，入队
        if(p->rchild!=NULL) q.EnQueue(p->rchild);                     //右子女不为空，出队
    }
}

//递归法置空树
void BinaryTree::destroy(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
}




