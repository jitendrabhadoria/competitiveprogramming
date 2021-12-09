// StairCase Problem
// Send Feedback
// A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
// Time complexity of your code should be O(n).
// Since the answer can be pretty large print the answer % mod(10^9 +7)
// Input Format:
// First line will contain T (number of test case).
// Each test case is consists of a single line containing an integer N.
// Output Format:
// For each test case print the answer in new line
// Constraints :
// 1 <= T < = 10
// 1 <= N <= 10^5

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin >> t;
    int m = pow(10,9)+7;
    while(t--){
        int n;
        cin >> n ; 
        int arr[n+1];
        arr[0]=1;
        arr[1]=1;
        arr[2]=2;
        for(int i = 3; i<n+1 ;i++){
            arr[i]=((((arr[i-1]%m)+(arr[i-2]%m))%m)+(arr[i-3]%m))%m;
        }  
        int ans = arr[n]%m;
        cout << ans <<endl;
    }
    return 0;
}