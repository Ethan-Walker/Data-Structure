#include <iostream>
#include "Huffman.h"
#define Max 100
using namespace std;

int main()
{
    int A[Max],n,i;
    char B[Max];
    cout<<"请输入要创建的霍夫曼树的外结点个数: ";
    cin>>n;
    cout<<"请输入每个结点名: ";
    for(i=0;i<n;i++)
        cin>>B[i];
    cout<<"请输入每个结点权重: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    HuffmanTree h(A,B,n);
    h.HuffmanCode();
    cout<<"遍历创建的Huffman树："<<endl;
    h.LevelOrder();
    h.PreOrder();

    return 0;
}
