// Code : All connected components
// Send Feedback
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// V is the number of vertices present in graph G and vertices are numbered from 1 to V.
// E is the number of edges present in graph G.
// You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
// Input Format :
// First line of input will contain T(number of test case), each test case follows as.
// Line 1: Two Integers V and E (separated by space)
// Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
// Output Format :
// For each test case and each connected components print the connected components in sorted order in new line.
// Order of connected components doesn't matter (print as you wish).
// Constraints :
// 2 <= V <= 10000
// 1 <= E <= 10000
// Sample Input 1:
// 1
// 4 2
// 2 1
// 4 3
// Sample Output 1:
// 1 2
// 4 3

#include <bits/stdc++.h>
using namespace std;

#define ll int

int arr[10001][10001];

struct query
{
    int aa;
    int bb;
};

struct node
{
    vector<int> nb;
};

vector<ll> vector_creator(ll n, ll starting_vertex, bool *visited, int max, node *nodes)
{
    vector<ll> temp;
    queue<ll> q;

    q.push(starting_vertex);

    visited[starting_vertex] = true;

    while (!q.empty())
    {
        ll current_element = q.front();
        temp.push_back(current_element);
        q.pop();
        vector<int> t1;
        t1 = nodes[current_element].nb;

        for (int i = 0; i < t1.size(); i++)
        {
            if (t1[i] == current_element)
            {
                continue;
            }
            if (!visited[t1[i]])
            {
                q.push(t1[i]);
                visited[t1[i]] = true;
            }
        }
    }
    return temp;
}

vector<vector<ll>> vector_return(ll n, int max, node *nodes)
{

    bool *visited = new bool[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        visited[i] = false;
    }

    vector<vector<ll>> super;
    vector<ll> tempo;
    for (ll i = 1; i <= max; i++)
    {
        if (!visited[i])
        {
            tempo = vector_creator(n, i, visited, max, nodes);
            if (tempo.size() != 0)
            {
                super.push_back(tempo);
            }
        }
    }
    for (int i = max + 1; i <= n; i++)
    {
        vector<int> t1;
        t1.push_back(i);
        super.push_back(t1);
    }

    return super;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll v, e;
        cin >> v >> e;
        int max = 0;

        node *nodes = new node[v + 1];
        for (int i = 0; i <= v; i++)
        {
            nodes[i].nb.push_back(i);
        }

        query q[e];
        for (int i = 0; i < e; i++)
        {

            ll a, b;
            cin >> a >> b;

            arr[a][b] = 1;
            arr[b][a] = 1;

            q[i].aa = a;
            q[i].bb = b;

            nodes[a].nb.push_back(b);
            nodes[b].nb.push_back(a);

            if (max < a)
            {
                max = a;
            }
            if (max < b)
            {
                max = b;
            }
        }

        vector<vector<ll>> super;

        super = vector_return(v, max, nodes);

        for (ll i = 0; i < super.size(); i++)
        {
            sort(super[i].begin(), super[i].end());
            for (ll j = 0; j < super[i].size(); j++)
            {
                cout << super[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < e; i++)
        {

            arr[q[i].aa][q[i].bb] = 0;
            arr[q[i].bb][q[i].aa] = 0;
        }
    }
}