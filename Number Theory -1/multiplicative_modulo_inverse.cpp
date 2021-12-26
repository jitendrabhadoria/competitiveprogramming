#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    int gcd;
    int x;
    int y;
};

Triplet extendedEuclid(int a, int b){
    // base case
    if(b == 0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    // extended euclid algorithm
    Triplet smallAns = extendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

int mmInverse(int a, int m){
    Triplet ans = extendedEuclid(a, m);
    return ans.x;
}

int main(){

    int a,m;
    cin>>a>>m;
    int ans = mmInverse(a,m);
    cout<<ans<<endl; 
    return 0;
}
