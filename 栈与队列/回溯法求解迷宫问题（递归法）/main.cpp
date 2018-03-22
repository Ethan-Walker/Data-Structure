#include <iostream>
#include <cstring>
const int m=5,p=6;
#include "Maze.h"
using namespace std;
int Maze[m+2][p+2];
int mark[m+2][p+2];                    //全局变量，自动赋值为0
struct offsets{                       //位置在直角坐标下的偏移
    int a,b;                          //a,b是x，y方向的偏移
    char dir[3];                        //dir是方向
};
offsets Move[8]={{0,-1,"W"},{-1,-1,"NW"},{-1,0,"N"},{-1,1,"NE"},{0,1,"E"},{1,1,"SE"},{1,0,"S"},{1,-1,"SW"}};                    //各个方向的偏移表
int SeekPath(int x,int y)
//从迷宫某一位置[i][j]开始，寻找通向出口[m][p]的一条路径，如果找到，函数返回1
//否则函数返回0，试探点的出发点为[1][1]
{
    int i,g,h;                      //g，h记录位置信息
    char d[3];                        //d记录方向
    if(x==m&&y==p) return 1;        //到达出口
    for(i=0;i<8;i++)                //依次按每一个方向寻找通向出口的路径
    {
        g=x+Move[i].a;                                            //找下一个位置g,h,d;
        h=y+Move[i].b;
        strcpy(d,Move[i].dir);
        if(Maze[g][h]==0&&mark[g][h]==0&&g>=0&&h>=0)              //试探坐标值为0位置和标记值为0的值，同时g、h必须大于等于0，否则死循环
        {
            mark[g][h]=1;                                        //将试探过的点标记值记作1，下次不能再试探
            if(SeekPath(g,h))                                     //试探g、h点
            {
                cout<<"("<<g<<","<<h<<"),"<<"Direction "<<d<<endl;
                return 1;                                        //试探成功，逆向输出路径坐标，一旦某个试探成功，则返回，不进行下面的换方向试探
            }
        }
                                                                  //回溯，换一个方向在试探通向出口的路径
    }
    if(x==1&&y==1)  cout<<"无法出去"<<endl;
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

int main()
{
    int i,j;


    for(i=0;i<m+2;i++)
        for(j=0;j<p+2;j++) cin>>Maze[i][j];
    mark[1][1]=1;                                                    //将迷宫进口标记为1，防止下一步试探进口
    if(SeekPath(1,1))
        cout<<"(1,1),Direction E"<<endl;

    //cout<<Maze[m][p]<<endl;

    return 0;
}
