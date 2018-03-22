#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <class T>
struct Node                            //结点存储树中结点
{
    T data;
    Node<T> *lchild,*rchild;
    Node():lchild(NULL),rchild(NULL){}
    Node(T _data,Node<T> *p=NULL,Node<T> *q=NULL):data(_data),lchild(p),rchild(q){}
};
template <class T>
class BinaryTree;
template <class T>
istream&operator>>(istream&is,BinaryTree<T> &tree);
template <class T>
ostream&operator<<(ostream&os,BinaryTree<T> &tree);

template <class T>
class BinaryTree
{
public:
    BinaryTree():root(NULL){}                         //构造函数，根结点赋为空
    BinaryTree(T value):refvalue(value),root(NULL){}  //构造函数，创建对象的同时为其中数据输入停止标记refvalue赋值
    BinaryTree(BinaryTree<T> &s);                     //复制构造函数
    ~BinaryTree(){destroy(root);}                     //析构函数
    Node<T>* getRoot(){return root;}
    bool IsEmpty(){return (root==NULL)?1:0;}          //判断二叉树是否为空
    int Height(){return Height(root);}                                 //返回树高度
    int Size(){return Size(root);}                                     //返回结点个数

    void PreOrder(){cout<<"前序遍历:";PreOrder(root);cout<<endl;}                                   //前序遍历
    void InOrder(){cout<<"中序遍历：";InOrder(root);cout<<endl;}                                     //中序遍历
    void PostOrder(){cout<<"后序遍历:";PostOrder(root);cout<<endl;}                                 //后序遍历
    void LevelOrder(){cout<<"按层次序遍历：";LevelOrder(root);cout<<endl;}                               //按层次序遍历

    int Insert(const T&x);                                             //插入新元素x
    Node<T> *Find(T &x)const;                                          //查找元素为x的结点


    Node<T>* Parent(Node<T> *current)                                  //返回父结点
    {
        return (root==NULL||root=current)?NULL:Parent(root,current);
    }
    Node<T>* LeftChild(Node<T> *current)                               //返回左子女
    {
        return (current==NULL)?NULL:current->lchild;
    }
    Node<T>* RightChild(Node<T> *current)                              //返回右子女
    {
        return (current==NULL)?NULL:current->rchild;
    }
private:
    T refvalue;                                                        //数据输入停止的标志
    Node<T> *root;                                                        //定义根结点的指针

    bool Insert(Node<T> *&subtree,const T&x)const;                     //插入 Node *&subtree=root(函数传入);subtree 表示的是root指针的引用
                                                                       //*&的作用是使得通过subtree既能改变指针root的值，也能改变*root指向的值
    bool destroy(Node<T> *subtree);                                   //删除
    bool Find(Node<T> *subtree,const T&x)const;                        //查找
    Node<T>* Copy(Node<T> *orignode);                                  //复制并返回根结点
    int Height(Node<T> *subtree);                                         //返回树高度
    int Size(Node<T> *subtree);                                           //返回结点数

    void PreOrder(Node<T> *subtree);                                      //前序遍历
    void InOrder(Node<T> *subtree);                                       //中序遍历
    void PostOrder(Node<T> *subtree);                                     //后序遍历
    void LevelOrder(Node<T> *subtree);

    void CreateBinaryTree(istream&is,BinaryTree<T> &BT);                       //建树一
   // void CreateBinaryTree(istream&is,Node<T> *&subtree);                         //建树二
    friend istream&operator>> <>(istream &is,BinaryTree<T> &tree);        //重载输入二叉树
    friend ostream&operator<< <>(ostream &os,BinaryTree<T> &tree);        //重载输出二叉树

    Node<T>* Parent(Node<T> *subtree,Node<T> *current);                //返回父母结点
    bool Traverse(Node<T> *subtree,ostream& os);
};



