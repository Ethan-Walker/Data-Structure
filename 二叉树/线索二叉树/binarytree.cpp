#include "binarytree.h"
//Ѱ�������µ�һ�����
Node* ThreadBTree::first(Node *current)
{
    Node *p=current;
    while(p->ltag==0) p=p->lchild;  //��p=1ʱ˵��������Ϊ�գ������·��Ľ�㼴Ϊ�������ʱ��һ�����,
    return p;
}
//Ѱ�����������һ�����
Node* ThreadBTree::last(Node *current)
{
    Node *p=current;
    while(p->rtag==0) p=p->rchild;   //��p=1ʱ˵��������Ϊ�գ������·��Ľ�㼴Ϊ�������ʱ���һ�����
    return p;
}
//Ѱ��ĳһ����ǰ��
Node* ThreadBTree::prior(Node *current)
{
    Node *p=current;
    if(p->ltag==0) return last(p->lchild);   //���ltag=0����lchild�д�ŵ�������������ǰ����Ѱ�ҵ�ǰ�����������������µ����һ�����
    else return p->lchild;                   //����ltag=1����lchild��Ϊǰ��
}
//Ѱ��ĳһ�ڵ�ĺ��
Node* ThreadBTree::next(Node *current)
{
    Node *p=current;
    if(p->rtag==0) return first(p->rchild); //���rtag=0����rchild�д�ŵ������������Ǻ�̣�Ѱ�ҵ�ǰ�����������������µĵ�һ�����
    else return p->rchild;                  //rtag=1����rchild�д�ŵ��Ǻ��
}

//�����㷨

//��������������������������ص㣬����first��next��������
void ThreadBTree::InOrder(Node *current)
{
    Node *p;
    for(p=first(root);p!=NULL;p=next(p))    //p�õ�������������������µĵ�һ����㣬Ȼ��ѭ���õ���̽��
                                            //��������У�ֻ�е����ʵ�����������һ�����󣬲Ż�õ���ָ��,ͨ��һ�����������������
    {
        cout<<p->data<<" ";
    }
    cout<<endl;
}


//���õݹ���������Զ�������������������
void ThreadBTree::CreateInThread()
{
    Node *pre=NULL;                          //pre����ָ�����ָ��p����������µ�ǰ����㣬����������������иոշ��ʹ��ĵ�
    if(root!=NULL)                           //�ǿն�������������
    {
        CreateInThread(root,pre);            //���������������������
        pre->rchild=NULL;                    //����ִ�����preָ��������������һ�����
        pre->rtag=1;                         //����������������һ�����
    }
}
void ThreadBTree::CreateInThread(Node *current,Node *&pre)
{
    if(current==NULL) return;
    CreateInThread(current->lchild,pre);     //�ݹ飬������������
    if(current->lchild==NULL)                //������Ϊ�գ������򱣴����ǰ����������ǰ����ǰ������
    {
        current->lchild=pre;
        current->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL)         //ǰ������������Ϊ�գ������򱣴���Ǻ�̣�������ǰ�����ĺ������
    {
       pre->rchild=current;
       pre->rtag=1;
    }
    pre=current;                             //ǰ�����ϣ���ǰָ����ǰ����
    CreateInThread(current->rchild,pre);     //�ݹ飬������������
}
void ThreadBTree::PreOrder(Node *subtree)
{
 if(subtree!=NULL)
 {
     cout<<subtree->data<<" ";
     PreOrder(subtree->lchild);
     PreOrder(subtree->rchild);
 }
}
void ThreadBTree::InOrder(Node *subtree)
{
 if(subtree!=NULL)
 {
     cout<<subtree->data<<" ";
     InOrder(subtree->lchild);
     InOrder(subtree->rchild);
 }
}
void ThreadBTree::PostOrder(Node *subtree)
{
 if(subtree!=NULL)
 {
     cout<<subtree->data<<" ";
     PostOrder(subtree->lchild);
     PostOrder(subtree->rchild);
 }
}






