// Remove Duplicates Recursively
// Send Feedback
// Given a string S, remove consecutive duplicates from it recursively.
// Input Format :
// First line of input will contain T number of test cases
// Next T line will contain the string S
// Output Format :
// For every test case print the answer in a separate line
// Constraints :
// 1 <= T <= 10
// 1 <= |S| <= 10^4
// where |S| represents the length of string
// Sample Input 1 :
// 1
// aabccba
// Sample Output 1 :
// abcba
// Sample Input 2 :
// 1
// xxxyyyzwwzzz
// Sample Output 2 :
// xyzwz

#include<bits/stdc++.h>
using namespace std;


void removeDuplicates(char s[]){
    
    if(s[0]=='\0'){
        return;
    }
    if(s[0]!=s[1]){
        removeDuplicates(s+1);
    } else {
        int i = 2;
		for (; s[i] != '\0'; i++) {
			s[i - 1] = s[i];
		}
		s[i - 1] = s[i];
		removeDuplicates(s);
    }
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        char str[10000];
        
        cin >> str;
                
        removeDuplicates(str);
        
        cout << str << endl;
        
    }
    return 0;
}