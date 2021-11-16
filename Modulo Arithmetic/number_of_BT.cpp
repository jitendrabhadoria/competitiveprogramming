// Number Of Balanced BTs
// Send Feedback
// You are given an integer h, find and print the count of all possible balanced binary trees of height h.
// This number can be huge, so return the output modulus 10^9 + 7.
// Input Format :
// The first line of input contains an integer, that denotes the value of the number of test cases. Let us denote it with the symbol T.
// Each test case consists of a single integer h, that denotes height of the binary tree, in a separate line.
// Output Format :
// For each test case, there is a single line of output, which prints the count of all possible balanced binary trees of height h, modulus 10^9 + 7. The output for each test case is printed in a separate line.
// Constraints :
// 1 <= T <= 10
// 1 <= h <= 20
// Time Limit: 1 second
// Sample Input 1:
// 1
// 2
// Sample Output 1:
// 3    
// Explanation:
// Following are the three balanced binary trees, that can be formed with height = 2.
// Alt Text

// Sample Input 2:
// 2
// 3
// 4
// Sample Output 2:
// 15
// 315

#include<bits/stdc++.h>
using namespace std;

int findBT(long long h){
    
    if(h==0 || h==1){
        return 1;
    }
    
    long long x = findBT(h-1);
    long long y = findBT(h-2);
    long long c = pow(10,9)+7;
    long long xx = ((x%c)*(x%c))%c;
    long long xy = ((x%c)*(y%c))%c;
    long long xy2 = ((2%c)*(xy%c))%c;
    long long answer = ((xx%c)+(xy2%c))%c;
    
    return answer;
    
}


int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        
        int h;
        cin >> h;
        long long numberOfBBT;
        numberOfBBT = findBT(h);
        cout<<numberOfBBT<<endl;
        
    }
    return 0;
}