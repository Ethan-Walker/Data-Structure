#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include "Huffman.h"
#define Max 100
using namespace std;

int main()
{
    int n,i,j,k,m=0,weight[Max]={0};
    char A[Max],B[Max]="\0";
    cout<<"请输入一组字符串,以回车结束输入 : "<<endl;
    gets(A);
    n=strlen(A);
    for(i=0;i<n;i++)           //计算输入的字符串中每个字符的权重，并将字符种类赋给B，对应的权重赋给weight
    {
        k=strlen(B);
        for(j=0;j<k;j++)       //在B中查找是否已经有A[i]字符
        {
            if(A[i]==B[j]) {break;} //有的话跳出
        }
        if(j==k)               //j==k说明B中没有A[i]字符
        {

            B[m]=A[i];         //在B中添加A[i]字符
        for(j=0;j<n;j++)       //从A中遍历，计算添加的A[i]字符权重
            if(A[j]==B[m])
                weight[m]++;
        m++;                   //B中字符数+1
        }

    }
    /*
    cout<<"输出得到字符、权重："
    cout<<m<<endl;
    cout<<B<<endl;
    for(i=0;i<m;i++)
        cout<<weight[i]<<" ";
        */
    string st[50];
    char ch[50];
    HuffmanTree h(weight,B,m); //构造Huffman树
    h.HuffmanCode(st,ch);
     //对Huffman树编码并输出,同时将字符、每个字符对应的编码分别保存到ch、st中
    /*
    cout<<endl<<"得到的数组："<<endl;
    for(i=0;i<m;i++)
    {

        cout<<left<<setw(5)<<ch[i]<<left<<setw(6)<<st[i]<<endl;

    }
    */
    cout<<endl<<"原字符串对应的编码结果： ";
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(A[i]==ch[j])
        {
            cout<<st[j];
            break;
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}
