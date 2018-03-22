#include <iostream>
using namespace std;
class num
{
public:
    num():data(1),y(0){cout<<"构造函数执行"<<endl;}
    int get(){return data;}
    friend istream& operator>>(istream& is,num &s);
    friend ostream& operator<<(ostream& os,num &s);
private:
    int data;
    int y;
};
istream& operator>>(istream&is,num &s)
{
    cout<<"请输入data和y值:";
    is>>s.data>>s.y;
    return is;
}
ostream& operator<<(ostream&os,num&s)
{
    os<<"输出类中成员变量:";
    os<<"s.data="<<s.data<<endl;
    os<<"s.y="<<s.y<<endl;
    return os;
}
int main()
{
     num s;
     cout<<"s.get()="<<s.get()<<endl;
     cout<<s;
     cin>>s;
     cout<<s;
     return 0;
}
