// Remove Consecutive Duplicates
// Send Feedback
// For a given string(str), remove all the consecutive duplicate characters.
// Example:
// Input String: "aaaa"
// Expected Output: "a"

// Input String: "aabbbcc"
// Expected Output: "abc"
//  Input Format:
// The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
// Output Format:
// The only line of output prints the updated string.
// Note:
// You are not required to print anything. It has already been taken care of.
// Constraints:
// 0 <= N <= 10^6
// Where N is the length of the input string.

// Time Limit: 1 second
// Sample Input 1:
// aabccbaa
// Sample Output 1:
// abcba
// Sample Input 2:
// xxyyzxx
// Sample Output 2:
// xyzx

#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[]) {
    // Write your code here
    char temp;
    int j,i,k;
    int count;
    int len = strlen(input)+1;
    char str[len];
    for(i=0 , k=0; input[i]!='\0' ;){
        count=0;
        temp = input[i];
        j=i;
        while(input[j]==temp){
            count++;
            j++;
        }
        //cout<<"Temp "<<temp<<"  Count "<<count<<endl;
        if(count==0){
            //str[k++]=temp;
            i++;
            continue;
        } else {
            str[k++]=temp;
            i+=count;
        }
    }
    str[i]='\0';
    for(i=0; str[i]!='\0'; i++){
        input[i]=str[i];
    }
    input[i]='\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}