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
    cout<<"����������ʽ���������:";
    PrintBT(s.getRoot());
    cout<<endl;
    return 0;
}