//operator >>
template <class T>
istream& operator>>(istream &is,BinaryTree<T> &tree)                               //重载操作，输入并建立一棵二叉树，is是输入流对象
{
    tree.CreateBinaryTree(is,tree);
    return is;

}

//operator <<
template <class T>
ostream&operator<<(ostream &os,BinaryTree<T> &tree)                              //重载操作，调用traverse前序遍历输出二叉树
{
    os<<"二叉树的前序遍历:"<<endl;
    tree.Traverse(tree.root,os);
    os<<endl;
    return os;
}

//Traverse
template <class T>
bool BinaryTree<T>::Traverse(Node<T>* subtree,ostream  &os)                 //从subtree结点开始，前序遍历并输出
{
    if(subtree!=NULL)
    {
        os<<subtree->data<<" ";
        Traverse(subtree->lchild,os);
        Traverse(subtree->rchild,os);

    }
    return true;
}
//destroy
template <class T>
bool BinaryTree <T> :: destroy ( Node<T>  *subtree)                            //私有函数，如果subtree不为空，则删除根节点为subtree的子树
{
    if(subtree!=NULL)                                                          //递归删除subtree
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
    return true;
}


//Height
template <class T>
int BinaryTree<T>::Height(Node<T> *subtree)              //计算树的高度
{
    if(subtree==NULL) return 0;
    int i=Height(subtree->lchild);                                    //左子树高度
    int j=Height(subtree->rchild);                                     //右子树高度
    return (i>j)?i+1:j+1;                                             //树的高度等于左右子树高度较大值+1（算上根结点）
}


//Size
template <class T>
int BinaryTree<T>::Size(Node<T> *subtree)                             //计算树中结点个数
{
    return 1+Size(subtree->lchild)+Size(subtree->rchild);             //根结点数1+左子树结点个数+右子树结点个数
}

//复制构造函数
template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &s)                                     //复制构造函数
{
    root=Copy(s.root);
}


//Copy
template <class T>
Node<T>* BinaryTree<T>::Copy(Node<T> *orignode)                       //复制树
{
        if(orignode==NULL) return NULL;
        Node<T> *p=new Node<T>;
        p->data=orignode->data;                                        //复制根结点
        p->lchild=Copy(orignode->lchild);                              //复制左子树
        p->rchild=Copy(orignode->rchild);                              //复制右子树

         return p;
}

//==  调用equal
template <class T>
int operator==(const BinaryTree<T> &s,const BinaryTree<T> &t)          //公有函数，调用Equal，并传入两树的根结点
{
    return Equal(s.root,t.root)?true:false;
}


//Equal
template <class T>
bool Equal(Node<T> *a,Node<T> *b)
{
    if(a==NULL&&b==NULL) return true;
    if(a!=NULL&&b!=NULL&&a->data==b->data&&Equal(a->lchild,b->lchild)&&Equal(a->rchild,b->rchild))
        //如果a，b不为空，且a，b结点数据相等，且a，b左右子树相等，则返回真
        return true;
    else return false;
}


//Parent
template <class T>
Node<T>* BinaryTree<T>::Parent(Node<T> *subtree,Node<T> *current)             //从结点subtree开始搜索，搜索current的父结点并返回
{
    Node<T> *p;
    if(subtree==NULL)   return NULL;
    if(subtree->lchild==current||subtree->rchild==current) return subtree;
    else {
            p=Parent(subtree->lchild,current);
            if(p!=NULL) return p;
    else return Parent(subtree->rchild,current);
    }

}
/*
//递归遍历

//preorder
template <class T>
void BinaryTree<T>::PreOrder(Node<T> *subtree)                   //前序遍历
{
    if(subtree!=NULL)
    {
        cout<<subtree->data<<" ";
        PreOrder(subtree->lchild);
        PreOrder(subtree->rchild);
    }
}

//InOrder
template <class T>
void BinaryTree<T>::InOrder(Node<T> *subtree)                    //中序遍历
{
    if(subtree!=NULL)
    {
        InOrder(subtree->lchild);
        cout<<subtree->data<<" ";
        InOrder(subtree->rchild);
    }
}

//PostOrder
template <class T>
void BinaryTree<T>::PostOrder(Node<T> *subtree)                     //后序遍历
{

    if(subtree!=NULL)
    {
        PostOrder(subtree->lchild);
        PostOrder(subtree->rchild);
        cout<<subtree->data<<" ";
    }
}
*/
//非递归遍历,利用栈
//preorder前序遍历，inorder中序遍历，postorder后序遍历


