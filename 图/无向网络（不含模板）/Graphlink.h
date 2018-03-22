#ifndef GRAPHLINK_H_INCLUDED
#define GRAPHLINK_H_INCLUDED
#include "Graph.h"
//邻接表表示图，适用于稀疏矩阵

//边结点
struct Edge
{
    int dest;        //边的另一顶点位置
    int cost;        //边上的权值
    Edge *link;      //下一条边链指针
    Edge(){}
    Edge(int position,int weight):dest(position),cost(weight),link(NULL){}
    bool operator!=(Edge &R)const{
        return (dest!=R.dest)?true:false;
    }
};
//顶点结点
struct Vertex
{
    char data;        //顶点名
    Edge *adj;        //边链表的头指针，保存第一条边的地址
    Vertex(int da=0):data(da),adj(NULL){}

};

//邻接表表示图的类定义
class Graphlink:public Graph
{
private:
      Vertex *NodeTable; //顶点表，各边链表的头结点
      int getVertexPos(char vertex)
      {
          for(int i=0;i<numVertices;i++)
            if(NodeTable[i].data==vertex) return i;
          return -1;
      }
public:
      Graphlink(int sz=DefaultVertices);          //构造函数
      ~Graphlink();
      char getValue(int i)                        //得到位置为i的顶点的值
      {
          return (i<numVertices&&i>=0)?NodeTable[i].data:0;
      }
      int getWeight(int v1,int v2);             //返回边v1、v2上的权重
      bool insertVertex(char vertex);           //插入顶点
      bool removeVertex(int v);                 //删除顶点
      bool insertEdge(int v1,int v2,int weight);  //插入一条边
      bool removeEdge(int v1,int v2);           //删除一条边

      int  getFirstNeighbor(int v);             //返回顶点为v的第一个邻接顶点的位置，若找不到，返回-1
      int  getNextNeighbor(int v,int w);        //返回顶点位置为v的某邻接顶点w的下一个邻接顶点的位置，若找不到，返回-1
      friend istream& operator>>(istream &in, Graphlink &G);   //输入
      friend ostream& operator<<(ostream &out,Graphlink &G);   //输出
};

Graphlink::Graphlink(int sz):Graph(sz)
{
    maxVertices=(sz>DefaultVertices)?sz:DefaultVertices;
    numVertices=numEdges=0;
    NodeTable=new Vertex[maxVertices];           //创建顶点表数组
}
//析构函数删除一个邻接表
Graphlink::~Graphlink()
{
    for(int i=0;i<numVertices;i++)               //删除各边链表中的结点
    {
        Edge *p=NodeTable[i].adj,*q;             //头指针
        while(p!=NULL)
        {
            q=p->link;
            delete p;
            p=q;
        }
    }
    delete []NodeTable;
}
//邻接表上的函数的实现都是顶点表与某个邻接表的联合操作

//得到顶点位置为v的第一个邻接顶点的位置
int Graphlink::getFirstNeighbor(int v)
{
    if(v!=-1) return -1;
    Edge *p=NodeTable[v].adj;
    if(p!=NULL)
        return p->dest;
    else return -1;
}

//返回顶点位置为v的某邻接顶点w的下一个邻接顶点的位置，若找不到，返回-1
int Graphlink::getNextNeighbor(int v,int w)
{
    if(v!=-1&&w!=-1)
    {
        Edge *p=NodeTable[v].adj;
        while(p!=NULL)
        {
            if(p->dest==w&&p->link!=NULL) return p->link->dest;
            p=p->link;
        }
    }
    return -1;
}

//得到边v1，v2上的权重
int Graphlink::getWeight(int v1,int v2)
{
    if(v1!=-1&&v2!=-1)
    {
        Edge *p=NodeTable[v1].adj;
        while(p!=NULL)
        {
            if(p->dest==v2) return p->cost;
            p=p->link;
        }
    }
    return 0;
}

//插入顶点
bool Graphlink::insertVertex(char vertex)
{
    if(numVertices==maxVertices) return false;
    NodeTable[numVertices].data=vertex;
    numVertices++;
    return true;
}

