#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

//���ṹ�嶨��
struct Node
{
    double weight;                        //Ȩֵ
    char ch;                              //������
    string code;                          //����
    Node* lchild,*rchild,*parent;
    Node(double _weight=0,char _ch='*',string _code="")                          //���캯��
    :weight(_weight),ch(_ch),code(_code),lchild(NULL),rchild(NULL),parent(NULL){}

    //���������
    bool operator<(Node &N){return weight<N.weight;}
    bool operator<=(Node &N){return weight<=N.weight;}
    bool operator>(Node &N){return weight>N.weight;}
    bool operator>=(Node &N){return weight>=N.weight;}
};


#endif // NODE_H_INCLUDED
