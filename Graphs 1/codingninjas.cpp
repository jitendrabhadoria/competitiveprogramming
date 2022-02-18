// Coding Ninjas
// Send Feedback
// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
// There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
// Input Format :
// First line will contain T(number of test case), each test case follows as.
// Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
// Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
// Assume input to be 0-indexed based
// Output Format :
// Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0, for each test case in a new line
// Constraints :
// 1 <= T <= 10
// 1 <= N <= 1000
// 1 <= M <= 1000
// Sample Input :
// 1
// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX
// Sample Output :
// 1

#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

int validPoint(int x, int y, int n, int m)
{

    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool dfs(char **board, vector<vector<bool>> &used, string &word, int x, int y, int wordIndex, int n, int m)
{

    if (wordIndex == 11)
    {
        return true;
    }

    used[x][y] = true;
    bool found = false;

    int dxdy[8][2] = {{-1, -1},
                      {-1, 0},
                      {-1, -1},
                      {0, -1},
                      {0, 1},
                      {1, -1},
                      {1, 0},
                      {1, 1}};

    for (int i = 0; i < 8; ++i)
    {

        int newX = x + dxdy[i][0];
        int newY = y + dxdy[i][1];

        if (validPoint(newX, newY, n, m) && board[newX][newY] == word[wordIndex] && !used[newX][newY])
        {

            found = found | dfs(board, used, word, newX, newY, wordIndex + 1, n, m);
        }
    }

    used[x][y] = false;

    return found;
}

bool hasPath(char **board, int n, int m)
{

    bool foundPath = false;
    string word = "CODINGNINJA";
    vector<vector<bool>> used(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (board[i][j] == word[0])
            {
                foundPath = dfs(board, used, word, i, j, 1, n, m);
                if (foundPath)
                    break;
            }
        }

        if (foundPath)
            break;
    }

    return foundPath;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        char **arr = new char *[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = new char[M];
            for (int j = 0; j < M; j++)
            {
                arr[i][j] = ' ';
            }
        }

        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < M; j++)

            {
                cin >> arr[i][j];
            }
        }

        bool ans = hasPath(arr, N, M);

        if (ans)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}