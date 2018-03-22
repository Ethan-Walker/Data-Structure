#include "tree.h"
#include <queue>
#include <iostream>
using namespace std;
//Ѱ��������Ϊtarget�Ľ�㣬ʹ֮��Ϊ��ǰ���
bool Tree::Find(char target)
{
    if(p==NULL) return false;
    return Find(root,target);
}
//����pΪ��������������ch,��ʹ���Ϊcurrent���
bool Tree::Find(Node *p,char ch)
{
    if(p==NULL) return false;
    if(p->data==ch)                                //p��ΪҪ�ҵĽ��
    {
        current=p;
        return true;
    }
    else            //���ĵݹ�������
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
			PostOrder(p);

	}
}                              //������p�����εݹ�Ѱ��p��firstChild,nextSibling��ÿ�����ݹ�������һ����Ů�����ֵܣ�
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

//Ѱ�ҵ�ǰ���ĵ�һ����Ů
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

//Ѱ��current���ĸ���㣬������current
bool Tree::Parent()
{
    if(current=NULL||root==NULL||root=current)
    {
        current=NULL;
        return false;
    }
    else return FindParent(root,current);

}
//tΪroot��㣬pΪcurrent���
bool Tree::FindParent(Node *t,Node *p)
{
    Node *q=t->firstChild;
    while(q!=NULL)                          //ѭ���ж�q����q���ֵ��Ƿ�Ϊcurrent��㣬���ǣ�t��Ϊ�����
    {
        if(q==p)
        {
            current=t;
            return true;
        }
        if(FindParent(q,p)) return true;    //��qΪ�����Ѱ��p�ĸ����
        q=q->nextSibling;                   //qָ�����ֵ�
    }

}//���ĵݹ�������
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
			PostOrder(p);

	}
}
//ɾ����pΪ��������
void Removesubtree(Node *p)
{
    Node *parent;
    current=p;                    //current��Ϊp
    Parent();                     //Ѱ��p�ĸ���㣬������current
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
//ɾ����rootΪ������������������
void Tree::destroy(Node *root)
{
    if(root!=NULL)
    {
        destroy(root->firstChild);
        destroy(root->nextSibling);
        delete root;
    }
}
//�ù��������,����Ů-�ֵܷ�������
//�� ����(R(A(D)(E))(B)(C(F(G)(H)(K))))
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
//�Թ�������ʽ�����
void Tree::Show(Node *t)
{
	if(t==NULL) return ;
	cout<<"(";
	cout<<t->data;
	for(Node *p=t->firstChild;p!=NULL;p=p->nextSibling)
		Show(p);
	cout<<")";
}
//���ĵݹ��ȸ�����
void Tree::PreOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		cout<<subtree->data<<" ";
		for(subtree=subtree->firstChild;subtree!=NULL;subtree=subtree->nextSibling)
			 PreOrder(subtree);
	}
}
//���ĵݹ�������
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
			PostOrder(p);
		cout<<subtree->data;
	}
}
//���ĵݹ��ȸ�������������Ӧ��Ů-�ֵܱ�ʾ�����Ķ�������ǰ�����
void Tree::PreOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		cout<<subtree->data<<" ";
		PreOrder(subtree->firstChild);
		PreOrder(subtree->nextSibling);
	}
}

//���ĵݹ���������������Ӧ��Ů-�ֵܱ�ʾ�������Ķ��������������
void Tree::PostOrder(Node *subtree)
{
	if(subtree!=NULL)
	{
		PostOrder(subtree->firstChild);
		cout<<subtree->data<<" ";
		PostOrder(subtree->nextSibling);
	}

}

//���İ������,���ö���
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
//�����Ľ����
int Tree::Size(Node *subtree)
{
	if(subtree==NULL) return 0;
	return 1+Size(subtree->firstChild)+Size(subtree->nextSibling);
}
//���������
int Tree::Height(Node *subtree)
{
	int m=1;
	if(subtree->firstChild==NULL) return 1;
	for(Node *p=subtree->firstChild;p!=NULL;p=p->nextSibling)
		   if(int t=Height(p))>m) m=Height(p)
}


