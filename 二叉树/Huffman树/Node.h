#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
//结点结构体定义
struct Node
{
    char ch;
    double weight;
    int code;
    Node* lchild,*rchild,*parent;
    Node(char _ch='\0',double _data=0,int _code=0):ch(_ch),data(_data),code(_code),lchild(NULL),rchild(NULL),parent(NULL){}
    bool operator<(Node &N){return weight<N.weight;}
    bool operator<=(Node &N){return weight<=N.weight;}
    bool operator>(Node &N){return weight>N.weight;}
    bool operator>=(Node &N){return weight>=N.weight;}
};

#endif // NODE_H_INCLUDED
