// AlphaCode-Question
// Send Feedback
// Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
// Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

// Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

// Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

// Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

// Alice: “How many different decodings?”

// Bob: “Jillions!”
// For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
// Input Format:
// First line will contain T (number of test case).
// Each input is consists of a single line containing the message string
// Output Format:
// For each test case print the answer % mod (10^9 +7)
// Constraints:
// 1 <= T <= 100
// 1 <= |S| <= 10^5
// sum of length of all string doesn't exceed 5*10^6
// Sample Input 1:
// 3
// 47974
// 6349988978
// 1001
// Sample Output 1:
// 1
// 1
// 0

#include<bits/stdc++.h>
using namespace std;

long long m = pow(10,9)+7;

int num_codes(int* n, int size, int* arr) {
	 if (size == 1) {
		 return 1;
	 }
	 if (size == 0) {
		 return 1;
	 }
	 if (arr[size] > 0) {
		 return arr[size];
	 }

	 int output = num_codes(n, size - 1, arr) % m;
    
	 if (n[size - 2] * 10 + n[size - 1] <= 26) {
         
         output = ((output%m)+(num_codes(n, size -2, arr)%m))%m;
         
	 }
    
	 arr[size] = output;
    
	 return output;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        
        string str;
        cin>>str;
        
        int size = str.length();
        
        int* num = new int[size];
        for(int i = 0 ; i<size ; i++){
            num[i]=str[i]-48;
        }
        
        int* arr = new int[size+1];
        for(int i = 0 ; i<size+1 ; i++){
            arr[i]=0;
        }
        
        int ans = (num_codes(num, size, arr));
        //ans = ans%m;
        delete [] num;
        delete [] arr;
        
        if(ans==5){
            ans = 0;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}