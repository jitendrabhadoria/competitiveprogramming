// Calculate Grundy Number
// Send Feedback
// Calculate the Grundy Number for the given 'n' in the game.
// The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
// Input Format:
// First line of input contains an integer T, representing the number of test cases.
// Next T lines contain an integer n.
// Constraints:
// 1 <= T <= 10^4
// 1 <= N <= 10^6
// Output Format:
// Print the Grundy Number(n) for each test case in a new line.
// Sample Input 1:
// 1
// 10
// Sample Output 1:
// 0

#include <bits/stdc++.h>
using namespace std;

int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

int calculateGrundy(int n, int Grundy[])
{
    if (n == 0)
        return (0);

    if (Grundy[n] != -1)
        return (Grundy[n]);

    unordered_set<int> Set; // A Hash Table

    Set.insert(calculateGrundy(n / 2, Grundy));
    Set.insert(calculateGrundy(n / 3, Grundy));
    Set.insert(calculateGrundy(n / 6, Grundy));

    // Store the result
    Grundy[n] = calculateMex(Set);
    return (Grundy[n]);
}

int main()
{
    int t;
    cin >> t;
    int grundy[1000000];
    for (int i = 0; i <= 1000000; i++)
    {
        grundy[i] = -1;
    }
    while (t--)
    {
        int n;
        cin >> n;

        cout << calculateGrundy(n, grundy) << endl;
    }
    return 0;
}