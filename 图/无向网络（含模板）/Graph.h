#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

//ͼ�Ļ���
const int DefaultVertices=100;
template<class T,class E>                     //TΪ������Ԫ���������ͣ�EΪȨ����������
class Graph
{
protected:
    int maxVertices;                          //ͼ����󶥵���
    int numEdges;                             //��ǰ����
    int numVertices;                          //��ǰ������

public:
    E maxWeight=100000;                 //���������
    Graph(int sz=DefaultVertices);            //����һ����ͼ
    //~Graph();                                 //��������

    bool GraphEmpty()const                    //��ͼ��û�бߣ��򷵻�true�����򣬷���false
    {
        if(numEdges==0) return true;
        else return false;
    }
    bool GraphFull()const                     //�ж�ͼ��
    {
        if(numEdges==maxVertices) return true;
        else return false;
    }
    int NumberOfVertices()
    {
        return numVertices;   //���ص�ǰ�����Ŀ
    }
    int NumberOfEdges()
    {
        return numEdges;   //���ص�ǰ����
    }
    int GetmaxVertices()
    {
        return maxVertices;   //�õ�ͼ����󶥵���
    }
};
template <class T,class E>
Graph<T,E>::Graph(int sz)
{
    numVertices=sz;
}

#endif // GRAPH_H_INCLUDED
