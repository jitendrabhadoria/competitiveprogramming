#include<bits/stdc++.h>
using namespace std;


int power(int a, int b, int c){

    if(a==0){
        return 0;
    }
    if(b==0){
        return 1;
    }
    long ans;
    if(b%2==0){
        //b is even
        long temp = power(a, b/2,c);
        ans = (temp*temp)%c;

    } else {

        long temp = power(a, b-1, c);
        ans = a%c;
        ans = (ans*temp)%c;

    }

    return int((ans+c)%c); //added c to handle negtive numbers
}

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;
    int ans = power(a,b,c);
    
    cout<<ans<<endl;
    return 0;
}