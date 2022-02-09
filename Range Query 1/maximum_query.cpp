// Maximum Query
// Send Feedback
// You are given an array of integet of size N and Q queries in form of (l, r). You are supposed to find the maximum value of array between index l and r (both inclusive)
// Input Format:
// First line of input contain an integer N (number of elements in the array)
// Second line contain N space-separated integers denoting the elements of the array
// Third line contain an integer Q (number of queries to be processed)
// Next Q line contain two space-separated integers denoting l and r.
// Output Format:
// For each test case print the output in newline.
// Constraints:
// 1 <= N <= 10^4
// 1 <= Q <= 10^6
// 1 <= arr[i] <= 10^9
// 0 <= l <= r < N
// Sample Input:
// 5
// 1 2 3 5 4
// 2 
// 0 1
// 3 4
// Sample Output:
// 2
// 5

#include<bits/stdc++.h>
using namespace std;

int query(int* tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		int temp = INT_MIN;
		return temp;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	int mid = (start+end)/2;

	int l = query(tree, start, mid, 2*treeNode+1, left, right);
	int r = query(tree, mid+1, end, 2*treeNode+2, left, right);


	int result;
	result = max(l,r);
    
   	return result;

}

void create(int* arr, int* tree, int start, int end, int treeNode){
    
	if (end == start)
	{
		tree[treeNode] = arr[start];
		return;
	}

	int mid = (start+end)/2;

	create(arr, tree, start, mid, 2*treeNode+1);
	create(arr, tree, mid+1, end, 2*treeNode+2);

	int left = tree[2*treeNode+1];
	int right = tree[2*treeNode+2];

	tree[treeNode] = max(left,right);
	
	return;
    
}

int main()
{
	int n, q;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cin>>q;
	int* tree = new int[4*n];
	create(arr, tree, 0, n-1, 0);
   
	while(q--){
		
		int b, c;
		cin>>b>>c;
		int result = query(tree, 0, n-1, 0, b, c);
        
        cout << result << endl;
	
	}
    
	return 0 ; 

}