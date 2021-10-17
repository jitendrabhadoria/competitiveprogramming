// Given a binary number as an integer N, convert it into decimal and print.
// Input format :
// An integer N in the Binary Format
// Output format :
// Corresponding Decimal number (as integer)
// Constraints :
// 0 <= N <= 10^9
// Sample Input 1 :
// 1100
// Sample Output 1 :
// 12
// Sample Input 2 :
// 111
// Sample Output 2 :
// 7
#include<iostream>
#include<cmath>

using namespace std;

int main() {
	unsigned long long int n, temp, sum=0;
    cin>>n;
    temp=n;
    int dig, i=0;
    if(n>=0 && n<=1000000000){
        while(n!=0){
            dig=n%10;
            sum=sum+(pow(2,i)*dig);
            n=n/10;
            i++;
        }
        cout<<sum;
    }
	
}
