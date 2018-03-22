#include <iostream>
#include "Huffman.h"
#define Max 100
using namespace std;

int main()
{
    int A[Max],n,i;
    char B[Max];
    cout<<"������Ҫ�����Ļ����������������: ";
    cin>>n;
    cout<<"������ÿ�������: ";
    for(i=0;i<n;i++)
        cin>>B[i];
    cout<<"������ÿ�����Ȩ��: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    HuffmanTree h(A,B,n);
    h.HuffmanCode();
    cout<<"����������Huffman����"<<endl;
    h.LevelOrder();
    h.PreOrder();

    return 0;
}
