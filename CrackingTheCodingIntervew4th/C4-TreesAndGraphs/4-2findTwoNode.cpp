//4.2 Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
#include <iostream>
#include <vector>
#include <queue>

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
    int numOfVetex;

public:
    DirectedGraph(int numOfVetex)
    {
        this->numOfVetex = numOfVetex;
        graph.resize(numOfVetex);
    }
    DirectedGraph(int numOfVetex, const vector<edge> edges)
    {
        this->numOfVetex = numOfVetex;
        graph.resize(numOfVetex);
        for (edge e : edges)
        {
            addEdge(e);
        }
    }

    void print()
    {
        int i = 0;
        for (vector<vector<int>>::iterator it = graph.begin(); it != graph.end(); it++)
        {
            cout << i << "-> ";
            for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++)
            {
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

    int getNumOfVertex()
    {
        return this->numOfVetex;
    }
    vector<int> getConnectedVertex(int v)
    {
        return graph[v];
    }
};

bool isConnectBFS(DirectedGraph *dg, int v, int w)
{
    int numOfVertex = dg->getNumOfVertex();
    vector<bool> visited;
    for (int i = 0; i < numOfVertex; i++)
    {
        visited.push_back(false);
    }

    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        int vertex = q.front();
        visited[vertex] = true;
        q.pop();
        vector<int> connected = dg->getConnectedVertex(vertex);
        for (vector<int>::iterator it = connected.begin(); it != connected.end(); it++)
        {
            if (!visited[*it])
            {
                q.push(*it);
            }
        }        
    }
    if (visited[w])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<edge> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};
    DirectedGraph *dg = new DirectedGraph(6, edges);
    dg->print();
    cout << endl;

    /*
    // test
    for (int i = 0; i < 6; i++)
    {
        vector<int> v = dg->getConnectedVertex(i);
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    */

    cout << isConnectBFS(dg, 0, 0) << endl; // 1
    cout << isConnectBFS(dg, 0, 1) << endl; // 1
    cout << isConnectBFS(dg, 0, 2) << endl; // 1
    cout << isConnectBFS(dg, 0, 3) << endl; // 0
    cout << isConnectBFS(dg, 0, 4) << endl; // 0
    cout << isConnectBFS(dg, 0, 5) << endl; // 0
    cout << isConnectBFS(dg, 3, 0) << endl; // 1
    cout << isConnectBFS(dg, 3, 0) << endl; // 1
    cout << isConnectBFS(dg, 5, 0) << endl; // 0
}