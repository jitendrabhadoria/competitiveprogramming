// Sum Of Squares
// Send Feedback
// Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
// The sum of squares over a range with range updates of 2 types:
// 1) increment in a range
// 2) set all numbers the same in a range.
// There will be T test cases in the input file. First line of the input contains two positive integers, N and Q.
// The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
// 2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

// 1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and 1 <= x <= 1,000).

// 0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and 1 <= x <= 1,000).
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// Line 1: contain two space-separated integers denoting the value of N and Q respectively
// Line 2: contain N space-separated integers denoting th value of array elements
// Next Q line contain the space separated value for queries as defined as above.
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 10000
// 1 <= arr[i] <= 1000
// 1 <= Q <= 10000
// Output Format:
// For each test case, print the answer in new line for query of type 2
// Sample Input 1:
// 2
// 4 5
// 1 2 3 4
// 2 1 4
// 0 3 4 1
// 2 1 4
// 1 3 4 1
// 2 1 4
// 1 1
// 1
// 2 1 1
// Sample Output 1:
// 30
// 7
// 13
// 1

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n;

ll tree[400000];
ll arr[100000];

void build(int node, int start,  int end){
    if(start > end)
        return;
    if(start==end){
        //Leaf node.
        tree[node] = arr[start]*arr[start];
        return;
    }
    //Recurse on the left child.
    int mid = (start+end)>>1;
    int left = node<<1, right = left+1;
    build(left, start, mid);
    //Recurse on the right child.
    build(right, mid+1, end);
    //Internal node will have the sum of both its children.
    tree[node] = tree[left] + tree[right];
}


//Time Complexity O(log(n))
ll query(int node, int start, int end, int l, int r){
    if(start > end || start > r || end < l)
        return 0; 
        //complete overlap
    if(l <= start && end <= r)
        return tree[node];
    //partial overlap
    int mid = (start+end)/2;
    int left = node<<1, right = left+1;
        return query(left, start, mid, l, r) + query(right, mid+1, end, l, r);
}

//Worst case complexity is O(n)
void update1(int node, int start, int end, int l, int r, int value){
    //increase values from l to r by value
    //no overlap of the l to r segment on the current segment
    if(start > end || start > r || end < l)
        return;
    if(start==end){
        //Leaf node
        arr[start]+=value;
        tree[node] = arr[start]*arr[start];
        return;
    }
    int mid = (start+end)/2;
    int left = node<<1, right = left+1;
    update1(left, start, mid, l, r, value);
    update1(right, mid+1, end, l, r, value);
    tree[node] = tree[left] + tree[right]; 
}

void update2(int node, int start, int end, int l, int r, int value){
    //increase values from l to r by value
    //no overlap of the l to r segment on the current segment
    if(start > end || start > r || end < l)
        return;
    if(start==end){
        //Leaf node
        arr[start] = value;
        tree[node] = arr[start]*arr[start];
        return;
    }
    int mid = (start+end)/2;
    int left = node<<1, right = left+1;
    update2(left, start, mid, l, r, value);
    update2(right, mid+1, end, l, r, value);
    tree[node] = tree[left] + tree[right]; 
}

int main(){

    cin >> t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));
        cin >> n;
        int q;
        cin >> q;
        for(int i = 0;i < n; i++){
            cin >> arr[i];
        }
        build(1, 0, n-1);
        int flag = 0;
        while(q--){
            int type;
            cin >> type;
            if(type == 0){
                int st, end, x;
                cin >> st >> end >> x;
                update2(1, 0, n-1, st-1, end-1, x);
            } else if(type == 1){
                int st, end, x;
                cin >> st >> end >> x;
                update1(1, 0, n-1, st-1, end-1, x);
            } else {
                int st, end;
                cin >> st >> end;
                if(flag == 0){
                    flag = 1;
                }
                cout << query(1, 0, n-1, st-1, end-1) << endl;
            }
        }  
    }
    return 0;
}