#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

struct ThreadNode
{
    int data;
    Node *lchild,*rchild;
    int ltag,rtag;
    Node(int _data):data(_data),lchild(NULL),rchild(NULL),ltag(0),rtag(0){}
};
class ThreadBTree
{
private:
    Node *root;
    void CreateInThread(Node *current,Node *&pre);                          //中序遍历建立线索二叉树
    Node *parent(Node *t);                                                  //寻找结点t的父结点
    void PreOrder(Node *subtree);
    void InOrder(Node *subtree);
    void PostOrder(Node *subtree);
public:
    ThreadBTree():root(NULL){}                                              //构造函数
    void CreateInThread();                                                  //建立中序线索二叉树
    Node *first(Node *current);                                             //寻找中序下第一个结点
    Node *last(Node *current);                                              //寻找中序下最后一个结点
    Node *next(Node *current);                                              //寻找结点在中序下的后继结点
    Node *prior(Node *current);                                             //寻找结点在中序下的前驱结点
    void PreOrder(cout<<"前序遍历：";PreOrder(root);cout<<endl;);                                                        //前序遍历
    void InOrder(cout<<"中序遍历：";InOrder(root);cout<<endl;);                                                         //中序遍历
    void PostOrder(cout<<"后序遍历：";PostOrder(root);cout<<endl;);                                                       //后序遍历

};

#endif // BINARYTREE_H_INCLUDED
