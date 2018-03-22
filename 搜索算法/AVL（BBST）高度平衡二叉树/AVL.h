#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include <iostream>
using namespace std;
struct AVLNode
{
    int data;
    int bf;                      //ƽ������
    AVLNode *lchild,*rchild;
    AVLNode(int da=0):data(da),bf(0),lchild(NULL),rchild(NULL){}
};
class AVLTree{
private:
    AVLNode *root;
    bool Insert(int x,AVLNode *&ptr);
    bool Remove(int x,AVLNode *&ptr);
    AVLNode* Search(int x,AVLNode *ptr);
    void InOrder(AVLNode *subtree);
    void LevelOrder(AVLNode *subtree);
public:
    AVLTree():root(NULL){}
    void Initial();                        //��ʼ����������������
    bool Insert(const int x){return Insert(x,root);}
    bool Remove(int x){return Remove(x,root);}
    bool Search(int x){return Search(x,root);}
    void RotateL(AVLNode *&ptr);               //����
    void RotateR(AVLNode *&ptr);               //�ҵ���
    void RotateLR(AVLNode *&ptr);              //������������
    void RotateRL(AVLNode *&ptr);              //������������
    int Height(AVLNode *ptr);
    void InOrder(){cout<<"�������: ";InOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"���������";LevelOrder(root);cout<<endl;}
};


#endif // AVL_H_INCLUDED
