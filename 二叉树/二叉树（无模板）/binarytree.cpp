#include <iostream>
#include <stack>
#include <queue>
#include "binarytree.h"
using namespace std;
istream& operator>>(istream &is,BinaryTree &BT)
{
    BT.CreateBT(is,BT);
    return is;
}
ostream& operator<<(ostream &os,BinaryTree &BT)
{
    os<<"��ǰ�������˳�����������:";
    BT.Traverse(os,BT.root);
    os<<endl;
    return os;
}

void BinaryTree::CreateBT(istream &is,BinaryTree &BT)
{
    cout<<"���Թ�������ʽ���������:"<<endl;
    cout<<"ע�⣬����Ů����Ů��һ��Ϊ��ʱ�����Ų���ʡ�ԣ���#�ַ��������룺"<<endl;
    stack<Node*> s;
    Node *p,*t;
    BT.root=NULL;
    char ch;
    int k=0;
    is>>ch;
    while(ch!=refvalue)
    {
        switch(ch)
        {
            case '(':s.push(p);k=1;break;                          //�����ţ�ѹ��p����ĸ��㣬ͬʱk=1����ʾ�������������������
            case ')':s.pop();break;                                //�����ţ���ջ�����˳�����
            case ',':k=2;break;                                    //���ţ�����k=2����ʾ�������������������
            default:
                p=new Node(ch);                                    //�½����p����ո����������
                if(BT.root==NULL) BT.root=p;                       //����㸳ֵ
                else if(k==1)                                      //����������
                {
                    t=s.top();
                    t->lchild=p;
                }
                else if(k==2)                                      //����������
                {
                    t=s.top();
                    t->rchild=p;
                }
        }
        is>>ch;
    }
}

void BinaryTree::Traverse(ostream &os,Node *subtree)
{

    if(subtree!=NULL)
    {
        os<<subtree->data<<" ";
        Traverse(os,subtree->lchild);
        Traverse(os,subtree->rchild);
    }
}


void PrintBT(Node *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        if(subtree->lchild!=NULL||subtree->rchild!=NULL)
        {
            cout<<"( ";
            PrintBT(subtree->lchild);
            cout<<", ";
            PrintBT(subtree->rchild);
            cout<<") ";
        }
    }
}


/*
//�ݹ����
//PreOrder
void BinaryTree::PreOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);
    }
}
//InOrder
void BinaryTree::InOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        InOrder(subtree->lchild);
        cout<<subtree->data<<" ";
        InOrder(subtree->rchild);
    }
}
//PostOrder
void BinaryTree::PostOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        PostOrder(subtree->lchild);
        PostOrder(subtree->rchild);
        cout<<subtree->data<<" ";
    }
}
*/
int BinaryTree::Size(Node *subtree)
{
    if(subtree==NULL) return 0;
    return 1+Size(subtree->lchild)+Size(subtree->rchild);
}


int BinaryTree::Height(Node *subtree)
{
    if(subtree==NULL) return 0;
    int i=Height(subtree->lchild);
    int j=Height(subtree->rchild);
    return (i>j)?i+1:j+1;
}

BinaryTree::BinaryTree(const BinaryTree &s)
{
    root=Copy(s.root);
}

Node* BinaryTree::Copy(Node *subtree)
{
    if(subtree==NULL) return NULL;

     Node *t=new Node(subtree->data);
     t->lchild=Copy(subtree->lchild);
     t->rchild=Copy(subtree->rchild);

    return t;
}
void BinaryTree::destroy(Node *subtree)
{
    if(subtree!=NULL)
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
}
//LevelOrder�������
void BinaryTree::LevelOrder(Node *subtree)
{
    queue<Node *> q;
    q.push(subtree);
    Node *p;
    while(!q.empty())                            //ѭ��ֱ�����пգ�����ѭ��,ÿ��ѭ��ѹ������������Ů
    {
        p=q.front();                             //�õ����׽��ָ�룬
        cout<<p->data<<" ";                      //���Ԫ��ֵ
        q.pop();                                 //����
        if(p->lchild!=NULL) q.push(p->lchild);   //����Ů��Ϊ�գ�ѹ����Ů
        if(p->rchild!=NULL) q.push(p->rchild);   //����Ů��Ϊ�գ�ѹ����Ů
    }

}



