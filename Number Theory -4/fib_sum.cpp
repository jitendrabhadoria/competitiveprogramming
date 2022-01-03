#include<bits/stdc++.h>
using namespace std;

#define m 1000000007
#define ll long long int

void multiply(ll A[2][2],ll M[2][2]){

	ll firstValue = (((A[0][0] % m) * (M[0][0] % m))%m + ((A[0][1] % m) * (M[1][0] % m))%m)%m;
	ll secondValue = (((A[0][0] % m) * (M[0][1] % m))%m + ((A[0][1] % m) * (M[1][1] % m))%m)%m;
	ll thirdValue = (((A[1][0] % m) * (M[0][0] % m))%m + ((A[1][1] % m) * (M[1][0] % m))%m)%m;
	ll fourthValue = (((A[1][0] % m) * (M[0][1] % m))%m + ((A[1][1] % m) * (M[1][1] % m))%m)%m;

	A[0][0] =firstValue%m;
	A[0][1] = secondValue%m;
	A[1][0] = thirdValue%m;
	A[1][1] = fourthValue%m;
	
}
void power(ll A[2][2],ll n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		ll F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}
}
ll getFibonacci(ll n){
	if(n==0 || n==1){
		return n;
	}
	ll A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}

int main(){
    
    // write your code here
    ll t;
    cin >> t;
    while(t--){
        
        ll n, p;
        cin >> n >> p;
        //sm = fm+2 - 1
        //sn-1 = fn+1 -1
        //ans = sm-sn-1
        ll nTerm = getFibonacci(n+1);
        ll mTerm = getFibonacci(p+2);
        
        ll nSum = (nTerm%m - 1)%m;
        ll mSum = (mTerm%m - 1)%m;
        
        ll ans = ((mSum%m)%m - (nSum%m)%m)%m;
        
        cout<<ans<<endl;
        
    }
    return 0;
}