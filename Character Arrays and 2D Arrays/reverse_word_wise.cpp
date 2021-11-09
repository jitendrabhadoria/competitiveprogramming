// Reverse Word Wise
// Send Feedback
// Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
// Input format :
// String in a single line
// Output format :
// Word wise reversed string in a single line
// Constraints :
// 0 <= |S| <= 10^7
// where |S| represents the length of string, S.
// Sample Input 1:
// Welcome to Coding Ninjas
// Sample Output 1:
// Ninjas Coding to Welcome
// Sample Input 2:
// Always indent your code
// Sample Output 2:
// code your indent Always

#include <iostream>
using namespace std;

void copyIntoOld(char final_arr[], char input[], int left, int right, int count){
    for(int i=right,j=count-left-2 ; i>=left ; i--,j--){
        final_arr[j]=input[i];
    }
}

void reverseStringWordWise(char input[]) {
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
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
