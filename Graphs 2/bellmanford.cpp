#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge *edge;
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
void printAns(int dist[], int n, int src, int dest)
{
    for (int i = 1; i <= n; ++i)
        if (i == dest)
            if (dist[i] == INT_MAX)
            {
                cout << "1000000000" << endl;
            }
            else
            {
                cout << dist[i] << endl;
            }
}
void BellmanFord(struct Graph *graph, int src, int dest)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V + 1];
    for (int i = 0; i <= V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "1000000000" << endl;
            return; // If negative cycle is detected, simply return
        }
    }
    printAns(dist, V, src, dest);
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        int src, dest;
        cin >> V;
        cin >> E;
        cin >> src;
        cin >> dest;
        struct Graph *graph = createGraph(V, E);
        for (int i = 0; i < E; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph->edge[i].src = u;
            graph->edge[i].dest = v;
            graph->edge[i].weight = w;
        }
        BellmanFord(graph, src, dest);
    }

    return 0;
}