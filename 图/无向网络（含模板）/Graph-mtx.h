#ifndef GRAPH-MTX_H_INCLUDED
#define GRAPH-MTX_H_INCLUDED
#include <iostream>
#include <iomanip>
#include "Graph.h"
using namespace std;

//用邻接矩阵表示的图的类定义
//针对带权无向图

template <class T,class E>
class Graphmtx;

template <class T,class E>
istream& operator>>(istream &in,Graphmtx<T,E> &G);

template <class T,class E>
ostream& operator<<(ostream &out,Graphmtx<T,E> &G);



template <class T,class E>
class Graphmtx:public Graph<T,E>
{
private:
    T *VerticesList;              //顶点表
    E **Edge;                     //邻接矩阵
    int getVertexPos(T vertex)    //得到顶点vertex在顶点表中的位置
    {
        for(int i=0; i<Graph<T,E>::numVertices; i++)
            if(VerticesList[i]==vertex)  return i;
        return -1;
    }

public:

    Graphmtx(int sz=DefaultVertices);                       //构造函数
    ~Graphmtx()                                             //析构函数
    {
        delete []VerticesList;
        delete []Edge;
    }
    T getValue(int i)                                       //取位置为i的顶点中元素值
    {
        return (i>=0&&i<=Graph<T,E>::numVertices)?VerticesList[i]:NULL;
    }
    E getWeight(int v1,int v2)                              //取边（v1，v2）上的权重
    {
        return v1!=-1&&v2!=-1?Edge[v1][v2]:0;
    }
    int  getFirstNeighbor(int v);             //返回顶点为v的第一个邻接顶点的位置，若找不到，返回-1
    int  getNextNeighbor(int v,int w);        //返回顶点位置为v的某邻接顶点w的下一个邻接顶点的位置，若找不到，返回-1

    bool insertVertex(const T &vertex);        //在图中插入一个顶点vertex，该顶点暂时没有入边
    bool removeVertex(int v);                 //若被删顶点是图中顶点，则删去顶点v和所有关联到它的边
    bool insertEdge(int v1,int v2,E cost);    //若构成边的两个顶点v1和v2是图中的顶点，则在图中插入一条边（v1，v2）
    bool removeEdge(int v1,int v2);           //若构成边的两个顶点v1，v2是图中顶点，则删去边（v1，v2）

    friend istream& operator>><>(istream &in, Graphmtx<T,E> &G);   //输入
    friend ostream& operator<<<>(ostream &out,Graphmtx<T,E> &G);   //输出
};


