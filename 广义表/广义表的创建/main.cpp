//�����Ĵ���
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;
template <class T>
struct Items{                                      //����ֵ����ṹ���壬���ص�һ���Ǳ�Ԫ�أ��������ӱ�
    int utype;                                     //=0/1/2
    union{
        int ref;                                   //utype=0,����ͷ��㣬������ü���
        T value;                                   //utype=1�������ֵ
        GenListNode<T> *hlink;                     //utype=2,���ָ���ӱ��ָ��
    }info;
    Items():utype(0),info.ref(0){}                 //���캯��
    Items(Items<T> &RL){utype=RL.utype;info=RL.info;}//���ƹ��캯��
};
template <class T>
struct GenListNode{                                //��������ඨ��
public:
    GenListNode():utype(0),tlink(NULL),info.ref(0){}
    GenListNode(GenListNode<T> &RL)                //���ƹ��캯��
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
    GenListNode<T> *tlink;                         //˽�в��ֱ�Items��һ��βָ����
};
template <class T>
class GenList;

template <class T>
istream& operator>>(istream &in,GenList<T> &L);
template <class T>
class GenList{                                     //Ҫ�õ��ݹ�ĺ�������length��depth,copy�ȣ�Ӧ�ڹ��г�Ա�����н����õ�˽�к����ݹ�õ��Ľ������ֵ
    GenList();                                     //��˽�г�Ա������ʵ�ֵݹ飬����ÿ�εݹ鶼�ø�һ��ֵ
    ~GenList();
    bool Head(Items &x);                           //���ر�ͷԪ��
    bool Tail(GenList<T> &lt);                     //���ر�β����β��һ�������
    GenListNode<T> *First();                       //���ر�ĵ�һ��Ԫ��
    GenListNode<T> *Next(GenListNode<T> *elem)     //���ر�Ԫ��elem��ֱ�Ӻ��Ԫ��
    void Copy(const GenList<T> &R);                //����һ�������ı�ͷ�����ƹ������ʹ˽�г�Ա��ͷָ��firstָ���Ƴɹ��Ĺ�����ͷ
    int Lengh();                                   //��������ĳ���
    int Depth();                                   //������������
    friend istream& operator>> <>(istream &in,GenList<T> &L);   //����>>
private:
    GenListNode<T> *first;                         //�����ͷָ��
    GenListNode<T> *Copy(GenListNode<T> *ls);      //����һ��lsָʾ���޹���ݹ��
    int Length(GenListNode<T> *ls);                //����lsָʾ�Ĺ����ĳ���
    int Depth(GenListNode<T> *ls);                 //������lsָʾ�Ĺ��������
    bool Equal(GenListNode<T> *s,GenListNode<T> *t);  //�ж���s��tΪ��ͷ������������Ƿ����
    void Remove(GenListNode<T> *ls);               //�ͷ���lsΪ����ͷ���Ĺ����
    void CreateList(istream& in,GenListNode<T> *&ls);  //����������������������ַ�������������һ����ͷ���Ĺ����ṹ

};
int main()
{

    return 0;
}
template <class T>
GenList::GenList()                                  //���캯��
{
    first=new GenListNode;                          //��������ͷ���
    assert(first!=NULL);
}
template <class T>
bool GenList<T>::Head(Items<T>& x)                  //�������ǿգ���ͨ��x�������һ��Ԫ�ص�ֵ
{
    if(first->tlink==NULL) return false;
    x.utype=first->tlink->utype;
    x.info=first->tlink->info;                      //���������ֱ�Ӹ���
    return true;
}
template <class T>
bool GenList<T>::Tail(GenList<T> &lt)               //�������ǿգ���ͨ��lt���ع�������ͷ֮������Ԫ�ع��ɵı�
{
    if(first->tlink==NULL) return false;
    lt.first->utype=0;                              //���ø���ͷ���
    lt.first->info.ref=0;
    lt.fiist->tlink=Copy(first->tlink->tlink);      //����ԭ�����ı�β��������ͷ֮�������Ԫ�ع��ɵı���ָ�븴�Ƶ�lt�ı�ͷ��tlink��
    return true;

}
template <class T>
GenListNode<T>* GenList<T>::First()                 //���ع����ĵ�һ��Ԫ��(ָ�����ָ�룩
{
    if(first->tlink==NULL) return NULL;
    return first->tlink;
}
template <class T>
GenListNode<T>* GenList<T>::Next(GenListNode<T> *elem)  //���ر�Ԫ��elem��ֱ�Ӻ��Ԫ�أ�ָ�����ָ�룩
{
    if(elem->tlink==NULL) return NULL;
    return elem->tlink;
}
template <class T>
void GenList<T>::Copy(const GenList<T> &R)              //���к���
{
    first=Copy(R.first);                                //����˽�к���
}
template <class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T> *ls)    //���Ʊ�
{
    GenListNode<T> *q=NULL;
    if(ls!=NULL)
    {
        q=new GenListNode<T>;                           //����ǰ���q
        q->utype=ls->utype;                             //���ƽ������
        switch(ls->utype)                               //����utype������Ϣ
        {
            case 0:q->info.ref=ls->info.ref;break;              //���Ƹ���ͷ���
            case 1:q->info.value=ls->info.value;break;          //����ԭ�ӽ��
            case 2:q->info.hlink=Copy(ls->info.hlink);break;    //�ݹ鸴���ӱ�
        }
        q->tlink=Copy(ls->tlink);                                //�ݹ鴦��ͬһ����һ�����
    }
    return q;
}
template <class T>
int GenList<T>::Length()                                        //���к���
{
    return Length(first);                                       //����˽�к�����������Ǳ�ͷָ�룬�����Ǹ���ͷ���ָ��
}
template <class T>
int GenList<T>::Length(GenListNode<T> *ls)                      //�����
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
bool GenList<T>::Equal(GenListNode<T> *s,GenListNode<T> *t)                              //�Ƚ�����������Ƿ����
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
void Delete(GenListNode<T> *f,T x)                                //ɾ�������������Ԫ��Ϊx�Ľ�㣬fΪ�����ĸ���ͷ���ָ��
{
    if(f->tlink!=NULL)
    {
        GenListNode<T> *p=f->tlink;
        while(p->utype==1&&p!=NULL&&p->info.value==x)               //ɾ����pͬ��ԭ��Ԫ��Ϊx�Ľ�㣬ѭ��ɾ��Ԫ����������x�Ľ��
        {
            f->tlink=p->tlink;
            delete p;
            p=f->tlink;
        }
        if(p!=NULL)
        {
            if(p->utype==2) Delete(p->info.hlink,x);                //ɾ���ӱ���ԭ��Ԫ��Ϊx�Ľ��
            if(p->tlink!=NULL)
                Delete(p->tlink,x);                                 //ɾ����pͬ��Ԫ��Ϊx�Ľ��

        }
    }


}
template <class T>
GenList<T>::~GenList()                                               //��������������ɾ�������������
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
    in>>chr;                                  //����һ���ַ�
    if(isaloha(chr)&&isuuper(chr)||chr=='(')  //������ַ��Ǵ�д��ĸ��
}





