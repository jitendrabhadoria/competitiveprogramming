#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;

        cin >> m;
        int mat[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                mat[i][j] = INF;
                if (i == j)
                {
                    mat[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (mat[a][b] < c)
            {
                continue;
            }
            else
            {
                mat[a][b] = c;
                mat[b][a] = c;
            }
        }
        int i, j, k;
        for (k = 1; k <= n; k++)
        {
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (mat[i][j] > (mat[i][k] + mat[k][j]) && (mat[k][j] != INF && mat[i][k] != INF))
                        mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int aa;
            int bb;
            cin >> aa >> bb;

            if (aa == bb)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << mat[aa][bb] << endl;
            }
        }
    }
}
