// The GCD Dillema
// Send Feedback
// Dwight is always bragging about how amazing he is at solving complicated problems with much ease. Jim got tired of this and gave him an interesting problem to solve.
// Jim gave Dwight a sequence of integers a1, a2, ..., an and q queries x1, x2, ..., xq on it. For each query xi Dwight has to count the number of pairs (l, r) such that 1 ≤ l ≤ r ≤ n and GCD(al, al + 1, ..., ar) = xi. Dwight is feeling out of his depth here and asked you to be his Secret Assistant to the Regional Manager. Your first task is to help him solve the problem. Are you up to it?
// Input Format:
// First line of input contains an integer N, representing the number of elements in the sequence.
// Second line contains N space-separated integers denoting the elements of the sequence.
// Third line of input contains an integer Q, representing the number of queries.
// Next Q line contains an integer X.
// Constraints:
// 1 < = N <= 10^4
// 1 <= arr[i] <= 10^9
// 1 <= Q <= 10^4
// 1 <= X <= 10^9 
// Output Format:
// For each query, print the answer in a new line.
// Sample Input:
// 2
// 8 12 
// 3
// 8
// 12
// 4
// Sample Output:
// 1
// 1
// 1

#include<bits/stdc++.h>
using namespace std;

const int LIM = 100003;
int A[LIM], N;
map<int, long long> countg[2], finalc; // final[i] stores the countg of subarrays with gcd = i
map<int, long long>::iterator it;

void precompute() {
  // at any state i, countg[prev] stores the gcd's of subarrays ending at A[i - 1] with their countg,
  // for making countg[curr], we take the gcd of A[i] with all elements in countg[prev] and add the countg
  // original solution by Rachit http://codeforces.com/contest/475/submission/8093857
  countg[0][A[0]] = 1;
  finalc[A[0]] = 1LL;
  int g, curr, prev;
  for(int i = 1; i < N; i++) {
    curr = i & 1, prev = curr ^ 1;
    countg[curr].clear();
    countg[curr][A[i]] = 1LL;    // 1 for the subarray containing only A[i], rest will come from taking gcd with those till A[i - 1] in countg[prev]
    for(it = countg[prev].begin(); it != countg[prev].end(); it++) {
      g = __gcd(it->first, A[i]);
      countg[curr][g] += it->second;   // every subarray giving it->first till A[i - 1] will give g with A[i]
    }
    for(it = countg[curr].begin(); it != countg[curr].end(); it++) finalc[it->first] += it->second;
  }
}

int main() {
 
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  precompute();
  int Q, x;
  long long ans;
  cin >> Q;
  while(Q--) {
    cin >> x;
    ans = finalc[x];
    cout << ans << "\n";
  }

  return 0;
}