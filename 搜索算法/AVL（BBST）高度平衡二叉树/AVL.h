#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include <iostream>
using namespace std;
struct AVLNode
{
    int data;
    int bf;                      //平衡因子
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
    void Initial();                        //初始化创建二叉搜索树
    bool Insert(const int x){return Insert(x,root);}
    bool Remove(int x){return Remove(x,root);}
    bool Search(int x){return Search(x,root);}
    void RotateL(AVLNode *&ptr);               //左单旋
    void RotateR(AVLNode *&ptr);               //右单旋
    void RotateLR(AVLNode *&ptr);              //先左旋后右旋
    void RotateRL(AVLNode *&ptr);              //先右旋后左旋
    int Height(AVLNode *ptr);
    void InOrder(){cout<<"中序遍历: ";InOrder(root);cout<<endl;}
    void LevelOrder(){cout<<"按层遍历：";LevelOrder(root);cout<<endl;}
};


#endif // AVL_H_INCLUDED
