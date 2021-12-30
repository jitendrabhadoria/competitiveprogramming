#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int a;
        string s;
        cin >> a >> s;
        if (a == 0){
            cout << s << "\n";
            continue;
        }
        int n = s.size();
        int b = 0;
        for (int i = 0; i < n; i++){
            b = (10 * b + s[i] - '0') % a;
        }
        int ans = gcd(a, b);
        cout << ans << endl;
    }
    return 0;
}
