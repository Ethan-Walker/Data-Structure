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
    const int maxWeight=100000;     //�������Ȩ��
    int NumberOfVertices(){return numVertices;}
    int NumberOfEdges(){return numEdges;}
    int GetmaxVertices(){return maxVertices;}

    virtual int  getFirstNeighbor(int v);             //���ض���Ϊv�ĵ�һ���ڽӶ����λ�ã����Ҳ���������-1
    virtual int  getNextNeighbor(int v,int w);        //���ض���λ��Ϊv��ĳ�ڽӶ���w����һ���ڽӶ����λ�ã����Ҳ���������-1

};


#endif // GRAPH_H_INCLUDED
