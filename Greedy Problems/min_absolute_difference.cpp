// Min. Absolute Difference In Array
// Send Feedback
// Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
// We define the absolute difference between two elements ai and aj (where i != j ) as |ai - aj|.
// Input format :
// The first line of input contains an integer that denotes the number of test cases. Let us denote it by the symbol T. 
// Each of the test cases contain two lines. The first line of each test case contains an integer, that denotes the value of N. The following line contains N space separated integers, that denote the array elements.
// Constraints :
// 1 <= T <= 10
// 2 <= N <= 10^5
// 0 <= arr[i] <= 10^8
// Output Format :
// You have to print minimum difference for each test case in new line.
// Sample Input 1:
// 1
// 5
// 2 9 0 4 5
// Sample Output 1:
// 1

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int mod(int a)
{
	if(a<0)
	{
		return -a;
	}
	return a;
}
ll minAbsoluteDiff(ll * arr, int n) {
   	sort(arr, arr+n);
	ll i=0;
	ll j=1;
	ll minimum=INT_MAX;
	while(j<n)
	{
		if(mod(arr[i]-arr[j])<minimum)
		{
			minimum=mod(arr[i]-arr[j]);
		}
		i++;
		j++;
	}
	return minimum;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll * arr = new ll[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        ll ans = minAbsoluteDiff(arr,n);
        cout<<ans<<endl;
    }
    return 0;
}