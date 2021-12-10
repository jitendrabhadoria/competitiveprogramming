// Roy and Coin Boxes
// Send Feedback
// Roy has N coin boxes numbered from 1 to N.
// Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
// He does this for M number of days.
// After M days, Roy has a query: How many coin boxes have at least X coins.
// He has Q such queries.
// Input Format:
// First line will contain T (number of test case), format of each test case follows
// First line contains two space separated integers N and M (N - number of coin boxes, M - number of days). Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
// Each of next Q lines contain a single integer X.
// Output Format:
// For each query of each test case output the result in a new line.
// Constraints:
// 1 <= T <= 10
// 1 ≤ N ≤ 10000
// 1 ≤ M ≤ min(10000, N)
// 1 ≤ L ≤ R ≤ N
// 1 ≤ Q ≤ 10000
// 1 ≤ X ≤ N
// Sample Input
// 1
// 7
// 4
// 1 3
// 2 5
// 1 2
// 5 6
// 4
// 1
// 7
// 4
// 2
// Sample Output
// 6
// 0
// 0
// 4


#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int N,M, Q, X;
        cin>>N>>M;
        
        int S[N+1];   // to store the count of number of times i is coming as L
        int E[N+1];   // to store the count of number of times i is coming as R
        int B[N+1];   // to store the content of box after all the M updates
        int exC[N+1]; // to store the exact count of number of box having i coins
        int atC[N+1]; // to store the atleast count of number of box having i coins i.e., sum(>=i till N)
        
        for(int i=0;i<N+1;i++){
            S[i]=0;
            E[i]=0;
            exC[i]=0;
            atC[i]=0;
            B[i]=0;
        }
        
        while(M--){
            
            int L,R;
            cin>>L>>R;
            S[L]++;
            E[R]++;
            
        }
        
        
        B[1]=S[1]; 					 //number of times L was 1 that many coins box 1 will have
        for(int i=2;i<N+1;i++){
            B[i]=S[i]-E[i-1]+B[i-1]; //number of coins in each boxes
        }
        
        for(int i=1;i<N+1;i++){
            int iVal = B[i];
            exC[iVal]++; 			 // stores the count of how many boxes have B[i] number of coins
        }
        
        atC[N]=exC[N];
        for(int i=N-1; i>=1 ;i--){
            atC[i]=atC[i+1]+exC[i];
        }
        
        cin>>Q;
        while(Q--){
            cin>>X;
            cout<<atC[X]<<endl;
        }
    }
    return 0;
}