#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    BinaryTree s;
    cin>>s;
    s.PreOrder();
    s.InOrder();
    s.PostOrder();
    return 0;
}
