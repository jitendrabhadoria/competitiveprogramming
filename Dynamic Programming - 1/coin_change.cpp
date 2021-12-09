// Coin Change Problem
// Send Feedback
// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.
// W can be pretty large so output the answer % mod(10^9 + 7)
// Input Format
// First line will contain T (number of test case), each test case is consists of 3 three lines.
// Line 1 : Integer n i.e. total number of denominations
// Line 2 : N integers i.e. n denomination values
// Line 3 : Value V
// Output Format
// For each test case print the number of ways (W) % mod(10^9 +7) in new line.
// Constraints :
// 1 <= T <= 10
// 1 <= N <= 10
// 1 <= V <= 5000

#include <bits/stdc++.h>
using namespace std;

int coin_change(int v, int* d, int n, int output[][5000]) {
    
    int m = pow(10,9)+7;
    
	if (v == 0) {
		return 1;
	}
	if (v < 0) {
		return 0;
	}
	if (n == 0) {
		return 0;
	}
    
    if(output[v][n]>-1){
        return output[v][n];
    }
    
	int first = coin_change(v - d[0], d, n, output);
	int second = coin_change(v, d + 1, n - 1, output);
    
    output[v][n]=((first%m) + (second%m))%m;

	return ((first%m) + (second%m))%m;
}

int main() {
	
    int m = pow(10,9)+7;
    
    int t;
    cin>>t;
    while(t--){
        int n,v;
        cin >> n ;
        int arr[n];
        for(int i = 0;i<n ;i++){
            cin>>arr[i];
        }
        cin>>v; 
        int output[v+1][5000];
        for(int i = 0; i<v+1; i++){
            for(int j = 0; j<n+1; j++){
                output[i][j]=-1;
            }
        }
     
        int ans = coin_change(v, arr, n, output);
        cout<<ans<<endl;
        
    }
       
}







