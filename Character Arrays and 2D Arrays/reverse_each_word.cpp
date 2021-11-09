// Reverse Each Word
// Send Feedback
// Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
// Example:
// Input Sentence: "Hello, I am Aadil!"
// The expected output will print, ",olleH I ma !lidaA".
// Input Format:
// The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.
// Output Format:
// The only line of output prints the sentence(string) such that each word in the sentence is reversed. 
// Constraints:
// 0 <= N <= 10^6
// Where N is the length of the input string.

// Time Limit: 1 second
// Sample Input 1:
// Welcome to Coding Ninjas
// Sample Output 1:
// emocleW ot gnidoC sajniN
// Sample Input 2:
// Always indent your code
// Sample Output 2:
// syawlA tnedni ruoy edoc

#include <iostream>
#include <cstring>
using namespace std;

void copyIntoOld(char final_arr[], char input[], int left, int right, int count){
    for(int i=right,j=0+left ; i>=left ; i--,j++){
        final_arr[j]=input[i];
    }
    
}

void reverseEachWord(char input[]) {
	//Code Begins Here
    int count=0;
    int left=0, right;
    
    //Count String Length
    for(int i=0 ; input[i]!='\0' ; i++){
        count++;
    }
    count++;
    
    //Create final_arr Character Array
    char *final_arr = new char[count];
        
    //Initialise Final
    for(int i=0 ; input[i]!='\0' ; i++){
        final_arr[i]=' ';
    }
    
    //Appending Space After Last Word
    input[count-1]=' ';
    input[count]='\0';
    final_arr[count]='\0';
    
    for(int i=0 ; input[i]!='\0' ; i++){
        if(input[i]==' '){
            right=i-1;
            copyIntoOld(final_arr, input, left, right, count);
            left=i+1;
        }
    }
    
    //Copy into input
    for(int i=0 ; final_arr[i]!='\0' ; i++){
        input[i]=final_arr[i];
    }
    
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}