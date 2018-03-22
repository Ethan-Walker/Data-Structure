#include <iostream>
#include "AVL.h"

using namespace std;

int main()
{
    int n,t;
    AVLTree b;
    b.Initial();
    b.InOrder();
    b.LevelOrder();

    cout<<endl<<"请输入要插入的结点数据: ";
    cin>>n;
    b.Insert(n);
    cout<<endl<<"插入结点后的二叉搜索树: "<<endl;
    b.LevelOrder();

    cout<<endl<<"请输入要查找的结点数据: ";
    cin>>n;
    if(b.Search(n))cout<<"搜索成功"<<endl;
    else cout<<"搜索结束"<<endl;
    return 0;
}
