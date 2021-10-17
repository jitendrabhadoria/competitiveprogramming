// Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
// Note : If a number has trailing zeros, then its reverse will not include them. For e.g., reverse of 10400 will be 401 instead of 00401.


// Input format :
// Integer N
// Output format :
// Corresponding reverse number
// Constraints:
// 0 <= N < 10^8
// Sample Input 1 :
// 1234
// Sample Output 1 :
// 4321
// Sample Input 2 :
// 1980
// Sample Output 2 :
// 891
#include<iostream>
using namespace std;

int main() {
	unsigned long long int n, temp, new_num=0;
    cin>>n;
    int dig, place=10;
    temp=n;
    if(n>=0 && n<100000000){
        while(n!=0){
        	dig=n%10;
            new_num=(new_num*place)+dig;
            n=n/10;
            //place*=10;
    	}
        cout<<new_num;
    }
}
