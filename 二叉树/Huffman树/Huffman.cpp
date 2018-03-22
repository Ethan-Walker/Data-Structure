#include <iostream>
#include <queue>
#include <string>
#include "MinHeap.h"
#include "Huffman.h"
using namespace std;

//���캯��
HuffmanTree::HuffmanTree(double A[],int n)
{
    int i;
    MinHeap<Node > mh;                                    //ʹ����С�Ѵ��ɭ��
    Node *parent,*first,*second,*temp;
    for(i=0;i<n;i++)                               //ɭ�ָ�������ʼ��
    {
        temp=new Node;
        temp->weight=A[i];
        temp->parent=temp->rchild=temp->lchild=NULL;
        mh.Insert(*temp);                            //���뵽��С����

    }
    for(i=0;i<n-1;i++)                              //ѭ��n-1�ˣ��γ�huffman��
    {
        first=new Node;
        second=new Node;
        parent=new Node;
        mh.RemoveMin(*first);                       //ѡ������Ȩֵ��С����
        mh.RemoveMin(*second);                      //ѡ������Ȩֵ��С����
        MergeTree(*first,*second,*parent);          //�ϲ� ��first��second��Ӹ���parent���
        mh.Insert(*parent);                         //���ϲ���õ��ĸ������뵽��С����
    }
    root=parent;
    //root->lchild->rchild->data122499621
}

//�ϲ�,���������������Ӹ���parent��㣬���Ӹ��������Ů
void HuffmanTree::MergeTree(Node &t1,Node &t2,Node &parent)
{
    parent.weight=t1.weight+t2.weight;                          //BUG fault
    parent.lchild=&t1;
    parent.rchild=&t2;
    t1.parent=t2.parent=&parent;
}

//ɾ����subtreeΪ����������
void HuffmanTree::destroy(Node *subtree)
{
    if(subtree!=NULL)
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
}

//ǰ�����
void HuffmanTree::PreOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);

    }
}
//�������
void HuffmanTree::InOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
         InOrder(subtree->lchild);
         cout<<subtree->data<<" ";
         InOrder(subtree->rchild);
    }
}
//�������
void HuffmanTree::PostOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
         PostOrder(subtree->lchild);
         PostOrder(subtree->rchild);
         cout<<subtree->data<<" ";
    }
}
//�������
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

