// Print Keypad Combinations Code
// Send Feedback
// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf


#include <iostream>
#include <string>
using namespace std;

void keypad(int num, string output){
    if(num == 0){
        cout<<output<<endl;
        return;
    }
    int newNumber = num/10;
    int currentNumber = num%10;
    switch(currentNumber){
        case 1 :keypad(newNumber, ""+output);
            	break;
        case 2 :keypad(newNumber, "a"+output);
            	keypad(newNumber, "b"+output);
            	keypad(newNumber, "c"+output);
            	break;
        case 3 :keypad(newNumber, "d"+output);
            	keypad(newNumber, "e"+output);
            	keypad(newNumber, "f"+output);
            	break;
        case 4 :keypad(newNumber, "g"+output);
            	keypad(newNumber, "h"+output);
            	keypad(newNumber, "i"+output);
            	break;
        case 5 :keypad(newNumber, "j"+output);
            	keypad(newNumber, "k"+output);
            	keypad(newNumber, "l"+output);
            	break;
        case 6 :keypad(newNumber, "m"+output);
            	keypad(newNumber, "n"+output);
            	keypad(newNumber, "o"+output);
            	break;
        case 7 :keypad(newNumber, "p"+output);
            	keypad(newNumber, "q"+output);
            	keypad(newNumber, "r"+output);
            	keypad(newNumber, "s"+output);
            	break;
        case 8 :keypad(newNumber, "t"+output);
            	keypad(newNumber, "u"+output);
            	keypad(newNumber, "v"+output);
            	break;
        case 9 :keypad(newNumber, "w"+output);
            	keypad(newNumber, "x"+output);
            	keypad(newNumber, "y"+output);
            	keypad(newNumber, "z"+output);
            	break;
    }
}


void printKeypad(int num){
	string output="";
   	keypad(num,output);
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}