#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

#include <iostream>
#include "Node.h"
using namespace std;

class HuffmanTree
{
private:
    Node *root;                               //根结点
    void destroy(Node *subtree);              //删除树
    void PreOrder(Node *subtree);             //前序遍历
    void InOrder(Node *subtree);              //中序遍历
    void LevelOrder(Node *subtree);           //按层遍历
    void PostOrder(Node *subtree);            //后序遍历
    void HuffmanCode(Node *&subtree,string st[50],char ch[]);         //对已创建好的Huffman树进行编码
public:
    HuffmanTree(int A[],char B[],int n);      //构造函数
    ~HuffmanTree(){destroy(root);}            //析构函数
    void PreOrder(){cout<<"前序遍历: ";PreOrder(root);cout<<endl;}
    void InOrder(){cout<<"中序遍历: ";InOrder(root);cout<<endl;}
    void PostOrder(){cout<<"后序遍历：";PostOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"按层遍历: ";LevelOrder(root);cout<<endl;}
    void MergeTree(Node *&t1,Node *&t2,Node *&parent);                            //合并子树
    void HuffmanCode(string st[50],char ch[]){cout<<endl<<"每个字符编码结果: "<<endl;HuffmanCode(root,st,ch);cout<<endl;} //调用编码函数

};

#endif // HUFFMAN_H_INCLUDED
