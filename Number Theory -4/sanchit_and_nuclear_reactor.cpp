// Sanchit And Nuclear Reactor
// Send Feedback
// We all know Sanchit Lee Cooper who is a Caltech theoretical physicist. He has eccentric and arrogant behavior. Due to his belief that he's intellectually superior, he's not ashamed to insult his own friends, like Howard, who is an engineer and not a real scientist. But nobody messes with an engineer. So Howard accepted an challenge from Sanchit. Sanchit was involved in numerous experiments as a wunderkind, such as his plan for building his own nuclear reactor - a plan stopped by government. So Sanchit presented Howard with a problem about his own nuclear reactor. It contains a large tank and at each second an atom is introduced in the tank which reacts with already existing atoms and produces some energy. Also he defined a special threshold number for his reactor called Cooper number m which is always a prime number. Energy output is defined as previous energy output of the tank multiplied by number of atoms present in it. But due to some special condition of the tank, all atoms attains stable state when number of atoms are multiple of Cooper number and no new reaction occurs. Energy output in this case is same as previous case. Also initial energy of the reactor is 1 and initially there is no atom in the tank. Now Sanchit ask Howard to tell the energy output after time T. But sadly Howard is not able to solve it and ask for your help.
// Input Format
// The first line of input contains T(number of the test case), each test case follows as.
// contian two space-separated integers N and M where M is a prime number.
// Output Format
// You have to determine the energy output after time T. As the number can be quite large so output it modulo Cooper number m.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 10^18
// 1 <= M <= 10^4
// Sample Input
// 2
// 1 5
// 2 5
// Sample Output
// 1
// 2
// Explanation
// After 1 seconds, there is only 1 atom in the tank. Hence energy output is 1. After 2 seconds, there are 2 atoms which reacts to give energy output of 2.

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int

long long fact(ll a, ll m){
	long long res=1;
	for(ll i=2;i<=a;i++)
		res=(res%m * i%m)%m;
	return res;
}
int main(){

	ll n;
	cin>>n;
	while(n--){
		ll t;
		ll m;
		cin>>t>>m;
		if(t<m){
			if(m-t==1){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<fact(t, m)%m<<endl;
				continue;
			}
		}
		else{
			ll last = t%m;
			ll facto=fact(last, m)%m;

			if((t/m)%2==0)
				cout<<facto<<endl;
			else
				cout<<((m-1)%m*facto%m)%m<<endl;
		}
	}
	return 0;
}