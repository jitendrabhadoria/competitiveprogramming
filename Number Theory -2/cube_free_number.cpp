// Find The Cube Free Number
// Send Feedback
// A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
// Note: we will consider 1 as the 1st cube free number
// Input Format:
// First line of the test case will be the number of test case T 
// Each test case contain an integer N
// Output Format:
// For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^6
// Sample Input:
// 10
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// Sample Output:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// Not Cube Free
// 8
// 9

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAXN 1000000
#define CRMAXN 100
#define pb push_back

int main(){
    
    // write your code here
    int t;
    cin >> t ;
    
    int * sieve = new int[MAXN];
    int * indices = new int[MAXN];
    for(int i=0;i<=MAXN;i++){
        sieve[i]=1;
        indices[i]=0;
    }
    
	for(int i=2 ; i <= CRMAXN ; i++){
        if((i*i*i)<=MAXN){
        	sieve[i*i*i]=0;
        }
    }
    for(int i=2 ; i <= MAXN ; i++){
        if(sieve[i]==0){
            for(int j=i*2; j<=MAXN; j+=i){
                sieve[j]=0;
            }
        }
    }
    
    for(int i=0, j=0 ; i<=MAXN ; i++){
        if(sieve[i]==1){
        	indices[i]=j++;
        }
    }
    
    while(t--){
        
        int n;
        cin >> n;
        if(n>=1 && n<=MAXN){
        	int ans;
        	if(sieve[n]==1){
	        	ans = indices[n];
	        	cout<<ans<<endl;
	        }
	        else{
	            cout<<"Not Cube Free"<<endl;
	        }
        }
        
    }
    
    return 0;
}