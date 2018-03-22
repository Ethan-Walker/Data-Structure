#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
using namespace std;
const int Max=1024;
struct Node
{
    char data;
    Node *parent,*lchild,*rchild;
    Node(char _data):data(_data),parent(NULL),lchild(NULL),rchild(NULL){}
};
class BinaryTree
{
private:
    Node *root;

    void PreOrder(Node *subtree);
    void InOrder(Node *subtree);
    void PostOrder(Node *subtree);

    void CreateBT(istream&is,BinaryTree &BT);

public:
    void PreOrder(){PreOrder(root);cout<<endl;}
    void InOrder(){InOrder(root);cout<<endl;}
    void PostOrder(){PostOrder(root);cout<<endl;}

    friend istream&operator>>(istream&is,BinaryTree &BT);

};

#endif // BINARYTREE_H_INCLUDED
