// Sum of LCM
// Send Feedback
// Given n, calculate and print the sum :
// LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
// where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
// Input Format :
// First line of input will contain T(number of test case), each test case follows as.
// An Integer N
// Output Format :
// Required sum for each test case in newline.
// Constraints :
// 1 <= T <= 10^4
// 1 <= n <= 10^5
// Sample Input 1 :
// 1
// 5
// Sample Output 1 :
// 55
// Sample Input 2 :
// 1
// 2
// Sample Output 2 :
// 4

#include<bits/stdc++.h>
using namespace std;

#define maxn 1000000
#define ll long long int

ll* phi = new ll[maxn+1];
ll* ans = new ll[maxn+1];

void eulerPhi(){
 	
    for(ll i=1;i<=maxn;i++){
        phi[i] = i;
    }
    
    for(ll i=2;i<=maxn;i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(ll j=2*i;j<=maxn;j+=i){
                phi[j] = (phi[j]*(i-1))/i;
            }
        }
    }
    
    for (int i = 1; i <= maxn; i++) {
        for (int j = i; j <= maxn; j += i) {
            ans[j] += (i * phi[i]);
        }
    }
}

ll lcmSum(int m)
{
 
    ll answer = ans[m];
    answer = (answer + 1) * m;
    answer = answer / 2;
    return answer;
}

int main(){
    
    int t;
    cin >> t;
    
    eulerPhi();
    
    while(t--){
        
        ll n;
        cin >> n;
        cout<<lcmSum(n)<<endl;
        
    }
    return 0;
}
