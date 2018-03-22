#include <iostream>
#include "Huffman.h"
#define Max 100
using namespace std;

int main()
{
    int A[Max],n,i;
    cout<<"请输入要创建的霍夫曼树的结点个数: ";
    cin>>n;
    cout<<"请输入每个结点的数据: ";
    for(i=0;i<n;i++)
        cin>>A[i];
    HuffmanTree h(A,n);
    h.LevelOrder();
    h.PreOrder();
    h.InOrder();
    h.PostOrder();
    return 0;
}
