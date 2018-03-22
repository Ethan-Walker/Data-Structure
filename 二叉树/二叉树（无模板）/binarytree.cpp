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
    os<<"按前序遍历的顺序输出二叉树:";
    BT.Traverse(os,BT.root);
    os<<endl;
    return os;
}

void BinaryTree::CreateBT(istream &is,BinaryTree &BT)
{
    cout<<"请以广义表的形式输入二叉树:"<<endl;
    cout<<"注意，左子女右子女有一个为空时，逗号不能省略，以#字符结束输入："<<endl;
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
            case '(':s.push(p);k=1;break;                          //左括号，压入p即父母结点，同时k=1，标示接下来输入的是左子树
            case ')':s.pop();break;                                //右括号，退栈，即退出子树
            case ',':k=2;break;                                    //逗号，仅仅k=2，标示接下来输入的是右子树
            default:
                p=new Node(ch);                                    //新建结点p保存刚刚输入的数据
                if(BT.root==NULL) BT.root=p;                       //根结点赋值
                else if(k==1)                                      //链接左子树
                {
                    t=s.top();
                    t->lchild=p;
                }
                else if(k==2)                                      //链接右子树
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
//递归遍历
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
//LevelOrder按层遍历
void BinaryTree::LevelOrder(Node *subtree)
{
    queue<Node *> q;
    q.push(subtree);
    Node *p;
    while(!q.empty())                            //循环直到队列空，跳出循环,每次循环压根结点的左右子女
    {
        p=q.front();                             //得到队首结点指针，
        cout<<p->data<<" ";                      //输出元素值
        q.pop();                                 //出队
        if(p->lchild!=NULL) q.push(p->lchild);   //左子女不为空，压左子女
        if(p->rchild!=NULL) q.push(p->rchild);   //右子女不为空，压右子女
    }

}



