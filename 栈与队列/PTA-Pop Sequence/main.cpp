#include <iostream>
#include <stack>
#define Max 1000
using namespace std;
//给出一段有序数字，判断能否从栈中弹出得到对应的顺序
int main()
{
    stack<int> s;
    int i,j,f,x,cnt;
    int M,N,K;
    int A[Max];
    cin>>M>>N>>K;
    while(K--)
    {
        cnt=0;j=1;                                             //cnt为能否成功的标记，每次循环j都是从1开始压栈
        for(i=0;i<N;i++) cin>>A[i];
        for(i=0;i<N;i++)                                       //从第一个数字遍历
        {
            if(s.empty())                                      //判断栈顶是否为空
             {
                    for(;j<=A[i];j++)                          //从当前j元素一直压栈j，j+1,..直到压到A【i】元素
                    s.push(j);
                    if(s.size()>M) {cnt++;break;}              //判断此时栈长是否超过限制，超过则说明此时得到A【i】元素不合理，即错误

                   x=s.top();                                  //x保存即将弹出的栈顶元素
                   s.pop();                                    //栈顶元素和A【i】对应，弹出
                   continue;

             }
              if(x>A[i])                                       // 如果之前栈顶元素x即A【i-1】比此时的A【i】元素大，则应该
             {
                x=s.top();                                     //比较当前栈顶元素与A【i】是否相等，相等则正确，弹出栈顶元素x
                if(x==A[i]) s.pop();
                else {cnt++;break;}                            //不相等则错误

             }
             else if(x<A[i])                                   //如果A【i-1】比此时的A【i】元素小，则应该从当前的j开始压栈，j+1，j+2..直到压到A【i】
             {
                 for(;j<=A[i];j++)
                    s.push(j);
                if(s.size()>M) {cnt++;break;}                   //如果超过栈的大小限制，则说明不能得到A【i】元素，故退出
                 x=s.top();
                 s.pop();
                 continue;
             }


        }
        if(cnt==1)
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        while(!s.empty())                                      //每次循环后，要清空栈，防止栈中元素对下次循环的影响
                s.pop();

    }
    return 0;
}
