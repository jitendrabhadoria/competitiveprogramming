// GCD
// Send Feedback
// Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
// Input format :
// First line of Input will contain T(number of test cases), each test case follows as.
// x and y (separated by space)
// Output format :
// Print GCD of x and y for each test case in newline
// Constraints:
// 1 <= T <= 10^5
// 1 <= x, y <= 10^9
// Sample Input 1:
// 1
// 20 5
// Sample Output 1:
// 5
// Sample Input 2:
// 1
// 96 14
// Sample Output 2:
// 2

#include<bits/stdc++.h>
using namespace std;

int gcdFunction(int x, int y){
    
    if(y==0){
        return x;
    }
    
    return gcdFunction(y, x%y);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
    	int x,y;
        cin>>x>>y;
        int ans;
        if(x>y){
            ans=gcdFunction(x,y);
        } else if(y>x){
            ans=gcdFunction(y,x);
        } else if(x==y){
            ans=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}