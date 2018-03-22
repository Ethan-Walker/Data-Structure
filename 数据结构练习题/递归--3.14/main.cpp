#include <iostream>
using namespace std;
const int n=10;
int Max(int A[],int n)
{
    if(n==0) return A[0];
    if(A[0]<A[n-1])
    {
        A[0]=A[n-1];
    }
    return Max(A,n-1);

}
int sum(int A[],int n)
{
    if(n==0) return 0;
    return A[n-1]+sum(A,n-1);
}
double average(int A[],int n)
{
    int t=sum(A,n);
    return (t*1.0/n);
}
int main()
{
    int A[n],B[n],i;
    for(i=0;i<n;i++)
        cin>>A[i];
    for(i=0;i<n;i++)
        B[i]=A[i];

    cout<<"Max="<<Max(B,n)<<endl;
    cout<<"sum="<<sum(A,n)<<endl;
    cout<<"average="<<average(A,n)<<endl;

    return 0;
}
