//广义表的创建
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;
template <class T>
struct Items{                                      //返回值的类结构定义，返回的一般是表元素，而不是子表
    int utype;                                     //=0/1/2
    union{
        int ref;                                   //utype=0,附加头结点，存放引用计数
        T value;                                   //utype=1，存放数值
        GenListNode<T> *hlink;                     //utype=2,存放指向子表的指针
    }info;
    Items():utype(0),info.ref(0){}                 //构造函数
    Items(Items<T> &RL){utype=RL.utype;info=RL.info;}//复制构造函数
};
template <class T>
struct GenListNode{                                //广义表结点类定义
public:
    GenListNode():utype(0),tlink(NULL),info.ref(0){}
    GenListNode(GenListNode<T> &RL)                //复制构造函数
    {
        utype=RL.utype;
        tlink=RL.tlink;
        info=RL.info;
    }
private:
    int utype;
    union{
        int ref;
        T value;
        GenListNode<T> *hlink;
    }info;
    GenListNode<T> *tlink;                         //私有部分比Items多一个尾指针域
};
template <class T>
class GenList;

template <class T>
istream& operator>>(istream &in,GenList<T> &L);
template <class T>
class GenList{                                     //要用到递归的函数，如length，depth,copy等，应在公有成员函数中仅仅得到私有函数递归得到的结果并赋值
    GenList();                                     //在私有成员函数里实现递归，避免每次递归都得赋一次值
    ~GenList();
    bool Head(Items &x);                           //返回表头元素
    bool Tail(GenList<T> &lt);                     //返回表尾，表尾是一个广义表
    GenListNode<T> *First();                       //返回表的第一个元素
    GenListNode<T> *Next(GenListNode<T> *elem)     //返回表元素elem的直接后继元素
    void Copy(const GenList<T> &R);                //传入一个广义表的表头，复制广义表，并使私有成员表头指针first指向复制成功的广义表表头
    int Lengh();                                   //计算广义表的长度
    int Depth();                                   //计算广义表的深度
    friend istream& operator>> <>(istream &in,GenList<T> &L);   //重载>>
private:
    GenListNode<T> *first;                         //广义表头指针
    GenListNode<T> *Copy(GenListNode<T> *ls);      //复制一个ls指示的无共享递归表
    int Length(GenListNode<T> *ls);                //求由ls指示的广义表的长度
    int Depth(GenListNode<T> *ls);                 //计算由ls指示的广义表的深度
    bool Equal(GenListNode<T> *s,GenListNode<T> *t);  //判断以s，t为表头的两个广义表是否相等
    void Remove(GenListNode<T> *ls);               //释放以ls为附加头结点的广义表
    void CreateList(istream& in,GenListNode<T> *&ls);  //从输入流对象输入广义表的字符串描述，建立一个带头结点的广义表结构

};
int main()
{

    return 0;
}
template <class T>
GenList::GenList()                                  //构造函数
{
    first=new GenListNode;                          //建立附加头结点
    assert(first!=NULL);
}
template <class T>
bool GenList<T>::Head(Items<T>& x)                  //若广义表非空，则通过x返回其第一个元素的值
{
    if(first->tlink==NULL) return false;
    x.utype=first->tlink->utype;
    x.info=first->tlink->info;                      //共用体对象直接复制
    return true;
}
template <class T>
bool GenList<T>::Tail(GenList<T> &lt)               //若广义表非空，则通过lt返回广义表除表头之外其他元素构成的表
{
    if(first->tlink==NULL) return false;
    lt.first->utype=0;                              //设置附加头结点
    lt.first->info.ref=0;
    lt.fiist->tlink=Copy(first->tlink->tlink);      //复制原广义表的表尾，即除表头之外的其他元素构成的表，其指针复制到lt的表头的tlink中
    return true;

}
template <class T>
GenListNode<T>* GenList<T>::First()                 //返回广义表的第一个元素(指向结点的指针）
{
    if(first->tlink==NULL) return NULL;
    return first->tlink;
}
template <class T>
GenListNode<T>* GenList<T>::Next(GenListNode<T> *elem)  //返回表元素elem的直接后继元素（指向结点的指针）
{
    if(elem->tlink==NULL) return NULL;
    return elem->tlink;
}
template <class T>
void GenList<T>::Copy(const GenList<T> &R)              //公有函数
{
    first=Copy(R.first);                                //调用私有函数
}
template <class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T> *ls)    //复制表
{
    GenListNode<T> *q=NULL;
    if(ls!=NULL)
    {
        q=new GenListNode<T>;                           //处理当前结点q
        q->utype=ls->utype;                             //复制结点类型
        switch(ls->utype)                               //根据utype传送信息
        {
            case 0:q->info.ref=ls->info.ref;break;              //复制附加头结点
            case 1:q->info.value=ls->info.value;break;          //复制原子结点
            case 2:q->info.hlink=Copy(ls->info.hlink);break;    //递归复制子表
        }
        q->tlink=Copy(ls->tlink);                                //递归处理同一层下一个结点
    }
    return q;
}
template <class T>
int GenList<T>::Length()                                        //公有函数
{
    return Length(first);                                       //调用私有函数，传入的是表头指针，而不是附加头结点指针
}
template <class T>
int GenList<T>::Length(GenListNode<T> *ls)                      //计算表长
{
    if(ls!=NULL) return 1+Length(ls->tlink);
    return 0;
}
template <class T>
int GenList<T>::Depth()
{
    return Depth(first);
}
template <class T>
int GenList<T>::Depth(GenListNode<T> *ls)
{
    if(ls->tlink==NULL&&ls->hlink==NULL) return 1;
    if(ls->utype==2)
    {
        return 1+Depth(ls->hlink);

    }
    return Depth(ls->tlink);
}
template <class T>
bool GenList<T>::Equal(GenListNode<T> *s,GenListNode<T> *t)                              //比较两个广义表是否相等
{
    if(s->tlink=NULL&&t->tlink==NULL) return true;
    if(s->tlink!=NULL&&t->tlink!=NULL&&s->tlink->utype==t->tlink->utype){
            if(s->tlink->utype==1)
             x=(s->tlink->info.value==t->tlink->info.value)?1:0;
             if(s->tlink->utype==2)
             x=Equal(s->tlink->hlink,t->tlink->hlink);
    if(x==1) return Equal(s->tlink,t->tlink);
    else return false;
    }
    return false;
}

