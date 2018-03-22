#ifndef GRAPH-MTX_H_INCLUDED
#define GRAPH-MTX_H_INCLUDED
#include <iostream>
#include <iomanip>
#include "Graph.h"
#include <queue>
using namespace std;
//邻接矩阵表示图，适用于非稀疏矩阵
class Graphmtx:public Graph
{
private:
    char *VerticesList;              //顶点表
    int **Edge;                      //邻接矩阵

public:
    Graphmtx(int sz=DefaultVertices);                       //构造函数
    ~Graphmtx()                                             //析构函数
    {
        delete []VerticesList;delete []Edge;
    }
    char getValue(int i)                                    //取位置为i的顶点中元素值
    {
        return (i>=0&&i<=numVertices)?VerticesList[i]:NULL;
    }
    int getWeight(int v1,int v2)                            //取边（v1，v2）上的权重
    {
        return v1!=-1&&v2!=-1?Edge[v1][v2]:0;
    }
    int getVertexPos(char vertex)    //得到顶点vertex在顶点表中的位置
    {
        for(int i=0;i<numVertices;i++)
            if(VerticesList[i]==vertex)  return i;
        return -1;
    }
    int  getFirstNeighbor(int v);             //返回顶点为v的第一个邻接顶点的位置，若找不到，返回-1
    int  getNextNeighbor(int v,int w);        //返回顶点位置为v的某邻接顶点w的下一个邻接顶点的位置，若找不到，返回-1

    bool insertVertex(const char vertex);        //在图中插入一个顶点vertex，该顶点暂时没有入边
    bool removeVertex(int v);                 //若被删顶点是图中顶点，则删去顶点v和所有关联到它的边
    bool insertEdge(int v1,int v2,int cost);    //若构成边的两个顶点v1和v2是图中的顶点，则在图中插入一条边（v1，v2）
    bool removeEdge(int v1,int v2);           //若构成边的两个顶点v1，v2是图中顶点，则删去边（v1，v2）

    friend istream& operator>>(istream &in, Graphmtx &G);   //输入
    friend ostream& operator<<(ostream &out,Graphmtx &G);   //输出
};

Graphmtx::Graphmtx(int sz):Graph(sz)
{
    maxVertices=(sz>DefaultVertices)?sz:DefaultVertices;
    numVertices=numEdges=0;
    VerticesList=new char[maxVertices];  //创建顶点表数组

    Edge=(int **)new int*[maxVertices];   //创建邻接矩阵数组
    for(int i=0;i<maxVertices;i++)
        Edge[i]=new int[maxVertices];

    for(int i=0;i<maxVertices;i++)        //邻接矩阵初始化
        for(int j=0;j<maxVertices;j++)
        Edge[i][j]=(i==j?0:maxWeight);
}

int Graphmtx::getFirstNeighbor(int v)
//返回顶点位置为v的第一个邻接顶点的位置，若找不到，返回-1
{
    if(v!=-1)
    {
        for(int col=0;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;

    }
    return -1;
}

int Graphmtx::getNextNeighbor(int v,int w)
//返回顶点位置为v的某邻接顶点w的下一个邻接顶点的位置，若找不到，返回-1
{
    if(v!=-1&&w!=-1)
    {
        for(int col=w+1;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
    }
    return -1;
}

bool Graphmtx::insertVertex(const char vertex)
//插入顶点vertex，不对边做处理
{
    if(numVertices==maxVertices) return false;      //空间不足
    else
    {
        VerticesList[numVertices++]=vertex;
        return true;
    }

}

bool Graphmtx::removeVertex(int v)
//删去顶点表中位置为v的顶点和所有关联到它的边
{
    if(v<0||v>=numVertices) return false;            //v不在图中，不删除
    if(numVertices==1) return false;                 //只剩一个顶点，不能删除

    VerticesList[v]=VerticesList[numVertices-1];     //顶点表中删除该顶点
    for(int i=0;i<numVertices;i++)                   //减去与之相关联的边数
            if(Edge[v][i]>0&&Edge[v][i]<maxWeight)
                numEdges--;
    for(int i=0;i<numVertices;i++)
        Edge[v][i]=Edge[numVertices-1][i];           //用最后一行填补第v行
    numVertices--;
    for(int i=0;i<numVertices;i++)
        Edge[i][v]=Edge[i][numVertices];             //最后一列填补第v列
    return true;
}

bool Graphmtx::insertEdge(int v1,int v2,int cost)
//若构成边的两个顶点v1和v2是图中的顶点，则在图中插入一条边（v1，v2）
{
    if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices&&Edge[v1][v2]==maxWeight) //插入条件
    {
        Edge[v1][v2]=Edge[v2][v1]=cost;
        numEdges++;
        return true;
    }
    return false;
}

bool Graphmtx::removeEdge(int v1,int v2)
//若构成边的两个顶点v1，v2是图中顶点，则删去边（v1，v2）
{
    if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<maxWeight)  //删除条件
    {
        Edge[v1][v2]=Edge[v2][v1]=maxWeight;
        numEdges--;
        return true;
    }
    return false;
}
//为了建立用邻接矩阵存储的图，重载图输入输出
//输入各顶点信息  例：A，B，C，D，E
//再输入各边的信息
/* A B C D E
A B 24
A C 46
B C 15
B E 67
C E 37
C D 53
E D 31
*/

