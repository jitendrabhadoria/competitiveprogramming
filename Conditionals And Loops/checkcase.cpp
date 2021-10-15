/*
Write a program that takes a character as input and prints either 1, 0 or -1 according to the following rules.
1, if the character is an uppercase alphabet (A - Z)
0, if the character is a lowercase alphabet (a - z)
-1, if the character is not an alphabet

Input format :
Single Character

Output format :
1 or 0 or -1

Constraints :
Input can be any character

Sample Input 1 :
v
Sample Output 1 :
0

Sample Input 2 :
V
Sample Output 2 :
1

Sample Input 3 :
#
Sample Output 3 :
-1

*/
#include<iostream>

using namespace std;

int main() {
	char a;
    cin>>a;
    int b;
    b=a;
    if(b<=90 && b>=65){
        cout<<"1";
    } else if(b<=122 && b>=97){
        cout<<"0";
    } else {
        cout<<"-1";
    }
}
