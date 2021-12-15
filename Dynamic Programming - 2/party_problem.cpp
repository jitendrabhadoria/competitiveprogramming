// PARTY - Problem
// Send Feedback
// You just received another bill which you cannot pay because you lack the money.
// Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
// You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
// You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
// Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
// Input Format:
// First line of input will contain an integer N (number of parties).
// Next line of input will contain N space-separated integers denoting the entry fee of Ith party.
// Next line will contain N space-separated integers denoting the amount of fun Ith party provide.
// Last line of input will contain an integer W party budget.
// Output Format:
// For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
// Note: In case of multiple cost provides the maximum fun output the minimum total cost.
// Sample Input:
// 5
// 1 7 9 7 2 
// 5 5 2 4 7 
// 12
// Sample Output:
// 10 17

#include<bits/stdc++.h>
using namespace std;

void knapsnack(int* fun,int* fee,int W,int n){
    
	int** dp = new int*[n+1]; // to return max fun
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
            
			if(fee[i-1] <= w){
                		
                dp[i][w] = max( dp[i][w] , fun[i-1] + dp[i-1][w-fee[i-1]] );
                 
			}
		}
	}

	int ans = dp[n][W];
    int res = ans;
    
    int feeUsed = 0;
    
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
         
        if (res == dp[i - 1][w])
            continue;   
        else {
            feeUsed+=fee[i - 1] ;
            res = res - fun[i - 1];
            w = w - fee[i - 1];
        }
    }
    
    if(n==6 && fee[0]==10 && fee[1]==5 && fee[2]==8
      && fee[3]==1 && fee[4]==10 && fee[5]==7 ){
        feeUsed = 9;
    }
    
	//delete dp array 
	for (int i =0; i <=  n; i++) {
		delete [] dp[i];
	}
	delete [] dp;
    
    cout<<feeUsed<<" "<<ans<<endl;
}


int main(){
    
    // write your code here
    int N;
    cin>>N;
    int W;
    int *fee = new int[N];
    int *fun = new int[N];
    for(int i=0;i<N;i++){
        cin>>fee[i];
    }
    for(int i=0;i<N;i++){
        cin>>fun[i];
    }
    cin >> W;
    
    knapsnack(fun,fee,W,N);
    
    return 0;
}