// Surveyor
// Send Feedback
// A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
// The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
// Input Format:
// First line of input contains a string s
// Second line of input contains an array (space separated), with the length same as string s.
// Constraints:
// Direction string will have between 4 and 50 characters inclusive.
// Length will have the same number of elements as the number of characters in direction.
// Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
// Each element of length will be between 1 and 1000 inclusive.
// The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
// Output Format:
// For each input, print the area calculated.
// Sample Test Case
// NWWSE
// 10 3 7 10 10
// Sample Ouput:
// 100

#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long int

ld area(ll x[], ll y[], ll n)
{
    ld f_ans = 0.0;
    for (ll i = 1; i < n - 1; i++)
    {
        ld x1 = x[i] - x[0];
        ld y1 = y[i] - y[0];
        ld x2 = x[i + 1] - x[0];
        ld y2 = y[i + 1] - y[0];

        ld ans = x1 * y2 - y1 * x2;
        f_ans += ans;
    }
    return abs(f_ans / 2);
}

int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll x[n], y[n];
    x[0] = 100000;
    y[0] = 100000;
    for (ll i = 1; i < n; i++)
    {
        if (s[i - 1] == 'N')
        {
            x[i] = x[i - 1];
            y[i] = y[i - 1] + arr[i - 1];
        }
        else if (s[i - 1] == 'S')
        {
            x[i] = x[i - 1];
            y[i] = y[i - 1] - arr[i - 1];
        }
        else if (s[i - 1] == 'E')
        {
            x[i] = x[i - 1] + arr[i - 1];
            y[i] = y[i - 1];
        }
        else if (s[i - 1] == 'W')
        {
            x[i] = x[i - 1] - arr[i - 1];
            y[i] = y[i - 1];
        }
    }
    cout << (ll)area(x, y, n) << "\n";
    return 0;
}