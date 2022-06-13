// Collinear Points
// Send Feedback
// You are given a set of 3 points in a 2-D plane. You have to find out whether they are collinear or not.
// Input Format:
// First line of input will contain T, representing the number of test cases.
// Each test case contains three lines containing two space separated integers x and y, respectively, denoting the points in 2-D plane.
// Constraints:
// 1 <= T <= 10^5
// -10^6 <= x, y <= 10^6
// Ouput Format:
// For each test case output "YES" if they are collinear and "NO" if they are not.
// Sample Input:
// 2
// 1 3
// 1 4
// 1 5
// -1 0
//  0 1
//  1 0
// Sample Output:
// YES
// NO

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{

    // write your code here
    ll t;
    cin >> t;
    while (t--)
    {

        ll x1, x2, x3;
        ll y1, y2, y3;

        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;

        ll ans = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

        if (ans == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}