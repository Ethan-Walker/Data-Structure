#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
using namespace std;
//用结构体定义树结点
struct BiTNode
{
    char data;                                                          //数据域
    BiTNode *lchild,*rchild;                                            //左子女，右子女
    BiTNode(char _data='\0'):data(_data),lchild(NULL),rchild(NULL){}    //构造函数

};

//二叉树定义
class BinaryTree
{
private:
    BiTNode *BiTree;                                                    //根结点
    void PreOrder(BiTNode *subtree);                                    //前序遍历
    void InOrder(BiTNode *subree);                                      //中序遍历
    void PostOrder(BiTNode *subtree);                                   //后序遍历
    void LevelOrder(BiTNode *subtree);                                  //按层遍历
    bool Insert(char ch,BiTNode *&subtree);                             //插入结点
    bool Remove(char ch,BiTNode *&subtree);                             //删除结点
    void Create(istream &is);                                           //初始创建二叉树
public:
    BinaryTree():BiTree(NULL){}                                         //构造函数
    ~BinaryTree(){destroy(BiTree);}                                     //析构函数
    void destroy(BiTNode *subtree);                                     //置空树
    bool Insert(const char ch){return Insert(ch,BiTree);}               //插入结点
    bool Remove(const char ch){return Remove(ch,BiTree);}               //删除结点
    void PreOrder(){cout<<"前序遍历：";PreOrder(BiTree);cout<<endl;}    //前序遍历
    void InOrder(){cout<<"中序遍历：";InOrder(BiTree);cout<<endl;}      //中序遍历
    void PostOrder(){cout<<"后序遍历: ";PostOrder(BiTree);cout<<endl;}  //后序遍历
    void LevelOrder(){cout<<"按层遍历: ";LevelOrder(BiTree);cout<<endl;}//按层遍历
    friend istream& operator>>(istream &is,BinaryTree &BT);             //运算符重载，重载>>

};


#endif // BINARYTREE_H_INCLUDED
