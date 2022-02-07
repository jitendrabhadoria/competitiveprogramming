// Winning Lottery
// Send Feedback
// Harshit knows through his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
// Input Format:
// First line of input contians an integer T, representing the number of test cases.
// Next T lines contains two space-separated integers: S,D
// Constraints:
// 1 <= T <= 1000
// 1 <= D <= 1000
// 1 <= S <= 9*D
// Time Limit: 1 second
// Output Format
// The output contains a single integer denoting the winning lottery number
// Sample Input 1:
// 1
// 9 2
// Sample Output 1:
// 18
// Explanation
// There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.

#include<bits/stdc++.h>
using namespace std;


void findSmallest(int m, int s) 
{ 
   
    if (s == 0) 
    { 
        (m == 1)? cout << 0 
                : cout << "Not possible"; 
        return ; 
    } 
  
    if (s > 9*m) 
    { 
        cout << "Not possible"; 
        return ; 
    } 
  
    int res[m]; 
  
    s -= 1; 
  
    for (int i=m-1; i>0; i--) 
    { 
        
        if (s > 9) 
        { 
            res[i] = 9; 
            s -= 9; 
        } 
        else
        { 
            res[i] = s; 
            s = 0; 
        } 
    } 
  
    res[0] = s + 1;  
  
    
    for (int i=0; i<m; i++) 
        cout << res[i]; 
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        
        int s, d;
		cin >> s >> d;
		findSmallest(d, s);
        cout<<endl;
        
    }
	
}