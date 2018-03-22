#include "tree.h"
#include <queue>
#include <iostream>
using namespace std;
//寻找数据域为target的结点，使之成为当前结点
bool Tree::Find(char target)
{
    if(p==NULL) return false;
    return Find(root,target);
}
//在以p为根结点的树中搜索ch,并使其成为current结点
bool Tree::Find(Node *p,char ch)
{
    if(p==NULL) return false;
    if(p->data==ch)                                //p即为要找的结点
    {
        current=p;
        return true;
    }
    else            //树的递归后根遍历
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
			PostOrder(p);

	}
}                              //若不是p，依次递归寻找p的firstChild,nextSibling（每个结点递归查找其第一个子女，右兄弟）
    {
        if(Find(p->firstChild,ch)) return true;
        else if(Find(p->nextSibling,ch)) return true;
    }

}
bool Tree::Root()
{
    current=root;
    if(root!=NULL)
        return true;
    else return false;
}

//寻找当前结点的第一个子女
bool Tree::FirstChild()
{
    if(current!=NULL&&current->firstChild!=NULL)
    {
        current=current->firstChild;
        return true;
    }
    else
    {
        current=NULL;
        return true;
    }
}
bool Tree::nextSibling()
{
    if(current!=NULL&&current->nextSibling!=NULL)
    {
        current=current->nextSibling;
        return true;
    }
    else
    {
        current=NULL;
        return false;
    }
}

//寻找current结点的父结点，并赋给current
bool Tree::Parent()
{
    if(current=NULL||root==NULL||root=current)
    {
        current=NULL;
        return false;
    }
    else return FindParent(root,current);

}
//t为root结点，p为current结点
bool Tree::FindParent(Node *t,Node *p)
{
    Node *q=t->firstChild;
    while(q!=NULL)                          //循环判断q或者q的兄弟是否为current结点，若是，t即为父结点
    {
        if(q==p)
        {
            current=t;
            return true;
        }
        if(FindParent(q,p)) return true;    //以q为根结点寻找p的父结点
        q=q->nextSibling;                   //q指向右兄弟
    }

}//树的递归后根遍历
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
			PostOrder(p);

	}
}
//删除以p为根的子树
void Removesubtree(Node *p)
{
    Node *parent;
    current=p;                    //current赋为p
    Parent();                     //寻找p的父结点，并赋给current
    parent=current;
    if(parent->firstChild==p)
    {
        parent->firstChild=p->nextsibling;
    }
    else
    {
         Node *t=parent->firstChild;
         while(t->nextSibling!=p) t=t->nextSibling;
         t->nextsibling=p->nextSibling;
    }
    destroy(p);
    return true;
}
//删除以root为根结点的树，不是子树
void Tree::destroy(Node *root)
{
    if(root!=NULL)
    {
        destroy(root->firstChild);
        destroy(root->nextSibling);
        delete root;
    }
}
//用广义表构造树,以子女-兄弟法创建树
//例 输入(R(A(D)(E))(B)(C(F(G)(H)(K))))
Node* Tree::Create(char *&A)
{
	if(*A=='\0') return NULL;
	if(*A==')') {A++;return NULL;}
	if(*A=='(')  A++;
	Node *t=new Node(*(A++));
	t->firstChild=Create(A);
	t->nextSibling=Create(A);
	return t;
}
//以广义表的形式输出树
void Tree::Show(Node *t)
{
	if(t==NULL) return ;
	cout<<"(";
	cout<<t->data;
	for(Node *p=t->firstChild;p!=NULL;p=p->nextSibling)
		Show(p);
	cout<<")";
}
//树的递归先根遍历
void Tree::PreOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		cout<<subtree->data<<" ";
		for(subtree=subtree->firstChild;subtree!=NULL;subtree=subtree->nextSibling)
			 PreOrder(subtree);
	}
}
//树的递归后根遍历
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
			PostOrder(p);
		cout<<subtree->data;
	}
}
//树的递归先根遍历，借助对应子女-兄弟表示创建的二叉树的前序遍历
void Tree::PreOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		cout<<subtree->data<<" ";
		PreOrder(subtree->firstChild);
		PreOrder(subtree->nextSibling);
	}
}

//树的递归后根遍历，借助对应子女-兄弟表示法创建的二叉树的中序遍历
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		PostOrder(subtree->firstChild);
		cout<<subtree->data<<" ";
		PostOrder(subtree->nextSibling);
	}

}

//树的按层遍历,利用队列
void Tree::LevelOrder(Node *subtree)
{
     queue<Node*> q;
     if(subtree!=NULL)
         q.push(subtree);
     Node *p;
     while(!q.empty())
	 {
	 	p=q.front();
	    q.pop();
	    cout<<p->data<<" ";
        for(p=p->firstChild;p!=NULL;p=p->nextSibling)  q.push(p);
	 }
}
//求树的结点数
int Tree::Size(Node *subtree)
{
	if(subtree==NULL) return 0;
	return 1+Size(subtree->firstChild)+Size(subtree->nextSibling);
}
//求树的深度
int Tree::Height(Node *subtree)
{
	int m=1;
	if(subtree->firstChild==NULL) return 1;
	for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
		   if(int t=Height(p))>m) m=Height(p)
}


