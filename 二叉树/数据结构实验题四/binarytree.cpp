#include <iostream>
#include <queue>
#include "binarytree.h"
#define Max 100
using namespace std;

istream& operator>>(istream &is,BinaryTree &BT)
{
    BT.CreateBT(is,BT);
    return is;
}
ostream& operator<<(ostream &os,BinaryTree &BT)
{
    os<<"按前序遍历的顺序输出二叉树:";
    BT.Traverse(os,BT.root);
    os<<endl;
    return os;
}

void BinaryTree::CreateBT(istream &is,BinaryTree &BT)
{
   queue<Node*> s;
   int i,A[Max],n;
   while(is>>A[i]) i++;
   n=i;
   Node *p,*q;
   p=new Node(A[0]);
   i=1;
   q=new Node(A[i]);
   while(i<n)
   {
       if(q->data>p->data)
       {
           if(p->lchild==NULL)
           {
               p->lchild=q;
               s.push(q);
               i++;
               q=new Node(A[i]);
           }
           else
           {
               p=s.front();
               s.pop();
           }
       }
       else if(q->data<p->data)
       {
           if(p->rchild==NULL)
           {
               p->rchild=q;
               s.push(q);
               i++;
               q=new Node(A[i]);
            }
            else
            {
                p=s.front();
                s.pop();
            }
       }
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
