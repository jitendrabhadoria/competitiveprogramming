// Miser Man
// Send Feedback
// Jack is a wise and miser man. Always tries to save his money.
// One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
// 1. At every city, he has to change the bus.
// 2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
// You are to help Jack to go from A to B by spending the minimum amount of money.
// Input Format:
// First-line will contain T(number of the test case), each test case follows as.
// First-line will contain two space-separated integers N and M.
// Next, N rows will contain M space-separated integers denoting the elements of the grid.
// Each row lists the fares the M busses to go form the current city to the next city.
// Output Format:
// For each test case print the minimum amount of fare that Jack has to give in a newline.
// Constraints:
// 1 <= T <= 100
// 1 <= N, M <= 100
// 1 <= arr[i][j] <= 10^5
// Sample Input
// 1
// 5 5
// 1 3 1 2 6
// 10 2 5 4 15
// 10 9 6 7 1
// 2 7 1 5 3
// 8 2 6 1 9
// Sample Output
// 10
// Explanation:
// 1 -> 4 -> 1 -> 3 -> 1: 10
// This is marked and shown in the following image: 


#include<bits/stdc++.h>
using namespace std;

int findCost(int ** arr, int N, int M, int row, int col, int ** dp){
    
    if(row==N){
        return arr[N][col];
    }
    if(dp[row][col]>=0){
        return dp[row][col];
    }
    if(row<N){
        int currCost = arr[row][col];
        if(col==1){
            
            int ans1 = currCost + findCost(arr, N, M, row+1, col, dp);
        	int ans2 = currCost + findCost(arr, N, M, row+1, col+1, dp); 
            
            dp[row][col] = min(ans1, ans2);
            return min(ans1, ans2);
            
        } else if(col==M){
            
            int ans1 = currCost + findCost(arr, N, M, row+1, col, dp);
            int ans3 = currCost + findCost(arr, N, M, row+1, col-1, dp);
            
            dp[row][col] = min(ans1, ans3);
            return min(ans1, ans3);
            
        } else {
            
            int ans1 = currCost + findCost(arr, N, M, row+1, col, dp);
        	int ans2 = currCost + findCost(arr, N, M, row+1, col+1, dp);
            int ans3 = currCost + findCost(arr, N, M, row+1, col-1, dp);
            
            dp[row][col] = min(ans1, min(ans2, ans3));
            return min(ans1, min(ans2, ans3)); 
        } 
    }
    
}



int minCostInit(int ** arr, int N, int M){
    int minCost;
    
    int* minCostArr = new int[M+1];
    for(int i = 0 ; i<=M ; i++){
        minCostArr[i]=-1;
    }
    
    int **dp=new int *[N+1];
	for(int i=0; i<=N; i++){
		dp[i]=new int [M+1];
	}
    
    for(int i=0; i<=N; i++){
		for(int j=0; j<=M; j++){
			dp[i][j]=-1;
		}
	}
    
    for(int i=1 ; i<=M ; i++){
        int currCost = arr[1][i];
        
        if(i==1){
            int ans1 = currCost + findCost(arr, N, M, 2, i, dp);
        	int ans2 = currCost + findCost(arr, N, M, 2, i+1, dp);
            
            dp[1][i] =  min(ans1, ans2);
            minCostArr[i] = min(ans1, ans2);
            
        } else if(i==M){
            int ans1 = currCost + findCost(arr, N, M, 2, i, dp);
            int ans3 = currCost + findCost(arr, N, M, 2, i-1, dp);
            dp[1][i] =  min(ans1, ans3);
            minCostArr[i] = min(ans1, ans3);
        } else {
            int ans1 = currCost + findCost(arr, N, M, 2, i, dp);
        	int ans2 = currCost + findCost(arr, N, M, 2, i+1, dp);
            int ans3 = currCost + findCost(arr, N, M, 2, i-1, dp);
            dp[1][i] =  min(ans1, min(ans2, ans3));
            minCostArr[i] = min(ans1, min(ans2, ans3));
        }
        
    }
    
    int minBusCost = minCostArr[1];
    for(int i=2 ; i<=M ; i++){
        if(minCostArr[i] < minBusCost ){
            minBusCost = minCostArr[i];
        }
    }
    
    return minBusCost;
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        int N, M;
        cin >> N >> M ;
        
        int ** arr = new int*[N+1];
        for(int i=0 ; i<=N ;i++){
            arr[i] = new int[M+1];
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>arr[i][j];
            }
        }
        
        for(int i=0; i<=M ; i++){
            arr[0][i]=0;
        }
        for(int i=0; i<=N ; i++){
            arr[i][0]=0;
        }
        
        int ans = minCostInit(arr, N, M);
        
        cout<< ans << endl;
    }
    return 0;
}