// BOTTOM
// Send Feedback
//     We will use the
//     following(standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.
// Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).
// Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// First line will contain two space-separated integers N and M denoting the number of vertex and edges respectively.
// Next M line will contain two space separated integers a, b denoting an edge from a to b.
// Output Format:
// For each test case output the bottom of the specified graph on a single line.
// Constraints:
// 1 <= T <= 50
// 1 <= N, M <= 10^5
// Sample Input:
// 1
// 3 6
// 3 1
// 2 3
// 3 2
// 1 2
// 1 3
// 2 1
// Sample Output:
// 1 2 3
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int start, unordered_set<int> &visited, stack<int> &finished_vertices_stack)
{
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs(edges, adjacent, visited, finished_vertices_stack);
        }
    }
    finished_vertices_stack.push(start);
}
void dfs2(vector<int> *edgesT, int start, unordered_set<int> &visited, vector<int> &component)
{
    visited.insert(start);
    component.push_back(start);
    for (int i = 0; i < edgesT[start].size(); i++)
    {
        int adjacent = edgesT[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs2(edgesT, adjacent, visited, component);
        }
    }
}
vector<vector<int>> getSCC(vector<int> *edges, vector<int> *edgesT, int n)
{
    unordered_set<int> visited;
    stack<int> finished_vertices_stack;
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs(edges, i, visited, finished_vertices_stack);
        }
    }
    visited.clear();
    vector<vector<int>> output;
    while (!finished_vertices_stack.empty())
    {
        int element = finished_vertices_stack.top();
        finished_vertices_stack.pop();
        if (visited.count(element) == 0)
        {
            vector<int> component;
            dfs2(edgesT, element, visited, component);
            output.push_back(component);
        }
    }
    return output;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;

        vector<int> *edges = new vector<int>[v];
        vector<int> *edgesT = new vector<int>[v];
        for (int i = 0; i < e; i++)
        {
            int j, k;
            cin >> j >> k;
            edges[j - 1].push_back(k - 1);
            edgesT[k - 1].push_back(j - 1);
        }
        vector<vector<int>> components = getSCC(edges, edgesT, v);

        auto it = components.begin();
        vector<int> ans;
        while (it != components.end())
        {
            int flag = 0;
            auto it2 = (*it).begin();
            while (it2 != (*it).end())
            {
                for (int i = 0; i < edges[*it2].size(); ++i)
                {

                    int cc = count((*it).begin(), (*it).end(), edges[*it2][i]);
                    if (cc == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                }
                it2++;
            }
            if (flag == 0)
            {
                it2 = (*it).begin();
                while (it2 != (*it).end())
                {
                    ans.push_back(*it2 + 1);
                    it2++;
                }
            }

            it++;
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}