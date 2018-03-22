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
    bool Insert(int x,BSTNode *&subtree);              //插入结点
    bool Remove(int x,BSTNode *&subtree);              //删除结点
    BSTNode* Search(int x,BSTNode *subtree);           //查找结点
    void destroy(BSTNode *subtree);                    //释放树
    void PreOrder(BSTNode *subtree);                   //前序遍历
    void InOrder(BSTNode *subtree);                    //中序遍历
    void LevelOrder(BSTNode *subtree);                 //按层遍历
public:
    BST():root(NULL){}                                 //构造函数
    ~BST(){destroy(root);}                             //析构函数
    bool Insert(const int x){return Insert(x,root);}  //插入结点
    bool Remove(int x){return Remove(x,root);}         //删除结点
    bool Search(const int x){return (Search(x,root)!=NULL)?true:false;} //查找结点

    void LevelOrder(){cout<<"按层遍历：";LevelOrder(root);cout<<endl;} //按层遍历
    void PreOrder(){cout<<"前序遍历：";PreOrder(root);cout<<endl;}    //前序遍历二叉搜索树
    void InOrder(){cout<<"中序遍历：";InOrder(root);cout<<endl;}     //中序遍历二叉搜索树
    void Traverse(ostream &os,BSTNode *subtree);        //中序遍历二叉搜索树
    friend istream&operator>>(istream &is,BST &B);      //运算符重载
    friend ostream&operator<<(ostream &os,BST &B);      //运算符重载
};
#endif // BST_H_INCLUDED
