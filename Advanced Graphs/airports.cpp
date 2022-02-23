// AIRPORTS
// Send Feedback
// The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
// Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
// A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, and with minimum cost.
// Input Format:
// The first line of input contains the integer T (the number of test cases), each test case follow as.
// Line1: Three space-separated integers N, M and cost number of locations, number of possible roads and cost of airport respectively
// The following M lines each contain three integers X, Y and C, separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
// Output Format:
// For each test case print the cost in a newline.
// Constraints:
// 1 <= T <= 20
// 1 <= N, M <= 10^5
// 1 <= cost <= 10^9
// 1 <= weight(of each road) <= 10^9
// Sample Input
// 2
// 4 4 100
// 1 2 10
// 4 3 12
// 4 1 41
// 2 3 23
// 5 3 1000
// 1 2 20
// 4 5 40
// 3 2 30
// Sample Output
// 145
// 2090

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class edge
{
public:
    ll ei, ej, cost;
};

ll find_parent(ll num, ll *parents, ll *rank)
{
    if (num == parents[num])
    {
        return num;
    }
    ll p = find_parent(parents[num], parents, rank);
    if (rank[p] <= rank[num])
    {
        parents[p] = num;
        rank[num]++;
    }
    else
    {
        parents[num] = p;
        rank[p]++;
    }
    return p;
}

bool compare(edge e1, edge e2)
{
    return e1.cost < e2.cost;
}

int main()
{
    ll t;
    cin >> t;
    for (ll iter = 1; iter <= t; iter++)
    {
        ll n, m, a;
        cin >> n >> m >> a;
        edge *edges = new edge[m + 1];
        for (ll i = 0; i < m; i++)
        {
            cin >> edges[i].ei >> edges[i].ej >> edges[i].cost;
        }
        sort(edges, edges + m, compare);
        // initially all will be parents of itself
        ll *parents = new ll[n + 1];
        for (ll i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
        // set rank for each vertex
        ll *rank = new ll[n + 1]{};
        // connect those vertices with roads which have less cost
        // than building an airport
        ll cost = 0;
        ll j = 0;
        for (ll i = 0; i < m && j < n - 1; i++)
        {
            edge e = edges[i];
            // build a road if cost of building a road is less than airport
            // as we have already sorted we dont need to do this
            if (e.cost >= a)
            {
                break;
            }
            // find parents of both vertices
            ll p1 = find_parent(e.ei, parents, rank);
            ll p2 = find_parent(e.ej, parents, rank);
            if (p1 != p2)
            {
                cost += e.cost;
                if (rank[p1] <= rank[p2])
                {
                    parents[p1] = p2;
                    rank[p2]++;
                }
                else
                {
                    parents[p2] = p1;
                    rank[p1]++;
                }
                j++;
            }
        }
        ll numair = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (i == parents[i])
            {
                cost += a;
                numair += 1;
            }
        }
        cout << cost << "\n";
    }
    return 0;
}