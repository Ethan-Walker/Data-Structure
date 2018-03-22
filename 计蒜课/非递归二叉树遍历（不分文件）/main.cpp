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
    int n;                                               //����������������������ã������һ���ڵ�ʱ������ո�
    void PreOrder(Node *subtree,int n);
    void InOrder(Node *subtree,int n);
    void PostOrder(Node *subtree,int n);

    void CreateBT(istream&is,BinaryTree &BT);

public:
    void PreOrder(){/*cout<<"ǰ�����:";*/PreOrder(root,n);cout<<endl;}
    void InOrder(){/*cout<<"�������:";*/InOrder(root,n);cout<<endl;}
    void PostOrder(){/*cout<<"�������:";*/PostOrder(root,n);cout<<endl;}

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

//�����㷨�����ö��н�����Ľ������ת���ɶ�����
void BinaryTree::CreateBT(istream &is,BinaryTree &BT)
{
    Node *p,*p1;
    queue<Node*> q;
    BT.root=NULL;
    char S[Max][10];
    int k=0,i,j;
    while(is>>S[k]) k++;
    BT.n=k;
    p=new Node(S[0][0]);                                         //p��ʼ��Ϊ�����
    for(i=0;i<k;i++)
    {
        j=0;
        p1=new Node(S[i][j]);                                    //�½����p1����ֵ
        j+=2;                                                    //����������±꣬��������B(A,1)�е�Aλ��
        switch(S[i][j])
        {
            case '0':p1->parent=NULL;BT.root=p;break;            //��pΪ����㣬���޸��ڵ㣬��Ϊ�գ���p��ַ�����������ĸ����
            default:                                             //�Ǹ����
                while(p->data!=S[i][j]&&!q.empty())              //������в�Ϊ����p1�и���㲻Ϊp��ѭ�������У�ֱ��p�õ�����p1�ĸ����
                {
                    p=q.front();                                 //�õ�����Ԫ��
                    q.pop();                                     //����
                }
                j+=2;                                             //������ֵλ���ж�p1��p������Ů��������Ů
                switch(S[i][j])
                {

                    case '1':p->lchild=p1;p1->parent=p;break;     //����Ů��p1���ӵ�p������Ůָ�룬pΪp1�ĸ����
                    case '2':p->rchild=p1;p1->parent=p;break;     //����Ů��p1���ӵ�p������Ůָ�룬pΪp1�ĸ����
                }

        }
        q.push(p1);                                               //���ո��½�������Ľ�����

    }

}
//�ǵݹ����
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
//�ǵݹ�������
struct stkNode                                            //����ʱ����ջ����ඨ��
{
    Node *ptr;                                         //ָ��������ָ��
    int tag;                                       //�ý����ջ�ı��ֵ��L������������˻أ�R������������˻�
    stkNode(Node *N=NULL):ptr(N),tag(0){}              //���캯��,����һ��stkNode���ʱ��Ĭ�Ͻ��ָ��ΪNULL�����ֵΪL
};
void BinaryTree::PostOrder(Node *subtree,int n)
{
    stack<stkNode> s;
    stkNode w;
    Node *p=subtree;                                   //p�Ǳ���ָ��
    do
    {
        while(p!=NULL)                                    //�������·��Ľ��ѭ����ȥ��ֱ��Ϊ��
        {
            w.ptr=p;                                      //���������ָ�븳��w.ptr
            w.tag=0;                                      //w.tag��ΪL���
            s.push(w);                                    //ѹջ
            p=p->lchild;                                  //�����·��������ȥ
        }
        int continue1=1;                                  //ѭ���ı�ǣ����ڵ����������˻�ʱ����Ҫѭ����ջ������
        while(continue1&&!s.empty())                      //ջ��������ջ
        {
            w=s.top();
            s.pop();
            p=w.ptr;
            switch(w.tag)                                 //�ж�ջ�����ָ��ı��ֵ
            {
            case 0:w.tag=1;                               //���������˻أ����޸�ջ�����ֵ������ѹջ
                   s.push(w);
                   continue1=0;                           //�����������˻أ�������ѭ����ջ��continue1��Ϊ0
                   p=p->rchild;                           //������������������ѭ��do while�У��������·����һֱѹջ����
                   break;
            case 1:
                   if(n>1)cout<<w.ptr->data<<" ";                //���������˻أ����ջ��ֵ����������ֵ������ѭ����ջ
                   else cout<<w.ptr->data;
                   n--;
                   break;
            }
        }
    }while(!s.empty());                                    //ջΪ��ʱ�˳�ѭ��
}

