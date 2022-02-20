// Prim's Algorithm Send Feedback
// Given an undirected,
// connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.
// Input Format :
// First line will contain T(number of test case), each test case follows as.
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// Weight of MST for each test case in new line.
// Constraints :
// 1 <= T <= 10
// 2 <= V, E <= 10^5
// 1 <= wt <= 10^4
// Sample Input 1 :
// 1
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 9

#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *weights, bool *visited, int n)
{
    // Initialized to -1 means there is no vertex till now
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        // Conditions: the vertex must be unvisited and either minVertex value is -1
        //  or if minVertex has some vertex to it, then weight of currentvertex
        //  should be less than the weight of the minVertex.
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int **edges, int n)
{
    int *parent = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];
    // Initially, the visited array is assigned to false and weights array
    // to infinity.
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    // Values assigned to vertex 0.(the selected starting vertex to begin with)
    parent[0] = -1;
    weights[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // Find min vertex
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;
        // Explore unvisited neighbors
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weights[j])
                {
                    // updating weight array and parent array
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    // Final MST printed
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (weights[i]);
    }

    cout << sum << endl;
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
        int **edges = new int *[n]; // Adjacency matrix used to store the graph
        for (int i = 0; i < n; i++)
        {
            edges[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                // Initially all pairs are assigned 0 weight which
                // means that there is no edge between them
                edges[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < e; i++)
        {
            int f, s, weight;
            cin >> f >> s >> weight;

            if (edges[f][s] > weight)
            {
                edges[f][s] = weight;
            }
            if (edges[s][f] > weight)
            {
                edges[s][f] = weight;
            }
        }
        prims(edges, n);
        for (int i = 0; i < n; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
    }

    return 0;
}
