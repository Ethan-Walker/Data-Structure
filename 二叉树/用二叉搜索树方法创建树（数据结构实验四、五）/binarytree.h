#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
using namespace std;
//�ýṹ�嶨�������
struct BiTNode
{
    char data;                                                          //������
    BiTNode *lchild,*rchild;                                            //����Ů������Ů
    BiTNode(char _data='\0'):data(_data),lchild(NULL),rchild(NULL){}    //���캯��

};

//����������
class BinaryTree
{
private:
    BiTNode *BiTree;                                                    //�����
    void PreOrder(BiTNode *subtree);                                    //ǰ�����
    void InOrder(BiTNode *subree);                                      //�������
    void PostOrder(BiTNode *subtree);                                   //�������
    void LevelOrder(BiTNode *subtree);                                  //�������
    bool Insert(char ch,BiTNode *&subtree);                             //������
    bool Remove(char ch,BiTNode *&subtree);                             //ɾ�����
    void Create(istream &is);                                           //��ʼ����������
public:
    BinaryTree():BiTree(NULL){}                                         //���캯��
    ~BinaryTree(){destroy(BiTree);}                                     //��������
    void destroy(BiTNode *subtree);                                     //�ÿ���
    bool Insert(const char ch){return Insert(ch,BiTree);}               //������
    bool Remove(const char ch){return Remove(ch,BiTree);}               //ɾ�����
    void PreOrder(){cout<<"ǰ�������";PreOrder(BiTree);cout<<endl;}    //ǰ�����
    void InOrder(){cout<<"���������";InOrder(BiTree);cout<<endl;}      //�������
    void PostOrder(){cout<<"�������: ";PostOrder(BiTree);cout<<endl;}  //�������
    void LevelOrder(){cout<<"�������: ";LevelOrder(BiTree);cout<<endl;}//�������
    friend istream& operator>>(istream &is,BinaryTree &BT);             //��������أ�����>>

};


#endif // BINARYTREE_H_INCLUDED
