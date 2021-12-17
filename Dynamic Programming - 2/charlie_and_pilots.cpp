// Charlie and Pilots
// Send Feedback
// Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
// Input Format:
// First line will contain T(number of test case), each test case as follow.
// The first line of each test case contains integer N, N is even, the number of pilots working for the Charlie's company.
// The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, a salary as a captain (X) and a salary as an assistant (Y).
// Constraints
// 1 <= T <= 20
// 2 ≤ N ≤ 1000
// 1 ≤ Y < X ≤ 100000
// Output Format:
// For each test case print the minimal amount of money Charlie needs to give for the pilots' salaries. in newline. 
// Sample Input
// 1
// 4 
// 5000 3000 
// 6000 2000 
// 8000 1000 
// 9000 6000 
// Sample Output
// 19000 

#include<bits/stdc++.h>
using namespace std;

int optimalArr(int * aSal, int * cSal, int n, int x, int ** dp){
    if(n==0){
        return 0;
    }
    
    if(dp[n][x]>=0){
        return dp[n][x];
    }
    
    if(x==0){
        
        dp[n][x]= aSal[0] + optimalArr(aSal+1, cSal+1, n-1, x+1, dp);
        return aSal[0] + optimalArr(aSal+1, cSal+1, n-1, x+1, dp);
    }
    
    if(x==n){
        dp[n][x]= cSal[0] + optimalArr(aSal+1, cSal+1, n-1, x-1, dp);
        return cSal[0] + optimalArr(aSal+1, cSal+1, n-1, x-1, dp);
    }
    
    
    
    int option1 = aSal[0] + optimalArr(aSal+1, cSal+1, n-1, x+1, dp);
    int option2 = cSal[0] + optimalArr(aSal+1, cSal+1, n-1, x-1, dp);
    
    int ans = min(option1, option2);
    
    dp[n][x]=ans;
    
    return ans;

}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int* aSal = new int[n+1];
        int* cSal = new int[n+1];
        
        int** dp = new int *[n+1];
        for(int i=0 ; i<=n ; i++){
            dp[i] =  new int[n+1];
            for(int j=0 ; j<=n ; j++){
                dp[i][j]=-1;
            }
        }
        
        for(int i=1; i<=n ; i++){
            cin >> cSal[i] >> aSal[i];
        }
        
        int x=0;
        int ans = optimalArr(aSal+1, cSal+1, n, x, dp);

        cout<<ans<<endl;
    
    }
    return 0;
}