//����������
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
    cout<<endl<<"������Ҫ�����Ľ������: ";
    cin>>n;
    if(b.Search(n)==true) cout<<"�����ɹ�."<<endl;
    else cout<<"����ʧ��."<<endl;
    cout<<endl<<"������Ҫ����Ľ������: ";
    cin>>n;
    b.Insert(n);
    cout<<endl<<"�������Ķ���������: "<<endl;
    b.LevelOrder();
    cout<<b;
    cout<<endl<<"������Ҫɾ���Ľ������: ";
    cin>>n;
    b.Remove(n);
    cout<<"ɾ������Ķ���������: "<<endl;
    b.LevelOrder();
    cout<<b;
    return 0;
}
