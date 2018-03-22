#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *lchild,*rchild;
    Node(char _data,Node *lch=NULL,Node *rch=NULL):data(_data),lchild(lch),rchild(rch){}
    Node():lchild(NULL),rchild(NULL){}

};
class BinaryTree
{
private:
   Node *root;
   char tag;
   void PreOrder(Node *subtree);
   void InOrder(Node *subtree);
   void PostOrder(Node *subtree);
   void LevelOrder(Node *subtree);

   Node* pCreateBinaryTree(char *pre,char *in,int n);         //�������ǰ�����pre�� �������in��������n���ؽ�������
   Node* lCreateBinaryTree(char *post,char *in,int n);        //������ĺ������post���������in��������n���ؽ�������

   void destroy(Node *subtree);


public:
    BinaryTree(char t='#'):root(NULL),tag(t){};
    ~BinaryTree(){destroy(root);}

    void PreOrder(){cout<<"ǰ�������";PreOrder(root);cout<<endl;}
    void InOrder(){cout<<"�������: ";InOrder(root);cout<<endl;}
    void PostOrder(){cout<<"���������";PostOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"�������: ";LevelOrder(root);cout<<endl;}
    //friend istream&operator>>(istream &is,BinaryTree &BT);
    //friend ostream&operator<<(ostream &os,BinaryTree &BT);
    void pCreateBinaryTree();        //����ǰ�� �����������������ؽ����������ظ����ָ�븳��root
    void lCreateBinaryTree();        //������� �����������������ؽ����������ظ����ָ�븳��root

};



#endif // BINARYTREE_H_INCLUDED
