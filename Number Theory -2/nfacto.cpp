// Number Of Factors
// Send Feedback
// A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
// Input Format:
// First line of input will contain T(number of test cases), each test case follows as.
// Each test cases consists of a single line containing integers a, b, and n as described above.
// Output Format:
// Output for each test case one line containing the number of n-factorful integers in [a, b].
// Constraints:
// 1 <= T <= 10000
// 1 ≤ a ≤ b ≤ 10^6
// 0 <= b - a <= 100
// 0 ≤ n ≤ 10
// Sample Input
// 4
// 1 3 1
// 1 10 2
// 1 10 3
// 1 100 3
// Sample Output
// 2 
// 2
// 0
// 8

#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int * spf = new int[MAXN];
bool * isPrime = new bool[MAXN+1];
int * nof = new int[MAXN+1];

void sieve(){
    
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
    
    int n = MAXN+1;
    
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
    
}
 
int findFactors(int x){
    
    vector<int> ret;
    int j=0;
    while (x != 1)
    {
        if(j==0){
            ret.push_back(spf[x]);
        	x = x / spf[x];
        	j++;
    	
        } else {
            int temp = spf[x];
        	if(temp == ret[j-1]){
        		x = x / spf[x];
        	}
        	else {
            	ret.push_back(spf[x]);
            	x = x / spf[x];
            	j++;
        	}
        } 
    }
    
    return ret.size();
}

void fillDP(){
    
    nof[1]=0;
    
    for(int i=2;i<=999999;i++){
        
        int p;
        
        if(isPrime[i]){
            p=1;
        } else{
            p = findFactors(i);
        }
        nof[i]=p;  
    }
    nof[1000000]=2;

}

int superPrime(int a, int b, int d){

          
    int ans=0;
    
    if(a<b){
        for(int i = a; i<=b;i++){
	        if(nof[i]==d){
	            ans++;
        	}
    	}
    }
    if(b<=a){
        for(int i = b; i<=a;i++){
	        if(nof[i]==d){
	            ans++;
        	}
    	}
    }
    
    return ans;
    
}


int main(){
    
    // write your code here
    int t;
    cin >> t;
    sieve(); // O(nloglogn)
    fillDP();
    while(t--){
        
        int a,b,n;
        
    	cin >> a >> b >> n;
       
	    int ans = superPrime(a,b,n);
	    
	    cout<<ans<<endl;
    }    
    return 0;
}