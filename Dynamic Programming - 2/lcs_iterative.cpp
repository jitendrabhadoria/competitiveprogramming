// Given two strings S1 and S2 with lengths M and N respectively, find the length of the longest common subsequence.
// A subsequence of a string S whose length is K, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K. For example, subsequences of string "abc" are -- ""(empty string), a, b, c, ab, bc, ac, abc.
// Input Format :
// First line will contain T(number of test case), each test case will consist of two lines.
// Line 1: String S1
// Line 2: String s2
// Output Format :
// Length of the longest common subsequence for each test case in a newline.
// Constraints :
// 1 <= T <= 100
// 1 <= M <= 100
// 1 <= N <= 100

// Time Limit: 1 sec
// Sample Input 1:
// 1
// adebc
// dcadb
// Sample Output 1:
// 3
// Explanation of Sample Input 1:
// "a", "d", "b", "c", "ad", "ab", "db", "dc" and "adb" are present as a subsequence in both the strings in which "adb" has the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
// Sample Input 2:
// 1
// abcd
// acbdef
// Sample Output 2:
// 3
// Explanation of Sample Input 2:
// "a", "b", "c", "d", "ab", "ac", "ad", "bd", "cd", "abd" and "acd" are present as a subsequence in both the strings S1 and S2 in which "abd" and "acd" are of the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.

#include<bits/stdc++.h>
using namespace std;

int lcsI(char* s1, char* s2) {
	int m = strlen(s1);
	int n = strlen(s2);
	int** dp = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <=n ;i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j<= n; j++) {
			if (s1[m - i] == s2[n - j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}	else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int ans =  dp[m][n];
	// delete 2d array
	for (int i =0; i <=  m; i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        char a[100];
		char b[100];
		cin >> a;
		cin >> b;
		cout << lcsI(a, b) << endl;
        
    }
    return 0;
}