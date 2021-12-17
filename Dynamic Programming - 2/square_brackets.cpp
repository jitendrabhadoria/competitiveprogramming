// Square Brackets
// Send Feedback
// You are given:
// a positive integer n,
// an integer k, 1<=k<=n,
// an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
// What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
// Illustration
// Several proper bracket expressions:
// [[]][[[]][]] 
// [[[][]]][][[]]
// An improper bracket expression:
// [[[][]]][]][[]]
// There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
// Task
// Write a program which for each data set from a sequence of several data sets:
// 1. reads integers n, k and an increasing sequence of k integers from input,
// 2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
// 3. writes the result to output.
// Note: since result can be pretty large output the answer % mod (10^9 + 7).
// Input Format:
// The first line of the input file contains one integer T(number of test cases), each test case follows as.
// The first line contains two integers n and k separated by single space.
// The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
// Output Format:
//  For each test case print the number of balanced square bracket sequence % mod (10^9 + 7), that can be formed using the above rules in a new line.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 100
// 1 <= K <= N
// Sample Input
// 5 
// 1 1 
// 1 
// 1 1 
// 2 
// 2 1 
// 1 
// 3 1 
// 2 
// 4 2 
// 5 7 
// Sample Output
// 1 
// 0 
// 2 
// 3 
// 2 


#include<bits/stdc++.h>
using namespace std;

#define m 1000000007

long long number_of_proper_bracket_expressions(bool *boolean_arr, long long n, long long O, long long C, long long **dp)
{
	if(boolean_arr[0])
	{
		return 0;
	}
	
	if(C > n || O > n)
	{
		return 0;
	}
	if( C == n && O == n )
	{
		return 1;
	}
    if(dp[O][C]>-1)
	{
		return dp[O][C];
	}
	long long ans;
	if( C == O || (boolean_arr[C+O+1]==true)){
        
		ans = number_of_proper_bracket_expressions(boolean_arr, n, O+1, C, dp);
        
	}
	else if( O == n )
	{
		ans = number_of_proper_bracket_expressions(boolean_arr, n, O, C+1, dp);
	}
	else
	{
		long long option1 = number_of_proper_bracket_expressions(boolean_arr, n, O+1, C, dp);
		long long option2 = number_of_proper_bracket_expressions(boolean_arr, n, O, C+1, dp);
		ans = ((option1%m)+(option2%m))%m;
	}
	dp[O][C] = ans;
	return ans;
}



int main(){
    
    // write your code here
    long long t;
    cin>>t;
    while(t--){
        
        long long n,k;
        cin >> n >> k;
        
        long long * arr = new long long[k];
        
        bool *boolean_arr = new bool [(2*n)+1];
		for(long long i=0; i<=2*n; i++){
			boolean_arr[i]=false;
		}
        
        for(long long i=0 ; i<k ; i++){
            cin >> arr[i];
            boolean_arr[arr[i]]=true;
        }
        
        long long ** dp = new long long *[n+1];
		for(long long i=0; i<=n; i++)
		{
			dp[i]=new long long [n+1];
			for(long long j=0; j<=n; j++)
			{
				dp[i][j]=-1;
			}
		}
        
        cout<<number_of_proper_bracket_expressions(boolean_arr, n, 0, 0, dp)<<endl; 
        
        // delete 2d array
		for (long long i =0; i <=  n; i++) {
			delete [] dp[i];
		}
		delete [] dp;
        
        delete [] boolean_arr;
        
        delete [] arr;
        
    
    }
    return 0;
}