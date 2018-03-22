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
    void CreateInThread(Node *current,Node *&pre);                          //���������������������
    Node *parent(Node *t);                                                  //Ѱ�ҽ��t�ĸ����
    void PreOrder(Node *subtree);
    void InOrder(Node *subtree);
    void PostOrder(Node *subtree);
public:
    ThreadBTree():root(NULL){}                                              //���캯��
    void CreateInThread();                                                  //������������������
    Node *first(Node *current);                                             //Ѱ�������µ�һ�����
    Node *last(Node *current);                                              //Ѱ�����������һ�����
    Node *next(Node *current);                                              //Ѱ�ҽ���������µĺ�̽��
    Node *prior(Node *current);                                             //Ѱ�ҽ���������µ�ǰ�����
    void PreOrder(cout<<"ǰ�������";PreOrder(root);cout<<endl;);                                                        //ǰ�����
    void InOrder(cout<<"���������";InOrder(root);cout<<endl;);                                                         //�������
    void PostOrder(cout<<"���������";PostOrder(root);cout<<endl;);                                                       //�������

};

#endif // BINARYTREE_H_INCLUDED
