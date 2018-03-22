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
    cout<<"������һ���ַ���,�Իس��������� : "<<endl;
    gets(A);
    n=strlen(A);
    for(i=0;i<n;i++)           //����������ַ�����ÿ���ַ���Ȩ�أ������ַ����ำ��B����Ӧ��Ȩ�ظ���weight
    {
        k=strlen(B);
        for(j=0;j<k;j++)       //��B�в����Ƿ��Ѿ���A[i]�ַ�
        {
            if(A[i]==B[j]) {break;} //�еĻ�����
        }
        if(j==k)               //j==k˵��B��û��A[i]�ַ�
        {

            B[m]=A[i];         //��B�����A[i]�ַ�
        for(j=0;j<n;j++)       //��A�б�����������ӵ�A[i]�ַ�Ȩ��
            if(A[j]==B[m])
                weight[m]++;
        m++;                   //B���ַ���+1
        }

    }
    /*
    cout<<"����õ��ַ���Ȩ�أ�"
    cout<<m<<endl;
    cout<<B<<endl;
    for(i=0;i<m;i++)
        cout<<weight[i]<<" ";
        */
    string st[50];
    char ch[50];
    HuffmanTree h(weight,B,m); //����Huffman��
    h.HuffmanCode(st,ch);
     //��Huffman�����벢���,ͬʱ���ַ���ÿ���ַ���Ӧ�ı���ֱ𱣴浽ch��st��
    /*
    cout<<endl<<"�õ������飺"<<endl;
    for(i=0;i<m;i++)
    {

        cout<<left<<setw(5)<<ch[i]<<left<<setw(6)<<st[i]<<endl;

    }
    */
    cout<<endl<<"ԭ�ַ�����Ӧ�ı������� ";
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
