#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <class T>
struct Node                            //���洢���н��
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
    BinaryTree():root(NULL){}                         //���캯��������㸳Ϊ��
    BinaryTree(T value):refvalue(value),root(NULL){}  //���캯�������������ͬʱΪ������������ֹͣ���refvalue��ֵ
    BinaryTree(BinaryTree<T> &s);                     //���ƹ��캯��
    ~BinaryTree(){destroy(root);}                     //��������
    Node<T>* getRoot(){return root;}
    bool IsEmpty(){return (root==NULL)?1:0;}          //�ж϶������Ƿ�Ϊ��
    int Height(){return Height(root);}                                 //�������߶�
    int Size(){return Size(root);}                                     //���ؽ�����

    void PreOrder(){cout<<"ǰ�����:";PreOrder(root);cout<<endl;}                                   //ǰ�����
    void InOrder(){cout<<"���������";InOrder(root);cout<<endl;}                                     //�������
    void PostOrder(){cout<<"�������:";PostOrder(root);cout<<endl;}                                 //�������
    void LevelOrder(){cout<<"������������";LevelOrder(root);cout<<endl;}                               //����������

    int Insert(const T&x);                                             //������Ԫ��x
    Node<T> *Find(T &x)const;                                          //����Ԫ��Ϊx�Ľ��


    Node<T>* Parent(Node<T> *current)                                  //���ظ����
    {
        return (root==NULL||root=current)?NULL:Parent(root,current);
    }
    Node<T>* LeftChild(Node<T> *current)                               //��������Ů
    {
        return (current==NULL)?NULL:current->lchild;
    }
    Node<T>* RightChild(Node<T> *current)                              //��������Ů
    {
        return (current==NULL)?NULL:current->rchild;
    }
private:
    T refvalue;                                                        //��������ֹͣ�ı�־
    Node<T> *root;                                                        //���������ָ��

    bool Insert(Node<T> *&subtree,const T&x)const;                     //���� Node *&subtree=root(��������);subtree ��ʾ����rootָ�������
                                                                       //*&��������ʹ��ͨ��subtree���ܸı�ָ��root��ֵ��Ҳ�ܸı�*rootָ���ֵ
    bool destroy(Node<T> *subtree);                                   //ɾ��
    bool Find(Node<T> *subtree,const T&x)const;                        //����
    Node<T>* Copy(Node<T> *orignode);                                  //���Ʋ����ظ����
    int Height(Node<T> *subtree);                                         //�������߶�
    int Size(Node<T> *subtree);                                           //���ؽ����

    void PreOrder(Node<T> *subtree);                                      //ǰ�����
    void InOrder(Node<T> *subtree);                                       //�������
    void PostOrder(Node<T> *subtree);                                     //�������
    void LevelOrder(Node<T> *subtree);

    void CreateBinaryTree(istream&is,BinaryTree<T> &BT);                       //����һ
   // void CreateBinaryTree(istream&is,Node<T> *&subtree);                         //������
    friend istream&operator>> <>(istream &is,BinaryTree<T> &tree);        //�������������
    friend ostream&operator<< <>(ostream &os,BinaryTree<T> &tree);        //�������������

    Node<T>* Parent(Node<T> *subtree,Node<T> *current);                //���ظ�ĸ���
    bool Traverse(Node<T> *subtree,ostream& os);
};



//operator >>
template <class T>
istream& operator>>(istream &is,BinaryTree<T> &tree)                               //���ز��������벢����һ�ö�������is������������
{
    tree.CreateBinaryTree(is,tree);
    return is;

}

//operator <<
template <class T>
ostream&operator<<(ostream &os,BinaryTree<T> &tree)                              //���ز���������traverseǰ��������������
{
    os<<"��������ǰ�����:"<<endl;
    tree.Traverse(tree.root,os);
    os<<endl;
    return os;
}

//Traverse
template <class T>
bool BinaryTree<T>::Traverse(Node<T>* subtree,ostream  &os)                 //��subtree��㿪ʼ��ǰ����������
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
bool BinaryTree <T> :: destroy ( Node<T>  *subtree)                            //˽�к��������subtree��Ϊ�գ���ɾ�����ڵ�Ϊsubtree������
{
    if(subtree!=NULL)                                                          //�ݹ�ɾ��subtree
    {
        destroy(subtree->lchild);
        destroy(subtree->rchild);
        delete subtree;
    }
    return true;
}


