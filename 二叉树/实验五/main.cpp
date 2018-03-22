#include <iostream>
#include <cstdlib>
#include "binarytree.h"
using namespace std;

int main()
{
    int n,i;
    char ch1,ch2;
    BinaryTree tree;
    cin>>tree;
    cout<<endl;
    tree.InOrder();
    tree.LevelOrder();
    cout<<endl<<"请输入要插入的结点数据：";
    cin>>ch1;
    tree.Insert(ch1);
    cout<<"请输入要删除的结点数据: ";
    cin>>ch2;
    tree.Remove(ch2);
    cout<<endl<<"进行插入、删除操作后的二叉树遍历结果:"<<endl;
    tree.InOrder();
    tree.LevelOrder();
    system("pause");
    return 0;
}
