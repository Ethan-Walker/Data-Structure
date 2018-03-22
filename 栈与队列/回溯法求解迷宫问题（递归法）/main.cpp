#include <iostream>
#include <cstring>
const int m=5,p=6;
#include "Maze.h"
using namespace std;
int Maze[m+2][p+2];
int mark[m+2][p+2];                    //ȫ�ֱ������Զ���ֵΪ0
struct offsets{                       //λ����ֱ�������µ�ƫ��
    int a,b;                          //a,b��x��y�����ƫ��
    char dir[3];                        //dir�Ƿ���
};
offsets Move[8]={{0,-1,"W"},{-1,-1,"NW"},{-1,0,"N"},{-1,1,"NE"},{0,1,"E"},{1,1,"SE"},{1,0,"S"},{1,-1,"SW"}};                    //���������ƫ�Ʊ�
int SeekPath(int x,int y)
//���Թ�ĳһλ��[i][j]��ʼ��Ѱ��ͨ�����[m][p]��һ��·��������ҵ�����������1
//����������0����̽��ĳ�����Ϊ[1][1]
{
    int i,g,h;                      //g��h��¼λ����Ϣ
    char d[3];                        //d��¼����
    if(x==m&&y==p) return 1;        //�������
    for(i=0;i<8;i++)                //���ΰ�ÿһ������Ѱ��ͨ����ڵ�·��
    {
        g=x+Move[i].a;                                            //����һ��λ��g,h,d;
        h=y+Move[i].b;
        strcpy(d,Move[i].dir);
        if(Maze[g][h]==0&&mark[g][h]==0&&g>=0&&h>=0)              //��̽����ֵΪ0λ�úͱ��ֵΪ0��ֵ��ͬʱg��h������ڵ���0��������ѭ��
        {
            mark[g][h]=1;                                        //����̽���ĵ���ֵ����1���´β�������̽
            if(SeekPath(g,h))                                     //��̽g��h��
            {
                cout<<"("<<g<<","<<h<<"),"<<"Direction "<<d<<endl;
                return 1;                                        //��̽�ɹ����������·�����꣬һ��ĳ����̽�ɹ����򷵻أ�����������Ļ�������̽
            }
        }
                                                                  //���ݣ���һ����������̽ͨ����ڵ�·��
    }
    if(x==1&&y==1)  cout<<"�޷���ȥ"<<endl;
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
    mark[1][1]=1;                                                    //���Թ����ڱ��Ϊ1����ֹ��һ����̽����
    if(SeekPath(1,1))
        cout<<"(1,1),Direction E"<<endl;

    //cout<<Maze[m][p]<<endl;

    return 0;
}
