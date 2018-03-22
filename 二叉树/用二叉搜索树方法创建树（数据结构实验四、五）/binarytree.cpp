//��������Ա����ʵ��
#include "binarytree.h"
#include "Queue.h"
#include<iostream>
using namespace std;

//���������
istream& operator>>(istream &is,BinaryTree &BT)
{
    BT.Create(is);
    return is;
}

//��ʼ������������
void BinaryTree::Create(istream &is)
{
    char ch;
    int n,i;
    cout<<"�����������������,ע����ַ����Կո�ֿ����Իس�����: ";
        while(is>>ch)
        Insert(ch,BiTree);

    cout<<"�����������ɹ�."<<endl;
}

//������
//������ԣ�Ҫ����Ľ����ڸ��������뵽��������С�ڸ���������������
//          �����Ӧ����Ϊ�գ��򽫸ý�����
//          �����Ϊ�գ��򽫸ý�������������Ƚϣ��ظ���������
bool BinaryTree::Insert(char ch,BiTNode *&subtree)
{
    if(subtree==NULL)                       //����
    {
        subtree=new BiTNode(ch);            //���뵽�����
        return true;
    }
    else if(ch<subtree->data)               //������С�ڸ����
    {
        Insert(ch,subtree->lchild);         //���뵽������
    }
    else if(ch>subtree->data)               //����ӵ���ڸ����
    {
        Insert(ch,subtree->rchild);         //���뵽������
    }
    else return false;                      //ch�������У����ٲ���
}

//ɾ�����
//ɾ�����ԣ������еĶ������в��ҵ������Ľ��
//          1.���������Ϊ�գ�������Ů����ý��λ��
//          2.���������Ϊ�գ�������Ů����ý��λ��
//          3.�������������Ϊ�գ����������������һ����Ů�����λ��
bool BinaryTree::Remove(char ch,BiTNode *&subtree)
{
    BiTNode *current;
    if(subtree!=NULL)
    {
        if(ch<subtree->data)        Remove(ch,subtree->lchild);        //����������ִ��ɾ��
        else if(ch>subtree->data)   Remove(ch,subtree->rchild);        //����������ִ��ɾ��
        else if(subtree->lchild!=NULL&&subtree->rchild!=NULL)          //����������Ϊ��
        {
            current=subtree->rchild;
            while(current->lchild!=NULL) current=current->lchild;      //Ѱ�������������µ�һ�����
            subtree->data=current->data;                               //���ҵ��Ľ�����ݴ�����������
            Remove(subtree->data,subtree->rchild);                     //ɾ��������ظ����
        }
        else
        {
            current=subtree;
            if(subtree->lchild==NULL) subtree=subtree->rchild;          //������Ϊ�գ�����Ů�
                else                  subtree=subtree->lchild;          //������Ϊ�գ�����Ů�
            delete current;
            return true;
        }
    }
}

//ǰ�����
void BinaryTree::PreOrder(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);
    }
}
//�������
void BinaryTree::InOrder(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        InOrder(subtree->lchild);
        cout<<subtree->data<<" ";
        InOrder(subtree->rchild);
    }
}
//�������
void BinaryTree::PostOrder(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        PostOrder(subtree->lchild);
        PostOrder(subtree->rchild);
        cout<<subtree->data<<" ";
    }
}
//�ö���ʵ�ְ������
void BinaryTree::LevelOrder(BiTNode *subtree)
{
    Queue<BiTNode*> q;
    BiTNode *p=subtree;
    q.EnQueue(p);

    while(!q.IsEmpty())
    {
        p=q.DeQueue();                                                //����
        cout<<p->data<<" ";
        if(p->lchild!=NULL) q.EnQueue(p->lchild);                     //����Ů��Ϊ�գ����
        if(p->rchild!=NULL) q.EnQueue(p->rchild);                     //����Ů��Ϊ�գ�����
    }
}

//�ݹ鷨�ÿ���
void BinaryTree::destroy(BiTNode *subtree)
{
    if(subtree!=NULL)
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
}




