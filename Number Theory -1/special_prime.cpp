// Special Prime
// Send Feedback
// Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
// You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
// Example of special prime 19 = 7 + 11 + 1
// Neighbouring primes are prime number such that there is no other prime number between them.
// Input Format:
// An integer N.
// Output Format:
// Print the number of special primes
// Constraints:
// 1 <= N <= 2*10^5
// Sample Input:
// 27
// Sample Output:
// 2

#include<bits/stdc++.h>
using namespace std;

int makeSieve(int n){
    
    vector<int> primeArr;
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
    }
    
    
    for(int i=0;i<=n;i++){
        if(isPrime[i] == true){
            primeArr.push_back(i);
        }
    }
    
    int count = 0;
    
    int temp2 = 1+primeArr[0]+primeArr[1];
    if(temp2<=n && isPrime[temp2]){
        count++;
    }
    
    for(int i=1; i<primeArr.size()-1;i++){
        
        int temp = 1+primeArr[i]+primeArr[i+1];
        if(temp<=n && isPrime[temp]){
            count++;
        }
        
    }
        
    return count;
}
int main(){
    int n;
    cin >> n;
    int nPrimes = makeSieve(n);
    cout<<nPrimes <<endl;
    return 0;
}
