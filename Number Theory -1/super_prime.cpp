// Super Prime
// Send Feedback
// A number is called super-prime if it has exactly two distinct prime divisors
// Example 10 , 6
// You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
// Input Format:
// Contain an integer N
// Output Format:
// Print the number of super prime between [1, N]
// Constraints:
// 1 <= N <= 10^6
// Sample Input 1:
// 10
// Sample Output 1:
// 2
// Sample Input 2:
// 25
// Sample Output 2:
// 10
// Explanation:
// The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24.

#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int * spf = new int[MAXN];

void sieve()
{
    spf[1] = 1;
    
   
    for (int i=2; i<MAXN; i++)
 
        spf[i] = i;
 
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
 
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
    
}
 
int findFactors(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    
    return ret.size();
}

int superPrime(int n){

    vector<int> nprimeArr;
    
    bool isPrime[n+1];
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
    }// O(NloglogN)
    
    for(int i=1;i<=n;i++){
        if(isPrime[i] == false){
            nprimeArr.push_back(i);
        }
    } // O(n)
    
    int ansCount=0;
	
    for(int j=1 ; j < nprimeArr.size() ; j++ ){
        
        int p = findFactors(nprimeArr[j]); //O(logn)
        
        if(p==2){
            ansCount++; 
        }
    }
    
    return ansCount;
    
}


int main(){
    
    // write your code here

    int n;
    cin >> n;
    
    sieve(); // O(nloglogn)
   
    int ans = superPrime(n);
    
    cout<<ans<<endl;
    return 0;
}