//Height
template <class T>
int BinaryTree<T>::Height(Node<T> *subtree)              //�������ĸ߶�
{
    if(subtree==NULL) return 0;
    int i=Height(subtree->lchild);                                    //�������߶�
    int j=Height(subtree->rchild);                                     //�������߶�
    return (i>j)?i+1:j+1;                                             //���ĸ߶ȵ������������߶Ƚϴ�ֵ+1�����ϸ���㣩
}


//Size
template <class T>
int BinaryTree<T>::Size(Node<T> *subtree)                             //�������н�����
{
    return 1+Size(subtree->lchild)+Size(subtree->rchild);             //�������1+������������+������������
}

//���ƹ��캯��
template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &s)                                     //���ƹ��캯��
{
    root=Copy(s.root);
}


//Copy
template <class T>
Node<T>* BinaryTree<T>::Copy(Node<T> *orignode)                       //������
{
        if(orignode==NULL) return NULL;
        Node<T> *p=new Node<T>;
        p->data=orignode->data;                                        //���Ƹ����
        p->lchild=Copy(orignode->lchild);                              //����������
        p->rchild=Copy(orignode->rchild);                              //����������

         return p;
}

//==  ����equal
template <class T>
int operator==(const BinaryTree<T> &s,const BinaryTree<T> &t)          //���к���������Equal�������������ĸ����
{
    return Equal(s.root,t.root)?true:false;
}


//Equal
template <class T>
bool Equal(Node<T> *a,Node<T> *b)
{
    if(a==NULL&&b==NULL) return true;
    if(a!=NULL&&b!=NULL&&a->data==b->data&&Equal(a->lchild,b->lchild)&&Equal(a->rchild,b->rchild))
        //���a��b��Ϊ�գ���a��b���������ȣ���a��b����������ȣ��򷵻���
        return true;
    else return false;
}


//Parent
template <class T>
Node<T>* BinaryTree<T>::Parent(Node<T> *subtree,Node<T> *current)             //�ӽ��subtree��ʼ����������current�ĸ���㲢����
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
//�ݹ����

//preorder
template <class T>
void BinaryTree<T>::PreOrder(Node<T> *subtree)                   //ǰ�����
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
void BinaryTree<T>::InOrder(Node<T> *subtree)                    //�������
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
void BinaryTree<T>::PostOrder(Node<T> *subtree)                     //�������
{

    if(subtree!=NULL)
    {
        PostOrder(subtree->lchild);
        PostOrder(subtree->rchild);
        cout<<subtree->data<<" ";
    }
}
*/
//�ǵݹ����,����ջ
//preorderǰ�������inorder���������postorder�������


//ǰ���������һ��ֻѹ������
template <class T>
void BinaryTree<T>::PreOrder(Node<T> *subtree)
{
	stack<Node<T>*> s;
	s.push(NULL);
	Node<T> *p=subtree;                                  //p��������ָ��
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		if(p->rchild!=NULL) s.push(p->rchild);           //Ԥ��������ָ������ջ��
		if(p->lchild!=NULL) p=p->lchild;                 //��������Ϊ�գ���������
		else {p=s.top();s.pop();}                        //������Ϊ�գ���ջ���õ�������ָ��
    }
}

//ǰ�����������:��ѹ����������ѹ������
/*template <class T>
void BinaryTree<T>::PreOrder(Node<T> *subtree)
{
	stack<Node<T>*> s;
	s.push(subtree);
	Node<T> *p=subtree;
	while(!s.empty())                                    //��ջ��Ϊ�գ�һֱѭ��
	{
		p=s.top();
		s.pop();
		cout<<p->data<<" ";
		if(p->rchild!=NULL) s.push(p->rchild);
		if(p->lchild!=NULL) s.push(p->lchild);
	}
}
*/

//�������
template <class T>
void BinaryTree<T>::InOrder(Node<T> *subtree)
{
	stack<Node<T>*> s;
    Node<T> *p=subtree;
    do
    {
        while(p!=NULL)                                    //p��Ϊ��ʹ��ѭ��ѹ������Ů
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())                                    //���ջ��Ϊ�գ���ջ���õ�����㣬ͬʱ�����������ݣ������ҽ��
        {
            p=s.top();
            s.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }

    }while(p!=NULL||!s.empty());                          //��ջΪ�գ���pΪ�ռ����ʵ��������ҽ��ʱ���˳�ѭ����������ѭ��ѹ��p������

}


