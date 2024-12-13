#include <iostream>
#include <vector>
using namespace std;

#define V 5

int minKey(vector<int>& key, vector<bool>& mstSet) {

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void print(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<< parent[i] << " - " << i << " \t"
        << graph[parent[i]][i] << " \n";
}

void primMST(vector<vector<int>>& graph) {

    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V);

    for (int i= 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0]= 0;
    parent[0] = -1;

    for (int count= 0; count < V - 1; count++) {

        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v= 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    print(parent, graph);
}

int main() {
    vector<vector<int>> graph= { { 3, 2, 0, 3, 0 },
                              { 2, 0, 3, 8, 1 },
                              { 0, 3, 0, 9, 7 },
                              { 5, 2, 9, 0, 0 },
                              { 0, 5, 8, 9, 0 } };

    primMST(graph);

    return 0;
}