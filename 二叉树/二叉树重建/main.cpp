#include <iostream>
#include <cstdio>

#include "binarytree.h"
using namespace std;
int main()
{
    BinaryTree BT1,BT2;
    cout<<"BT1:"<<endl;
    BT1.pCreateBinaryTree();
    BT1.PreOrder();
    BT1.InOrder();
    BT1.PostOrder();
    BT1.LevelOrder();

    cout<<endl<<"BT2:"<<endl;
    BT2.lCreateBinaryTree();
    BT2.PreOrder();
    BT2.InOrder();
    BT2.PostOrder();
    BT2.LevelOrder();

    return 0;
}