template <class T,class E>
Graphmtx<T,E>::Graphmtx(int sz):Graph<T,E>(sz)
{

    Graph<T,E>::maxVertices=sz;
    Graph<T,E>::numVertices=Graph<T,E>::numEdges=0;

    VerticesList=new T[ Graph<T,E>:: maxVertices];  //创建顶点表数组

    Edge=(E **)new E*[ Graph<T,E>:: maxVertices];   //创建邻接矩阵数组

    for(int i=0; i< Graph<T,E>:: maxVertices; i++)
        Edge[i]=new E[ Graph<T,E>:: maxVertices];
    for(int i=0; i< Graph<T,E>:: maxVertices; i++)      //邻接矩阵初始化
        for(int j=0; j< Graph<T,E>:: maxVertices; j++)
            Edge[i][j]=(i==j?0: Graph<T,E>:: maxWeight);

}
template <class T,class E>
int Graphmtx<T,E>::getFirstNeighbor(int v)
//返回顶点为v的第一个邻接顶点的位置，若找不到，返回-1
{
    if(v!=-1)
    {
        for(int col=0; col<Graph<T,E>::numVertices; col++)
            if(Edge[v][col]>0&&Edge[v][col]<Graph<T,E>::maxWeight) return col;

    }
    return -1;
}
template <class T,class E>
int Graphmtx<T,E>::getNextNeighbor(int v,int w)
//返回顶点位置为v的某邻接顶点w的下一个邻接顶点的位置，若找不到，返回-1
{
    if(v!=-1&&w!=-1)
    {
        for(int col=w+1; col<Graph<T,E>::numVertices; col++)
            if(Edge[v][col]>0&&Edge[v][col]<Graph<T,E>::maxWeight) return col;
    }
    return -1;
}
template <class T,class E>
bool Graphmtx<T,E>::insertVertex(const T& vertex)
//插入顶点vertex
{
    if(Graph<T,E>::numVertices==Graph<T,E>::maxVertices) return false;
    else
    {
        VerticesList[Graph<T,E>::numVertices++]=vertex;
        return true;
    }

}
template <class T,class E>
bool Graphmtx<T,E>::removeVertex(int v)
//删去顶点表中位置为v的顶点和所有关联到它的边
{
    if(v<0||v>=Graph<T,E>::numVertices) return false;//v不在图中，不删除
    if(Graph<T,E>::numVertices==1) return false;     //只剩一个顶点，不能删除
    VerticesList[v]=VerticesList[Graph<T,E>::numVertices-1];  //顶点表中删除该顶点
    for(int i=0; i<Graph<T,E>::numVertices; i++)
        if(Edge[v][i]>0&&Edge[v][i]<Graph<T,E>::maxWeight) Graph<T,E>::numEdges--;  //减去与之相关联的边数
    for(int i=0; i<Graph<T,E>::numVertices; i++)
        Edge[v][i]=Edge[Graph<T,E>::numVertices-1][i];            //用最后一行填补第v行
    Graph<T,E>::numVertices--;
    for(int i=0; i<Graph<T,E>::numVertices; i++)
        Edge[i][v]=Edge[i][Graph<T,E>::numVertices];              //最后一列填补第v列
    return true;

}
template <class T,class E>
bool Graphmtx<T,E>::insertEdge(int v1,int v2,E cost)
//若构成边的两个顶点v1和v2是图中的顶点，则在图中插入一条边（v1，v2）
{
    if(v1>=0&&v1<Graph<T,E>::numVertices&&v2>=0&&v2<Graph<T,E>::numVertices&&Edge[v1][v2]==Graph<T,E>::maxWeight) //插入条件
    {
        Edge[v1][v2]=Edge[v2][v1]=cost;
        Graph<T,E>::numEdges++;
        return true;
    }
    return false;
}
template <class T,class E>
bool Graphmtx<T,E>::removeEdge(int v1,int v2)
//若构成边的两个顶点v1，v2是图中顶点，则删去边（v1，v2）
{
    if(v1>=0&&v1<Graph<T,E>::numVertices&&v2>=0&&v2<Graph<T,E>::numVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<Graph<T,E>::maxWeight)  //删除条件
    {
        Edge[v1][v2]=Edge[v2][v1]=Graph<T,E>::maxWeight;
        Graph<T,E>::numEdges--;
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
template <class T,class E>
istream& operator>>(istream &in,Graphmtx<T,E> &G)
{
    int i,v1,v2,m,n;
    T vertex1,vertex2;
    E weight;
    cout<<"请输入所要创建图的顶点个数和边数：";
    in>>n>>m;

    cout<<endl<<"请输入各顶点内数据：";
    for(i=0; i<n; i++)
    {
        in>>vertex1;
        G.insertVertex(vertex1);
    }
    cout<<endl<<"请输入各边的信息："<<endl;
    for(i=0; i<m;)
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
template <class T,class E>
ostream& operator<<(ostream &out,Graphmtx<T,E> &G)
//输出图的所有顶点和边的信息
{
    int i,j,m,n;
    T vertex1,vertex2;
    E weight;
    n=G.NumberOfVertices();
    m=G.NumberOfEdges();
    out<<left<<"顶点总数："<<setw(3)<<n<<"边数："<<setw(3)<<m<<endl;
    out<<"各边的信息："<<endl;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++) //无向图只要遍历上三角即可
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




















#endif // GRAPH-MTX_H_INCLUDED
