//二叉搜索树
#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    int n,t;
    BST b;
    cin>>b;
    b.LevelOrder();
    cout<<b;
    cout<<endl<<"请输入要搜索的结点数据: ";
    cin>>n;
    if(b.Search(n)==true) cout<<"搜索成功."<<endl;
    else cout<<"搜索失败."<<endl;
    cout<<endl<<"请输入要插入的结点数据: ";
    cin>>n;
    b.Insert(n);
    cout<<endl<<"插入结点后的二叉搜索树: "<<endl;
    b.LevelOrder();
    cout<<b;
    cout<<endl<<"请输入要删除的结点数据: ";
    cin>>n;
    b.Remove(n);
    cout<<"删除结点后的二叉搜索树: "<<endl;
    b.LevelOrder();
    cout<<b;
    return 0;
}
