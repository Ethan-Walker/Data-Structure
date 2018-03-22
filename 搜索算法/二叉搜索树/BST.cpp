#include "BST.h"
#include <queue>
#include <iostream>
using namespace std;
#define Max 50
istream&operator>>(istream &is,BST &B)
{
    cout<<"������Ҫ��ʼ�������Ķ����������Ľ�����: ";
    int n,i,A[Max];
    is>>n;
    cout<<"��������������: ";
    for(i=0;i<n;i++)
    {
        is>>A[i];
        B.Insert(A[i]);
    }
    return is;

}
ostream &operator<< (ostream &os,BST &B)
{
    cout<<"���������";
    B.Traverse(os,B.root);
    return os;
}
void BST::Traverse(ostream &os,BSTNode *subtree)
{
    if(subtree!=NULL)
    {
        Traverse(os,subtree->lchild);
        os<<subtree->data<<" ";
        Traverse(os,subtree->rchild);
    }
}
//�ͷ���
void BST::destroy(BSTNode *subtree)
{
    if(subtree!=NULL)
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
}

//������
bool BST::Insert(const int x,BSTNode *&subtree)
{
    if(subtree==NULL)
    {
        subtree=new BSTNode(x);
        return true;
    }
    else if(x<subtree->data) Insert(x,subtree->lchild);
    else if(x>subtree->data) Insert(x,subtree->rchild);
    return false;                                        //�������иý��
}

//ɾ�����
bool BST::Remove(int x,BSTNode *&subtree)
{
    if(subtree!=NULL)
    {
        if(x<subtree->data) Remove(x,subtree->lchild);
        else if(x>subtree->data) Remove(x,subtree->rchild);
        else if(subtree->lchild!=NULL&&subtree->rchild!=NULL)
        {
            BSTNode *temp=subtree->rchild;
            while(temp->lchild!=NULL) temp=temp->lchild;
            subtree->data=temp->data;
            Remove(temp->data,subtree->rchild);

        }
        else
        {
            BSTNode *temp=subtree;
            if(subtree->lchild==NULL) subtree=subtree->rchild;
            else subtree=subtree->lchild;
            delete temp;
            return true;
        }
    }
}
//����,δ�����������
BSTNode* BST::Search(int x,BSTNode *subtree)
{
    if(subtree==NULL) return NULL;
    if(x==subtree->data) return subtree;
    else if(x<subtree->data) return Search(x,subtree->lchild);
    else if(x>subtree->data) return Search(x,subtree->rchild);

}
//ǰ�����
void BST::PreOrder(BSTNode *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);

    }
}
//�������
void BST::InOrder(BSTNode *subtree)
{
    if(subtree!=NULL)
    {
         InOrder(subtree->lchild);
         cout<<subtree->data<<" ";
         InOrder(subtree->rchild);
    }
}

//�������
void BST::LevelOrder(BSTNode *subtree)
{
    queue<BSTNode*> q;
    BSTNode *temp;
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








