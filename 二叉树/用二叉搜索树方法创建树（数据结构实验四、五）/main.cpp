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
    cout<<endl<<"������Ҫ����Ľ�����ݣ�";
    cin>>ch1;
    tree.Insert(ch1);
    cout<<"������Ҫɾ���Ľ������: ";
    cin>>ch2;
    tree.Remove(ch2);
    cout<<endl<<"���в��롢ɾ��������Ķ������������:"<<endl;
    tree.InOrder();
    tree.LevelOrder();
    system("pause");
    return 0;
}
