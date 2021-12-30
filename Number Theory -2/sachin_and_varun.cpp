#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Triplet{
    public:
    ll gcd;
    ll x;
    ll y;
};

Triplet gcdExtendedEuclid(ll a,ll b){
//Base Case
    if(b==0){
        Triplet myAns;
        myAns.gcd = a;
        myAns.x = 1;
        myAns.y = 0;
        return myAns;
    }
    Triplet smallAns = gcdExtendedEuclid(b,a%b);
    //Extended euclid says
    Triplet myAns;
    myAns.gcd = smallAns.gcd;
    myAns.x = smallAns.y;
    myAns.y = (smallAns.x - ((a/b)*(smallAns.y)));
    return myAns;
}

ll modInverse(ll A, ll M){
    ll x = gcdExtendedEuclid(A, M).x;
    return (x % M + M) % M;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,d;
        cin >> a >> b >> d;
        ll g = __gcd(a,b);
        //Special Cases
        if(d%g){
            cout << 0 << endl;
            continue;
        }
        if(d == 0){
            cout << 1 << endl;
            continue;
        }
        a/=g;
        b/=g;
        d/=g;
        ll y1 = ((d%a) * modInverse(b,a) ) %a;
        ll firstValue = d/b;
        if(d < y1*b){
            cout << 0 <<endl;
            continue;
        }
        ll n = (firstValue - y1)/a;
        ll ans = n +1 ;
        cout << ans <<endl;
    }
    return 0;
}
