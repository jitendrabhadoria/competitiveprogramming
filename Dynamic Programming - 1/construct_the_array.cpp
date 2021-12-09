// https://www.hackerrank.com/challenges/construct-the-array/problem


#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

int constructArray(int n, int k, int x){
    long oneCount = 1;
    long nonOneCount= 0;
    
    for(int i  = 1 ; i < n ; i++){
        long prevOneCount = oneCount;
        oneCount = (nonOneCount*(k-1))%M;
        nonOneCount = (prevOneCount + ((nonOneCount)*(k-2))%M)%M;
    }
    if(x==1){
        return oneCount;
    }
    else{
        return nonOneCount;
    }
}

int main(){
    int n , k , x;
    cin >> n >> k >> x;
    
    int ans = constructArray(n,k,x);
    
    cout<<ans<<endl;


    return 0;
}
