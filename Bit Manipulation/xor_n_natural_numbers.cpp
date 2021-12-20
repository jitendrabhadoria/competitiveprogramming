// XOR of Natural Numbers
// Send Feedback
// You are given an integer N and asked to find the Xor of first N natural numbers.
// Input Format:
// The first line of input will contain T(number of test cases), each test case follows as.
// The only line of input contains an integer N.
// Output Format:
// For each test case print the Xor of first N natural number in a new line.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^9
// Sample Input:
// 1 
// 8
// Sample Output:
// 8

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        
        int N;
        cin >> N;
        
        int x = N&3; //computing remainder when divided by (3+1) i.e., 4
        if(x==0){
            cout<<N<<endl;
        } else if(x==1){
            cout<<1<<endl;
        } else if(x==2){
            cout<<N+1<<endl;
        } else {
            cout<<0<<endl;
        }
    }
    return 0;
}