// Product of first N natural numbers
// Send Feedback
// You are given an integer N and you have to calculate the product of the first N natural numbers.
// As the answer will be large, print the answer modulo 10^9+7.
// Input Format :
// The first line of input contains an integer, that denotes the value of the number of test cases. Let us denote it with the symbol T.
// Each test case consists of a single integer N in a separate line.
// Output Format :
// For each test case, print the product of the first N natural numbers modulus 10^9 + 7 in a separate line.
// Constraints :
// 1 <= T <= 100
// 1 <= N <= 10^5
// Time Limit: 1 second
// Sample Input 1:
// 2
// 3
// 4
// Sample output 1:
// 6
// 24

#include<bits/stdc++.h>
using namespace std;

long long productN(int n){
	if(n == 1){
        return 1;
    }
    
    long long c = pow(10,9) + 7;
    long long smallAns = productN(n-1);
    long long finalAns = ((n%c)*(smallAns%c))%c;
    
    return finalAns;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long ans = productN(n);
        cout << ans << endl;
    }
    return 0;
}