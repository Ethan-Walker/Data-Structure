#include <iostream>
#include "binarytree.h"
using namespace std;



int main()
{
    BinaryTree<char> s('#');
    cin>>s;
    cout<<s;
    s.PreOrder();
    s.InOrder();
    s.PostOrder();
    cout<<"�Թ�������ʽ���������:";
    PrintBTree(s.getRoot());
    cout<<endl;
    BinaryTree<char> t(s);
    cout<<"���ƹ��캯��ִ�к�ǰ�����t";
    t.PreOrder();
    t.LevelOrder();
    return 0;
}
