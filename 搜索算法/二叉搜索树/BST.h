#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>
using namespace std;
struct BSTNode
{
    int data;
    BSTNode *lchild,*rchild;
    BSTNode(int _data=0):data(_data),lchild(NULL),rchild(NULL){}

};

class BST
{
private:
    BSTNode *root;
    bool Insert(int x,BSTNode *&subtree);              //������
    bool Remove(int x,BSTNode *&subtree);              //ɾ�����
    BSTNode* Search(int x,BSTNode *subtree);           //���ҽ��
    void destroy(BSTNode *subtree);                    //�ͷ���
    void PreOrder(BSTNode *subtree);                   //ǰ�����
    void InOrder(BSTNode *subtree);                    //�������
    void LevelOrder(BSTNode *subtree);                 //�������
public:
    BST():root(NULL){}                                 //���캯��
    ~BST(){destroy(root);}                             //��������
    bool Insert(const int x){return Insert(x,root);}  //������
    bool Remove(int x){return Remove(x,root);}         //ɾ�����
    bool Search(const int x){return (Search(x,root)!=NULL)?true:false;} //���ҽ��

    void LevelOrder(){cout<<"���������";LevelOrder(root);cout<<endl;} //�������
    void PreOrder(){cout<<"ǰ�������";PreOrder(root);cout<<endl;}    //ǰ���������������
    void InOrder(){cout<<"���������";InOrder(root);cout<<endl;}     //�����������������
    void Traverse(ostream &os,BSTNode *subtree);        //�����������������
    friend istream&operator>>(istream &is,BST &B);      //���������
    friend ostream&operator<<(ostream &os,BST &B);      //���������
};
#endif // BST_H_INCLUDED
