// Nikunj and Donuts
// Send Feedback
// Nikunj loves donuts, but he also likes to stay fit. He eats n donuts in one sitting, and each donut has a calorie count, ci. After eating a donut with k calories, he must walk at least 2^j * k(where j is the number donuts he has already eaten) miles to maintain his weight.
// Given the individual calorie counts for each of the n donuts, find and print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight. Note that he can eat the donuts in any order.
// Input Format:
// First line of input will contain T(number of test cases), each test case follows as.
// The first line contains an integer, n, denoting the number of donuts. 
// The second line contains n space-separated integers describing the respective calorie counts of each donut, i.e ci.
// Constraints
//  1 <= T <= 10^5
//  1 ≤ n ≤ 40
//  1 ≤ ci ≤ 1000
// Output Format:
// Print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight for each test case in new line
// Sample Input 1
// 1
// 3
// 1 3 2
// Sample Output 1
// 11
// Explanation:
// The minimum miles that Nikunj has to walk are 11 miles. He will first eat donut with calorie count 3, then the one with calorie count 2 and then the donut with calorie count as 1. The miles travelled are calculated as: 2^0*3 + 2^1*2 + 2^2*1.

#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

ll minimum_miles(ll *arr, ll n)
{
	ll total_miles=0;
	for(ll i=0; i<n; i++)
	{
		total_miles+=pow(2, i)*arr[n-1-i];
	}
	return total_miles;
}
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        ll n;
		cin>>n;
		ll *arr=new ll [n];
		for(ll i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		sort(arr, arr+n);
		cout<<minimum_miles(arr, n)<<endl;
    }
	
}