istream& operator>>(istream &in,Graphmtx &G)
{
    int i,v1,v2,m,n;
    char vertex1,vertex2;
    int weight;
    cout<<"请输入所要创建图的顶点个数和边数：";
    in>>n>>m;
    cout<<endl<<"请输入各顶点内数据：";
    for(i=0;i<n;i++)
    {
        in>>vertex1;
        G.insertVertex(vertex1);
    }
    cout<<endl<<"请输入各边的信息："<<endl;
    for(i=0;i<m;)
    {
        in>>vertex1>>vertex2>>weight;
        v1=G.getVertexPos(vertex1);
        v2=G.getVertexPos(vertex2);
        if(v1==-1||v2==-1)
        {
            cout<<"边两端点信息有误,请重新输入！"<<endl;
        }
        else
        {
          G.insertEdge(v1,v2,weight);
          i++;
        }
    }
    return in;
}

ostream& operator<<(ostream &out,Graphmtx &G)
//输出图的所有顶点和边的信息
{
    int i,j,m,n;
    char vertex1,vertex2;
    int weight;

    n=G.NumberOfVertices();
    m=G.NumberOfEdges();
    out<<left<<"顶点总数："<<setw(3)<<n<<"边数："<<setw(3)<<m<<endl;
    out<<"各边的信息："<<endl;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)  //无向图只要遍历上三角即可
       {
           weight=G.getWeight(i,j);
           if(weight>0&&weight<G.maxWeight)   //存在边
           {
             vertex1=G.getValue(i);
             vertex2=G.getValue(j);
             //以（vertex1，vertex2，weight）的格式输出每条边的信息
             out<<"("<<vertex1<<","<<vertex2<<","<<weight<<")"<<endl;
           }
       }
       return out;
}

//连通图中DFS、BFS只用遍历一次即可访问所有顶点，访问非连通图，每完成一次DFS/BFS，则需要对每个顶点重新检测,是否仍有未访问顶点
void DFS(Graphmtx &G,int loc,int visited[]);

//通过DFS，找出无向图的所有连通分量
void Components(Graphmtx &G)
{
    int i,n=G.NumberOfVertices();
    int *visited=new int[n];
    for(i=0;i<n;i++)
        visited[i]=0;
    for(i=0;i<n;i++)
        if(visited[i]==0)         //未访问过，访问该连通分量
        {
          DFS(G,i,visited);
        }
    delete []visited;
}
//递归DFS，

//深度优先遍历(访问所有的节点）
//从顶点vertex出发，访问其所在的连通分量
void DFS(Graphmtx &G,char vertex)
{

    int i,loc,n=G.NumberOfVertices();
    int *visited=new int[n];            //建立指针数组 （方便销毁）
    for(i=0;i<n;i++)                    //访问标记 辅助数组
        visited[i]=0;
    loc=G.getVertexPos(vertex);
    DFS(G,loc,visited);
    delete []visited;
}
//从顶点位置loc出发，以深度优先的次序访问该结点所在的极大连通子图（可能是非连通图）
void DFS(Graphmtx &G,int loc,int visited[])
{
    cout<<G.getValue(loc)<<" ";
    visited[loc]=1;
    int w=G.getFirstNeighbor(loc);          //找顶点loc的第一个邻接顶点
    while(w!=-1)
    {
        if(visited[w]==0) DFS(G,w,visited); //先递归访问邻接顶点的邻接…邻接…
        w=G.getNextNeighbor(loc,w);         //得到原顶点的另外一个邻接顶点
    }
}

//BFS广度优先搜索
void BFS(Graphmtx &G,char vertex)
{
    int loc,i,n,w;
    n=G.NumberOfVertices();           //获取当前顶点总数
    int *visited=new int[n];          //访问标记数组
    for(i=0;i<n;i++)
        visited[i]=0;
    cout<<vertex<<" ";
    loc=G.getVertexPos(vertex);
    visited[loc]=1;
    queue<int> q;
    q.push(loc);

    while(!q.empty())
    {
        loc=q.front();
        q.pop();
        w=G.getFirstNeighbor(loc);
        while(w!=-1)
        {
            if(visited[w]==0)                   //访问loc的第一个邻接顶点
            {
                cout<<G.getValue(w)<<" ";
                visited[w]=1;
                q.push(w);                      //入队
            }
            w=G.getNextNeighbor(loc,w);         //找顶点loc的下一个邻接顶点

        }
    }
    delete []visited;

}

#endif // GRAPH-MTX_H_INCLUDED
