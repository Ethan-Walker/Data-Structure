#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int Max=1024;
struct Node
{
    char data;
    Node *parent,*lchild,*rchild;
    Node(char _data):data(_data),parent(NULL),lchild(NULL),rchild(NULL){}
};
class BinaryTree
{
private:
    Node *root;
    int n;                                               //二叉树结点总数，计数作用，到最后一个节点时不输出空格
    void PreOrder(Node *subtree,int n);
    void InOrder(Node *subtree,int n);
    void PostOrder(Node *subtree,int n);

    void CreateBT(istream&is,BinaryTree &BT);

public:
    void PreOrder(){/*cout<<"前序遍历:";*/PreOrder(root,n);cout<<endl;}
    void InOrder(){/*cout<<"中序遍历:";*/InOrder(root,n);cout<<endl;}
    void PostOrder(){/*cout<<"后序遍历:";*/PostOrder(root,n);cout<<endl;}

    friend istream&operator>>(istream&is,BinaryTree &BT);

};

int main()
{
    BinaryTree s;
    cin>>s;
    s.PreOrder();
    s.InOrder();
    s.PostOrder();
    return 0;
}
istream& operator>>(istream&is,BinaryTree &BT)
{
    BT.CreateBT(is,BT);
    return is;
}

//核心算法，利用队列将输入的结点数据转换成二叉树
void BinaryTree::CreateBT(istream &is,BinaryTree &BT)
{
    Node *p,*p1;
    queue<Node*> q;
    BT.root=NULL;
    char S[Max][10];
    int k=0,i,j;
    while(is>>S[k]) k++;
    BT.n=k;
    p=new Node(S[0][0]);                                         //p初始化为根结点
    for(i=0;i<k;i++)
    {
        j=0;
        p1=new Node(S[i][j]);                                    //新建结点p1并赋值
        j+=2;                                                    //跳到父结点下标，例：跳到B(A,1)中的A位置
        switch(S[i][j])
        {
            case '0':p1->parent=NULL;BT.root=p;break;            //若p为根结点，则无父节点，赋为空，把p地址赋给二叉树的根结点
            default:                                             //非根结点
                while(p->data!=S[i][j]&&!q.empty())              //如果队列不为空且p1中父结点不为p，循环出队列，直到p得到的是p1的父结点
                {
                    p=q.front();                                 //得到队首元素
                    q.pop();                                     //出队
                }
                j+=2;                                             //跳到数值位，判断p1是p的左子女还是右子女
                switch(S[i][j])
                {

                    case '1':p->lchild=p1;p1->parent=p;break;     //左子女，p1连接到p的左子女指针，p为p1的父结点
                    case '2':p->rchild=p1;p1->parent=p;break;     //右子女，p1连接到p的右子女指针，p为p1的父结点
                }

        }
        q.push(p1);                                               //将刚刚新建并处理的结点入队

    }

}
//非递归输出
void BinaryTree::PreOrder(Node *subtree,int n)
{
   stack<Node *> s;
   while(subtree!=NULL||!s.empty())
   {
       if(subtree!=NULL)
        {
            if(n>1)
            cout<<subtree->data<<" ";
            else cout<<subtree->data;
            n--;
            s.push(subtree);
            subtree=subtree->lchild;
        }
        else
        {
            subtree=s.top();
            s.pop();
            subtree=subtree->rchild;
        }
   }
}
void BinaryTree::InOrder(Node *subtree,int n)
{
    stack<Node*> s;
    while(!s.empty()||subtree!=NULL)
    {
        if(subtree!=NULL)
        {
            s.push(subtree);
            subtree=subtree->lchild;
        }
        else{
            subtree=s.top();
            s.pop();
            if(n>1) cout<<subtree->data<<" ";
            else cout<<subtree->data;
            n--;
            subtree=subtree->rchild;
        }
    }
}
//非递归后序遍历
struct stkNode                                            //遍历时所用栈结点类定义
{
    Node *ptr;                                         //指向树结点的指针
    int tag;                                       //该结点退栈的标记值，L代表从左子树退回，R代表从右子树退回
    stkNode(Node *N=NULL):ptr(N),tag(0){}              //构造函数,创建一个stkNode结点时，默认结点指针为NULL，标记值为L
};
void BinaryTree::PostOrder(Node *subtree,int n)
{
    stack<stkNode> s;
    stkNode w;
    Node *p=subtree;                                   //p是遍历指针
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
            case 1:
                   if(n>1)cout<<w.ptr->data<<" ";                //从右子树退回，输出栈顶值，即根结点的值，继续循环退栈
                   else cout<<w.ptr->data;
                   n--;
                   break;
            }
        }
    }while(!s.empty());                                    //栈为空时退出循环
}

