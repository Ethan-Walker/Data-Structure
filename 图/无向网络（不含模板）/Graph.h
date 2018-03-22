#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
const int DefaultVertices=100;
class Graph
{
protected:
    int numVertices;
    int numEdges;
    int maxVertices;
public:
    Graph(int sz=DefaultVertices){ numVertices=sz;}
    ~Graph(){}
    const int maxWeight=100000;     //定义最大权重
    int NumberOfVertices(){return numVertices;}
    int NumberOfEdges(){return numEdges;}
    int GetmaxVertices(){return maxVertices;}

    virtual int  getFirstNeighbor(int v);             //返回顶点为v的第一个邻接顶点的位置，若找不到，返回-1
    virtual int  getNextNeighbor(int v,int w);        //返回顶点位置为v的某邻接顶点w的下一个邻接顶点的位置，若找不到，返回-1

};


#endif // GRAPH_H_INCLUDED
