#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class HuffmanTree
{
private:
    Node *root;
    void destroy(Node *subtree);
    void PreOrder(Node *subtree);
    void InOrder(Node *subtree);
    void LevelOrder(Node *subtree);
    void PostOrder(Node *subtree);

public:
    HuffmanTree(double A[],int n);
    ~HuffmanTree(){destroy(root);}
    void PreOrder(){cout<<"前序遍历: ";PreOrder(root);cout<<endl;}
    void InOrder(){cout<<"中序遍历: ";InOrder(root);cout<<endl;}
    void PostOrder(){cout<<"后序遍历：";PostOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"按层遍历: ";LevelOrder(root);cout<<endl;}
    void MergeTree(Node &t1,Node &t2,Node &parent);

};

#endif // HUFFMAN_H_INCLUDED
