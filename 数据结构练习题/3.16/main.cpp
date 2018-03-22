#include <iostream>
#include <stack>
using namespace std;

int akm(int m,int n)
{
    if(m==0) return n+1;
    else if(n==0)return akm(m-1,1);
    else return akm(m-1,akm(m,n-1));
}

int akm_(int m,int n)
{
    stack<int> s,result_;
    s.push(n);
    s.push(m);
    int a,b;
    while(1)
    {
        a=s.top();
        if(a==0&&) {s.pop();b=s.top();return b+1;}
        else
        {
            s.pop();
            b=s.top();
            if(b==0) {s.pop();s.push(1);s.push(a-1);}
            else
        }
    }
}
int main()
{
    int result;
    result=akm(1,3);
    cout<<"result="<<result<<endl;


    return 0;

}
