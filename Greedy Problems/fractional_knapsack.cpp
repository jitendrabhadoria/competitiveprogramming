// Fractional Knapsack
// Send Feedback
// You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
// Note: You are allowed to break the items in parts.
// Input Format:
// The first line of input contains two space separated integers, that denote the value of N and W.
// Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.    
// Constraints:
// 1 <= N = 2*10^5
// 1 <= W <= 10^9
// 1 <= value, weight <= 10^5
// Time Limit: 1 sec
// Output Format:
// Print the maximum total value upto six decimal places.
// Sample Input 1:
// 4 22
// 6 4
// 6 4
// 4 4
// 4 4
// Sample Output 1:
// 20.000000
// Explanation:
// The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, we will add all the items in the knapsack and total value will be 20 units.

#include <bits/stdc++.h>

using namespace std;

struct Item {
	int value;
    int weight;
};

bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

double fractionalKnapsack(Item * arr, int N, int size)
{
	sort(arr, arr + size, cmp);

	int curWeight = 0;
    
	double finalvalue = 0.0;

	for (int i = 0; i < size; i++) {

		if (curWeight + arr[i].weight <= N) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		} else {
			int remain = N - curWeight;
			finalvalue += arr[i].value * ((double)remain / arr[i].weight);
			break;
		}
	}

	return finalvalue;
}

int main()
{
	int n;
    long long int w;
    cin >> n >> w;
        
    Item * arr = new Item [n]; 

    for(int i=0;i<n;i++){
        cin>>arr[i].value>>arr[i].weight;
    }
    
	double ans = fractionalKnapsack(arr, w, n);
    cout.precision(6);
	cout << fixed << ans << endl;
	return 0;
}
