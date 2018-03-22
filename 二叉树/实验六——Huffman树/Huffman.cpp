#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Queue.h"
#include "MinHeap.h"
#include "Huffman.h"
using namespace std;

//���캯��
HuffmanTree::HuffmanTree(int A[],char B[],int n) //AΪ����Ȩ�أ�BΪ����������
{
    int i;
    MinHeap<Node > mh;                           //ʹ����С�Ѵ��ɭ��
    Node *parent,*first,*second,*temp;
    for(i=0;i<n;i++)                             //ɭ�ָ�������ʼ��
    {
        temp=new Node(A[i],B[i]);
        mh.Insert(*temp);                        //���뵽��С����
    }
    for(i=0;i<n-1;i++)                           //ѭ��n-1�ˣ��γ�huffman��
    {
        first=new Node;
        second=new Node;
        parent=new Node;
        mh.RemoveMin(*first);                    //ѡ������Ȩֵ��С����
        mh.RemoveMin(*second);                   //ѡ������Ȩֵ��С����
        MergeTree(first,second,parent);          //�ϲ� ��first��secondȨֵ��Ӹ���parent���
        mh.Insert(*parent);                      //���ϲ���õ��ĸ������뵽��С����
    }
    root=parent;                                 //�����ɵ�Huffman������㸳��root
}

//�ϲ�,���������������Ӹ���parent��㣬���Ӹ��������Ů
void HuffmanTree::MergeTree(Node *&t1,Node *&t2,Node *&parent)
{
    parent->weight=t1->weight+t2->weight;
    parent->lchild=t1;
    parent->rchild=t2;
    t1->parent=t2->parent=parent;
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
        cout<<left<<setw(4)<<subtree->weight;
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
         cout<<left<<setw(4)<<subtree->weight;
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
         cout<<left<<setw(4)<<subtree->weight;
    }
}
//�������
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
//��Huffman�����б���
void HuffmanTree::HuffmanCode(Node *&subtree,string st[50],char ch[])
{
     int i=0;
     Queue<Node*> q;
     Node *temp;
     q.EnQueue(subtree);
     cout<<left<<setw(8)<<"�ַ�"<<setw(8)<<"Ȩ��"<<setw(8)<<"����"<<endl;
     while(!q.IsEmpty())
     {
         q.DeQueue(temp);
         Node *l=temp->lchild,*r=temp->rchild;
         if(l==NULL&&r==NULL)                                //����������Ϊ�գ��������㣬����������
            {
                cout<<left<<setw(8)<<temp->ch<<setw(8)<<temp->weight<<setw(8)<<temp->code<<endl;
                ch[i]=temp->ch;
                st[i]=temp->code;
                i++;
                continue;
            }
         if(l!=NULL){l->code=temp->code+"0";q.EnQueue(l);}    //��������Ϊ�գ���������������+0
         if(r!=NULL){r->code=temp->code+"1";q.EnQueue(r);}    //��������Ϊ�գ���������������+1
     }
}




