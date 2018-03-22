#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

//图的基类
const int DefaultVertices=100;
template<class T,class E>                     //T为顶点内元素数据类型，E为权重数据类型
class Graph
{
protected:
    int maxVertices;                          //图中最大顶点数
    int numEdges;                             //当前边数
    int numVertices;                          //当前顶点数

public:
    E maxWeight=100000;                 //代表无穷大
    Graph(int sz=DefaultVertices);            //建立一个空图
    //~Graph();                                 //析构函数

    bool GraphEmpty()const                    //若图中没有边，则返回true，否则，返回false
    {
        if(numEdges==0) return true;
        else return false;
    }
    bool GraphFull()const                     //判断图满
    {
        if(numEdges==maxVertices) return true;
        else return false;
    }
    int NumberOfVertices()
    {
        return numVertices;   //返回当前结点数目
    }
    int NumberOfEdges()
    {
        return numEdges;   //返回当前边数
    }
    int GetmaxVertices()
    {
        return maxVertices;   //得到图中最大顶点数
    }
};
template <class T,class E>
Graph<T,E>::Graph(int sz)
{
    numVertices=sz;
}

#endif // GRAPH_H_INCLUDED
