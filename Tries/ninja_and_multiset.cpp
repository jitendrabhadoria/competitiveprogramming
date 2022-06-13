// Ninja and Multiset
// Send Feedback
// Our problem setter, Ninja, is fascinated by different types of sets. Quite recently, he came across a new term- Multiset. Multiset is a set, where equal elements are allowed. He started experimenting with it and has managed to frame a pretty interesting problem for you to solve.
// You are given a multiset G, initially containing only 0, and a few queries q. Queries are actually of 3 types:
// "+ x" — This query adds an integer x to the given multiset.
// "- x" — This query erases one occurrence of x from the given multiset. Before this query is encountered, it is guaranteed that the multiset will contain integer x at least once.
// "? x" — In this query, you are given integer x and you need to compute the maximum value of bitwise exclusive OR (also known as XOR) of integer x and some integer y from the given multiset.
// Input Format:
// First line on input contain Q (number of queries ).
// Next Q line contain Q queries as defined above.
// Output Format:
// For each query of type '?' print the answer in new line
// Constraints:
// 1 <= Q <= 10^5
// 1 <= x <= 10^9
// Sample Input 1:
// 8
// ? 8
// ? 5
// + 10
// ? 5
// ? 4
// + 4
// - 4
// ? 10
// Sample Output 1:
// 8
// 5
// 15
// 14
// 10
// Explanation:
// Initially the multiset contains only the integer 0. So for the first query, answer is 8 XOR 0 = 8.
// Similarily, the answer for second query is 5 XOR 0 = 5.
// After the third query, 10 is added to the multiset.
// For the fourth query, 5 will be XOR'ed with 0 and 10. Out of these, 5 XOR 10 = 15 is max.
// Similarily, for the fifth query, 4 will be XOR'ed with 0 and 10. Out of these, 4 XOR 10 = 14 is max.
// After the sixth query, 4 is added to the multiset.
// After the seventh query, 4 is erased from the multiset.
// For the last query, 10 is XOR'ed with 0 and 10. Out of these, 10 XOR 0 = 10 is max.

#include <bits/stdc++.h>
using namespace std;

//{
#define cel(n, k) ((n - 1) / k + 1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007
#define null NULL

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//}

struct node
{
    ll cur;
    node *child[2];

    node()
    {
        cur = 0;
        fr(2)
            child[i] = null;
    }
};

node *root = new node();

ll resetbit(ll a, ll i)
{
    return a & ~(1LL << i);
}

ll setbit(ll a, ll i)
{
    return a | (1LL << i);
}

bool check(ll mask, ll i)
{
    return mask & (1LL << i);
}

void insert(ll num, ll i, node *root)
{
    if (i == -1)
        return;
    ll id = check(num, i);
    // cout<<"inserting "<<id<<endl;
    if (root->child[id] == null)
    {
        node *t = new node();
        root->child[id] = t;
    }

    root->child[id]->cur++;
    insert(num, i - 1, root->child[id]);
}

void delet(ll num, ll i, node *root)
{
    if (i == -1)
        return;

    ll id = check(num, i);

    root->child[id]->cur--;
    delet(num, i - 1, root->child[id]);
}

ll query(ll num, ll i, node *root)
{
    if (i == -1)
        return num;

    ll id = 1 - check(num, i);

    if (root->child[id] == null || root->child[id]->cur == 0)
    {
        id = 1 - id;
        num = resetbit(num, i);
    }
    else
        num = setbit(num, i);

    query(num, i - 1, root->child[id]);
}

void init(ll num, ll i, node *root)
{
    if (i == -1)
        return;
    ll id = check(num, i);
    // cout<<"inserting "<<id<<endl;
    if (root->child[id] == null)
    {
        node *t = new node();
        root->child[id] = t;
    }

    root->child[id]->cur = 300005;
    insert(num, i - 1, root->child[id]);
}

int main()
{
    ll n, q, d, num;
    char choice;
    cin >> n;

    init(0, 63, root);

    fr(n)
    {
        cin >> choice >> num;

        if (choice == '+')
            insert(num, 63, root);
        else if (choice == '-')
            delet(num, 63, root);
        else
            cout << query(num, 63, root) << endl;
    }
    return 0;
}
