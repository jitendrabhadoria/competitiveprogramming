#include<bits/stdc++.h>
using namespace std;


long long power(int x, int n){

    if(n==0){
        return 1;
    }
    if(n%2==0){

        long long temp = power(x, n/2);
        long long ans = temp*temp;
        return ans;

    } else {

        long long temp = power(x, n/2);
        long long ans = temp*temp*x;
        return ans;

    }
}

int main(){
    
    int x,n;
    cin >> x >> n;
    long long ans = power(x,n);
    
    cout<<ans<<endl;
    return 0;
}