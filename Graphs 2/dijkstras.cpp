// Dijkstra's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
// Note : Order of vertices in output doesn't matter.
// Input Format :
// First line will contain T(number of test case), each test case follows as.
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// In different lines, ith vertex number and its distance from source (separated by space)
// Constraints :
// 1 <= T <= 10
// 2 <= V, E <= 10^3
// Sample Input 1 :
// 1
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5

#include <iostream>
#include <climits>
using namespace std;
int findMinVertex(int *distance, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}
void dijkstra(int **edges, int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0; // 0 is considered as the starting node.
    for (int i = 0; i < n - 1; i++)
    {
        // Find min vertex
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;
        // Explore unvisited neighbors
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                // distance of any node will be the current node's distance + the weight
                // of the edge between them
                int dist = distance[minVertex] + edges[minVertex][j];
                if (dist < distance[j])
                { // If required, then updated.
                    distance[j] = dist;
                }
            }
        }
    }
    // Final output of distance of each node with respect to 0
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int e;
        cin >> n >> e;
        int **edges = new int *[n];
        for (int i = 0; i < n; i++)
        {
            edges[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                edges[i][j] = 0;
            }
        }
        for (int i = 0; i < e; i++)
        {
            int f, s, weight;
            cin >> f >> s >> weight;
            edges[f][s] = weight;
            edges[s][f] = weight;
        }
        dijkstra(edges, n);
        for (int i = 0; i < n; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
    }
    return 0;
}
