// Totient Function
// Send Feedback
// You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// An integer N in new line.
// Output Format:
// For each test case print the answer in new line
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 10^9
// Sample Input:
// 2
// 20
// 21
// Sample Output:
// 8 
// 12

#include<bits/stdc++.h>
using namespace std;

#define maxn 1000000
#define ll long long int

ll* phi = new ll[maxn+1];

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
}

ll primeFactors(ll n){
    
    ll ans = 1;
    ll count = 0;
    while (n % 2 == 0)
    {
        count++;
        n = n/2;
    }
    ans = ans * phi[(1<<count)];

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n = n/i;
        }
        
        ans = ans * phi[int(pow(i,count))];
        if(n==1){
            break;
        }
    }
    
    if (n > 2)
        ans *= (n-1);
    
    return ans;
}

int main(){
    
    int t;
    cin >> t;
    
    eulerPhi();
    
    while(t--){
        
        ll n;
        cin >> n;
        if(n>=1 && n<=1000000000){
            if(n<=1000000)
        		cout<<phi[n]<<endl;
            else if(n>1000000)
            	cout<<primeFactors(n)<<endl;
        }
        
    }
    return 0;
}
