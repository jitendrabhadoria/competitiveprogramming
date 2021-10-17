// Given a number N, find its square root. You need to find and print only the integral part of square root of N.
// For eg. if number given is 18, answer is 4.
// Input format :
// Integer N
// Output Format :
// Square root of N (integer part only)
// Constraints :
// 0 <= N <= 10^8
// Sample Input 1 :
// 10
// Sample Output 1 :
// 3
// Sample Input 2 :
// 4
// Sample Output 2 :
// 2

#include<iostream>
using namespace std;

int main() {
	long long int n, temp, i=2;
    cin>>n;
    temp=n;
    if(n>=0 && n<=100000000){
        if(n==0){
            cout<<"0";
        } else if(n==1){
            cout<<"1";
        } else {
            for(i=2; i<n/2; i++){
                if((i*i)<=n){
                    continue;
                } else{
                    i--;
                    break;
                }
            }
        	cout<<i;
        }
    }
	
}
