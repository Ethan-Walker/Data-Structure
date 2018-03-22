#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<double> s;
    char ch;
    double result,left,right,operand,value;
    while(cin>>ch)
    {
        if(isdigit(ch))                 //判断输入的字符是否是0--9之间的数字
           {


               cin.putback(ch);       //遇到操作数，则将该字符放回输入流，因为要输入的操作数可能大于10，或者小数，得用double变量保存
               cin>>operand;          //用double变量保存操作数
               s.push(operand);        //操作数压栈
           }
        else {
                right=s.top();s.pop();left=s.top();s.pop();     //得栈顶元素，赋给右值（可能为减数或者除数），出栈；得栈顶元素，赋给左值，可能是被减数，被除数，出栈
            switch(ch)
              {
                 case '+':{value=left+right;break;}
                 case '-':{value=left-right;break;}
                 case '*':{value=left*right;break;}
                 case '/':{value=left/right;break;}
              }
              s.push(value);

        }

    }
    result=s.top();
    cout<<result<<endl;
    return 0;
}
