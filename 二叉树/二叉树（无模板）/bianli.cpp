#include <iostream>
#include "binarytree.h"
#include <stack>
#include <queue>
using namespace std;

//非递归遍历  栈的应用
//前序遍历 方法一 只压右子树
/*
void BinaryTree::PreOrder(Node *subtree)
{
    stack<Node*> s;
    Node *p=subtree;
    s.push(NULL);
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        if(p->rchild!=NULL) {s.push(p->rchild);}                     //右子树不为空，压右子树
        if(p->lchild!=NULL) {p=p->lchild;}                           //左子树不为空，进入左子树，但不压栈
        else {p=s.top();s.pop();}                                    //左子树为空，退栈并得到栈顶元素
    }
}*/
/*
//前序遍历  方法二 先压右子树，再压左子树
void BinaryTree::PreOrder(Node *subtree)
{
    stack<Node*> s;
    s.push(subtree);
    Node *p=subtree;
    while(!s.empty())
    {
        p=s.top();
        s.pop();
        cout<<p->data<<" ";
        if(p->rchild!=NULL) s.push(p->rchild);
        if(p->lchild!=NULL) s.push(p->lchild);

    }
}  */

//前序遍历  方法三 压根结点
void BinaryTree::PreOrder(Node *subtree)
{
    stack <Node *> s;
    Node *p=subtree;
    while(p!=NULL||!s.empty())    //当且仅当栈空且p指向最右下方的空树跳出循环
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";   //输出根结点
            s.push(p);            //根结点入栈
            p=p->lchild;          //访问左子树
        }
        else
        {
            p=s.top();            //得到栈顶根节点指针
            s.pop();              //根节点出栈
            p=p->rchild;          //访问右子树
        }
    }
}

//中序遍历   方法一 压根结点
void BinaryTree::InOrder(Node *subtree)
{
    stack <Node *> s;
    Node *p=subtree;
    while(p!=NULL||!s.empty())
    {
        if(p!=NULL)
        {
           s.push(p);
           p=p->lchild;
        }
        else
        {
           p=s.top();
           s.pop();
           cout<<p->data<<" ";
           p=p->rchild;
        }
    }
}
//中序遍历
/*
void BinaryTree::InOrder(Node *subtree)
{
    stack<Node*> s;
    Node *p=subtree;
    do{
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }

        if(!s.empty())
        {
            p=s.top();
            s.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }

    }while(!s.empty()||p!=NULL);
    cout<<endl;
}
*/
//后序遍历，需要判断从左子树退回还是右子树退回，新建节点结构体，含标记值
struct stkNode                                            //遍历时所用栈结点类定义
{
    Node *ptr;                                         //指向树结点的指针
    int tag;                                       //该结点退栈的标记值，L代表从左子树退回，R代表从右子树退回
    stkNode(Node *N=NULL):ptr(N),tag(0){}              //构造函数,创建一个stkNode结点时，默认结点指针为NULL，标记值为L
};
void BinaryTree::PostOrder(Node *subtree)
{
    stack<stkNode> s;
    stkNode w;
    Node *p=subtree;                                   //p是遍历指针
    do
    {
        while(p!=NULL)                                    //向最左下方的结点循环下去，直到为空
        {
            w.ptr=p;                                      //左子树结点指针赋给w.ptr
            w.tag=0;                                      //w.tag赋为L标记
            s.push(w);                                    //压栈
            p=p->lchild;                                  //向左下方结点走下去
        }
        int continue1=1;                                  //循环的标记，用于当从右子树退回时，需要循环退栈两或多次
        while(continue1&&!s.empty())                      //栈不空则退栈
        {
            w=s.top();
            s.pop();
            p=w.ptr;
            switch(w.tag)                                 //判断栈顶结点指针的标记值
            {
            case 0:w.tag=1;                               //从左子树退回，则修改栈顶标记值后重新压栈
                   s.push(w);
                   continue1=0;                           //不是右子树退回，则不用再循环退栈，continue1赋为0
                   p=p->rchild;                           //访问右子树，跳到大循环do while中，将其左下方结点一直压栈……
                   break;
            case 1:cout<<w.ptr->data<<" ";                //从右子树退回，输出栈顶值，即根结点的值，继续循环退栈
                   break;
            }
        }
    }while(!s.empty());                                    //栈为空时退出循环
}

