#include<bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y){
    // Base Case
    if (b == 0){
        *x = 1;
        *y = 0;
        return b;
    }
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b, a % b, &x1, &y1);
    // Update x and y using results of
    // recursive call
    *x = y1;
    *y = x1 - y1 * (a/b);

    return gcd;

}

int main(){

    int a,b;
    cin>>a>>b;
    int x,y;
    int ans = gcdExtended(a,b,&x,&y);
    cout<<x<<" "<<y<<endl;
    return 0;
}