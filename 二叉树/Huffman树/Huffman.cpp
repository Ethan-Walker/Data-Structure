#include <iostream>
#include <queue>
#include <string>
#include "MinHeap.h"
#include "Huffman.h"
using namespace std;

//构造函数
HuffmanTree::HuffmanTree(double A[],int n)
{
    int i;
    MinHeap<Node > mh;                                    //使用最小堆存放森林
    Node *parent,*first,*second,*temp;
    for(i=0;i<n;i++)                               //森林各棵树初始化
    {
        temp=new Node;
        temp->weight=A[i];
        temp->parent=temp->rchild=temp->lchild=NULL;
        mh.Insert(*temp);                            //插入到最小堆中

    }
    for(i=0;i<n-1;i++)                              //循环n-1趟，形成huffman树
    {
        first=new Node;
        second=new Node;
        parent=new Node;
        mh.RemoveMin(*first);                       //选出根的权值最小的树
        mh.RemoveMin(*second);                      //选出根的权值次小的树
        MergeTree(*first,*second,*parent);          //合并 将first和second相加赋给parent结点
        mh.Insert(*parent);                         //将合并后得到的根结点插入到最小堆中
    }
    root=parent;
    //root->lchild->rchild->data122499621
}

//合并,将两个树根结点相加赋给parent结点，链接根结点与子女
void HuffmanTree::MergeTree(Node &t1,Node &t2,Node &parent)
{
    parent.weight=t1.weight+t2.weight;                          //BUG fault
    parent.lchild=&t1;
    parent.rchild=&t2;
    t1.parent=t2.parent=&parent;
}

//删除以subtree为根结点的子树
void HuffmanTree::destroy(Node *subtree)
{
    if(subtree!=NULL)
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
}

//前序遍历
void HuffmanTree::PreOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);

    }
}
//中序遍历
void HuffmanTree::InOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
         InOrder(subtree->lchild);
         cout<<subtree->data<<" ";
         InOrder(subtree->rchild);
    }
}
//后序遍历
void HuffmanTree::PostOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
         PostOrder(subtree->lchild);
         PostOrder(subtree->rchild);
         cout<<subtree->data<<" ";
    }
}
//按层遍历
void HuffmanTree::LevelOrder(Node *subtree)
{
    queue<Node*> q;
    Node *temp;
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