//删除顶点
bool Graphlink::removeVertex(int v)
{
    if(numVertices==1||v<0||v>=numVertices) return false;
    Edge *p=NodeTable[v].adj;
    while(p!=NULL)
    {
        //删除指向该结点的边
        int x=p->dest;
        Edge *q=NodeTable[x].adj,*s=q,*post=q->link;
        if(s->dest==v)
        {
            NodeTable[x].adj=post;
            delete s;
        }
        else
        {
            while(s!=NULL)
            {
                if(s->dest!=v) {q=s;s=post;post=post->link;}
                else break;
            }
            q->link=post;
            delete s;
        }

        //删除该结点发出的边
        q=p->link;
        delete p;
        p=q;
        numEdges--;
    }
    numVertices--;
    NodeTable[v].data=NodeTable[numVertices].data;
    p=NodeTable[v].adj=NodeTable[numVertices].adj;


    //将原先指向最后一位顶点的边，全部指向v
    Edge *s;
    while(p!=NULL)
    {
        s=NodeTable[p->dest].adj;
        while(s!=NULL)
        {
            if(s->dest==numVertices){s->dest=v;break;}
            else s=s->link;
        }
        p=p->link;
    }
    return true;
}



//插入一条边(v1,v2)(v2,v1)实际上插入两次
bool Graphlink::insertEdge(int v1,int v2,int weight)
{
    if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices)
    {
        //插入（v1，v2）
        Edge *p=NodeTable[v1].adj;
        while(p!=NULL&&p->dest!=v2)
            p=p->link;
        if(p!=NULL)                  //已有该边，不再插入
            return false;
        p=new Edge;
        p->dest=v2;p->cost=weight;
        //头插法
        p->link=NodeTable[v1].adj;
        NodeTable[v1].adj=p;


        //插入（v2，v1）
        Edge *q=NodeTable[v2].adj;
        q=new Edge;
        q->dest=v1;q->cost=weight;
        //头插法
        q->link=NodeTable[v2].adj;
        NodeTable[v2].adj=q;

        numEdges++; return true;
    }
    return false;
}

//删除边（删除（v1，v2）、（v2，v1）
bool Graphlink::removeEdge(int v1,int v2)
{
    if(v1!=-1&&v2!=-1)
    {
        //删除（v1，v2）
        Edge *p=NodeTable[v1].adj,*q=p->link;
        if(p->dest==v2)
        {
            NodeTable[v1].adj=q;
            delete p;
        }
        else
        {
            while(q->dest!=v2&&q!=NULL)
            {
                p=q;
                q=q->link;
            }
            if(q==NULL) return false;
            else {
                p->link=q->link;
                delete q;
            }
        }

        //删除（v2，v1）
        p=NodeTable[v2].adj;q=p->link;
        if(p->dest==v1)
        {
            NodeTable[v2].adj=q;
            delete p;
        }
        else
        {
            while(q->dest!=v1&&q!=NULL)
            {
                p=q;
                q=q->link;
            }
            if(q==NULL) return false;
            else {
                p->link=q->link;
                delete q;
            }
        }
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

istream& operator>>(istream &in,Graphlink &G)
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

ostream& operator<<(ostream &out,Graphlink &G)
//输出图的所有顶点和边的信息
{
    int i,m,n;
    n=G.NumberOfVertices();
    m=G.NumberOfEdges();
    out<<left<<"顶点总数："<<setw(3)<<n<<"边数："<<setw(3)<<m<<endl;
    out<<"各边的信息："<<endl;
    for(i=0;i<n;i++)
    {
       Edge *p=G.NodeTable[i].adj;
       char ch=G.NodeTable[i].data;
       while(p!=NULL)
       {
         cout<<"("<<ch<<","<<G.NodeTable[p->dest].data<<","<<p->cost<<")"<<endl;
         p=p->link;
       }
    }
       return out;
}






#endif // GRAPHLINK_H_INCLUDED
