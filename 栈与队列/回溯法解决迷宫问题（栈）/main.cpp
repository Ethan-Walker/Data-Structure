//用栈解决迷宫问题
#include <iostream>
#include <stack>
using namespace std;
const int m=5,p=6;
int mark[m+2][p+2];
int Maze[m+2][p+2];
struct offsets{                       //位置在直角坐标下的偏移
    int a,b;                          //a,b是x，y方向的偏移
    char dir[3];                        //dir是方向
};
offsets Move[8]={{0,-1,"W"},{-1,-1,"NW"},{-1,0,"N"},{-1,1,"NE"},{0,1,"E"},{1,1,"SE"},{1,0,"S"},{1,-1,"SW"}};                    //各个方向的偏移表

struct Items{
    int x,y;
    //char di[3];
 //   char direc[3];
};
void SeekPath(int m,int p)
{
    int i,k,d,g,h;
    stack<Items> st;
    Items tmp;
    tmp.x=1,tmp.y=1;                                             //从（1,1）开始
    st.push(tmp);                                                //将(1,1)位置坐标压入栈中
    while(!st.empty())
    {
        k=tmp.x;d=tmp.y;                                         //k,d用于保存栈顶位置坐标信息，来确定下一个坐标值
        for(i=0;i<8;i++)                                         //八个方向遍历试探
        {
            g=k+Move[i].a;                                        //（g，h）为即将试探的坐标值
            h=d+Move[i].b;

            if(g==m&&h==p)                                       //如果试探的刚好是出口，则将栈中元素输出，输出的是进口到出口的反向路径
            {
                 cout<<g<<" "<<h<<endl;                          //先输出出口坐标
                while(!st.empty()){                              //循环从栈中得到坐标位置，反向输出路径
                tmp=st.top();
                cout<<tmp.x<<" "<<tmp.y<<endl;                  //逆序输出经过的位置坐标
                st.pop();
                }

                return ;                                         //找到出口则函数终止
            }
            if(Maze[g][h]==0&&mark[g][h]==0&&g>=0&&h>=0)         //如果试探的坐标满足条件：不是墙，之前没有试探过，坐标值合理
            {                                                    //则压栈
                mark[g][h]=1;                                    //先将该点标记值记作1，下次不能再试探
                tmp.x=g,tmp.y=h;                                 //tmp保存该点位置坐标信息
                st.push(tmp);                                    //压入tmp到栈中
                k=g;                                             //k，d相应的变成此时的栈顶坐标，来确定下一个试探坐标
                d=h;
                i=0;                                           //i=0很关键，新的栈顶坐标（k，d）试探时，仍然要从8个方向试探
            }
        }
        st.pop();                                              //8个方向试探后都不成功，则退栈，试探失败，路径中往后退一步
        tmp=st.top();                                           //tmp保存当前栈顶元素，即后退一步的当前坐标，循环试探其他位置
    }
    cout<<"无法出去"<<endl;
}

int main()
{

    int i,j;
    mark[1][1]=1;
    for(i=0;i<m+2;i++)
        for(j=0;j<p+2;j++)
        cin>>Maze[i][j];
    SeekPath(m,p);
    return 0;
}
/*
1 1 1 1 1 1 1 1
0 0 0 1 1 1 1 1
1 0 1 0 1 1 0 1
0 1 1 0 1 1 0 1
1 1 1 1 0 0 1 1
1 1 1 0 0 1 0 0
1 1 1 1 1 1 1 1
*/
