// Smallest Super-Sequence
// Send Feedback
// Given two strings S and T, find and return the length of their smallest super-sequence.
// A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
// Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
// Input Format:
// First line will contain T(number of test case), each test consists of two lines.
// Line 1 : A string
// Line 2: Another string
// Output Format:
// Length of the smallest super-sequence of given two strings for each test case in new line.
// Constraints:
// 1 <= T <= 50
// 1 <= |str1|, |str2| <= 500
// Sample Input:
// 1
// ab
// ac
// Sample Output:
// 3
// Sample Output Explanation:
// Their smallest super-sequence can be "abc" which has length=3.

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        string s1, s2;
        cin>>s1;
        cin>>s2;
        
        int l1 = s1.length();
        int l2 = s2.length();
        
        int dp[l1+1][l2+1];
        
        for(int i = l2 , j=0 ; i >= 0 ; i--, j++){
            dp[l1][i] = j;
        }
        for(int i = l1 , j=0 ; i >= 0 ; i--, j++){
            dp[i][l2] = j;
        }
        
        for(int i = l1-1; i>=0 ; i--){
            for(int j = l2-1 ;  j>=0 ; j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        cout<<dp[0][0]<<endl;   
    }
    return 0;
}