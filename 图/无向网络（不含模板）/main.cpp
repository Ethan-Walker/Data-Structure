#include <iostream>
#include "Graphmtx.h"
#include "Graphlink.h"
using namespace std;

int main()
{
    Graphmtx G;
    cin>>G;
    cout<<G<<endl;
    cout<<"�������е���ͨ������";
    Components(G);
    cout<<endl<<"��B��������������ͨ�����������������������";
    DFS(G,'B');                   //��BΪ��㣬�����������
    cout<<endl<<"��C��������������ͨ�������й������������";
    BFS(G,'C');
    /*
    G.removeEdge(1,2);
    cout<<G<<endl;

    G.insertVertex('H');
    G.insertEdge(0,5,100);
    cout<<G<<endl;

    G.removeVertex(3);
    cout<<G<<endl;*/
    return 0;
}
