// Ninja Factor
// Send Feedback
// Ninja is given an array of integers of size N and Q queries, each query will be consists of two integers l, r and ninja is supposed to calculate the number of i such that the ninja factor of array[i] is a prime number where l <= i <= r
// Ninja factor of a Number A is defined as the number of integers B such that
// 1 <= B <= A
// LCM (A, B) = A * B
// Input Format:
//  Line1: contain two space-separated integers N and Q denoting the number of elements in array and number of queries.
// Line2: contain N space-separated integers denoting the elements of the array
// Next, Q lines contain two space-separated integers l, r describing the query.
// Output Format:
// For each query print the answer in a newline.
// Constraints:
// 1 <= N , Q <= 10^5
// 1 <= arr[i] <= 10^9
// 1 <= l, r <= N
// Sample Input:
// 10 6
// 8 8 6 8 6 7 10 7 9 9 
// 2 10
// 7 7
// 5 7
// 7 8
// 6 10
// 3 4
// Sample Output:
// 2
// 0
// 1
// 0
// 0
// 1

#include<bits/stdc++.h>
using namespace std;

#define maxn 1000000
#define ll long long int

ll* phi = new ll[maxn+1];
bool * isPrime = new bool[maxn+1];

void sieve(){

    int n = maxn+1;
    
    for(int i=0;i<=n;i++){
        isPrime[i] = true;
    }
    
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i=2;i*i<=n;i++){
        if(isPrime[i] == true){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    
}

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
    
    // write your code here
    int n, q, l, r, count;
    
    cin >> n >> q;
    
    int * arr = new int[n+1];
    int * ansArr = new int[n+1];
        
    sieve();
    eulerPhi();
  
    
    for(int i=1;i<=n;i++){
        
        cin >> arr[i];
        
    }
    
    count = 0;
    for(int i=1;i<=n;i++){
        
        if(isPrime[phi[arr[i]]]){
            count++;
        }
        ansArr[i]=count;
    }
    
    
    while(q--){
        
        cin >> l >> r;
                       
        int ans = ansArr[r]-ansArr[l-1];
    
        cout<<ans<<endl;
        
    }
    return 0;
}

