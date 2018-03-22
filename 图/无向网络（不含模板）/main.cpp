#include <iostream>
#include "Graphmtx.h"
#include "Graphlink.h"
using namespace std;

int main()
{
    Graphmtx G;
    cin>>G;
    cout<<G<<endl;
    cout<<"访问所有的连通分量：";
    Components(G);
    cout<<endl<<"从B出发对其所在连通分量进行深度优先搜索，：";
    DFS(G,'B');                   //以B为起点，深度优先搜索
    cout<<endl<<"从C出发对其所在连通分量进行广度优先搜索：";
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
