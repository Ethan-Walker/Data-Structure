#ifndef GRAPH-MTX_H_INCLUDED
#define GRAPH-MTX_H_INCLUDED
#include <iostream>
#include <iomanip>
#include "Graph.h"
using namespace std;

//���ڽӾ����ʾ��ͼ���ඨ��
//��Դ�Ȩ����ͼ

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
    T *VerticesList;              //�����
    E **Edge;                     //�ڽӾ���
    int getVertexPos(T vertex)    //�õ�����vertex�ڶ�����е�λ��
    {
        for(int i=0; i<Graph<T,E>::numVertices; i++)
            if(VerticesList[i]==vertex)  return i;
        return -1;
    }

public:

    Graphmtx(int sz=DefaultVertices);                       //���캯��
    ~Graphmtx()                                             //��������
    {
        delete []VerticesList;
        delete []Edge;
    }
    T getValue(int i)                                       //ȡλ��Ϊi�Ķ�����Ԫ��ֵ
    {
        return (i>=0&&i<=Graph<T,E>::numVertices)?VerticesList[i]:NULL;
    }
    E getWeight(int v1,int v2)                              //ȡ�ߣ�v1��v2���ϵ�Ȩ��
    {
        return v1!=-1&&v2!=-1?Edge[v1][v2]:0;
    }
    int  getFirstNeighbor(int v);             //���ض���Ϊv�ĵ�һ���ڽӶ����λ�ã����Ҳ���������-1
    int  getNextNeighbor(int v,int w);        //���ض���λ��Ϊv��ĳ�ڽӶ���w����һ���ڽӶ����λ�ã����Ҳ���������-1

    bool insertVertex(const T &vertex);        //��ͼ�в���һ������vertex���ö�����ʱû�����
    bool removeVertex(int v);                 //����ɾ������ͼ�ж��㣬��ɾȥ����v�����й��������ı�
    bool insertEdge(int v1,int v2,E cost);    //�����ɱߵ���������v1��v2��ͼ�еĶ��㣬����ͼ�в���һ���ߣ�v1��v2��
    bool removeEdge(int v1,int v2);           //�����ɱߵ���������v1��v2��ͼ�ж��㣬��ɾȥ�ߣ�v1��v2��

    friend istream& operator>><>(istream &in, Graphmtx<T,E> &G);   //����
    friend ostream& operator<<<>(ostream &out,Graphmtx<T,E> &G);   //���
};


template <class T,class E>
Graphmtx<T,E>::Graphmtx(int sz):Graph<T,E>(sz)
{

    Graph<T,E>::maxVertices=sz;
    Graph<T,E>::numVertices=Graph<T,E>::numEdges=0;

    VerticesList=new T[ Graph<T,E>:: maxVertices];  //�������������

    Edge=(E **)new E*[ Graph<T,E>:: maxVertices];   //�����ڽӾ�������

    for(int i=0; i< Graph<T,E>:: maxVertices; i++)
        Edge[i]=new E[ Graph<T,E>:: maxVertices];
    for(int i=0; i< Graph<T,E>:: maxVertices; i++)      //�ڽӾ����ʼ��
        for(int j=0; j< Graph<T,E>:: maxVertices; j++)
            Edge[i][j]=(i==j?0: Graph<T,E>:: maxWeight);

}
template <class T,class E>
int Graphmtx<T,E>::getFirstNeighbor(int v)
//���ض���Ϊv�ĵ�һ���ڽӶ����λ�ã����Ҳ���������-1
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
//���ض���λ��Ϊv��ĳ�ڽӶ���w����һ���ڽӶ����λ�ã����Ҳ���������-1
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
//���붥��vertex
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
//ɾȥ�������λ��Ϊv�Ķ�������й��������ı�
{
    if(v<0||v>=Graph<T,E>::numVertices) return false;//v����ͼ�У���ɾ��
    if(Graph<T,E>::numVertices==1) return false;     //ֻʣһ�����㣬����ɾ��
    VerticesList[v]=VerticesList[Graph<T,E>::numVertices-1];  //�������ɾ���ö���
    for(int i=0; i<Graph<T,E>::numVertices; i++)
        if(Edge[v][i]>0&&Edge[v][i]<Graph<T,E>::maxWeight) Graph<T,E>::numEdges--;  //��ȥ��֮������ı���
    for(int i=0; i<Graph<T,E>::numVertices; i++)
        Edge[v][i]=Edge[Graph<T,E>::numVertices-1][i];            //�����һ�����v��
    Graph<T,E>::numVertices--;
    for(int i=0; i<Graph<T,E>::numVertices; i++)
        Edge[i][v]=Edge[i][Graph<T,E>::numVertices];              //���һ�����v��
    return true;

}
template <class T,class E>
bool Graphmtx<T,E>::insertEdge(int v1,int v2,E cost)
//�����ɱߵ���������v1��v2��ͼ�еĶ��㣬����ͼ�в���һ���ߣ�v1��v2��
{
    if(v1>=0&&v1<Graph<T,E>::numVertices&&v2>=0&&v2<Graph<T,E>::numVertices&&Edge[v1][v2]==Graph<T,E>::maxWeight) //��������
    {
        Edge[v1][v2]=Edge[v2][v1]=cost;
        Graph<T,E>::numEdges++;
        return true;
    }
    return false;
}
template <class T,class E>
bool Graphmtx<T,E>::removeEdge(int v1,int v2)
//�����ɱߵ���������v1��v2��ͼ�ж��㣬��ɾȥ�ߣ�v1��v2��
{
    if(v1>=0&&v1<Graph<T,E>::numVertices&&v2>=0&&v2<Graph<T,E>::numVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<Graph<T,E>::maxWeight)  //ɾ������
    {
        Edge[v1][v2]=Edge[v2][v1]=Graph<T,E>::maxWeight;
        Graph<T,E>::numEdges--;
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
template <class T,class E>
istream& operator>>(istream &in,Graphmtx<T,E> &G)
{
    int i,v1,v2,m,n;
    T vertex1,vertex2;
    E weight;
    cout<<"��������Ҫ����ͼ�Ķ�������ͱ�����";
    in>>n>>m;

    cout<<endl<<"����������������ݣ�";
    for(i=0; i<n; i++)
    {
        in>>vertex1;
        G.insertVertex(vertex1);
    }
    cout<<endl<<"��������ߵ���Ϣ��"<<endl;
    for(i=0; i<m;)
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
template <class T,class E>
ostream& operator<<(ostream &out,Graphmtx<T,E> &G)
//���ͼ�����ж���ͱߵ���Ϣ
{
    int i,j,m,n;
    T vertex1,vertex2;
    E weight;
    n=G.NumberOfVertices();
    m=G.NumberOfEdges();
    out<<left<<"����������"<<setw(3)<<n<<"������"<<setw(3)<<m<<endl;
    out<<"���ߵ���Ϣ��"<<endl;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++) //����ͼֻҪ���������Ǽ���
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




















#endif // GRAPH-MTX_H_INCLUDED