//前序遍历方法一：只压右子树
template <class T>
void BinaryTree<T>::PreOrder(Node<T> *subtree)
{
	stack<Node<T>*> s;
	s.push(NULL);
	Node<T> *p=subtree;                                  //p保存根结点指针
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		if(p->rchild!=NULL) s.push(p->rchild);           //预留右子树指针留在栈中
		if(p->lchild!=NULL) p=p->lchild;                 //左子树不为空，进左子树
		else {p=s.top();s.pop();}                        //左子树为空，退栈并得到右子树指针
    }
}

//前序遍历方法二:先压右子树，再压左子树
/*template <class T>
void BinaryTree<T>::PreOrder(Node<T> *subtree)
{
	stack<Node<T>*> s;
	s.push(subtree);
	Node<T> *p=subtree;
	while(!s.empty())                                    //当栈不为空，一直循环
	{
		p=s.top();
		s.pop();
		cout<<p->data<<" ";
		if(p->rchild!=NULL) s.push(p->rchild);
		if(p->lchild!=NULL) s.push(p->lchild);
	}
}
*/

//中序遍历
template <class T>
void BinaryTree<T>::InOrder(Node<T> *subtree)
{
	stack<Node<T>*> s;
    Node<T> *p=subtree;
    do
    {
        while(p!=NULL)                                    //p不为空使，循环压入左子女
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())                                    //如果栈不为空，退栈并得到根结点，同时输出根结点数据，访问右结点
        {
            p=s.top();
            s.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }

    }while(p!=NULL||!s.empty());                          //当栈为空，且p为空及访问到的最后的右结点时，退出循环，否则再循环压入p的左结点

}


//后序遍历，需要判断从左子树退回还是右子树退回，新建节点结构体，含标记值
template <class T>
struct stkNode                                            //遍历时所用栈结点类定义
{
    Node<T> *ptr;                                         //指向树结点的指针
    int tag;                                              //该结点退栈的标记值，L代表从左子树退回，R代表从右子树退回
    stkNode(Node<T> *N=NULL):ptr(N),tag(0){}              //构造函数,创建一个stkNode结点时，默认结点指针为NULL，标记值为L
};
template <class T>
void BinaryTree<T>::PostOrder(Node<T> *subtree)
{
    stack< stkNode<T> > s;
    stkNode<T> w;
    Node<T> *p=subtree;                                   //p是遍历指针
    do
    {
        while(p!=NULL)                                    //向最左下方的结点循环下去，直到为空
        {
            w.ptr=p;                                      //左子树结点指针赋给w.ptr
            w.tag=0;                                      //w.tag赋为L标记
            s.push(w);                                    //压栈
            p=p->lchild;                                  //向左下方结点走下去
        }
        int continue1=1;                                  //循环的标记，用于当从右子树退回时，需要循环退栈两或多次
        while(continue1&&!s.empty())                      //栈不空则退栈
        {
            w=s.top();
            s.pop();
            p=w.ptr;
            switch(w.tag)                                 //判断栈顶结点指针的标记值
            {
            case 0:w.tag=1;                               //从左子树退回，则修改栈顶标记值后重新压栈
                   s.push(w);
                   continue1=0;                           //不是右子树退回，则不用再循环退栈，continue1赋为0
                   p=p->rchild;                           //访问右子树，跳到大循环do while中，将其左下方结点一直压栈……
                   break;
            case 1:cout<<w.ptr->data<<" ";                //从右子树退回，输出栈顶值，即根结点的值，继续循环退栈
                   break;
            }
        }
    }while(!s.empty());                                    //栈为空时退出循环
    cout<<endl;
}
/*
//CreateBinaryTree  通过前序遍历输入创建二叉树，注意左右子树为空时，要输入#作为终止符
template <class T>
void BinaryTree<T>::CreateBinaryTree(istream&is,Node<T> *&subtree)
//私有函数，以递归方式建立二叉树
{
	T item;
	if(!is.eof())                       //未读完，输入流仍有值，继续读入并建树
	{
		is>>item;
		if(item!=refvalue)                  //输入的不是终止标记
		{
			subtree=new Node<T>(item);      //新建根节点，并赋入刚刚输入的数据
			if(subtree==NULL)
			{
				cerr<<"存储分配错！"<<endl;          //分配失败，异常退出
			}
			CreateBinaryTree(is,subtree->lchild);         //递归建立左子树
			CreateBinaryTree(is,subtree->rchild);         //递归建立右子树
		}
	}
}
*/

