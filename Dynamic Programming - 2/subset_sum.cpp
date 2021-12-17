// Subset Sum - Problem
// Send Feedback
// Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
// Input Format
// First-line will contain T(number of test cases), each test case consists of three lines. 
// First-line contains a single integer N(length of input array).
// Second-line contains n space-separated integers denoting the elements of array.
// The last line contains a single positive integer k.
// Output Format
// Output Yes if there exists a subset whose sum is k, else output No for each test case in new line.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 500
// 1 <= arr[i] <= 10^4
// 1 <= K <= 500
// Sample Input
// 1
// 3
// 1 2 3
// 4
// Sample Output
// Yes

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int* val, int n, int sum){

    bool** dp = new bool*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new bool[sum+1];
    }

    //dp[i][j] indicates number of possibility of having j weight from ith item
    for(int i=0;i<=sum;i++){
        dp[0][i]=false;
    }

    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){

            dp[i][j] = dp[i-1][j];
            if(j>=val[i-1]){
                
                dp[i][j] = dp[i][j] || dp[i-1][j-val[i-1]];
				//val[i-1] kyuki arr me value starts at arr[0]

            }

        }
    }

    bool ans = dp[n][sum];

    return ans;

}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        int n,k;
        cin>>n;
        
        int* arr = new int[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cin>>k;
        
        int ans = subsetSum(arr,n,k);
        
        if(ans==1){
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
        
        
        
    }
    return 0;
}