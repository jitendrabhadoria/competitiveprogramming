// Largest Bitonic Subsequence
// Send Feedback
// You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
// Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
// Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
// Input Format:
// First line will contain T (number of test case), each test is consists of two lines. 
// Line 1 : A positive Integer N, i.e., the size of array
// Line 2 : N space-separated integers as elements of the array 
// Output Format:
// Length of Largest Bitonic subsequence for each test case in a newline.
// Input Constraints:
// 1 <= T <= 10
// 1<= N <= 5000
// Sample Input 1:
// 1
// 6
// 15 20 20 6 4 2
// Sample Output 1:
// 5
// Sample Output 1 Explanation:
// Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
// Sample Input 2:
// 1
// 2
// 1 5
// Sample Output 2:
// 2
// Sample Input 3:
// 1
// 2
// 5 1
// Sample Output 3:
// 2


#include<bits/stdc++.h>
using namespace std;

int lbs(int * arr, int n){
    
    int * leftCount = new int[n];
    int * rightCount = new int[n];
    int * lbs = new int[n];
    
    for (int i = 0; i < n; i++) {
		lbs[i] = 0;
        leftCount[i]=0;
        rightCount[i]=0;
	}
    
    leftCount[0]=1;
    rightCount[n-1]=1;
    for (int i = 1; i < n; i++) {
        
        leftCount[i]=1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] >= arr[i]) {
				continue;
			} 
			int possibleAns = leftCount[j] + 1;
			if (possibleAns > leftCount[i]) {
				leftCount[i] = possibleAns;
			}
		}
       
	}
    
    for (int i = n-1; i >= 0 ; i--) {
        
        rightCount[i]=1;
        for (int j = i+1 ; j < n ; j++) {
			if (arr[j] >= arr[i]) {
				continue;
			}
			int possibleAns = rightCount[j] + 1;
			if (possibleAns > rightCount[i]) {
				rightCount[i] = possibleAns;
			}
		}
	}
    
    
	for (int i = 0; i < n; i++) {
        lbs[i]=rightCount[i]+leftCount[i]-1;
	}
   
    int best = 0;
	for (int i = 0; i < n; i++) {
		if (best < lbs[i]) {
			best = lbs[i];
		}
	}
    
    delete [] leftCount;
    delete [] rightCount;
    delete [] lbs;
    return best;
    
}


int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        
        int N;
        cin >> N;
        
        int * arr = new int[N];
        for(int i = 0 ; i<N ; i++){
            cin >> arr[i];
        }
        
        int ans = lbs(arr, N);
        cout << ans << endl;
        
        delete [] arr;
        
    }
    return 0;
}