// Column Wise Sum
// Send Feedback
// Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.
// Input Format :
// First and only line of input contains M and N, followed by M * N space separated integers representing the elements in the 2D array.
// Output Format :
// Sum of every ith column elements (separated by space)
// Constraints :
// 1 <= M, N <= 10^3
// Sample Input :
// 4 2 1 2 3 4 5 6 7 8
// Sample Output :
// 16 20

#include<iostream>
using namespace std;


int main(){

    int m,n;	
    int sum=0;
    cin>>m>>n;
    int arr[1000][1000];
    
    // m rows n columns
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0 ; i<n ; i++){
        sum=0;
        for(int j=0 ; j<m ; j++){
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
    
  
}


