// Code : Has Path
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Input Format :
// First line will contain T(number of test cases), each test case as follow.
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
// Line (E+2) : Two integers v1 and v2 (separated by space)
// Output Format :
// true or false for each test case in a newline.
// Constraints :
// 1 <= T <= 10
// 2 <= V <= 1000
// 1 <= E <= 1000
// 0 <= v1, v2 <= V-1
// Sample Input 1 :
// 1
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// true
// Sample Input 2 :
// 1
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :
// false

#include <bits/stdc++.h>
using namespace std;

bool printBFS(int **edges, int n, int sv, bool *visited, int v2)
{

    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty())
    {

        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        if (currentVertex == v2)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {

            if (i == currentVertex)
            {
                continue;
            }

            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    return false;
}

void BFS(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int ans = printBFS(edges, n, v1, visited, v2);
    if (ans == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    delete[] visited;
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
            int f, s;
            cin >> f >> s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }

        int v1, v2;

        cin >> v1 >> v2;

        if (edges[v1][v2] == 1)
        {
            cout << "true" << endl;
        }
        else
        {
            BFS(edges, n, v1, v2);
        }

        for (int i = 0; i < n; i++)
        {
            delete[] edges[i];
        }

        delete[] edges;
    }

    return 0;
}