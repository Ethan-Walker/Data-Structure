//������Ů�ֵܱ�ʾ��
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
struct Node
{
    char data;
    Node *firstChild,*nextSibling;
    Node(char _data='\0',Node *f=NULL,Node *n=NULL):data(_data),firstChild(f),nextSibling(n){}
};
class Tree
{
private:
    Node *root,*current;                                         //������뵱ǰ���
    bool Find(Node *p,char ch);                                  //����pΪ��������������ch����ʹcurrentָ��ǰ���
    void Removesubtree(Node *p);                                 //ɾ����pΪ��������,��Ӱ�������ṹ
    bool FindParent(Node *t,Node *p);
    void PreOrder(Node *subtree);                                //�ȸ�����
    void PostOrder(Node *subtree);                               //�������
    void LevelOrder(Node *subtree);                              //�������
public:
    Tree():root(NULL),current(NULL){}
    ~Tree(){destroy(root);}
    bool Root();                                                 //Ѱ�Ҹ���ʹ֮��Ϊ��ǰ���
    bool IsEmpty(){return (root==NULL)?true:false;}              //�ж�����
    bool FirstChild();                                           //Ѱ�ҵ�ǰ���ĵ�һ����Ů��ʹ֮��Ϊ��ǰ���
    bool nextSibling();                                          //Ѱ�ҵ�ǰ������һ���ֵܣ�ʹ֮��Ϊ��ǰ���
    bool Parent();                                               //Ѱ�ҵ�ǰ���ĸ�ĸ��㣬ʹ֮��Ϊ��ǰ���
    bool Find(char target);                                      //Ѱ��������Ϊtarget�Ľ�㣬ʹ֮��Ϊ��ǰ���
    void destroy(Node *root);                                    //ֱ��ɾ��rootΪ��������
    void Create(char *&A);                                       //�Թ�������ʽ���벢������
    void Show(Node *t);                                          //�Թ�������ʽ�����
	void PreOrder(){cout<<"�ȸ�������";PreOrder(root);cout<<endl;}//�ȸ�����
	void PostOrder(){cout<<"���������";PostOrder(root);cout<<endl;} //�������
	void LevelOrder(){cout<<"���������";LevelOrder(root);cout<<endl;} //�������
	int Size(Node *subtree);                                      //�������Ľ����
	int Height(Node *subtree);                                    //�����������
};
#endif // TREE_H_INCLUDED
