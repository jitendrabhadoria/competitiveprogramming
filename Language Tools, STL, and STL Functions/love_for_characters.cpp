// Love for Characters
// Send Feedback
// Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
// Input:
// First line contains an integer denoting length of the string.
// Next line contains the string.
// Constraints:
// 1<=n<=10^5
// ‘a’<= each character of string <= ‘z’
// Output:
// Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
// Sample Input:
// 6
// aabsas
// Sample output:
// 3 2 0

#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
    return (char)(i+97);
}

void printCount(char s[], int n){
    map<char, int> countMap;
    
    int count_a=0, count_s=0, count_p=0;  
    
    for(int i=0;s[i]!='\0';i++){
        countMap[s[i]]++;
    }

    for(int i=0;i<26;i++){
        char currentChar = getChar(i);
        if(currentChar == 'a'){
            count_a = countMap[currentChar];
        } else if(currentChar == 's'){
            count_s = countMap[currentChar];
        } else if(currentChar == 'p'){
            count_p = countMap[currentChar];
        }
    }
    
    cout<<count_a<<" "<<count_s<<" "<<count_p<<endl;
    return;
}

int main()
{
    
    int n;
    cin>>n;
    char s[n];
    int i;
    for(i=0; i<n; i++){
        cin>>s[i];
    }
    s[i]='\0';
    printCount(s, n);
    cout<<endl;
	return 0;
}

