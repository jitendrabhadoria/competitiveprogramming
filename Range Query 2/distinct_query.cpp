// Distinct Query Problem
//     Send Feedback
//         Given a sequence of n numbers a1,
//     a2, ..., an and a number of d - queries.A d - query is a pair(i, j)(1 ≤ i ≤ j ≤ n).
// For each d - query(i, j), you have to return the number of distinct elements in the subsequence ai, ai + 1, ..., aj.
// Input Format : Line 1 : n(1 ≤ n ≤ 30000).
// Line 2 : n numbers a1, a2, ..., an(1 ≤ ai ≤ 10 ^ 6).Line 3 : q(1 ≤ q ≤ 200000), the number of d - queries.
// In the next q lines, each line contains 2 numbers i, j representing a d - query(1 ≤ i ≤ j ≤ n).
// Output Format : For each d - query(i, j), print the number of distinct elements in the subsequence ai, ai + 1, ..., aj in a single line.
// Sample Input 1 : 5 1 1 2 1 3 3 1 5 2 4 3 5 Sample Output 1 : 3 2 3

#include <bits/stdc++.h>
using namespace std;

class event
{
public:
    int first, second, index;
};

bool compare(event a, event b)
{

    return a.second < b.second;
}

void update(int index, int value, int n, int *bit)
{
    for (; index <= n; index += (index & (-index)))
    {
        bit[index] += value;
    }
}

int value(int index, int *bit)
{
    int count = 0;
    for (; index > 0; index -= (index & (-index)))
    {
        count += bit[index];
    }
    return count;
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    event *query = new event[q];
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }

    sort(query, query + q, compare);

    int *bit = new int[n + 1];
    int *ans = new int[q];

    int total = 0;
    int k = 0;
    int *last = new int[1000001];
    for (int i = 0; i <= 1000000; i++)
    {
        last[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (last[arr[i]] != -1)
        {
            update(last[arr[i]], -1, n, bit);
        }
        else
        {
            total++;
        }

        update(i, 1, n, bit);
        last[arr[i]] = i;

        while (k < q && query[k].second == i)
        {
            ans[query[k].index] = total - value(query[k].first - 1, bit);
            k++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}