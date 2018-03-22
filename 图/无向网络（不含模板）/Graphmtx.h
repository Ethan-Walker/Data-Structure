#ifndef GRAPH-MTX_H_INCLUDED
#define GRAPH-MTX_H_INCLUDED
#include <iostream>
#include <iomanip>
#include "Graph.h"
#include <queue>
using namespace std;
//�ڽӾ����ʾͼ�������ڷ�ϡ�����
class Graphmtx:public Graph
{
private:
    char *VerticesList;              //�����
    int **Edge;                      //�ڽӾ���

public:
    Graphmtx(int sz=DefaultVertices);                       //���캯��
    ~Graphmtx()                                             //��������
    {
        delete []VerticesList;delete []Edge;
    }
    char getValue(int i)                                    //ȡλ��Ϊi�Ķ�����Ԫ��ֵ
    {
        return (i>=0&&i<=numVertices)?VerticesList[i]:NULL;
    }
    int getWeight(int v1,int v2)                            //ȡ�ߣ�v1��v2���ϵ�Ȩ��
    {
        return v1!=-1&&v2!=-1?Edge[v1][v2]:0;
    }
    int getVertexPos(char vertex)    //�õ�����vertex�ڶ�����е�λ��
    {
        for(int i=0;i<numVertices;i++)
            if(VerticesList[i]==vertex)  return i;
        return -1;
    }
    int  getFirstNeighbor(int v);             //���ض���Ϊv�ĵ�һ���ڽӶ����λ�ã����Ҳ���������-1
    int  getNextNeighbor(int v,int w);        //���ض���λ��Ϊv��ĳ�ڽӶ���w����һ���ڽӶ����λ�ã����Ҳ���������-1

    bool insertVertex(const char vertex);        //��ͼ�в���һ������vertex���ö�����ʱû�����
    bool removeVertex(int v);                 //����ɾ������ͼ�ж��㣬��ɾȥ����v�����й��������ı�
    bool insertEdge(int v1,int v2,int cost);    //�����ɱߵ���������v1��v2��ͼ�еĶ��㣬����ͼ�в���һ���ߣ�v1��v2��
    bool removeEdge(int v1,int v2);           //�����ɱߵ���������v1��v2��ͼ�ж��㣬��ɾȥ�ߣ�v1��v2��

    friend istream& operator>>(istream &in, Graphmtx &G);   //����
    friend ostream& operator<<(ostream &out,Graphmtx &G);   //���
};

Graphmtx::Graphmtx(int sz):Graph(sz)
{
    maxVertices=(sz>DefaultVertices)?sz:DefaultVertices;
    numVertices=numEdges=0;
    VerticesList=new char[maxVertices];  //�������������

    Edge=(int **)new int*[maxVertices];   //�����ڽӾ�������
    for(int i=0;i<maxVertices;i++)
        Edge[i]=new int[maxVertices];

    for(int i=0;i<maxVertices;i++)        //�ڽӾ����ʼ��
        for(int j=0;j<maxVertices;j++)
        Edge[i][j]=(i==j?0:maxWeight);
}