//�����������Ҫ�жϴ��������˻ػ����������˻أ��½��ڵ�ṹ�壬�����ֵ
template <class T>
struct stkNode                                            //����ʱ����ջ����ඨ��
{
    Node<T> *ptr;                                         //ָ��������ָ��
    int tag;                                              //�ý����ջ�ı��ֵ��L������������˻أ�R������������˻�
    stkNode(Node<T> *N=NULL):ptr(N),tag(0){}              //���캯��,����һ��stkNode���ʱ��Ĭ�Ͻ��ָ��ΪNULL�����ֵΪL
};
template <class T>
void BinaryTree<T>::PostOrder(Node<T> *subtree)
{
    stack< stkNode<T> > s;
    stkNode<T> w;
    Node<T> *p=subtree;                                   //p�Ǳ���ָ��
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
            case 1:cout<<w.ptr->data<<" ";                //���������˻أ����ջ��ֵ����������ֵ������ѭ����ջ
                   break;
            }
        }
    }while(!s.empty());                                    //ջΪ��ʱ�˳�ѭ��
    cout<<endl;
}
/*
//CreateBinaryTree  ͨ��ǰ��������봴����������ע����������Ϊ��ʱ��Ҫ����#��Ϊ��ֹ��
template <class T>
void BinaryTree<T>::CreateBinaryTree(istream&is,Node<T> *&subtree)
//˽�к������Եݹ鷽ʽ����������
{
	T item;
	if(!is.eof())                       //δ���꣬����������ֵ���������벢����
	{
		is>>item;
		if(item!=refvalue)                  //����Ĳ�����ֹ���
		{
			subtree=new Node<T>(item);      //�½����ڵ㣬������ո����������
			if(subtree==NULL)
			{
				cerr<<"�洢�����"<<endl;          //����ʧ�ܣ��쳣�˳�
			}
			CreateBinaryTree(is,subtree->lchild);         //�ݹ齨��������
			CreateBinaryTree(is,subtree->rchild);         //�ݹ齨��������
		}
	}
}
*/

//CreateBinaryTree �������������ʽ����������
template <class T>
void BinaryTree<T>::CreateBinaryTree(istream&is,BinaryTree<T> &BT)                //����������ķ�ʽ��ʾҪ�����Ķ�����
{
    stack<Node<T>*> s;
    BT.root=NULL;
    Node<T> *p,*t;
    int k=0;                                                                      //k��Ϊ���������������
    cout<<"�밴�չ������ʽ���������"<<endl;
    cout<<"ע�⣺ֻ������Ů��������Ů�����ڶ��Ų���ʡ��"<<endl;
    T ch;
    is>>ch;
    while(ch!=refvalue)                                                         //����ַ�����
    {
        switch(ch)
        {
            case '(':s.push(p);k=1;break;  //���������Ž�ǰһ�δ����Ľ��pѹջ��k=1����Ǽ���������ַ�Ҫ������p������Ů
            case ')':t=s.top();s.pop();break; //���������ţ��õ�ջ��Ԫ�ز���ջ��ʵ���Ͼ����˳�����
            case ',':k=2;break;               //�������ţ�k=2����Ǽ���������ַ�Ҫ������ջ����������Ů��
            default:p=new Node<T>(ch);            //������㱣��������ַ�ֵ
                  if(BT.root==NULL) BT.root=p;           //��һ�����룬��BT�������ĸ����p
                  else if(k==1)
                        {
                            t=s.top();t->lchild=p;             //����t������Ů
                        }
                  else if(k==2)
                  {
                      t=s.top();t->rchild=p;                   //����t������Ů
                  }

        }
          is>>ch;
    }
}


//LevelOrder ���ö��а���������������
template <class T>
void BinaryTree<T>::LevelOrder(Node<T> *subtree)
{
    queue<Node<T>*> q;
    Node<T> *s;
    q.push(subtree);
    while(!q.empty())
    {
        s=q.front();                           //�õ�����Ԫ��
        q.pop();
        cout<<s->data<<" ";
        if(s->lchild!=NULL) q.push(s->lchild);
        if(s->rchild!=NULL) q.push(s->rchild);
    }
}




//PrintBtree  �Թ�������ʽ���������
template <class T>
void PrintBTree(Node<T> *BT)
//�Թ�������ʽ���������
{
	if(BT!=NULL)                                     //��Ϊ��ʱ�����ݹ�
	{
		cout<<BT->data;                              //������������
		if(BT->lchild!=NULL||BT->rchild!=NULL)       //�����������ȫΪ��
		{
			cout<<"(";
			PrintBTree(BT->lchild);                  //�ݹ����������
			cout<<",";
			PrintBTree(BT->rchild);                  //�ݹ����������
			cout<<")";
		}
	}
}


#endif // BINARYTREE_H_INCLUDED
