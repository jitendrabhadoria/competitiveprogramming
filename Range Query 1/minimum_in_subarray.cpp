// Minimum In SubArray
// Send Feedback
// You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:
// Query on range:
// You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].
// Update query:
// You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
// Input Format:
// The first line of input contains two integers: N and Q, representing the length of the sequence and the number of queries. 
// The second line of input contains N space-separated integers, A[i].  
// Next, Q lines contain the queries. Each line contains one character, followed by two space-separated integers. For the query on range, the character will be q and for the update query, the character will be u. 
// Constraints:
// 1 ≤ i ≤ N
// 0 ≤ B ≤ 10^8
// 1 ≤ i <= j ≤ N
// Output Format:
// For each query on range, print the minimum number between the range, in a new line.
// Sample Input 1:
// 4 3
// 5 2 4 3
// q 1 3
// u 1 1
// q 3 4
// Sample Output 1:
// 2
// 3

#include<bits/stdc++.h>
using namespace std;

void buildtree(int* arr, int* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildtree(arr, tree, start, mid, 2 * treenode);
	buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree[treenode] = min(tree[2 * treenode] , tree[2 * treenode + 1]);
}
void updatetree(int* arr, int* tree, int start, int end, int treenode, int index, int value)
{
	if (start == end)
	{
		arr[index] = value;
		tree[treenode] = value;
		return;
	}
	int mid = (start + end) / 2;
	if (index > mid)//right
	{
		updatetree(arr, tree, mid + 1, end, 2 * treenode + 1, index, value);
	}
	else//left
	{
		updatetree(arr, tree, start, mid, 2 * treenode, index, value);
	}
	tree[treenode] = min(tree[2 * treenode] , tree[2 * treenode + 1]);
}
int query(int* tree, int start, int end, int treenode, int left, int right)
{
	if(start>right || end <left)
	{
		return INT_MAX;
        
	}
    
    if(start>=left && end<=right)
    {
        return tree[treenode];
    }
	int mid=(start+end)/2;
	int ans1=query(tree, start, mid, 2*treenode, left, right);
	int ans2=query(tree, mid+1, end, 2*treenode+1, left, right);
	return min(ans1, ans2);
}
int main()
{
	int n, q;
	cin>>n>>q;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int *tree=new int [4*n];
	buildtree(arr, tree, 0, n - 1, 1);
	//at this point of time i have my tree with me.
	while(q--)
	{
		char query_type;
        int l,r,x,y;
        
		cin>>query_type>>l>>r;
        
		if(query_type=='q')
		{
			cout<<query(tree, 0, n-1, 1, l-1, r-1)<<endl;
		}
		else
		{
			x=l;
            y=r;
			//we need to update arr[x]=y;
			updatetree(arr, tree, 0, n - 1, 1, x-1, y);
		}
	}
}

