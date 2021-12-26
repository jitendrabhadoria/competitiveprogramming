// Find Prime Numbers From 1 to N
// Send Feedback
// Given a number N, find number of primes in the range [1,N].
// Input Format:
// The only line of input consists of a number N
// Output Format:
// Print the number of primes in the range [1,N].
// Constraints:
// 1 ≤ N ≤ 10^6
// Sample Input :
// 3 
// Sample Output -
// 2

#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){

    bool flag = true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            flag = false;
            break;
        }
    }

    return flag;
}

int main(){
    int n;
    cin>>n;

    int count = 0 ;
    for(int i=2;i<=n;i++){
        if(checkPrime(i)){
            count++;
        }
    }
    if(n==1){
        count = 0;
    }

    cout<<count<<endl;
    return 0;
}