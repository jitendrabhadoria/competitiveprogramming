// Merge Sort Code
// Send Feedback
// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// First line of input will contain T number of test cases
// First line of every input will contain a single integer N size of the input array.
// second line of each input will contain N space-separated integers.
// Output format :
// For every test case print, array elements in increasing order (separated by space) in a separate line.
// Constraints :
// 1 <= T <= 10
// 1 <= n <= 10^5
// Sample Input 1 :
// 1
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 1
// 5
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

#include<bits/stdc++.h>
using namespace std;

long long merge(long long A[], int left, int mid, int right){
    
    int i=left, j=mid, k=0;
    
    int temp[right-left+1];

    while(i<mid && j<=right){
        if(A[i]<=A[j]){
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
}
void merge_sort(long long A[], int left, int right){
    if(right > left){
        int mid = (left+right)/2;
		merge_sort(A, left, mid);
       	merge_sort(A, mid+1, right);
        merge(A, left, mid+1, right);
    }
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
    
    merge_sort(arr, 0, n-1);

    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    
    cout<<endl;

    delete arr;
    }
    
}