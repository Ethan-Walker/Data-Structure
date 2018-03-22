#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

#include <iostream>
#include "Node.h"
using namespace std;

class HuffmanTree
{
private:
    Node *root;                               //�����
    void destroy(Node *subtree);              //ɾ����
    void PreOrder(Node *subtree);             //ǰ�����
    void InOrder(Node *subtree);              //�������
    void LevelOrder(Node *subtree);           //�������
    void PostOrder(Node *subtree);            //�������
    void HuffmanCode(Node *&subtree,string st[50],char ch[]);         //���Ѵ����õ�Huffman�����б���
public:
    HuffmanTree(int A[],char B[],int n);      //���캯��
    ~HuffmanTree(){destroy(root);}            //��������
    void PreOrder(){cout<<"ǰ�����: ";PreOrder(root);cout<<endl;}
    void InOrder(){cout<<"�������: ";InOrder(root);cout<<endl;}
    void PostOrder(){cout<<"���������";PostOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"�������: ";LevelOrder(root);cout<<endl;}
    void MergeTree(Node *&t1,Node *&t2,Node *&parent);                            //�ϲ�����
    void HuffmanCode(string st[50],char ch[]){cout<<endl<<"ÿ���ַ�������: "<<endl;HuffmanCode(root,st,ch);cout<<endl;} //���ñ��뺯��

};

#endif // HUFFMAN_H_INCLUDED
