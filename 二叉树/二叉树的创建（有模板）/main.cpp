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
    cout<<"以广义表的形式输出二叉树:";
    PrintBTree(s.getRoot());
    cout<<endl;
    BinaryTree<char> t(s);
    cout<<"复制构造函数执行后前序遍历t";
    t.PreOrder();
    t.LevelOrder();
    return 0;
}
