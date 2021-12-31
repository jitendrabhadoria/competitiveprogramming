// Segmented Sieve Problem
// Send Feedback
// In this problem you have to print all primes from given interval.
// Input Format:
// First line of input will contain T(number of test cases), each test case follows as.

// On each line are written two integers L and U separated by a blank. L - lower bound of 
// interval, U - upper bound of interval.
// Output Format:
// For each test case output must contain all primes from interval [L; U] in increasing order.
// Constraints:
// 1  <= T <= 100
// 1 <= L <= U <= 10^9
// 0 <= U - L <= 10^5
// Sample Input:
// 2
// 2 10
// 3 7
// Sample Output:
// 2 3 5 7
// 3 5 7 
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
#define ll long long int

vector<ll>* sieve(){

    bool isPrime[MAX];

    for(ll i=0;i<MAX;i++){
        isPrime[i] = true;
    }
       
    for(ll i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i){
                isPrime[j] = false;
            }
        }
    }

    vector<ll>* primes = new vector<ll>();
    
    primes->push_back(2);
    
    for(ll i=3;i<MAX;i+=2){
        if(isPrime[i]){
            primes->push_back(i);
        }
    }

    return primes;

}

void printPrimes(long long l, long long r, vector<ll>* & primes){
    
    bool isPrime[r-l+1];
    
    for(ll i=0;i<=r-l;i++){
        isPrime[i] = true;
    }
    
    for(ll i = 0 ; primes->at(i)*(long long)primes->at(i) <= r ; i++){

        ll currPrime = primes->at(i);
        // Just smaller or equal value to l
        
        long long base = (l/(currPrime))*(currPrime);
        if(base < l){
        
            base = base + currPrime;
        
        }
        // Mark all mutliples within L To R as false
        for(long long j = base;j<=r ;j+= currPrime){
        
            isPrime[j-l] = false;
        
        }
        // There may be a case where base is itself a prime number .
        if(base == currPrime){
        
            isPrime[base-l] = true;
        
        }
    }
    for(ll i=0;i<=r-l;i++){
        if(isPrime[i] == true){
            if(i+l != 1)
            	cout << i + l << " ";
        }
    }
    
}

int main(){

    vector<ll>* primes = sieve();

    ll t;
    cin >> t;

    while(t--){
       
        long long l,r;
        cin>>l>>r;
        
        printPrimes(l,r,primes);
        cout<<endl;
    
    }
    
    return 0;

}
