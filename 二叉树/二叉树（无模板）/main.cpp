#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    BinaryTree s;
    cin>>s;
    cout<<s;
    s.PreOrder();
    s.InOrder();
    s.PostOrder();
    s.LevelOrder();
    cout<<"按广义表的形式输出二叉树:";
    PrintBT(s.getRoot());
    cout<<endl;
    return 0;
}
