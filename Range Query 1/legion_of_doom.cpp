// Legion of Doom
// Send Feedback
// Lex Luthor’s Legion of Doom is a tough organization to get into, even for greatest supervillains. Recently, a spot has opened up because The Mad Hatter has retired. Harley Quinn doesn't want to waste this opportunity, and jumps at the chance of the interview. But she has a PhD in psychology, not in Computer Science. She has kidnapped you and will let you go only if you are able to solve the evil questions of Lex Luthor.
// You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
// 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
// 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
// Input Format:
// In the first line you'll be given T, number of test cases.

// Each test case will start with N and C. After that you'll be given C commands in the format as mentioned above
// Constraints:
//  1 <= T <= 10
//  1 <= N, C <= 10000
//  1 <= val <= 10^8
//  1 <= p <= q <= N
// Output Format:
// Print the answers of the queries in new line for each test case.
// Sample Input 1:
// 1
// 8 6
// 0 2 4 26
// 0 4 8 80
// 0 4 5 20
// 1 8 8 
// 0 5 7 14
// 1 4 8
// Sample Output 1:
// 80  
// 508

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void update_add(ll* tree, ll* lazy, ll start, ll end, ll treenode, ll left, ll right, ll value)
{
	if (start > end)
	{
		return;
	}
	if (lazy[treenode] != 0)
	{
		tree[treenode] += (end - start + 1) * lazy[treenode];
		if (start != end)
		{
			lazy[2 * treenode] += lazy[treenode];
			lazy[2 * treenode + 1] += lazy[treenode];
		}
		lazy[treenode] = 0;
	}
	//completely outside
	if (start > right || end < left)
	{
		return;
	}
	//completely inside
	if (start >= left && end <= right)
	{
		tree[treenode] += (end - start + 1) * value;
		if (start != end)
		{
			lazy[2 * treenode] += value;
			lazy[2 * treenode + 1] += value;
		}
		return;
	}
	//partial overlap
	ll mid = (start + end) / 2;
	update_add(tree, lazy, start, mid, 2 * treenode, left, right, value);
	update_add(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right, value);
	tree[treenode] = tree[2 * treenode] + tree[2 * treenode + 1];
	return;
}
ll query_sum(ll* tree, ll* lazy, ll start, ll end, ll treenode, ll left, ll right)
{
	if (start > end)
	{
		return 0;
	}
	if (lazy[treenode] != 0)
	{
		tree[treenode] += (end - start + 1) * lazy[treenode];
		if (start != end)
		{
			lazy[2 * treenode] += lazy[treenode];
			lazy[2 * treenode + 1] += lazy[treenode];
		}
		lazy[treenode] = 0;
	}
	//completely outside
	if (start > right || end < left)
	{
		return 0;
	}
	//completely inside
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	//partial overlap
	ll mid = (start + end) / 2;
	ll left_child = query_sum(tree, lazy, start, mid, 2 * treenode, left, right);
	ll right_child = query_sum(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right);
	return left_child + right_child;
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, c;
		cin >> n >> c;

		ll* tree = new ll[4 * n]();
		ll* lazy = new ll[4 * n]();
		while (c--)
		{
			ll command_type;
			cin >> command_type;
			if (command_type == 0)
			{
				ll left, right, value;
				cin >> left >> right >> value;
				update_add(tree, lazy, 0, n - 1, 1, left - 1, right - 1, value);
			}
			else
			{
				ll left, right;
				cin >> left >> right;
				cout << query_sum(tree, lazy, 0, n - 1, 1, left - 1, right - 1) << endl;
			}
		}
	}
}