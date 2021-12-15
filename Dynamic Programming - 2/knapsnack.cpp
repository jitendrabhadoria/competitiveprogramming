// Knapsnack - Problem
// Send Feedback
// A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
// Note: Space complexity should be O(W).
// Input Format :
// Line 1 : N i.e. number of items
// Line 2 : N Integers i.e. weights of items separated by space
// Line 3 : N Integers i.e. values of items separated by space
// Line 4 : Integer W i.e. maximum weight thief can carry
// Output Format :
// Line 1 : Maximum value V
// Constraints
// 1 <= N <= 10^4
// 1<= wi <= 100
// 1 <= vi <= 100
// 1 <= W <= 1000
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output :
// 13

#include<bits/stdc++.h>
using namespace std;

int knapsnack(int* val,int* wt,int W,int n){
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[W+1];
	}

	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int w=0;w<=W;w++){

			dp[i][w] = dp[i-1][w]; // ith item with max weight w 
			if(wt[i-1] <= w){
				dp[i][w] = max(dp[i][w],val[i-1] + dp[i-1][w-wt[i-1]]);
			}
		}
	}

	int ans = dp[n][W];
	//delete dp array 
	for (int i =0; i <=  n; i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}


int main(){
    
    // write your code here
    int N;
    cin>>N;
    int W;
    int *wt = new int[N];
    int *val = new int[N];
    for(int i=0;i<N;i++){
        cin>>wt[i];
    }
    for(int i=0;i<N;i++){
        cin>>val[i];
    }
    cin >> W;
    
    cout << knapsnack(val,wt,W,N)<<endl;
    
    return 0;
}