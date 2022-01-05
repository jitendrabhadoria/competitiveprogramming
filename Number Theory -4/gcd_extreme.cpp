// GCD Extreme
// Send Feedback
// Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
// G=0;
// for(i = 1 ; i < N ; i++)
//    for(j = i+1 ; j <= N ; j++) 
//        G+=gcd(i,j);
// Here gcd() is a function that finds the greatest common divisor of the two input numbers.
// Input Format:
// The first line of input will contain T(number of the test case). Each test case contains an integer N.
// Output Format:
// For each test case print the answer in a new line.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^5
// Sample Input:
// 3
// 10
// 100
// 3
// Sample Output:
// 67
// 13015
// 3

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long int
#define MAX 1000001

ll phi[MAX];
unsigned ll S[MAX], G[MAX];

int main()
{
	unsigned ll i, j, n;
    phi[1] = 1;
    for (i = 2; i < MAX; i += 2)
    {
        phi[i] = i / 2;
    }
    for (i = 3; i < MAX; i += 2)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            for (j = i << 1; j < MAX; j += i)
            {
                if (!phi[j])
                {
                    phi[j] = j;
                }

                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    for (i = 0; i < MAX; i++)
        S[i] = phi[i];
    for (i = 2; i < MAX; i++)
    {
        for (j = 2; j * i < MAX; j++)
        {
            S[i * j] += j * phi[i];
        }
    }
    G[1] = 0;
    for (i = 2; i < MAX; i++)
        G[i] = G[i - 1] + S[i];
    
    ll t;
    cin>>t;
    while (t--)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << G[n] << endl;
    }
    
    return 0;
}