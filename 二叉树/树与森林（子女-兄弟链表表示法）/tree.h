//树的子女兄弟表示法
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
    Node *root,*current;                                         //根结点与当前结点
    bool Find(Node *p,char ch);                                  //在以p为根结点的树中搜索ch，并使current指向当前结点
    void Removesubtree(Node *p);                                 //删除以p为根的子树,不影响其他结构
    bool FindParent(Node *t,Node *p);
    void PreOrder(Node *subtree);                                //先根遍历
    void PostOrder(Node *subtree);                               //后根遍历
    void LevelOrder(Node *subtree);                              //按层遍历
public:
    Tree():root(NULL),current(NULL){}
    ~Tree(){destroy(root);}
    bool Root();                                                 //寻找根，使之成为当前结点
    bool IsEmpty(){return (root==NULL)?true:false;}              //判断树空
    bool FirstChild();                                           //寻找当前结点的第一个子女，使之成为当前结点
    bool nextSibling();                                          //寻找当前结点的下一个兄弟，使之成为当前结点
    bool Parent();                                               //寻找当前结点的父母结点，使之成为当前结点
    bool Find(char target);                                      //寻找数据域为target的结点，使之成为当前结点
    void destroy(Node *root);                                    //直接删除root为根结点的树
    void Create(char *&A);                                       //以广义表的形式输入并创建树
    void Show(Node *t);                                          //以广义表的形式输出树
	void PreOrder(){cout<<"先根遍历：";PreOrder(root);cout<<endl;}//先根遍历
	void PostOrder(){cout<<"后根遍历：";PostOrder(root);cout<<endl;} //后根遍历
	void LevelOrder(){cout<<"按层遍历：";LevelOrder(root);cout<<endl;} //按层遍历
	int Size(Node *subtree);                                      //计算树的结点数
	int Height(Node *subtree);                                    //计算树的深度
};
#endif // TREE_H_INCLUDED
