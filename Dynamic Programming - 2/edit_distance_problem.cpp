// Edit Distance - Problem
// Send Feedback
// Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
// 1. Delete a character

// 2. Replace a character with another one

// 3. Insert a character
// Note - Strings don't contain spaces
// Input Format :
// First line of input will contain T (number of test cases), each test case consists of two lines.
// Line 1 : String s
// Line 2 : String t
// Output Format :
// For each test case print the Edit Distance value in new line.
// Constraints:
// 1 <= T <= 100
// 1<= m,n <= 100
// Sample Input 1 :
// 1
// abc
// dc
// Sample Output 1 :
// 2

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        char a[100];
		char b[100];
        
		cin >> a;
		cin >> b;
        
        int m = strlen(a);
		int n = strlen(b);
        
		int** dp = new int*[m + 1];
        
		for (int i = 0; i <= m; i++) {
			dp[i] = new int[n + 1];
		}
        
		for (int i = 0; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int i = 0; i <=n ;i++) {
			dp[0][i] = i;
		}
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[m-i]==b[n-j]){
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j]=1 + min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]));
                }
                
            }
        }
        
        int ans = dp[m][n];
        
        // delete 2d array
		for (int i =0; i <=  m; i++) {
			delete [] dp[i];
		}
		delete [] dp;
        
        cout<<ans<<endl;
        
    }
    return 0;
}