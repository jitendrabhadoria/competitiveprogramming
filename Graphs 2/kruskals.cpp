// Kruskal's Algorithm Send Feedback
// Given an undirected,
// connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
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

#include <iostream>
#include <algorithm>
using namespace std;
// Class that store values for each vertex
class Edge
{
public:
    int source;
    int dest;
    int weight;
};
// Comparator function used to sort edges
bool compare(Edge e1, Edge e2)
{
    // Edges will sorted in order of their weights
    return e1.weight < e2.weight;
}
// Function to find the parent of a vertex
int findParent(int v, int *parent)
{
    // Base case, when a vertex is parent of itself
    if (parent[v] == v)
    {
        return v;
    }
    // Recursively called to find the topmost parent of the vertex.
    return findParent(parent[v], parent);
}
void kruskals(Edge *input, int n, int E)
{
    // In-built sort function: Sorts the edges in
    // increasing order of their weights
    sort(input, input + E, compare);
    // Array to store final edges of MST
    Edge *output = new Edge[n - 1];
    // Parent array initialized with their indexes
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0; // To maintain the count of number of edges in    the MST
    int i = 0;     // Index to traverse over the input array
    while (count != n - 1)
    { // As the MST contains n-1 edges.
        Edge currentEdge = input[i];
        // Figuring out the parent of each edge's vertices
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);
        // If their parents are not equal, then we added that edge to        output
        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;                           // Increased the count
            parent[sourceParent] = destParent; // Updated the parent array
        }
        i++;
    }
    // Finally, printing the MST obtained.
    long long int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].dest)
        {
            sum += (output[i].weight);
        }
        else
        {
            sum += (output[i].weight);
        }
    }

    cout << sum << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n, E;
        cin >> n;
        cin >> E;
        Edge *input = new Edge[E];
        for (int i = 0; i < E; i++)
        {
            int s, d, w;
            cin >> s >> d >> w;
            input[i].source = s;
            input[i].dest = d;
            input[i].weight = w;
        }
        kruskals(input, n, E);
    }
    return 0;
}