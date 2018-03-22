//��ջ����Թ�����
#include <iostream>
#include <stack>
using namespace std;
const int m=5,p=6;
int mark[m+2][p+2];
int Maze[m+2][p+2];
struct offsets{                       //λ����ֱ�������µ�ƫ��
    int a,b;                          //a,b��x��y�����ƫ��
    char dir[3];                        //dir�Ƿ���
};
offsets Move[8]={{0,-1,"W"},{-1,-1,"NW"},{-1,0,"N"},{-1,1,"NE"},{0,1,"E"},{1,1,"SE"},{1,0,"S"},{1,-1,"SW"}};                    //���������ƫ�Ʊ�

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
    tmp.x=1,tmp.y=1;                                             //�ӣ�1,1����ʼ
    st.push(tmp);                                                //��(1,1)λ������ѹ��ջ��
    while(!st.empty())
    {
        k=tmp.x;d=tmp.y;                                         //k,d���ڱ���ջ��λ��������Ϣ����ȷ����һ������ֵ
        for(i=0;i<8;i++)                                         //�˸����������̽
        {
            g=k+Move[i].a;                                        //��g��h��Ϊ������̽������ֵ
            h=d+Move[i].b;

            if(g==m&&h==p)                                       //�����̽�ĸպ��ǳ��ڣ���ջ��Ԫ�������������ǽ��ڵ����ڵķ���·��
            {
                 cout<<g<<" "<<h<<endl;                          //�������������
                while(!st.empty()){                              //ѭ����ջ�еõ�����λ�ã��������·��
                tmp=st.top();
                cout<<tmp.x<<" "<<tmp.y<<endl;                  //�������������λ������
                st.pop();
                }

                return ;                                         //�ҵ�����������ֹ
            }
            if(Maze[g][h]==0&&mark[g][h]==0&&g>=0&&h>=0)         //�����̽��������������������ǽ��֮ǰû����̽��������ֵ����
            {                                                    //��ѹջ
                mark[g][h]=1;                                    //�Ƚ��õ���ֵ����1���´β�������̽
                tmp.x=g,tmp.y=h;                                 //tmp����õ�λ��������Ϣ
                st.push(tmp);                                    //ѹ��tmp��ջ��
                k=g;                                             //k��d��Ӧ�ı�ɴ�ʱ��ջ�����꣬��ȷ����һ����̽����
                d=h;
                i=0;                                           //i=0�ܹؼ����µ�ջ�����꣨k��d����̽ʱ����ȻҪ��8��������̽
            }
        }
        st.pop();                                              //8��������̽�󶼲��ɹ�������ջ����̽ʧ�ܣ�·����������һ��
        tmp=st.top();                                           //tmp���浱ǰջ��Ԫ�أ�������һ���ĵ�ǰ���꣬ѭ����̽����λ��
    }
    cout<<"�޷���ȥ"<<endl;
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
