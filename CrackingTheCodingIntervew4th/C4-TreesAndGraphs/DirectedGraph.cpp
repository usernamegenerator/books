#include <iostream>
#include <vector>

using namespace std;

typedef struct edge
{
    int v;
    int w;
} edge;

class DirectedGraph
{
private:
    vector<vector<int>> graph;

public:
    DirectedGraph(int numOfVetex)
    {
        graph.resize(numOfVetex);
    }
    DirectedGraph(int numOfVetex, const vector<edge> edges)
    {
        graph.resize(numOfVetex);
        for (edge e : edges)
        {
            addEdge(e);
        }
    }

    void print()
    {
        int i = 0;
        for (vector< vector<int> >::iterator it = graph.begin(); it != graph.end(); it++)
        {
            cout << i << "-> ";
            for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++){
                cout << *jt << " ";
            }
            i++;
            cout << endl;
        }
    }

    void addEdge(const edge e)
    {
        graph[e.v].push_back(e.w);
    }
};

int main()
{
    /*
    int numOfVetex = 10;
    DirectedGraph *dg = new DirectedGraph(10);
    edge e = {1,2};
    dg->addEdge(e);
    */

    vector<edge> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};
    DirectedGraph *dg = new DirectedGraph(10, edges);
    dg->print();
}