template <class T>
void Delete(GenListNode<T> *f,T x)                                //删除广义表中所有元素为x的结点，f为广义表的附加头结点指针
{
    if(f->tlink!=NULL)
    {
        GenListNode<T> *p=f->tlink;
        while(p->utype==1&&p!=NULL&&p->info.value==x)               //删除与p同层原子元素为x的结点，循环删除元素连续等于x的结点
        {
            f->tlink=p->tlink;
            delete p;
            p=f->tlink;
        }
        if(p!=NULL)
        {
            if(p->utype==2) Delete(p->info.hlink,x);                //删除子表中原子元素为x的结点
            if(p->tlink!=NULL)
                Delete(p->tlink,x);                                 //删除与p同层元素为x的结点

        }
    }


}
template <class T>
GenList<T>::~GenList()                                               //析构函数，调用删除整个广义表函数
{
    Remove(first);
}
template <class T>
void GenList<T>::Remove(GenListNode<T> *f)
{
    GenListNode<T> *p=f->tlink;
    if(p==NULL) return ;
    while(p!=NULL)
    {
        if(p->utype==1) {f->tlink=p->tlink;delete p;p=f->tlink;}
        else if(p->utype==2)
        {
            Remove(p->info.hlink);
            f->tlink=p->tlink;
            delete p;
            p=f->tlink;
        }
        else if(p->utype==0) {delete p;return ;}

    }
}
template <class T>
void GenList<T>::CreateList(istream& in,GenListNode<T> *&ls)
{
    T chr;
    in>>chr;                                  //输入一个字符
    if(isaloha(chr)&&isuuper(chr)||chr=='(')  //输入的字符是大写字母或（
}





