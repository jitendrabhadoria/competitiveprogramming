// Boredom
// Send Feedback
// Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
// He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
// Input Format :
// First line will contain T (number of test case), each test case is consists of two line.
// Line 1: Integer N 
// Line 2: A list of N integers
// Output Format :
// For each test case print maximum points, Gary can receive from the Game setup in a newline.
// Constraints :
//  1 <= T <= 50
//  1 <= N <= 10^5
//  1 <= A[i] <= 1000
// Sample Input :
// 1
// 2
// 1 2
// Sample Output :
// 2

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
    	long long arr[n];
    	long long freq[1001];
    	long long dp[1001];
    	for(long long i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(long long i=0;i<1001;i++){
        	freq[i]=0;
    	}
    	for(long long i=0;i<n;i++){
	        freq[arr[i]]++;
	    }
        
	    dp[0]=0;
	    dp[1]=max((1*freq[1]),(dp[0])); 
	    for(long long i = 2 ; i<1001 ;i++){
	        dp[i]=max((dp[i-2]+i*freq[i]),dp[i-1]);
	    }
        
    
	    cout<<dp[1000]<<endl;
	}
   
    return 0;
}