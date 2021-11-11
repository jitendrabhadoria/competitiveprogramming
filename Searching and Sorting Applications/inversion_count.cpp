// Inversion Count
// Send Feedback
// For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]' 
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').
// Input format :
// The first line of input contains an integer 'N', denoting the size of the array.

// The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
// Output format :
// Print a single line containing a single integer that denotes the total count of inversions in the input array.
// Note:
// You are not required to print anything, it has been already taken care of. Just implement the given function.  
// Constraints :
// 1 <= N <= 10^5 
// 1 <= ARR[i] <= 10^9

// Where 'ARR[i]' denotes the array element at 'ith' index.

// Time Limit: 1 sec
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation of Sample Output 1:
// We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
// Sample Input 2 :
// 5
// 2 5 1 3 4
// Sample Output 2 :
// 4
// Explanation of Sample Output 1:
// We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).

#include<iostream>
using namespace std;

long long merge(long long A[], int left, int mid, int right){
    int i= left, j=mid, k=0;
    int temp[right-left+1];
    long long count = 0;

    while(i<mid && j<=right){
        if(A[i]<=A[j]){
            temp[k++]=A[i++];
        } else{
            temp[k++]=A[j++];
            count+=mid-i;
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
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}