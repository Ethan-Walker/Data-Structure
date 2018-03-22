#include <iostream>
#include "binarytree.h"
#include <stack>
#include <queue>
using namespace std;

//�ǵݹ����  ջ��Ӧ��
//ǰ����� ����һ ֻѹ������
/*
void BinaryTree::PreOrder(Node *subtree)
{
    stack<Node*> s;
    Node *p=subtree;
    s.push(NULL);
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        if(p->rchild!=NULL) {s.push(p->rchild);}                     //��������Ϊ�գ�ѹ������
        if(p->lchild!=NULL) {p=p->lchild;}                           //��������Ϊ�գ�����������������ѹջ
        else {p=s.top();s.pop();}                                    //������Ϊ�գ���ջ���õ�ջ��Ԫ��
    }
}*/
/*
//ǰ�����  ������ ��ѹ����������ѹ������
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

//ǰ�����  ������ ѹ�����
void BinaryTree::PreOrder(Node *subtree)
{
    stack <Node *> s;
    Node *p=subtree;
    while(p!=NULL||!s.empty())    //���ҽ���ջ����pָ�������·��Ŀ�������ѭ��
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";   //��������
            s.push(p);            //�������ջ
            p=p->lchild;          //����������
        }
        else
        {
            p=s.top();            //�õ�ջ�����ڵ�ָ��
            s.pop();              //���ڵ��ջ
            p=p->rchild;          //����������
        }
    }
}

//�������   ����һ ѹ�����
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
//�������
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
//�����������Ҫ�жϴ��������˻ػ����������˻أ��½��ڵ�ṹ�壬�����ֵ
struct stkNode                                            //����ʱ����ջ����ඨ��
{
    Node *ptr;                                         //ָ��������ָ��
    int tag;                                       //�ý����ջ�ı��ֵ��L������������˻أ�R������������˻�
    stkNode(Node *N=NULL):ptr(N),tag(0){}              //���캯��,����һ��stkNode���ʱ��Ĭ�Ͻ��ָ��ΪNULL�����ֵΪL
};
void BinaryTree::PostOrder(Node *subtree)
{
    stack<stkNode> s;
    stkNode w;
    Node *p=subtree;                                   //p�Ǳ���ָ��
    do
    {
        while(p!=NULL)                                    //�������·��Ľ��ѭ����ȥ��ֱ��Ϊ��
        {
            w.ptr=p;                                      //���������ָ�븳��w.ptr
            w.tag=0;                                      //w.tag��ΪL���
            s.push(w);                                    //ѹջ
            p=p->lchild;                                  //�����·��������ȥ
        }
        int continue1=1;                                  //ѭ���ı�ǣ����ڵ����������˻�ʱ����Ҫѭ����ջ������
        while(continue1&&!s.empty())                      //ջ��������ջ
        {
            w=s.top();
            s.pop();
            p=w.ptr;
            switch(w.tag)                                 //�ж�ջ�����ָ��ı��ֵ
            {
            case 0:w.tag=1;                               //���������˻أ����޸�ջ�����ֵ������ѹջ
                   s.push(w);
                   continue1=0;                           //�����������˻أ�������ѭ����ջ��continue1��Ϊ0
                   p=p->rchild;                           //������������������ѭ��do while�У��������·����һֱѹջ����
                   break;
            case 1:cout<<w.ptr->data<<" ";                //���������˻أ����ջ��ֵ����������ֵ������ѭ����ջ
                   break;
            }
        }
    }while(!s.empty());                                    //ջΪ��ʱ�˳�ѭ��
}

