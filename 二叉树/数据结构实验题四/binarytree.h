#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *lchild,*rchild;
    Node():lchild(NULL),rchild(NULL){}
    Node(int _data,Node *lch=NULL,Node *rch=NULL):data(_data),lchild(lch),rchild(rch){};

};
class BinaryTree
{
private:
    Node *root;
    char refvalue;

    void PreOrder(Node *subtree);
    void InOrder(Node *subtree);
    void PostOrder(Node *subtree);
    void LevelOrder(Node *shbtree);

    int Size(Node *subtree);
    int Height(Node *subtree);
    Node* Copy(Node *subtree);

    void Traverse(ostream&os,Node *subtree);
    void CreateBT(istream&is,BinaryTree &BT);

public:
    BinaryTree(const BinaryTree &s);
    BinaryTree(char ref='#'):refvalue(ref),root(NULL){}
    //~BinaryTree(){destroy(root);}
    void destroy(Node *subtree);

    void PreOrder(){cout<<"前序遍历：";PreOrder(root);cout<<endl;}
    void InOrder(){cout<<"中序遍历：";InOrder(root);cout<<endl;}
    void PostOrder(){cout<<"后序遍历：";PostOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"按层遍历：";LevelOrder(root);cout<<endl;}

    int Size(){return Size(root);}
    int Height(){return Height(root);}
    Node *getRoot(){return root;}
    bool IsEmpty(){return (root==NULL)?true:false;}

    friend istream& operator>>(istream&is,BinaryTree &BT);
    friend ostream& operator<<(ostream&os,BinaryTree &BT);

};

#endif // BINARYTREE_H_INCLUDED
