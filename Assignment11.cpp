#include <iostream>
using namespace std;
#include <limits.h>
#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX,  min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printShortestPath(int dist[])
{
    cout << "Vertex \t Distance from the Source" << endl;
    for (int i= 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstraAlg(int graph[V][V], int src)
{
    int dist[V]; 
    bool sptSet[V]; 

    for (int i= 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v= 0; v < V; v++)

            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v ] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printShortestPath(dist);
}

int main()
{

    int graph[V][V] = { { 0, 6, 0, 0, 0, 0, 0, 2, 0 },
                        { 6, 0, 8, 0, 0, 0, 0, 5, 0 },
                        { 0, 2, 0, 3, 0, 6, 0, 0, 8 },
                        { 0, 0, 3, 0, 1, 7, 0, 0, 0 },
                        { 0, 0, 0, 1, 0, 5, 0, 0, 0 },
                        { 0, 0, 6, 8, 2, 0, 8, 0, 0 },
                        { 0, 0, 0, 0, 0, 8, 0, 9, 4 },
                        { 2, 6, 0, 0, 0, 0, 9, 0, 3 },
                        { 0, 0, 8, 0, 0, 0, 4, 3, 0 } };

    dijkstraAlg(graph, 0);


    return 0;
}

