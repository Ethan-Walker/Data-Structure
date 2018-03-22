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

   Node* pCreateBinaryTree(char *pre,char *in,int n);         //按传入的前序遍历pre， 中序遍历in，结点个数n，重建二叉树
   Node* lCreateBinaryTree(char *post,char *in,int n);        //按传入的后序遍历post，中序遍历in，结点个数n，重建二叉树

   void destroy(Node *subtree);


public:
    BinaryTree(char t='#'):root(NULL),tag(t){};
    ~BinaryTree(){destroy(root);}

    void PreOrder(){cout<<"前序遍历：";PreOrder(root);cout<<endl;}
    void InOrder(){cout<<"中序遍历: ";InOrder(root);cout<<endl;}
    void PostOrder(){cout<<"后序遍历：";PostOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"按层遍历: ";LevelOrder(root);cout<<endl;}
    //friend istream&operator>>(istream &is,BinaryTree &BT);
    //friend ostream&operator<<(ostream &os,BinaryTree &BT);
    void pCreateBinaryTree();        //输入前序 中序遍历结果，调用重建函数，返回根结点指针赋给root
    void lCreateBinaryTree();        //输入后序 中序遍历结果，调用重建函数，返回根结点指针赋给root

};



#endif // BINARYTREE_H_INCLUDED
