#include <iostream>
#include "Huffman.h"
#define Max 100
using namespace std;

int main()
{
    int A[Max],n,i;
    cout<<"������Ҫ�����Ļ��������Ľ�����: ";
    cin>>n;
    cout<<"������ÿ����������: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    HuffmanTree h(A,n);
    h.LevelOrder();
    h.PreOrder();
    h.InOrder();
    h.PostOrder();
    return 0;
}
