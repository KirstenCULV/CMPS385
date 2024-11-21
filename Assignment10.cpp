#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;

    void DepthFirstTool(int v, vector<bool>& visited)
    {
        visited[v]= true;
        cout << v << " ";

        for (int i : adj[v]) {
            if (!visited[i])
                DepthFirstTool(i, visited);
        }
    }

public:
    Graph(int V)
    {
        this->V= V;
        adj.resize(V);
    }
    void addEdge(int v, int w) { adj[v].push_back(w); }
    void DepthFirst(int v)
    {
        vector<bool> visited(V, false);
        DepthFirstTool(v, visited);
    }
    void BreadFirst(int startVertex)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[startVertex]= true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();

            cout << currentVertex << " ";
            q.pop();

            for (int neighbor : adj[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    Graph g(8);
    // 0-8 = q-x
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);

    cout << "Here is a Depth First Traversal of this graph starting from vertex " "6: ";
    g.DepthFirst(6);
    cout << endl;

    cout << "Here is a Breadth First Traversal of this graph starting from vertex " "6: ";
    g.BreadFirst(6);
    cout << endl;



    return 0;
}