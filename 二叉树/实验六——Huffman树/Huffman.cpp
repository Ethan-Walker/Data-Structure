#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Queue.h"
#include "MinHeap.h"
#include "Huffman.h"
using namespace std;

//构造函数
HuffmanTree::HuffmanTree(int A[],char B[],int n) //A为外结点权重，B为外结点名数组
{
    int i;
    MinHeap<Node > mh;                           //使用最小堆存放森林
    Node *parent,*first,*second,*temp;
    for(i=0;i<n;i++)                             //森林各棵树初始化
    {
        temp=new Node(A[i],B[i]);
        mh.Insert(*temp);                        //插入到最小堆中
    }
    for(i=0;i<n-1;i++)                           //循环n-1趟，形成huffman树
    {
        first=new Node;
        second=new Node;
        parent=new Node;
        mh.RemoveMin(*first);                    //选出根的权值最小的树
        mh.RemoveMin(*second);                   //选出根的权值次小的树
        MergeTree(first,second,parent);          //合并 将first和second权值相加赋给parent结点
        mh.Insert(*parent);                      //将合并后得到的根结点插入到最小堆中
    }
    root=parent;                                 //将建成的Huffman树根结点赋给root
}

//合并,将两个树根结点相加赋给parent结点，链接根结点与子女
void HuffmanTree::MergeTree(Node *&t1,Node *&t2,Node *&parent)
{
    parent->weight=t1->weight+t2->weight;
    parent->lchild=t1;
    parent->rchild=t2;
    t1->parent=t2->parent=parent;
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
        cout<<left<<setw(4)<<subtree->weight;
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
         cout<<left<<setw(4)<<subtree->weight;
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
         cout<<left<<setw(4)<<subtree->weight;
    }
}
//按层遍历
void HuffmanTree::LevelOrder(Node *subtree)
{
    Queue<Node*> q;
    Node *temp;
    q.EnQueue(subtree);
    while(!q.IsEmpty())
    {
        q.DeQueue(temp);
        cout<<left<<setw(4)<<temp->weight;
        if(temp->lchild!=NULL) q.EnQueue(temp->lchild);
        if(temp->rchild!=NULL) q.EnQueue(temp->rchild);
    }

}
//将Huffman树进行编码
void HuffmanTree::HuffmanCode(Node *&subtree,string st[50],char ch[])
{
     int i=0;
     Queue<Node*> q;
     Node *temp;
     q.EnQueue(subtree);
     cout<<left<<setw(8)<<"字符"<<setw(8)<<"权重"<<setw(8)<<"编码"<<endl;
     while(!q.IsEmpty())
     {
         q.DeQueue(temp);
         Node *l=temp->lchild,*r=temp->rchild;
         if(l==NULL&&r==NULL)                                //左右子树都为空，到达外结点，输出外结点编码
            {
                cout<<left<<setw(8)<<temp->ch<<setw(8)<<temp->weight<<setw(8)<<temp->code<<endl;
                ch[i]=temp->ch;
                st[i]=temp->code;
                i++;
                continue;
            }
         if(l!=NULL){l->code=temp->code+"0";q.EnQueue(l);}    //左子树不为空，左子树根结点编码+0
         if(r!=NULL){r->code=temp->code+"1";q.EnQueue(r);}    //右子树不为空，右子树根结点编码+1
     }
}




