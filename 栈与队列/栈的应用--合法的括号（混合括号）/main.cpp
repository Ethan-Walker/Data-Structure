#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
#define MaxSize 80
stack<char> s;

void Judge(char ch[])
{
    int i;
    char ch2;
    if(strlen(ch)%2!=0) {cout<<"false"<<endl;return ;}
    for(i=0;i<strlen(ch);i++)
        {
            switch(ch[i])
            {
            case '[':
            case '(':
            case '{':{s.push(ch[i]);break;}
            case ']':
            case ')':
            case '}':  {
                if(!s.empty()){
                       ch2=s.top();
                       if((ch2=='('&&ch[i]==')')||(ch2=='['&&ch[i]==']')||(ch2=='{'&&ch[i]=='}')) {s.pop();break;}
                       else cout<<"false"<<endl;return ;

                       }
               else {cout<<"false"<<endl;return ;}
                       }
            }

        }

    if(s.empty()) {cout<<"true"<<endl;return ;}
   else {cout<<"false"<<endl;return ;}
}
int main()
{

    char ch[MaxSize];
    while(cin>>ch) {
       Judge(ch);
       while(!s.empty())
        s.pop();

    }
    return 0;
}