int Graphmtx::getFirstNeighbor(int v)
//���ض���λ��Ϊv�ĵ�һ���ڽӶ����λ�ã����Ҳ���������-1
{
    if(v!=-1)
    {
        for(int col=0;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;

    }
    return -1;
}

int Graphmtx::getNextNeighbor(int v,int w)
//���ض���λ��Ϊv��ĳ�ڽӶ���w����һ���ڽӶ����λ�ã����Ҳ���������-1
{
    if(v!=-1&&w!=-1)
    {
        for(int col=w+1;col<numVertices;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
    }
    return -1;
}

bool Graphmtx::insertVertex(const char vertex)
//���붥��vertex�����Ա�������
{
    if(numVertices==maxVertices) return false;      //�ռ䲻��
    else
    {
        VerticesList[numVertices++]=vertex;
        return true;
    }

}

bool Graphmtx::removeVertex(int v)
//ɾȥ�������λ��Ϊv�Ķ�������й��������ı�
{
    if(v<0||v>=numVertices) return false;            //v����ͼ�У���ɾ��
    if(numVertices==1) return false;                 //ֻʣһ�����㣬����ɾ��

    VerticesList[v]=VerticesList[numVertices-1];     //�������ɾ���ö���
    for(int i=0;i<numVertices;i++)                   //��ȥ��֮������ı���
            if(Edge[v][i]>0&&Edge[v][i]<maxWeight)
                numEdges--;
    for(int i=0;i<numVertices;i++)
        Edge[v][i]=Edge[numVertices-1][i];           //�����һ�����v��
    numVertices--;
    for(int i=0;i<numVertices;i++)
        Edge[i][v]=Edge[i][numVertices];             //���һ�����v��
    return true;
}

bool Graphmtx::insertEdge(int v1,int v2,int cost)
//�����ɱߵ���������v1��v2��ͼ�еĶ��㣬����ͼ�в���һ���ߣ�v1��v2��
{
    if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices&&Edge[v1][v2]==maxWeight) //��������
    {
        Edge[v1][v2]=Edge[v2][v1]=cost;
        numEdges++;
        return true;
    }
    return false;
}

bool Graphmtx::removeEdge(int v1,int v2)
//�����ɱߵ���������v1��v2��ͼ�ж��㣬��ɾȥ�ߣ�v1��v2��
{
    if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<maxWeight)  //ɾ������
    {
        Edge[v1][v2]=Edge[v2][v1]=maxWeight;
        numEdges--;
        return true;
    }
    return false;
}
//Ϊ�˽������ڽӾ���洢��ͼ������ͼ�������
//�����������Ϣ  ����A��B��C��D��E
//��������ߵ���Ϣ
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
    cout<<"��������Ҫ����ͼ�Ķ�������ͱ�����";
    in>>n>>m;
    cout<<endl<<"����������������ݣ�";
    for(i=0;i<n;i++)
    {
        in>>vertex1;
        G.insertVertex(vertex1);
    }
    cout<<endl<<"��������ߵ���Ϣ��"<<endl;
    for(i=0;i<m;)
    {
        in>>vertex1>>vertex2>>weight;
        v1=G.getVertexPos(vertex1);
        v2=G.getVertexPos(vertex2);
        if(v1==-1||v2==-1)
        {
            cout<<"�����˵���Ϣ����,���������룡"<<endl;
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
//���ͼ�����ж���ͱߵ���Ϣ
{
    int i,j,m,n;
    char vertex1,vertex2;
    int weight;

    n=G.NumberOfVertices();
    m=G.NumberOfEdges();
    out<<left<<"����������"<<setw(3)<<n<<"������"<<setw(3)<<m<<endl;
    out<<"���ߵ���Ϣ��"<<endl;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)  //����ͼֻҪ���������Ǽ���
       {
           weight=G.getWeight(i,j);
           if(weight>0&&weight<G.maxWeight)   //���ڱ�
           {
             vertex1=G.getValue(i);
             vertex2=G.getValue(j);
             //�ԣ�vertex1��vertex2��weight���ĸ�ʽ���ÿ���ߵ���Ϣ
             out<<"("<<vertex1<<","<<vertex2<<","<<weight<<")"<<endl;
           }
       }
       return out;
}

//��ͨͼ��DFS��BFSֻ�ñ���һ�μ��ɷ������ж��㣬���ʷ���ͨͼ��ÿ���һ��DFS/BFS������Ҫ��ÿ���������¼��,�Ƿ�����δ���ʶ���
void DFS(Graphmtx &G,int loc,int visited[]);

//ͨ��DFS���ҳ�����ͼ��������ͨ����
void Components(Graphmtx &G)
{
    int i,n=G.NumberOfVertices();
    int *visited=new int[n];
    for(i=0;i<n;i++)
        visited[i]=0;
    for(i=0;i<n;i++)
        if(visited[i]==0)         //δ���ʹ������ʸ���ͨ����
        {
          DFS(G,i,visited);
        }
    delete []visited;
}
//�ݹ�DFS��

//������ȱ���(�������еĽڵ㣩
//�Ӷ���vertex���������������ڵ���ͨ����
void DFS(Graphmtx &G,char vertex)
{

    int i,loc,n=G.NumberOfVertices();
    int *visited=new int[n];            //����ָ������ ���������٣�
    for(i=0;i<n;i++)                    //���ʱ�� ��������
        visited[i]=0;
    loc=G.getVertexPos(vertex);
    DFS(G,loc,visited);
    delete []visited;
}
//�Ӷ���λ��loc��������������ȵĴ�����ʸý�����ڵļ�����ͨ��ͼ�������Ƿ���ͨͼ��
void DFS(Graphmtx &G,int loc,int visited[])
{
    cout<<G.getValue(loc)<<" ";
    visited[loc]=1;
    int w=G.getFirstNeighbor(loc);          //�Ҷ���loc�ĵ�һ���ڽӶ���
    while(w!=-1)
    {
        if(visited[w]==0) DFS(G,w,visited); //�ȵݹ�����ڽӶ�����ڽӡ��ڽӡ�
        w=G.getNextNeighbor(loc,w);         //�õ�ԭ���������һ���ڽӶ���
    }
}

//BFS�����������
void BFS(Graphmtx &G,char vertex)
{
    int loc,i,n,w;
    n=G.NumberOfVertices();           //��ȡ��ǰ��������
    int *visited=new int[n];          //���ʱ������
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
            if(visited[w]==0)                   //����loc�ĵ�һ���ڽӶ���
            {
                cout<<G.getValue(w)<<" ";
                visited[w]=1;
                q.push(w);                      //���
            }
            w=G.getNextNeighbor(loc,w);         //�Ҷ���loc����һ���ڽӶ���

        }
    }
    delete []visited;

}

#endif // GRAPH-MTX_H_INCLUDED
