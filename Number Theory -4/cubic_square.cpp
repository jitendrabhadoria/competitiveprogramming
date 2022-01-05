// Cubic Square
// Send Feedback
// Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
// After school he found that tuples he wrote are modified by his little sister. His sister converted each b into base 3. Varun wrote everything in base 10.
// Help Varun to do his exercise.
// Input Format:
// First line of input contains a number T(number of test case). Each test case contains an integer a(base 10) followed by a string b (base 3) followed by integer m (base 10). All are space-separated.
// Output Format;
// Output a number for each test case a^b mod m in base 10 in new line.
// Constraints:
// 1 <= T <= 1000
// 1 <= a, m <= 10^9
// Number of digits in b will be less than 250.
// Sample Input:
// 2
// 2 10 10
// 3 21101 19
// Sample Output:
// 8
// 3


#include<bits/stdc++.h>
using namespace std;
int power(long long int a, string b, int m)
{
	int len = b.length();
	long long int final_ans = 1;
	for(int i=len-1;i>=0;i--)
	{
		if(b[i] == '0')
		{	
			a %= m;
			a = (((a*a)%m)*a)%m;
		}
		if(b[i] == '1')
		{	
			final_ans = final_ans * a;
			final_ans %= m;
			a = (((a*a)%m)*a)%m;
		}
		if(b[i] == '2')
		{
			final_ans = ((final_ans * a)%m) * a;
			final_ans %= m;
			a = (((a*a)%m)*a)%m;
		}
	}
	return final_ans;
}
int main()
{
	long long int t;
	cin >> t;
	//write code here
	while(t--)
	{
		long long int a; //in base 10
		string b; //in base 3
		int m; //in base 10
		cin >> a >> b >> m;

		cout << power(a,b,m) << endl;
	}

	return 0 ; 

}