// OrderSet - Problem
// Send Feedback
// In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations
// INSERT(S,x): if x is not in S, insert x into S
// DELETE(S,x): if x is in S, delete x from S
// and the two type of queries
// K-TH(S) : return the k-th smallest element of S
// COUNT(S,x): return the number of elements of S smaller than x
// Input Format:
// Line 1: Q , the number of operations
// In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.
// Constraints:
// 1 <= Q <= 2*10^5
// -10^9 <= x <= 10^9
// Output Format:
// For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number of elements in S, print the word 'invalid'.
// Sample Input 1:
// 8
// I -1
// I -1
// I 2
// C 0
// K 2
// D -1
// K 1
// K 2
// Sample Output 1:
// 1
// 2
// 2
// invalid

#include <bits/stdc++.h>

using namespace std;

#define MAX 200005
#define ll long long int

pair<int, int> M[MAX], T[MAX];
int BIT[MAX], A[MAX], n;
char C[MAX];
bool b;

int get_count(int idx)
{
    if (idx == 0)
        return 0;
    ll sum = 0;
    while (idx > 0)
    {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void updateBIT(int idx, int val)
{
    while (idx < MAX)
    {

        BIT[idx] += val;
        idx += idx & (-idx);
    }
}
int b_search(int x)
{
    int lo = 0, hi = n - 1, mid, ans = -1;
    while (lo <= hi)
    {
        mid = (lo + hi) >> 1;

        if (M[mid].first == x)
        {
            b = 1;
            return mid;
        }
        else if (M[mid].first > x)
            hi = mid - 1;
        else
        {
            ans = mid;
            lo = mid + 1;
        }
    }
    b = 0;
    return ans;
}
int main()
{
    int i, Q, x, k = 0, lo, hi, mid;
    cin >> Q;
    for (i = 0; i < Q; i++)
    {
        C[i] = getchar();
        while (C[i] < 65 || C[i] >= 91)
            C[i] = getchar();
        cin >> A[i];
        if (C[i] == 'I')
        {
            T[k].first = A[i];
            T[k++].second = 0;
        }
    }
    sort(T, T + k);
    M[0] = T[0];
    n = 1;
    for (i = 1; i < k; i++)
    {
        if (T[i].first != T[i - 1].first)
        {
            M[n++] = T[i];
        }
    }
    for (i = 0; i < Q; i++)
    {
        if (C[i] == 'I')
        {
            x = b_search(A[i]);

            if (M[x].second == 0)
            {
                M[x].second = 1;
                updateBIT(x + 1, 1);
            }
        }
        else if (C[i] == 'D')
        {
            x = b_search(A[i]);
            if (x != -1 && M[x].second == 1 && b)
            {
                updateBIT(x + 1, -1);
                M[x].second = 0;
            }
        }
        else if (C[i] == 'C')
        {
            x = b_search(A[i]);

            if (b)
                cout << get_count(x + 1 - 1) << endl;
            else if (x != -1)
                cout << get_count(x + 1) << endl;
            else
                cout << 0 << endl;
        }
        else if (C[i] == 'K')
        {
            k = A[i];
            x = -1;
            bool mno = 0;
            lo = 1;
            hi = MAX - 1;
            while (lo <= hi)
            {
                mid = (lo + hi) >> 1;
                if (get_count(mid) == k && get_count(mid - 1) != k)
                {
                    mno = 1;
                    x = mid;
                    break;
                }
                else if (get_count(mid) < k)
                {
                    x = mid;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }

            if (!mno)
                cout << "invalid" << endl;
            else
                cout << M[x - 1].first << endl;
        }
    }
    return 0;
}