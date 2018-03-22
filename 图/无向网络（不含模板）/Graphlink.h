#ifndef GRAPHLINK_H_INCLUDED
#define GRAPHLINK_H_INCLUDED
#include "Graph.h"
//�ڽӱ��ʾͼ��������ϡ�����

//�߽��
struct Edge
{
    int dest;        //�ߵ���һ����λ��
    int cost;        //���ϵ�Ȩֵ
    Edge *link;      //��һ������ָ��
    Edge(){}
    Edge(int position,int weight):dest(position),cost(weight),link(NULL){}
    bool operator!=(Edge &R)const{
        return (dest!=R.dest)?true:false;
    }
};
//������
struct Vertex
{
    char data;        //������
    Edge *adj;        //�������ͷָ�룬�����һ���ߵĵ�ַ
    Vertex(int da=0):data(da),adj(NULL){}

};

//�ڽӱ��ʾͼ���ඨ��
class Graphlink:public Graph
{
private:
      Vertex *NodeTable; //��������������ͷ���
      int getVertexPos(char vertex)
      {
          for(int i=0;i<numVertices;i++)
            if(NodeTable[i].data==vertex) return i;
          return -1;
      }
public:
      Graphlink(int sz=DefaultVertices);          //���캯��
      ~Graphlink();
      char getValue(int i)                        //�õ�λ��Ϊi�Ķ����ֵ
      {
          return (i<numVertices&&i>=0)?NodeTable[i].data:0;
      }
      int getWeight(int v1,int v2);             //���ر�v1��v2�ϵ�Ȩ��
      bool insertVertex(char vertex);           //���붥��
      bool removeVertex(int v);                 //ɾ������
      bool insertEdge(int v1,int v2,int weight);  //����һ����
      bool removeEdge(int v1,int v2);           //ɾ��һ����

      int  getFirstNeighbor(int v);             //���ض���Ϊv�ĵ�һ���ڽӶ����λ�ã����Ҳ���������-1
      int  getNextNeighbor(int v,int w);        //���ض���λ��Ϊv��ĳ�ڽӶ���w����һ���ڽӶ����λ�ã����Ҳ���������-1
      friend istream& operator>>(istream &in, Graphlink &G);   //����
      friend ostream& operator<<(ostream &out,Graphlink &G);   //���
};

Graphlink::Graphlink(int sz):Graph(sz)
{
    maxVertices=(sz>DefaultVertices)?sz:DefaultVertices;
    numVertices=numEdges=0;
    NodeTable=new Vertex[maxVertices];           //�������������
}
//��������ɾ��һ���ڽӱ�
Graphlink::~Graphlink()
{
    for(int i=0;i<numVertices;i++)               //ɾ�����������еĽ��
    {
        Edge *p=NodeTable[i].adj,*q;             //ͷָ��
        while(p!=NULL)
        {
            q=p->link;
            delete p;
            p=q;
        }
    }
    delete []NodeTable;
}
//�ڽӱ��ϵĺ�����ʵ�ֶ��Ƕ������ĳ���ڽӱ�����ϲ���

//�õ�����λ��Ϊv�ĵ�һ���ڽӶ����λ��
int Graphlink::getFirstNeighbor(int v)
{
    if(v!=-1) return -1;
    Edge *p=NodeTable[v].adj;
    if(p!=NULL)
        return p->dest;
    else return -1;
}

//���ض���λ��Ϊv��ĳ�ڽӶ���w����һ���ڽӶ����λ�ã����Ҳ���������-1
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

//�õ���v1��v2�ϵ�Ȩ��
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

//���붥��
bool Graphlink::insertVertex(char vertex)
{
    if(numVertices==maxVertices) return false;
    NodeTable[numVertices].data=vertex;
    numVertices++;
    return true;
}

//ɾ������
bool Graphlink::removeVertex(int v)
{
    if(numVertices==1||v<0||v>=numVertices) return false;
    Edge *p=NodeTable[v].adj;
    while(p!=NULL)
    {
        //ɾ��ָ��ý��ı�
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

        //ɾ���ý�㷢���ı�
        q=p->link;
        delete p;
        p=q;
        numEdges--;
    }
    numVertices--;
    NodeTable[v].data=NodeTable[numVertices].data;
    p=NodeTable[v].adj=NodeTable[numVertices].adj;


    //��ԭ��ָ�����һλ����ıߣ�ȫ��ָ��v
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



//����һ����(v1,v2)(v2,v1)ʵ���ϲ�������
bool Graphlink::insertEdge(int v1,int v2,int weight)
{
    if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices)
    {
        //���루v1��v2��
        Edge *p=NodeTable[v1].adj;
        while(p!=NULL&&p->dest!=v2)
            p=p->link;
        if(p!=NULL)                  //���иñߣ����ٲ���
            return false;
        p=new Edge;
        p->dest=v2;p->cost=weight;
        //ͷ�巨
        p->link=NodeTable[v1].adj;
        NodeTable[v1].adj=p;


        //���루v2��v1��
        Edge *q=NodeTable[v2].adj;
        q=new Edge;
        q->dest=v1;q->cost=weight;
        //ͷ�巨
        q->link=NodeTable[v2].adj;
        NodeTable[v2].adj=q;

        numEdges++; return true;
    }
    return false;
}

//ɾ���ߣ�ɾ����v1��v2������v2��v1��
bool Graphlink::removeEdge(int v1,int v2)
{
    if(v1!=-1&&v2!=-1)
    {
        //ɾ����v1��v2��
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

        //ɾ����v2��v1��
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

istream& operator>>(istream &in,Graphlink &G)
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

ostream& operator<<(ostream &out,Graphlink &G)
//���ͼ�����ж���ͱߵ���Ϣ
{
    int i,m,n;
    n=G.NumberOfVertices();
    m=G.NumberOfEdges();
    out<<left<<"����������"<<setw(3)<<n<<"������"<<setw(3)<<m<<endl;
    out<<"���ߵ���Ϣ��"<<endl;
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
