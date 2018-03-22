#include <iostream>
#include <queue>
#include "binarytree.h"
istream& operator>>(istream&is,BinaryTree &BT)
{
    BT.CreateBT(is,BT);
    return is;
}
void BinaryTree::CreateBT(istream &is,BinaryTree &BT)
{
    Node *p,*p1;
    queue<Node*> q;
    BT.root=NULL;
    char S[Max][10];
    int k=0,i,j;
    while(is>>S[k]) k++;
    p=new Node(S[0][0]);
    for(i=0;i<k;i++)
    {
        j=0;
        p1=new Node(S[i][j]);
        j+=2;
        switch(S[i][j])
        {
            case '0':p1->parent=NULL;BT.root=p;break;
            default:
                while(p->data!=S[i][j]&&!q.empty())
                {
                    p=q.front();
                    q.pop();
                }
                j+=2;
                switch(S[i][j])
                {

                    case '1':p->lchild=p1;p1->parent=p;break;
                    case '2':p->rchild=p1;p1->parent=p;break;
                }

        }
        q.push(p1);

    }

}

void BinaryTree::PreOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);
    }
}
void BinaryTree::InOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        InOrder(subtree->lchild);
        cout<<subtree->data<<" ";
        InOrder(subtree->rchild);

    }
}

void BinaryTree::PostOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
        PostOrder(subtree->lchild);
        PostOrder(subtree->rchild);
        cout<<subtree->data<<" ";

    }
}
