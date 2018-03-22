#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

//结点结构体定义
struct Node
{
    double weight;                        //权值
    char ch;                              //外结点名
    string code;                          //编码
    Node* lchild,*rchild,*parent;
    Node(double _weight=0,char _ch='*',string _code="")                          //构造函数
    :weight(_weight),ch(_ch),code(_code),lchild(NULL),rchild(NULL),parent(NULL){}

    //运算符重载
    bool operator<(Node &N){return weight<N.weight;}
    bool operator<=(Node &N){return weight<=N.weight;}
    bool operator>(Node &N){return weight>N.weight;}
    bool operator>=(Node &N){return weight>=N.weight;}
};


#endif // NODE_H_INCLUDED
