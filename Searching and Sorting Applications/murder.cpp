// Murder
// Send Feedback
// Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long.
// Input Format:
// First line of input contains an integer T, representing number of test case.
// For each test case, first line of input contains integer N, representing the number of stairs.
// For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
// Constraints
// T<=10^5
// 1<=N<=10^5
// All numbers will be between 0 and 10^9
// Sum of N over all test cases doesn't exceed 5*10^5
// Output Format
// For each test case output one line giving the final sum for each test case.
// Sample Input 1:
// 1
// 5
// 1 5 3 6 4
// Sample Output 1:
// 15
// Explanation:
// For the first number, the contribution to the sum is 0.
// For the second number, the contribution to the sum is 1.
// For the third number, the contribution to the sum is 1.
// For the fourth number, the contribution to the sum is 9 (1+5+3).
// For the fifth number, the contribution to the sum is 4 (1+3).
// Hence the sum is 15 (0+1+1+9+4).

#include<iostream>
using namespace std;

long long merge(long long A[], int left, int mid, int right){
    int i= left, j=mid, k=0;
    int temp[right-left+1];
    long long count = 0;

    while(i<mid && j<=right){
        if(A[i]<A[j]){
            count += ((right-j+1)*A[i]);
            temp[k++]=A[i++];
        } else{
            temp[k++]=A[j++];
        }
    }
    while(i<mid){
        temp[k++]=A[i++];
    } 
    while(j<=right) {
        temp[k++]=A[j++];
    }
    for(int i=left, k = 0; i<=right; i++, k++){
        A[i]=temp[k];
    }
    return count;
}


long long merge_sort(long long A[], int left, int right){
    long long count = 0;
    if(right > left){
        int mid = (left+right)/2;
        long long countLeft = merge_sort(A, left, mid);
        long long countRight = merge_sort(A, mid+1, right);
        long long myCount = merge(A, left, mid+1, right);
        return myCount + countLeft + countRight;
    }
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans = merge_sort(arr, 0, n-1);
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
    	cin >> n;

    	long long* arr = new long long[n];

    	for(int i = 0; i < n; ++i)
    	{
	        cin >> arr[i];
	    }

    	cout << getInversions(arr, n) << endl;

    	delete arr;
    }
    
    return 0;
}