#include <iostream>
#include <cstdio>
#include <queue>
#include "binarytree.h"
using namespace std;
const int Max=100;
//����ǰ�� �����������������ؽ������ظ����ָ�븳��root
void BinaryTree::pCreateBinaryTree()
{
    cout<<"������ǰ��������:";
    char pre[Max],in[Max];
    int i=0,n;
    while((pre[i]=cin.get())!='\n')i++;
    n=i;
    cout<<endl<<"����������������:";
    for(i=0;i<n;i++)
        cin>>in[i];
    root=pCreateBinaryTree(pre,in,n);
    cout<<endl<<"�ؽ��������ɹ���"<<endl;
}
Node* BinaryTree::pCreateBinaryTree(char *pre,char *in,int n)
//��ǰ�� �����������ؽ������������ظ����ָ��
//pre��ǰ����������in��������������n��ʾ������������������ض������ĸ����ָ��
{
    if(n==0) return NULL;                      //�����Ϊ0�����������ؿգ�����һ�ִ������Ҷ�ڵ�
    int k=0;
    while(pre[0]!=in[k]) k++;                 //�ҵ�ǰ������и����������������±�k�������k��Ԫ����������
                                               //�ұ�n(n-k-1)��Ԫ����������
    Node *p=new Node( pre[0] );                //��������㣬ͬʱ��ֵ
    p->lchild=pCreateBinaryTree(pre+1,in,k);   //��ǰ��MTR+1��ʼ������LMR��0~k-1 ��k��Ԫ�صݹ鴦����������
    p->rchild=pCreateBinaryTree(pre+k+1,in+k+1,n-(k+1));
    //��ǰ��MTR[k+1]��Ԫ�ؿ�ʼ�������k+1~n-1�������е�n-k-1��Ԫ�صݹ齨��������
    return p;
}




//���������� �������������ؽ������������ظ��ڵ�ָ�룬����root
void BinaryTree::lCreateBinaryTree()
{
    char ch;
    ch=cin.get();                             //cin�����ܻس���������һ������Ļس��������������У���ch����"��ȥ"�ûس���
    char post[Max],in[Max],C[Max];
    int i=0,j,n;
    cout<<"���������������:";
    while((post[i]=cin.get())!='\n') i++;
    n=i;
    cout<<"����������������:";
    for(i=0;i<n;i++)
        cin>>in[i];
    for(i=n-1,j=0;i>=0;i--,j++) C[j]=post[i];                    //����������������õ�C �����ؽ�������
    root=lCreateBinaryTree(C,in,n);
}
//������ �����������ؽ������������ظ����ָ�룬����root
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


//�ݹ����
//ǰ�����
void BinaryTree::PreOrder(Node *subtree)
{
    if(subtree!=NULL)
    {
         cout<<subtree->data<<" ";
         PreOrder(subtree->lchild);
         PreOrder(subtree->rchild);
    }
}
//�������
void BinaryTree::InOrder(Node *subtree)
{
    if(subtree!=NULL)
    {

         InOrder(subtree->lchild);
         cout<<subtree->data<<" ";
         InOrder(subtree->rchild);
    }
}
//�������
void BinaryTree::PostOrder(Node *subtree)
{
    if(subtree!=NULL)
    {

         PostOrder(subtree->lchild);
         PostOrder(subtree->rchild);
         cout<<subtree->data<<" ";
    }
}
//LevelOrder �������
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




