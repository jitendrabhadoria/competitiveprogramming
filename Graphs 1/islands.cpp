// Islands
// Send Feedback
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?
// Input Format:
// The first line of input will contain T(number of test cases), each test case follows as.
// Line 1: Two Integers N and M (separated by space)
// Next 'M' lines, each have two space-separated integers, 'u' and 'v', denoting that there exists an edge between Vertex 'u' and Vertex 'v'.
// Output Format:
// Print number of Islands for each test case in new line.
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 1000
// 1 <= M <= min((N*(N-1))/2, 1000)
// 0 <= u[i] ,v[i] < N
// Output Return Format :
// The count the number of connected groups of islands
// Sample Input :
// 1
// 2 1
// 0 1
// Sample Output :
// 1

#include <bits/stdc++.h>
using namespace std;
void visited_filler(int **arr, int n, int starting_vertex, bool *visited)
{
    queue<int> q;
    q.push(starting_vertex);
    visited[starting_vertex] = true;
    while (!q.empty())
    {
        int current_element = q.front();
        for (int i = 0; i < n; i++)
        {
            if (i == current_element)
            {
                continue;
            }
            if (visited[i])
            {
                continue;
            }
            if (arr[current_element][i] == 1)
            {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int N, M;
        cin >> N >> M;

        int **arr = new int *[N + 1];
        for (int i = 0; i < N + 1; i++)
        {
            arr[i] = new int[N + 1];
            for (int j = 0; j < N + 1; j++)
            {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            arr[u][v] = 1;
            arr[v][u] = 1;
        }

        bool *visited = new bool[N + 1];
        for (int i = 0; i < N + 1; i++)
        {
            visited[i] = false;
        }

        int count = 0;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                visited_filler(arr, N + 1, i, visited);
                count += 1;
            }
        }
        cout << count << endl;
    }

    return 0;
}