//CreateBinaryTree 以输入广义表的形式创建二叉树
template <class T>
void BinaryTree<T>::CreateBinaryTree(istream&is,BinaryTree<T> &BT)                //以输入广义表的方式表示要建立的二叉树
{
    stack<Node<T>*> s;
    BT.root=NULL;
    Node<T> *p,*t;
    int k=0;                                                                      //k作为处理左右子树标记
    cout<<"请按照广义表形式输入二叉树"<<endl;
    cout<<"注意：只有左子女或者右子女括号内逗号不能省略"<<endl;
    T ch;
    is>>ch;
    while(ch!=refvalue)                                                         //逐个字符处理
    {
        switch(ch)
        {
            case '(':s.push(p);k=1;break;  //遇到左括号将前一次创建的结点p压栈，k=1，标记即将输入的字符要连接于p的左子女
            case ')':t=s.top();s.pop();break; //遇到右括号，得到栈顶元素并退栈，实际上就是退出子树
            case ',':k=2;break;               //遇到逗号，k=2，标记即将输入的字符要连接于栈顶结点的右子女上
            default:p=new Node<T>(ch);            //创建结点保存输入的字符值
                  if(BT.root==NULL) BT.root=p;           //第一次输入，将BT保存树的根结点p
                  else if(k==1)
                        {
                            t=s.top();t->lchild=p;             //链接t的左子女
                        }
                  else if(k==2)
                  {
                      t=s.top();t->rchild=p;                   //链接t的右子女
                  }

        }
          is>>ch;
    }
}


//LevelOrder 利用队列按层次序输出二叉树
template <class T>
void BinaryTree<T>::LevelOrder(Node<T> *subtree)
{
    queue<Node<T>*> q;
    Node<T> *s;
    q.push(subtree);
    while(!q.empty())
    {
        s=q.front();                           //得到队首元素
        q.pop();
        cout<<s->data<<" ";
        if(s->lchild!=NULL) q.push(s->lchild);
        if(s->rchild!=NULL) q.push(s->rchild);
    }
}




//PrintBtree  以广义表的形式输出二叉树
template <class T>
void PrintBTree(Node<T> *BT)
//以广义表的形式输出二叉树
{
	if(BT!=NULL)                                     //树为空时结束递归
	{
		cout<<BT->data;                              //输出根结点数据
		if(BT->lchild!=NULL||BT->rchild!=NULL)       //根结点子树不全为空
		{
			cout<<"(";
			PrintBTree(BT->lchild);                  //递归输出左子树
			cout<<",";
			PrintBTree(BT->rchild);                  //递归输出右子树
			cout<<")";
		}
	}
}


#endif // BINARYTREE_H_INCLUDED
