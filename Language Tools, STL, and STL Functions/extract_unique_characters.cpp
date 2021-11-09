// Extract Unique characters
// Send Feedback
// Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
// Input format:
// The first and only line of input contains a string, that denotes the value of S.
// Output format :
// The first and only line of output contains the updated string, as described in the task.
// Constraints :
// 0 <= Length of S <= 10^8
// Time Limit: 1 sec
// Sample Input 1 :
// ababacd
// Sample Output 1 :
// abcd
// Sample Input 2 :
// abcde
// Sample Output 2 :
// abcde

#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
    return (char)(i+97);
}
string uniqueChar(string str) {
    map<char, bool> stateMap;
    string temp;
    int n = str.length();
    for(int i=0;i<26;i++){
    	stateMap[getChar(i)]=false;
    }
    for(int i=0;i<n;i++){
        if(!stateMap[str[i]]){
            temp.push_back(str[i]);
            stateMap[str[i]]=true;
        }
    }
    str=temp;
    return str;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}