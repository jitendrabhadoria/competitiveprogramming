// Connecting Dots
// Send Feedback
// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
// Assume input to be 0-indexed based.
// Input Format :
// Line 1 : Two integers N and M, the number of rows and columns of the board
// Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
// Output Format :
// Return 1 if there is a cycle else return 0
// Constraints :
// 2 ≤ N, M ≤ 400
// Sample Input :
// 3 4
// AAAA
// ABCA
// AAAA
// Sample Output :
// 1

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, char> pi;

bool vis[51][51];
char graph[51][51];
int dx[] = {1, -1, 0, 0}; // only left, right , up ,down are allowed here
int dy[] = {0, 0, 1, -1};
int m, n;
bool ok = false;

void dfs(int i, int j, int frmi, int frmj, char co)
{
    if (i < 1 || j < 1 || i > m || j > n)
        return;

    if (graph[i][j] != co)
        return;

    if (vis[i][j])
    {
        ok = true;
        return;
    }

    vis[i][j] = true;

    for (int y = 0; y < 4; y++)
    {
        int nxti = i + dx[y];
        int nxtj = j + dy[y];

        if (nxti == frmi && nxtj == frmj)
            continue; // it doesn't go back from where it comes from

        dfs(nxti, nxtj, i, j, co);
    }
}

int main()

{

    memset(vis, false, sizeof(vis));
    int x, y, u, v;
    char c;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)

    {
        for (int j = 1; j <= n; j++)

        {
            cin >> graph[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char z = graph[i][j];
            // cout<<z<<endl;
            if (!vis[i][j])
            {
                dfs(i, j, -1, -1, z);
                if (ok)
                {
                    cout << "1" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "0" << endl;
}