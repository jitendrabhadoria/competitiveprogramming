// Minimum Count
// Send Feedback
// Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
// Note : x^y represents x raise to the power y.
// Input Format :
// First line will contain T(number of test case), each test case consists of a single line containing an integer N.
// Output Format :
// For each test case print the required minimum count in a newline.
// Constraints :
//  1 <= T <= 1000
//  1 <= N <= 1000
// Sample Input 1 :
// 1
// 12
// Sample Output 1 :
// 3
// Sample Output 1 Explanation :
// 12 can be represented as :
// 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
// 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
// 1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
// 2^2 + 2^2 + 2^2
// As we can see, the output should be 3.
// Sample Input 2 :
// 1
// 9
// Sample Output 2 :
// 1

#include<bits/stdc++.h>
using namespace std;

bool is_perfect_square(int n)
{
	for(int i=1; i<=32; i++)
	{
		if(n==i*i)
		{
			return true;
		}
	}
	return false;
}

int countDig(int n, int* dp){
    if(is_perfect_square(n)==true){
        return 1;
    }
    if(n<=3){
        return n; // all adding powers of 1
    }
    int count=n;
	if(dp[n]>0)
	{
		return dp[n];
	}
	for(int i=1; i<=n; i++)
	{
		int temp=i*i;
		if(temp>n)
		{
			break;
		}
		else
		{
			count=min(count, 1+countDig(n-temp, dp)); //count if i not taken , 1+... if i taken 
		}
	}
	dp[n]=count;
	return count;
    //dp[i] represents the min cost for that number]
 
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int dp[1001];
        for(int i=0;i<=n;i++){
            dp[i]=0;
        }
        int ans = countDig(n,dp);
        cout<<ans<<endl;
    }
    return 0;
}