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

    cout<<endl<<"������Ҫ����Ľ������: ";
    cin>>n;
    b.Insert(n);
    cout<<endl<<"�������Ķ���������: "<<endl;
    b.LevelOrder();

    cout<<endl<<"������Ҫ���ҵĽ������: ";
    cin>>n;
    if(b.Search(n))cout<<"�����ɹ�"<<endl;
    else cout<<"��������"<<endl;
    return 0;
}
