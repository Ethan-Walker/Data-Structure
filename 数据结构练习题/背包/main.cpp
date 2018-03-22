#include <iostream>
#include <cstdlib>
#include <cstring>
#define Max 100
using namespace std;
int t;

bool Search(int A[],int n,int T,int tag,int &pre)
{
    if(T==0) return true;
    else if(T<0) return false;
    else if(T>0&&n<1) return false;
    else if(Search(A,n-1,T-A[n-1],tag,pre)&&pre!=n-1)
    {
        cout<<A[n-1]<<" ";
        if(tag!=n) pre=n-1;
        return true;
    }
    else  return Search(A,n-1,T,tag,pre);
}


void Way(int A[],int n,int T,int tag)
{
   // int pre=0;
    int pre=-1;

    Search(A,n,T,tag,pre);
    cout<<endl<<"a:"<<"  pre="<<pre<<"   n="<<n<<endl;
    Search(A,n,T,tag,pre);
    cout<<"结束"<<endl;

    return ;
}
int main()
{
   int A[Max],i=0,T,n;
   char B[Max][10];
   cout<<"请输入总体积T:";
   cin>>T;
   cout<<endl;
   cout<<"请输入n个背包的体积, 以 '#'字符结束：";
   while(cin>>B[i])
   {
       if(strcmp(B[i],"#")==0) break;
       i++;
   }
   n=i;
   for(i=0;i<n;i++)
    A[i]=atoi(B[i]);
    cout<<"所有可能满足条件的解为:"<<endl;
    for(i=n;i>=7;i--)
  {
      Way(A,i,T,i);
      cout<<endl;
  }

    return 0;
}
