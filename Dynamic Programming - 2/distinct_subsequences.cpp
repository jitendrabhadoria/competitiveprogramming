// Distinct Subsequences
// Send Feedback
// Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
// For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
// Input Format:
// First line of input contains an integer T which is equal to the number of test cases.
// Each of next T lines contains a string s.
// Output Format:
// Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%(10^9 + 7) where ans is the number of distinct subsequences. 
// Constraints:
// T ≤ 100
// 1 <= length(S) ≤ 10^5
// All input strings shall contain only uppercase letters.

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define m 1000000007


long long countSub(string str)
{
	ll *last=new ll [26];
	for(ll i=0; i<26; i++)
	{
		last[i]=-1;
	}

	long long n = str.length();

	long long dp[n + 1];

	dp[0] = 1;

	for (long long i = 1; i <=n; i++) {
		
		dp[i] = (2 * dp[i - 1])%m;

		if (last[str[i - 1]-65] != -1)
			dp[i] = (dp[i] - dp[last[str[i-1]-65]]+m)%m;

		last[str[i-1]-65] = i-1;
	}

    
    long long ans = dp[n]%m;
	return ans;
}

int main()
{
    long long t;
    cin >>  t;
    
    while(t--){
        
        string s;
        cin>>s;
        
        cout<<countSub(s)<<endl;
        
    }
	return 0;
}
