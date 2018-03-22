#include <iostream>
#include <cstdio>
#include <queue>
#include "binarytree.h"
using namespace std;
const int Max=100;
//输入前序 中序遍历结果，调用重建，返回根结点指针赋给root
void BinaryTree::pCreateBinaryTree()
{
    cout<<"请输入前序遍历结果:";
    char pre[Max],in[Max];
    int i=0,n;
    while((pre[i]=cin.get())!='\n')i++;
    n=i;
    cout<<endl<<"请输入中序遍历结果:";
    for(i=0;i<n;i++)
        cin>>in[i];
    root=pCreateBinaryTree(pre,in,n);
    cout<<endl<<"重建二叉树成功。"<<endl;
}
Node* BinaryTree::pCreateBinaryTree(char *pre,char *in,int n)
//按前序 中序遍历结果重建二叉树，返回根结点指针
//pre是前序遍历结果，in是中序遍历结果，n表示处理的树结点个数，返回二叉树的根结点指针
{
    if(n==0) return NULL;                      //结点数为0，不处理，返回空，即上一轮处理的是叶节点
    int k=0;
    while(pre[0]!=in[k]) k++;                 //找到前序遍历中根结点在中序遍历的下标k，即左边k个元素是左子树
                                               //右边n(n-k-1)个元素是右子树
    Node *p=new Node( pre[0] );                //创建根结点，同时赋值
    p->lchild=pCreateBinaryTree(pre+1,in,k);   //从前序MTR+1开始对中序LMR的0~k-1 共k个元素递归处理建立左子树
    p->rchild=pCreateBinaryTree(pre+k+1,in+k+1,n-(k+1));
    //从前序MTR[k+1]个元素开始对中序的k+1~n-1右子序列的n-k-1个元素递归建立右子树
    return p;
}




//输入后序遍历 中序遍历结果，重建二叉树，返回根节点指针，赋给root
void BinaryTree::lCreateBinaryTree()
{
    char ch;
    ch=cin.get();                             //cin不接受回车符，故上一次输入的回车符仍在输入流中，用ch接收"除去"该回车符
    char post[Max],in[Max],C[Max];
    int i=0,j,n;
    cout<<"请输入后序遍历结果:";
    while((post[i]=cin.get())!='\n') i++;
    n=i;
    cout<<"请输入中序遍历结果:";
    for(i=0;i<n;i++)
        cin>>in[i];
    for(i=n-1,j=0;i>=0;i--,j++) C[j]=post[i];                    //将后序遍历结果倒序得到C 传入重建函数中
    root=lCreateBinaryTree(C,in,n);
}
//按后序 中序遍历结果重建二叉树，返回根结点指针，赋给root
Node * BinaryTree::lCreateBinaryTree(char *post,char *in,int n)
{

    if(n==0) return NULL;
    int k=0;
    while(post[0]!=in[k]) k++;
    Node *p=new Node(post[0]);
    p->lchild=lCreateBinaryTree(post+n-k,in,k);
    p->rchild=lCreateBinaryTree(post+1,in+k+1,n-k-1);

    return p;
}


//递归遍历
//前序遍历
void BinaryTree::PreOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
         cout<<subtree->data<<" ";
         PreOrder(subtree->lchild);
         PreOrder(subtree->rchild);
    }
}
//中序遍历
void BinaryTree::InOrder(Node *subtree)
{
    if(subtree!=NULL)
    {

         InOrder(subtree->lchild);
         cout<<subtree->data<<" ";
         InOrder(subtree->rchild);
    }
}
//后序遍历
void BinaryTree::PostOrder(Node *subtree)
{
    if(subtree!=NULL)
    {

         PostOrder(subtree->lchild);
         PostOrder(subtree->rchild);
         cout<<subtree->data<<" ";
    }
}
//LevelOrder 按层遍历
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


//destroy
void BinaryTree::destroy(Node *subtree)
{
    if(subtree!=NULL)
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
}




