// Maximum Sum In Subarray
// Send Feedback
// You are given a sequence A[1], A[2], ..., A[N].
// A query is defined as follows:
// Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
// Given M queries, write a program that outputs the results of these queries.
// Input Format:
// The first line of input contains an integer N.
// In the second line contains N space separated integers.
// The third line contains the integer M.
// Next M lines contains 2 integers x and y.
// Output Format:
// For each query, print the answer in a new line.
// Constraints:
// 1 <= N <= 10^5
// 1 < = Q <= 10^5
// -10^4 <= arr[i] <= 10^4
// Sample Input 1:
// 3 
// -1 2 3 
// 1
// 1 2
// Sample Output 1:
// 2

#include<bits/stdc++.h>
using namespace std;
struct attrs {
	int max_sum;
	int sum;
	int best_prefix_sum;
	int best_suffix_sum;
};
void build_tree(int* arr, attrs* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode].sum = arr[start];
		tree[treenode].max_sum = arr[start];
		tree[treenode].best_suffix_sum = arr[start];
		tree[treenode].best_prefix_sum = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build_tree(arr, tree, start, mid, 2 * treenode);
	build_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree[treenode].sum = tree[2 * treenode].sum + tree[2 * treenode + 1].sum;
	tree[treenode].best_prefix_sum = max(tree[2 * treenode].best_prefix_sum, tree[2 * treenode].sum + tree[2 * treenode + 1].best_prefix_sum);
	tree[treenode].best_suffix_sum = max(tree[2 * treenode + 1].best_suffix_sum, tree[2 * treenode + 1].sum + tree[2 * treenode].best_suffix_sum);
	tree[treenode].max_sum = max
	(
		tree[2 * treenode].max_sum,
		max
		(
			tree[2 * treenode + 1].max_sum,
			max
			(
				tree[2 * treenode].sum + tree[2 * treenode + 1].best_prefix_sum,
				max
				(
					tree[2 * treenode + 1].sum + tree[2 * treenode].best_suffix_sum,
					tree[2 * treenode].best_suffix_sum + tree[2 * treenode + 1].best_prefix_sum
				)
			)
		)
	);
}
attrs query(attrs* tree, int start, int end, int treenode, int left, int right)
{
	//completely outside
	if (start > right || end < left)
	{
		return {-100000, -100000, -100000, -100000};
        //not used int min here because during recursion it will become +ve if any number is subtracted from it.
	}
	//completely inside
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	//partially outside and partially inside
	int mid = (start + end) / 2;
	attrs q1 = query(tree, start, mid, 2 * treenode, left, right);
	attrs q2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
	attrs ans;
	ans.sum = q1.sum + q2.sum;
	ans.best_prefix_sum = max(q1.best_prefix_sum, q1.sum + q2.best_prefix_sum);
	ans.best_suffix_sum = max(q1.best_suffix_sum + q2.sum, q2.best_suffix_sum);
	ans.max_sum = max
	(
		q1.max_sum,
		max
		(
			q2.max_sum,
			max
			(
				q1.sum + q2.best_prefix_sum,
				max
				(
					q2.sum + q1.best_suffix_sum,
					q1.best_suffix_sum + q2.best_prefix_sum
				)
			)
		)
	);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	attrs* tree = new attrs[4 * n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build_tree(arr, tree, 0, n - 1, 1);
	int m;
	cin >> m;
	while (m--)
	{
		int xi, yi;
		cin >> xi >> yi;
		cout << query(tree, 0, n - 1, 1, xi-1, yi-1).max_sum << endl;
		
	}
}